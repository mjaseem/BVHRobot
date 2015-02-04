/*!
  \file bvh_hierarchy.hpp
  \brief This file contains the data structure used to 
  * store a bvh skeleton hierarchy.
  *
  * This file defines the hierarchy data structure and 
  * also the data structure used to store the motion 
  * data in the bvh file.
*/

#ifndef _BVH_HIERARCHY_HPP_
#define _BVH_HIERARCHY_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "bvh_tokens.hpp"
#include "bvh_joints.hpp"
#include "matvec.hpp"


namespace bvh
{
  //! The hierarchy_t data structure
  /*! This data structure contains the bvh skeleton hierarchy. 
   *  The hierarchy is stored as a n-ary tree as per its natural 
   *  structure. 
   *  The hierarchy is linearized by a traversal of the tree
   *  and is also stored as a linear list of joints in 
   *  the order in which they appear in the file. 
   */ 
  class hierarchy_t
  {
  protected:
    
    //! The root pointer of the hierarchy tree
    joint_t *root_ptr;
    
    //! The total number of data channels the hierarchy has
    /*! The total number of channels represents the total number
     *  of degrees of freedom the hierarchy has.
     */
    unsigned int tot_num_channels;
    
    //! Flag signifying whether the linear joint list has been built or not
    bool has_valid_joint_list;
    
    //! The linear joint list
    /*! The joints appear in this list in the order in which they appear
     *  in the file. This list is built using the \ref build_joint_list
     *  method which is automatically called in the constructor.
     */
    std::list<joint_t *> joint_list;
    
    //! Method used to build the linear joint list
    void build_joint_list(joint_t* jtptr);
    
  public:
    
    //! Constructor
    /*! The constructor also has the added task of calling 
     *  \ref build_joint_list to make sure that the linear joint
     *  list gets built bfeore any access to the hierarchy is made.
     */
    hierarchy_t();
    
    //! Destructor
    ~hierarchy_t();
    
    //@{
    //! Accessor method
    joint_t* get_root_ptr(void);
    unsigned int get_tot_num_channels(void);
    bool get_has_valid_joint_list(void);
    std::list<joint_t *>* get_joint_list(void);
    
    void set_root_ptr(joint_t* _root_ptr);
    void set_tot_num_channels(unsigned int _tot_num_channels);
    void set_joint_list(std::list<joint_t *> _joint_list);
    //@}
    
    //! This method reads in the hierarchy from the input stream inp
    void read(std::ifstream &inp);
    
    //! This method prints the hierarchy on the output stream out
    /*! This method recursively accesses the hierarchy tree so it
     *  needs the a pointer in the tree from where to start the 
     *  recursion. To print out the whole hierarchy pass the root
     *  pointer as jtptr
     *
     *  This shows how to access the hierarchy recursively
     */ 
    void print_rec(std::ostream &out, joint_t* jtptr);
    
    //! This method reads in the hierarchy from the input stream inp
    /*! This method prints the hierarchy by linearly accessing the
     *  linear joint list
     *
     * This shows how to access the hierarchy linearly
     */ 
    void print_lin(std::ostream &out);
    
    //! This method updates the absolute transformation matrix for a joint
    /*! This method calculates the matrix by traversing the path 
     *  from the joint to the root and concatenating the relative
     *  transformation matrix at each node in the order -
     *  absoulute_Mjoint = Mroot * ... * Mgrandparent * Mparent * Mjoint
     *
     *  joint_data_channels should contain exactly the data channels 
     *  for the joint whose matrix has to be calculated, so that it can
     *  be used in the \ref joint_t::update_matrix call for the particular joint in question.
     *
     * CS775: Implement this method
     */
    void update_joint_matrix(joint_t *jtptr, float *joint_data_channels);

  };
  
  //! The motion_t data structure
  /*! This data structure contains the bvh moiton data. 
   *  The motion data is stored in the form of an array of dimension
   *  equal to frames * data_channels
   */ 
  class motion_t
  {
  protected:
    
    //! The number of frames
    unsigned int frames;
    
    //! The frame rate in fps
    double frame_rate;
    
    //! The motion data
    float **data;
    
    //! Total number of data channels
    unsigned int data_channels;
    
  public:
    //! Constructor
    motion_t();
    
    //! Destructor
    ~motion_t();
    
    //@{
    //! Accessor Method
    unsigned int get_frames(void);
    double get_frame_rate(void);
    float** get_data(void);
    unsigned int get_data_channels(void);
    
    void set_frames(unsigned int _frames);
    void set_frame_rate(double _frame_rate);
    void set_data(float** _data);
    void set_data_channels(unsigned int _data_channels);
    //@}
    
    //! This method reads in the motion data from the input stream inp
    /*! The motion data matrix is dynamically allocated in this method
     */ 
    void read(std::ifstream &inp);
    
    //! This method prints the motion data to the output stream out
    void print(std::ostream &out);
  };
}

#endif
