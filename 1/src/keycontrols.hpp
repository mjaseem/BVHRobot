#ifndef _KEYCONTROLS_HPP_
#define _KEYCONTROLS_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "frame.hpp"

class KeyControls {
public:

    int frame;
    int isCarMode;
    int startTransform;
    double prev_angle;
    int stage;
    Frame key_frame;

	KeyControls() {
		// Default values
		key_frame=Frame();

		frame=0;

		//Animation
		stage=0;
		isCarMode=0;
		prev_angle=0;
		startTransform=0;
		
	}

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void movement(GLFWwindow* window);
};

#endif
