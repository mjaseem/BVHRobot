#include "bvh_hierarchy.hpp"
#include "error.hpp"

using namespace bvh;

//--------------------------------------------------------------------------------
// hierarchy_t

hierarchy_t::hierarchy_t()
{
  root_ptr = NULL;
  tot_num_channels = 0;
  has_valid_joint_list = false;
}

hierarchy_t::~hierarchy_t()
{
  if (root_ptr != NULL) delete root_ptr;
}

joint_t* hierarchy_t::get_root_ptr(void)
{
  return root_ptr;
}

unsigned int hierarchy_t::get_tot_num_channels(void)
{
  return tot_num_channels;
}

bool hierarchy_t::get_has_valid_joint_list(void)
{
  return has_valid_joint_list;
}

std::list<joint_t *>* hierarchy_t::get_joint_list(void)
{
  return &joint_list;
}

void hierarchy_t::set_root_ptr(joint_t* _root_ptr)
{
  root_ptr = _root_ptr;
}

void hierarchy_t::set_tot_num_channels(unsigned int _tot_num_channels)
{
  tot_num_channels = _tot_num_channels;
}

void hierarchy_t::set_joint_list(std::list<joint_t *> _joint_list)
{
  joint_list = _joint_list;
}

void hierarchy_t::build_joint_list(joint_t* jtptr)
{
  if (jtptr == NULL) return;
  tot_num_channels += (jtptr->get_channels()).num_channels;
  joint_list.push_back(jtptr);
  std::list<joint_t *>::iterator iter;
  for(iter = jtptr->get_childlist()->begin(); iter != jtptr->get_childlist()->end(); iter++)
    {
      (*iter)->set_absolute_offset(jtptr->get_absolute_offset() + (*iter)->get_offset());
      build_joint_list(*iter);
    }
}

void hierarchy_t::read(std::ifstream &inp)
{
  std::string strtoken;
  inp>>strtoken;
  if (token_map_array::get_token(strtoken) != _HIERARCHY)
    throw new util::common::warning_error("(hierarchy_t::read) : Missing 'HIERARCHY' tag in bvh file");
  inp>>strtoken;
  root_ptr = new joint_t;
  try
    {
      root_ptr->read(inp, strtoken);
      build_joint_list(root_ptr);
      has_valid_joint_list = true;
    }
  catch (util::common::error *e)
    {
      util::common::error::propogate_error(e);
    }
}

void hierarchy_t::print_rec(std::ostream &out, joint_t* jtptr)
{
 if (jtptr == NULL) return;
  jtptr->print(out);
  std::list<joint_t *>::iterator iter;
  for(iter = jtptr->get_childlist()->begin(); iter != jtptr->get_childlist()->end(); iter++)
    print_rec(out, *iter);
}

void hierarchy_t::print_lin(std::ostream &out)
{
  if (has_valid_joint_list)
    {
      std::list<joint_t *>::iterator iter;
      for(iter = joint_list.begin(); iter != joint_list.end(); iter++)
	(*iter)->print(out);
    }
  else
    throw new util::common::warning_error("(hierarchy_t::print_linear_joint_list) Attempt to print an invalid joint list");
}

void hierarchy_t::update_joint_matrix(joint_t *jtptr, float *joint_data_channels)
{
    /* CS775: Implement this method */
    jtptr->update_matrix(joint_data_channels);
    jtptr->set_absolute_M(jtptr->get_M());
    joint_t* parent=jtptr->get_parent();
    if(parent!=NULL) 
      {   
	util::math::mat44 M1= parent->get_absolute_M();
	util::math::mat44 M2= jtptr->get_M();
	jtptr->set_absolute_M(M1*M2);
      }
}

//--------------------------------------------------------------------------------
// motion_t methods

motion_t::motion_t()
{
  frames = 0;
  frame_rate = 0.0;
  data = NULL;
}

motion_t::~motion_t()
{
  if (data != NULL)
    {
      for (unsigned int i = 0; i < frames; i++)
	delete[] data[i];
      delete[] data;
    }
}

unsigned int motion_t::get_frames(void)
{
  return frames;
}

double motion_t::get_frame_rate(void)
{
  return frame_rate;
}

float** motion_t::get_data(void)
{
  return data;
}

unsigned int motion_t::get_data_channels(void)
{
  return data_channels;
}

void motion_t::set_frames(unsigned int _frames)
{
  frames = _frames;
}

void motion_t::set_frame_rate(double _frame_rate)
{
  frame_rate = _frame_rate;
}

void motion_t::set_data(float** _data)
{
  data = _data;
}

void motion_t::set_data_channels(unsigned int _data_channels)
{
  data_channels = _data_channels;
}

void motion_t::read(std::ifstream &inp)
{
  std::string strtoken;
  inp>>strtoken;
  if (token_map_array::get_token(strtoken) != _MOTION)
    throw new util::common::warning_error("(motion_t::read) : Missing 'MOTION' tag in bvh file");

  inp>>strtoken;
  if (token_map_array::get_token(strtoken) != _FRAMES)
    throw new util::common::warning_error("(motion_t::read) : Missing 'Frames:' tag in bvh file");
  inp>>frames;

  inp>>strtoken;
  if (strtoken == "Frame")
    {
      std::string temptoken;
      inp>>temptoken;
      if (token_map_array::get_token(strtoken+" "+temptoken) != _FRAMETIME)
	throw new util::common::warning_error("(motion_t::read) : Missing 'Frame Time:' tag in bvh file");
    }
  else
    throw new util::common::warning_error("(motion_t::read) : Missing 'Frame Time:' tag in bvh file");
  inp>>frame_rate;

  data = new float*[frames];
  for(unsigned int i = 0; i < frames; i++)
    data[i] = new float[data_channels];

  for(unsigned int i = 0; i < frames; i++)
    {
      for(unsigned int j = 0; j < data_channels; j++)
	inp>>data[i][j];
    }
}

void motion_t::print(std::ostream &out)
{
  out<<"Motion Data"<<std::endl;
  out<<"Frames: "<<frames<<std::endl;
  out<<"Frame Time: "<<frame_rate<<std::endl;
  out<<"Data: "<<std::endl;
  for(unsigned int i = 0; i < frames; i++)
    {
      for(unsigned int j = 0; j < data_channels; j++)
	out<<data[i][j]<<" ";
      out<<std::endl;
    }
}
