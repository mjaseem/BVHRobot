#include "main.hpp"
#include "math.h"
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
bool FORWARD,BACKWARD;
bool CAMERA1;
bool CAMERA2;
bool REST;
//!GLFW keyboard callback
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //!Close the window if the ESC key was pressed
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		PLAY=!PLAY;
		REST=false;
	}
	if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
		SKELETON=!SKELETON;
	if (key == GLFW_KEY_F2 && action == GLFW_PRESS)
		FORWARD=true;
	if (key == GLFW_KEY_F3 && action == GLFW_PRESS)
		BACKWARD=true;
	if (key == GLFW_KEY_F4 && action == GLFW_PRESS)
		CAMERA1=!CAMERA1;
	if (key == GLFW_KEY_F5 && action == GLFW_PRESS)
		CAMERA2=!CAMERA2;

}

float** Animation_data;
void renderGL(unsigned int i){

	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(CAMERA1)	
	{
			double dist = -100;
			double angle = Animation_data[i][5];
			double delta_x = dist * sin( angle * M_PI / 180);
			double delta_z = dist * cos( angle * M_PI / 180);
			gluLookAt(Animation_data[i][0]+delta_x,Animation_data[i][1],Animation_data[i][2]+delta_z,Animation_data[i][0],Animation_data[i][1],Animation_data[i][2],0,1,0);
	}
	if(CAMERA2){
		gluLookAt(0,0,100,Animation_data[i][0],Animation_data[i][1],Animation_data[i][2],0,1,0);
	}
	if(SKELETON==true){
		glfwSetTime(0);
		if(REST==true)
			bvh_fig->render_canonical_pose();
		else
			bvh_fig->render_frame(i);
		while(glfwGetTime() <= bvh_fig->get_motion()->get_frame_rate());
	}
	else{
		glfwSetTime(0);
		glScalef(2,2,2);
		if(REST==true)
			robot.makeRobot();
		else
			robot.makeRobot(Animation_data[i]);
		while(glfwGetTime() <= bvh_fig->get_motion()->get_frame_rate());
	}
	glPopMatrix();

}


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

	try{
		bvh_fig = new bvh::bvh_t(bvhfilename, true); 
		try{
			bvh_fig->print_hierarchy(std::cout); 
		}
		catch (util::common::error *e)
		{ util::common::error::halt_on_error(e); }

	  	//! Setting up the GLFW Error callback
		glfwSetErrorCallback(cs775::error_callback);

  	//! Initialize GLFW
       	if (!glfwInit())
       	return -1;

       	 initSetup();
    	
 	Animation_data=(float**)malloc(sizeof(bvh_fig->get_motion()->get_data()));
	Animation_data=bvh_fig->get_motion()->get_data();

	
	PLAY=false;
	SKELETON=true;
	CAMERA1=false;
	CAMERA2=false;
	REST=true;
	robot = Robot();
	if(bvhfilename=="dance.bvh")
      		glScalef(0.005,0.005,0.005);
	else
		glScalef(0.001,0.001,0.001);

        unsigned int i=0;
      	//debug("Total number of frames: %d\n",bvh_fig->get_motion()->get_frames());

       	while (glfwWindowShouldClose(glfwGetCurrentContext()) == 0){
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       		glEnable(GL_DEPTH_TEST);
       		renderGL(i);
		  // Swap front and back buffers
       		glfwSwapBuffers(glfwGetCurrentContext()); // Poll for and process events
       		glfwPollEvents();
       		if(PLAY && (i<bvh_fig->get_motion()->get_frames()-1)) i++;
       		else if(!PLAY && FORWARD && (i<bvh_fig->get_motion()->get_frames()-1)) {i++; FORWARD=false;}
       		else if(!PLAY && BACKWARD && i>0) {i--; BACKWARD=false; }

		}
	}
	catch (util::common::error *e)
	{ util::common::error::halt_on_error(e); }
	glfwDestroyWindow(glfwGetCurrentContext());
	glfwTerminate();
	return 0;
}


void initSetup(void){
	GLFWwindow* window;
	int win_width=512;
	int win_height=512;

  	//! Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(win_width, win_height, "Transformers", NULL, NULL);
	if (!window){
		glfwTerminate();
		exit(0);
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


}

//-----------------------------------------------------------------------
