/*! \mainpage CS 775: Assignment 1 - BVH Player Basecode 
 *
 *  - Implement all methods marked "CS775" in the comments.
 *
 *  - To compile, use the Makefile.
 *
 *  - Create a separate gl_interface.cpp/gl_interface.hpp file
 *    and put all your glfw callbacks there.
 * 
 *  - For playing back your animation at the correct speed
 *    use glfw timers
 *
 *  - Your glfw display function can make calls to 
 *    \ref bvh::bvh_t::render_frame or \ref bvh::bvh_t::render_canonical_pose 
 *    to draw the skeleton itself.
 */

/*!
  \file main.hpp
  \brief This file is a header for the BVHplayer main function
*/

#include <iostream>
#include <string>
#include <unistd.h>
#include "bvh.hpp"
#include "error.hpp"


bvh::bvh_t* bvh_fig;
std::string progname, bvhfilename;

/*!
  \fn void usage(void)
  \brief This function displays the usage message
*/
void usage(void);

/*!
  \fn int main(int argc, char** argv)
  \brief The function reads in the input bvhfile and plays it
  *
  * CS 775: Call the function that will start your rendering in here.
*/
int main(int argc, char **argv);
