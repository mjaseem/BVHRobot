/*!
  \file bvh_joints.hpp
  \brief This file contains the data structure used to store a bvh joint
*/
#ifndef _BVH_JOINTS_HPP_
#define _BVH_JOINTS_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "bvh_tokens.hpp"
#include "matvec.hpp"

namespace bvh
{
  //! The types of data channels present in a bvh file
  enum channel_types { _xpos, _ypos, _zpos, _xrot, _yrot, _zrot};
  
  //! The types of joints present in a bvh file
  enum joint_types { _root, _joint, _endsite};
  
  //! The joint render mode
  enum joint_render_mode { _point, _sphere};
  
  //! The channel data type
  struct channel_t
  {
    //! The number of channels of data for a joint
    int num_channels;
    //! The order of data channels for a joint
    channel_types ch_order[6];
    
    //! Overloaded = operator
    channel_t& operator = (const channel_t& _ch); 
  };
  
  //! The offset data type is just a vec3
  typedef util::math::vec3 offset_t;
  
  //! The joint_t data structure
  /*! 
   *  It stores all info for a joint of the skeleton hierarchy.
   */ 
  class joint_t
  {
  protected:
    //! The joint name
    std::string name;
    
    //! The relative joint offset 
    /*! The joint offset relative to its parent. This defines
     *  the position of the joint when the skeleton is in the
     *  canonical pose. See the \ref update_matrix method for more
     *  information.
     */
    offset_t offset;
    
    //! The data channels for the joint
    channel_t channels;
    
    //! The childlist for the joint.
    /*! Every joint except an end site has a childlist which 
     *  contains pointers to all the child joints. For an 
     *  end site this list is empty.
     */
    std::list<joint_t *> childlist;
    
    //! The current relative transformation matrix of the joint
    /*! This matrix will place the joint in the correct position
     *  relative to its parent, provided the parent is already 
     *  positioned at the right place.
     */
    util::math::mat44 M;
    
    //! This is the type of the joint
    joint_types joint_type;
    
    //! The absolute joint offset
    /*! The absolute joint offset relative to the root. This 
     *  is calculated by summing up the offsets of all the 
     *  joints on path from the joint in question to the root.
     */
    offset_t absolute_offset;
    
    //! The current absolute transformation matrix of the joint
    /*! This matrix will place the joint in the correct absolute
     *  position relative to the root. 
     */
    util::math::mat44 absolute_M;
    
    //! A pointer to the parent of the current joint
    joint_t* parent;
    
    //! The joint scale factor
    /*! The scale factor for the joint while rendering. Has
     *  any effect only if the rendering mode is set to _sphere
     */
    float render_joint_size;
    
    //! The joint rendering mode
    joint_render_mode render_mode;
    
  public:
    //! Constructor
    joint_t();
    
    //! Destructor
    ~joint_t();
    
    //@{
    //! Accessor method
    std::string get_name(void);
    offset_t get_offset(void);
    channel_t get_channels(void);
    std::list<joint_t *>* get_childlist(void);
    util::math::mat44 get_M(void);
    joint_types get_joint_type(void);
    offset_t get_absolute_offset(void);
    util::math::mat44 get_absolute_M(void);
    joint_t* get_parent(void);
    float get_render_joint_size(void);
    joint_render_mode get_render_mode(void);
    
    void set_name(std::string _name);
    void set_offset(offset_t _offset);
    void set_channels(channel_t _channels);
    void set_childlist(std::list<joint_t *> _childlist);
    void set_M(util::math::mat44 _M);
    void set_absolute_M(util::math::mat44 _absolute_M);
    void set_joint_type(joint_types _joint_type);
    void set_absolute_offset(offset_t _absolute_offset);
    void set_parent(joint_t* _parent);
    void set_render_joint_size(float _render_joint_size);
    void set_render_mode(joint_render_mode _render_mode);
    //@}
    
    //! Method to read a joint
    /*! This method reads in a joint from the input stream inp
     *  and fills in the various joint attributes.
     */
    void read(std::ifstream &inp, std::string strtoken);
    
    //! This method prints the joint to an the output stream out
    void print(std::ostream &out);
    
    //! Method to update the current transformation matrix
    /*! This method reads in the data from data channels and uses
     *  it to calculate the joint transformation matrix \ref M.
     *  The following things are to be kept in mind -
     *  <ul>
     *    <li> The number of data elements in data_channels is
     *         given by the num_channels field \ref channels
     *    <li> The order of the data elements in data_channels is
     *         given by the ch_order field of \ref channels
     *  </ul>
     *  The rotations are used to create rotation matrices which are 
     *  multiplied in the order the corresponding channels appear
     *  in the BVH file (generally it is Zrotmat * Xrotmat * Yrotmat).
     *  The translation component is calculated as a sum of the
     *  (relative)offset and current position information read
     *  from data_channels
     *
     * CS 775: Implement this method
     */
    void update_matrix(float *data_channels);
  };
}

#endif
