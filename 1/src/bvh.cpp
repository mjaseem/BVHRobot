#include "bvh.hpp"
#include "error.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace bvh;

//--------------------------------------------------------------------------------
// bvh_t methods

bvh_t::bvh_t(std::string _filename)
{
  hierarchy = NULL;
  motion = NULL;
  has_motion = true;
  bvh_filename = _filename;
  try { read(); }
  catch (util::common::error *e)
    { util::common::error::propogate_error(e); }
}
 
bvh_t::bvh_t(std::string _filename, bool _has_motion)
{
  hierarchy = NULL;
  motion = NULL;
  has_motion = _has_motion;
  bvh_filename = _filename;
  try { read(); }
  catch (util::common::error *e)
    { util::common::error::propogate_error(e); }
}

bvh_t::~bvh_t()
{
  if (hierarchy != NULL) delete hierarchy;
  if (motion != NULL) delete motion;
}

hierarchy_t* bvh_t::get_hierarchy(void)
{
  return hierarchy;
}

motion_t* bvh_t::get_motion(void)
{
  return motion;
}

std::string bvh_t::get_filename(void)
{
  return bvh_filename;
}

bool bvh_t::get_has_motion(void)
{
  return has_motion;
}

void bvh_t::set_hierarchy(hierarchy_t* _hierarchy)
{
  hierarchy = _hierarchy;
}
	
void bvh_t::set_motion(motion_t* _motion)
{
  motion = _motion;
}

void bvh_t::read(void)
{
  if (bvh_filename.empty())
    throw new util::common::warning_error("(bvh_t::read) : Invalid filename");

  std::ifstream inp (bvh_filename.c_str());
  if (inp == NULL)
    throw new util::common::warning_error("(bvh_t::read) : Unable to open file for reading"); 

  hierarchy = new hierarchy_t;

  try { hierarchy->read(inp); }
  catch (util::common::error *e)
    { util::common::error::propogate_error(e); }

  if (has_motion)
    {
      motion = new motion_t;
      motion->set_data_channels(hierarchy->get_tot_num_channels());
      try { motion->read(inp); }
      catch (util::common::error *e)
	{ util::common::error::propogate_error(e); }
    }
  
  inp.close();
}

void bvh_t::print_hierarchy(std::ostream &out)
{
  try 
    { 
      hierarchy->print_lin(out); 
      out<<"Total number of channels : "<<hierarchy->get_tot_num_channels()<<std::endl;
    }
  catch (util::common::error *e)
    { util::common::error::propogate_error(e); }
}

void bvh_t::print_motion(std::ostream &out)
{
  if (has_motion)
    { 
      motion->print(out); 
    }
  else 
    throw new util::common::warning_error("(bvh_t::print_motion) No motion data available");
}

void bvh_t::render_pose(joint_t *jtptr)
{
  /* CS775: Implement this method */
  util::math::vec4 point1;
  util::math::vec4 point2;
  util::math::mat44 current_M=jtptr->get_absolute_M();
  util::math::vec4 origin=util::math::vec4(0,0,0,1);
  //(*iter)->print(std::cout);
  joint_t* parent=jtptr->get_parent();
  point1=current_M*origin;
  if(parent!=NULL)
    {
      util::math::mat44 parent_M=parent->get_absolute_M();
      point2=parent_M*origin;
    }
  else
    point2=point1;
  glVertex3f(point1[0]/point1[3],point1[1]/point1[3],point1[2]/point1[3]);
  glVertex3f(point2[0]/point2[3],point2[1]/point2[3],point2[2]/point2[3]);
  
}

void bvh_t::render_canonical_pose(void)
{
  /* CS775: Implement this method */
  std::list<joint_t *>::iterator iter;
  util::math::vec4 origin=util::math::vec4(0,0,0,1);
  //util::math::vec4 origin2=util::math::vec4(1,2,2,2);
  util::math::vec4 point1;
  util::math::vec4 point2;
  for(iter = hierarchy->get_joint_list()->begin(); iter != hierarchy->get_joint_list()->end(); iter++)
    {
      float values[6]={0,0,0,0,0,0};
      hierarchy->update_joint_matrix((*iter),values);
      util::math::mat44 current_M=(*iter)->get_absolute_M();
      //(*iter)->print(std::cout);
      joint_t* parent=(*iter)->get_parent();
      point1=current_M*origin;
      if(parent!=NULL)
	{
         util::math::mat44 parent_M=parent->get_absolute_M();
         point2=parent_M*origin;
	}
      else
	point2=point1;
      glVertex3f(point1[0]/point1[3],point1[1]/point1[3],point1[2]/point1[3]);
      glVertex3f(point2[0]/point2[3],point2[1]/point2[3],point2[2]/point2[3]);
    }
  
}



void bvh_t::render_frame(unsigned int frame_number)
{
  /* CS775: Implement this method */
  std::list<joint_t *>::iterator iter;
  float** data=motion->get_data();
  int offset_channels=0;
  glBegin(GL_LINES);
  for(iter = hierarchy->get_joint_list()->begin(); iter != hierarchy->get_joint_list()->end(); iter++)
    {
      float* values=new float[((*iter)->get_channels()).num_channels];
      values=data[frame_number]+offset_channels;
      hierarchy->update_joint_matrix((*iter),values);
      render_pose((*iter));
      offset_channels+=((*iter)->get_channels()).num_channels;
    }
  glEnd();
}

