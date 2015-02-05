#include "main.hpp"




void usage(void) 
{
  std::cerr<< "usage: "<<progname<<" [-h] -i bvhfile"<<std::endl<<std::endl;
  std::cerr<< "\t-h\t\t\tprint usage"<<std::endl;  
  std::cerr<< "\t-i bvhfile\t\tThe BVH filename\n";
  exit(0);
}

//-----------------------------------------------------------------------

bool PLAY;
bool SKELETON;


//!GLFW keyboard callback
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
  {
    //!Close the window if the ESC key was pressed
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
     if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
      PLAY=!PLAY;
    if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
      SKELETON=!SKELETON;
  }
float** Animation_data;
void renderGL( void )
{
    if (SKELETON==true){
    	glBegin(GL_LINES);
	bvh_fig->render_canonical_pose();
    	glEnd();
    }
    
    for(unsigned int i=0;i<bvh_fig->get_motion()->get_frames();i++)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if((PLAY==true)&&(SKELETON==true)){
		
		glfwSetTime(0);
		bvh_fig->render_frame(i);
		while(glfwGetTime() <= 0.01);
		glfwSwapBuffers(glfwGetCurrentContext());
		glfwPollEvents();
		}
	else if((PLAY==true)&&(SKELETON==false)){
		Animation_data=(float**)malloc(sizeof(bvh_fig->get_motion()->get_data()));
		Animation_data=bvh_fig->get_motion()->get_data();
		robot.makeRobot(Animation_data[i]);
		glfwSwapBuffers(glfwGetCurrentContext());
		glfwPollEvents();
		//robot.makeRobot();
	}
	else if(PLAY==false){
		while(PLAY==false){
		glfwSwapBuffers(glfwGetCurrentContext());
		glfwPollEvents();
		}
		
	}
    }
}
int main(int argc, char **argv)
{
  GLFWwindow* window;
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
  	
	PLAY=true;
	SKELETON=true;

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
  	glfwSetKeyCallback(window, key_callback);
  	//Framebuffer resize callback
  	glfwSetFramebufferSizeCallback(window, cs775::framebuffer_size_callback);

  	// Ensure we can capture the escape key being pressed below
  	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  	glfwGetFramebufferSize(window, &win_width, &win_height);
  	cs775::framebuffer_size_callback(window, win_width, win_height);
  	//Initialize GL state
  	cs775::initGL();
  	robot = Robot();
  
  	glScalef(0.01,0.01,0.01);
	while (glfwWindowShouldClose(window) == 0)
    	  {
		 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    		 glEnable(GL_DEPTH_TEST);
   		 renderGL();
		  // Swap front and back buffers
      		 glfwSwapBuffers(window);
      		  // Poll for and process events
      		 glfwPollEvents();

    	  }


    }
  catch (util::common::error *e)
    { util::common::error::halt_on_error(e); }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}


//-----------------------------------------------------------------------
