/*!
  \file bvh.hpp
  \brief This file contains the top level data structure 
  * used to store a bvh file data.
  *
  * This file defines the bvh data structure along with 
  * the toplevel access and rendering methods.
*/
#ifndef _BVH_HPP_
#define _BVH_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "bvh_tokens.hpp"
#include "bvh_joints.hpp"
#include "bvh_hierarchy.hpp"
#include "matvec.hpp"


namespace bvh
{
  //! The bvh data structure
  /*! The bvh data structure has primarily two components one to store the skeleton hierarchy,
   *  another to store the motion data. A bvh data structure may not even have any motion
   *  data. It would be desirable to extend this class so that it can handle multiple
   *  skeleton hierarchies from one file but since the exact specification of this is not 
   *  known it is left for the future.
       */
  class bvh_t
  {
  protected:
    
    //! A pointer to a bvh skeleton hierarchy
    hierarchy_t *hierarchy;
    
    //! A pointer to bvh motion data
    motion_t *motion;
    
    //! A flag indicating whether the bvh file has motion data or not
    bool has_motion;
    
    //! The bvh filename
    std::string bvh_filename;
    
    //! The default constructor
    /*! The default constructor is protected because it should never be called.
     *  The other constructors declared public should be used instead.
     */
    bvh_t(){};
    
    //! This method reads in the bvh file
    void read(void);
    
    //! Method to render the bvh hierarchy in its current pose
    /*! Assuming all the joint matrices have been updated for this pose
     *  
     * CS775: Implement this method
    */
    void render_pose(joint_t *jtptr);
    
 public:
    
    //! Constructor
    /*! The bvh filename is specified so that read can be called from the constructor
     *  and thus the bvh file gets loaded as soon as the object is instantiated
     */
    bvh_t(std::string _filename);
    
    //! Constructor
    /*! The bvh filename is specified so that read can be called from the constructor
     *  and thus the bvh file gets loaded as soon as the object is instantiated
     */
    bvh_t(std::string _filename, bool _has_motion);
    
    //! Destructor
    ~bvh_t();
    
    //@{
    //! Accessor method
    hierarchy_t* get_hierarchy(void);
    motion_t* get_motion(void);
    std::string get_filename(void);
    bool get_has_motion(void);
    
    void set_hierarchy(hierarchy_t* _hierarchy);
    void set_motion(motion_t* _motion);
    //@}
    
    //! This method prints the bvh skeleton hierarchyinto the output stream out
    void print_hierarchy(std::ostream &out);
    
    //! This method prints the bvh skeleton hierarchyinto the output stream out
    void print_motion(std::ostream &out);
    
    //! Method to render the bvh hierarchy in its canonical pose
    /*!
     * Canonical pose is the pose of the hierarchy at rest.
     *
     * CS775: Implement this method
     */
    void render_canonical_pose(void);
    
    //! Method to render the bvh hierarchy in its current pose in the given frame number 
    /*! his method accesses the hierarchy as the linear joint list. This function
     *  updates all the matrics for the hierarchy using \ref hierarchy_t::update_joint_matrix on each joint
     *  and then calls \ref render_pose to do all the rendering work.
     *
     * CS775: Implement this method
     */
    void render_frame(unsigned int frame_number);
  };
  
}

#endif
