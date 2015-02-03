#include "main.hpp"
#include "gl_framework.hpp"

void usage(void) 
{
  std::cerr<< "usage: "<<progname<<" [-h] -i bvhfile"<<std::endl<<std::endl;
  std::cerr<< "\t-h\t\t\tprint usage"<<std::endl;  
  std::cerr<< "\t-i bvhfile\t\tThe BVH filename\n";
  exit(0);
}

//-----------------------------------------------------------------------
/*void renderGL( void )
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glBegin(GL_LINES);
	bvh_fig->render_canonical_pose();
    glEnd();
    for(int i=0;i<motion->frames;i++)
    {
	bvh_fig->render_frame(i);
    }
}*/
int main(int argc, char **argv)
{
  
  progname = argv[0];

  bool bvhf_flag = false;

  char c;
  while ((c = getopt(argc, argv, "h?i:")) != EOF)
    {
      switch (c) 
        {
	case 'h':
        case '?':
          usage();
          break;
	case 'i':
	  bvhfilename =  optarg;   
          bvhf_flag = true;
          break;
	default:
	  usage();
	}
    }

  if (!(bvhf_flag)) usage();

  try 
    { 
      bvh_fig = new bvh::bvh_t(bvhfilename, true); 
      try 
	{ 
	  bvh_fig->print_hierarchy(std::cout); 
	  //bvh_fig->print_motion(std::cout); 
	}
      catch (util::common::error *e)
	{ util::common::error::halt_on_error(e); }

      /*!
       * CS 775:
       * CALL THE FUNCTION THAT STARTS YOUR PROGRAM HERE
       */
 
  	//! The pointer to the GLFW window
  	GLFWwindow* window;

  	//! Setting up the GLFW Error callback
  	glfwSetErrorCallback(cs775::error_callback);

  	//! Initialize GLFW
  	if (!glfwInit())
    	  return -1;

  	int win_width=512;
  	int win_height=512;

  	//! Create a windowed mode window and its OpenGL context
  	window = glfwCreateWindow(win_width, win_height, "Transformers", NULL, NULL);
  	if (!window)
    	{
      	  glfwTerminate();
      	  return -1;
    	}
  
  	//! Make the window's context current 
  	glfwMakeContextCurrent(window);

  	//Keyboard Callback
  	glfwSetKeyCallback(window, cs775::key_callback);
  	//Framebuffer resize callback
  	glfwSetFramebufferSizeCallback(window, cs775::framebuffer_size_callback);

  	// Ensure we can capture the escape key being pressed below
  	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  	glfwGetFramebufferSize(window, &win_width, &win_height);
  	cs775::framebuffer_size_callback(window, win_width, win_height);
  	//Initialize GL state
  	cs775::initGL();
  
  
  	glScalef(0.01,0.01,0.01);
	while (glfwWindowShouldClose(window) == 0)
    	  {
		 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    		 glEnable(GL_DEPTH_TEST);
    		 glBegin(GL_LINES);
		 bvh_fig->render_canonical_pose();
    		 glEnd();
   		 for(int i=0;i<bvh_fig->get_motion()->get_frames();i++)
    		  {
		    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		    glfwSetTime(0);
		    bvh_fig->render_frame(i);
		    while(glfwGetTime() <= 0.01);
		    glfwSwapBuffers(window);
		    glfwPollEvents();
    		  }
   		//renderGL();
		 // Swap front and back buffers
      		glfwSwapBuffers(window);
      
      		// Poll for and process events
      		glfwPollEvents();

    	  }


    }
  catch (util::common::error *e)
    { util::common::error::halt_on_error(e); }

  return 0;
}


//-----------------------------------------------------------------------
