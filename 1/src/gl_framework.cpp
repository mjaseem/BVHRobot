#include "gl_framework.hpp"

namespace cs775
{
  int win_width;
  int win_height;

  //! Initialize GL State
  void initGL(void)
  {
    //Set framebuffer clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //Set depth buffer furthest depth
    glClearDepth(1.0);
  }
  
  //!GLFW Error Callback
  void error_callback(int error, const char* description)
  {
    std::cerr<<description<<std::endl;
  }
  
  //!GLFW framebuffer resize callback
  void framebuffer_size_callback(GLFWwindow* window, int width, int height)
  {

    if  ( height == 0 ) height = 1;

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    //Draw to the whole window
    glViewport( 0, 0, width, height );

    //Keep the aspect ratio fixed
    double aspect;
    if (width > height)
    {
      aspect = (double)width/(double)height;
      //glOrtho(-aspect, aspect, -1.0, 1.0, -1.0, 1.0);
    }
    else
    {
      aspect = (double)height/(double)width;
      //glOrtho(-1.0, 1.0, -aspect, aspect, -1.0, 1.0);
    }

    win_width = width;
    win_height = height;
  }
  
  
};  
  


