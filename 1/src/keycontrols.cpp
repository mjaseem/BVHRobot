#include "keycontrols.hpp"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <unistd.h>

#include "keycontrols.hpp"

using namespace std;

//!GLFW keyboard callback
void KeyControls::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	
	//!Close the window if the ESC key was pressed
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
	  glfwSetWindowShouldClose(window, GL_TRUE);
	}

	/* Start animation */
	if(key == GLFW_KEY_C) {
		startTransform = 1;
	}

	

//--------------------------------------------------

/* Hip TX control*/
	if( key == GLFW_KEY_LEFT && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
		key_frame.hip_TX -= 0.05;
	} else if( key == GLFW_KEY_RIGHT && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
		key_frame.hip_TX += 0.05;
	}

/* Hip TZ control*/
	if( key == GLFW_KEY_UP && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
		if(!isCarMode && frame!=9)
			key_frame.hip_TZ -= 0.05;
	} else if( key == GLFW_KEY_DOWN && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
		if(!isCarMode && frame!=9)
			key_frame.hip_TZ += 0.05;
	}

/* Hip TY control*/
	if( key == GLFW_KEY_APOSTROPHE && mods == 0 && action == GLFW_PRESS) {
		if(!isCarMode && frame!=9)
			key_frame.hip_TY -= 0.05;
	} else if( key == GLFW_KEY_APOSTROPHE && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
		if(!isCarMode && frame!=9)
			key_frame.hip_TY += 0.05;
	}

/*Left Foot*/
	if( key == GLFW_KEY_N && mods == 0) {
			key_frame.leftFoot_X -= 5;
	} else if( key == GLFW_KEY_N && mods == GLFW_MOD_SHIFT ) {
			key_frame.leftFoot_X += 5;
	}

/*Right Foot*/
	if( key == GLFW_KEY_F11 && action == GLFW_PRESS) {
			key_frame.rightFoot_X -= 5;
	} else if( key == GLFW_KEY_F12 && action == GLFW_PRESS) {
			key_frame.rightFoot_X += 5;
	} 


//---------Arm Controls-----------------
/* Left lower arm control*/
	if( key == GLFW_KEY_X && mods == 0) {
		key_frame.leftLowerArm_X += 5;
	} else if( key == GLFW_KEY_X && mods == GLFW_MOD_SHIFT ) {
		key_frame.leftLowerArm_X -= 5;
	} 

/* right lower arm control*/
	if( key == GLFW_KEY_Z && mods == 0) {
		key_frame.rightLowerArm_X += 5;
	} else if( key == GLFW_KEY_Z && mods == GLFW_MOD_SHIFT ) {
		key_frame.rightLowerArm_X -= 5;
	} 

/* Left Upper arm X control*/
	if( key == GLFW_KEY_S && mods == 0) {
		key_frame.leftUpperArm_X += 5;
	} else if( key == GLFW_KEY_S && mods == GLFW_MOD_SHIFT ) {
		key_frame.leftUpperArm_X -= 5;
	} 

/* right Upper arm X control*/
	if( key == GLFW_KEY_A && mods == 0) {
		key_frame.rightUpperArm_X += 5;
	} else if( key == GLFW_KEY_A && mods == GLFW_MOD_SHIFT ) {
		key_frame.rightUpperArm_X -= 5;
	} 

/* Left Upper arm Y control*/
	if( key == GLFW_KEY_W && mods == 0) {
		key_frame.leftUpperArm_Y += 5;
	} else if( key == GLFW_KEY_W && mods == GLFW_MOD_SHIFT ) {
		key_frame.leftUpperArm_Y -= 5;
	} 

/* right Upper arm Y control*/
	if( key == GLFW_KEY_Q && mods == 0) {
		key_frame.rightUpperArm_Y += 5;
	} else if( key == GLFW_KEY_Q && mods == GLFW_MOD_SHIFT ) {
		key_frame.rightUpperArm_Y -= 5;
	} 

/* Left Upper arm Z control*/
	if( key == GLFW_KEY_D && mods == 0) {
		key_frame.leftUpperArm_Z += 5;
	} else if( key == GLFW_KEY_D && mods == GLFW_MOD_SHIFT ) {
		key_frame.leftUpperArm_Z -= 5;
	} 

/* right Upper arm Z control*/
	if( key == GLFW_KEY_E && mods == 0) {
		key_frame.rightUpperArm_Z += 5;
	} else if( key == GLFW_KEY_E && mods == GLFW_MOD_SHIFT ) {
		key_frame.rightUpperArm_Z -= 5;
	} 

//-------Leg cotrols-------------

/* Left lower Leg control*/
	if( key == GLFW_KEY_B && mods == 0) {
		key_frame.leftLowerLeg_X += 5;
	} else if( key == GLFW_KEY_B && mods == GLFW_MOD_SHIFT ) {
		key_frame.leftLowerLeg_X -= 5;
	} 

/* right lower Leg control*/
	if( key == GLFW_KEY_V && mods == 0) {
		key_frame.rightLowerLeg_X += 5;
	} else if( key == GLFW_KEY_V && mods == GLFW_MOD_SHIFT ) {
		key_frame.rightLowerLeg_X -= 5;
	} 

/* Left Upper Leg X control*/
	if( key == GLFW_KEY_G && mods == 0) {
		key_frame.leftUpperLeg_X += 5;
	} else if( key == GLFW_KEY_G && mods == GLFW_MOD_SHIFT ) {
		key_frame.leftUpperLeg_X -= 5;
	} 

/* right Upper Leg X control*/
	if( key == GLFW_KEY_F && mods == 0) {
		key_frame.rightUpperLeg_X += 5;
	} else if( key == GLFW_KEY_F && mods == GLFW_MOD_SHIFT ) {
		key_frame.rightUpperLeg_X -= 5;
	} 

/* Left Upper Leg Y control*/
	if( key == GLFW_KEY_T && mods == 0) {
		key_frame.leftUpperLeg_Y += 5;
	} else if( key == GLFW_KEY_T && mods == GLFW_MOD_SHIFT ) {
		key_frame.leftUpperLeg_Y -= 5;
	} 

/* right Upper Leg Y control*/
	if( key == GLFW_KEY_R && mods == 0) {
		key_frame.rightUpperLeg_Y += 5;
	} else if( key == GLFW_KEY_R && mods == GLFW_MOD_SHIFT ) {
		key_frame.rightUpperLeg_Y -= 5;
	} 

/* Left Upper Leg Z control*/
	if( key == GLFW_KEY_H && mods == 0) {
		key_frame.leftUpperLeg_Z += 5;
	} else if( key == GLFW_KEY_H && mods == GLFW_MOD_SHIFT ) {
		key_frame.leftUpperLeg_Z -= 5;
	} 

/* right Upper Leg Z control*/
	if( key == GLFW_KEY_Y && mods == 0) {
		key_frame.rightUpperLeg_Z += 5;
	} else if( key == GLFW_KEY_Y && mods == GLFW_MOD_SHIFT ) {
		key_frame.rightUpperLeg_Z -= 5;
	} 
//--------------------------------------------------

/* bust X control*/
	if( key == GLFW_KEY_U && mods == 0) {
		key_frame.bust_X += 5;
	} else if( key == GLFW_KEY_U && mods == GLFW_MOD_SHIFT ) {
		key_frame.bust_X -= 5;
	} 

/* bust Y control*/
	if( key == GLFW_KEY_J && mods == 0) {
		key_frame.bust_Y += 5;
	} else if( key == GLFW_KEY_J && mods == GLFW_MOD_SHIFT ) {
		key_frame.bust_Y -= 5;
	} 

/* bust Z control*/
	if( key == GLFW_KEY_M && mods == 0) {
		key_frame.bust_Z += 5;
	} else if( key == GLFW_KEY_M && mods == GLFW_MOD_SHIFT ) {
		key_frame.bust_Z -= 5;
	} 
//-------Head----------------------
/* head X control*/
	if( key == GLFW_KEY_I && mods == 0) {
		key_frame.head_X += 5;
	} else if( key == GLFW_KEY_I && mods == GLFW_MOD_SHIFT ) {
		key_frame.head_X -= 5;
	} 

/* head Y control*/
	if( key == GLFW_KEY_K && mods == 0) {
		key_frame.head_Y += 5;
	} else if( key == GLFW_KEY_K && mods == GLFW_MOD_SHIFT ) {
		key_frame.head_Y -= 5;
	} 
/* head Z control*/
	if( key == GLFW_KEY_COMMA && mods == 0) {
		key_frame.head_Z += 5;
	} else if( key == GLFW_KEY_COMMA && mods == GLFW_MOD_SHIFT ) {
		key_frame.head_Z -= 5;
	} 
//----------Transformation--------------------------
	if(key == GLFW_KEY_0)	{
		frame = 0;
	}
	if(key == GLFW_KEY_1 )	{
		frame = 1;
	}
	if(key == GLFW_KEY_2 )	{
		frame = 2;
	}
	if(key == GLFW_KEY_3)	{
		frame = 3;
	}
	if(key == GLFW_KEY_4)	{
		frame = 4;
	}
	if(key == GLFW_KEY_5)	{
		frame = 5;
	}
	if(key == GLFW_KEY_6)	{
		frame = 6;
	}
	if(key == GLFW_KEY_7)	{
		frame = 7;
	}
	if(key == GLFW_KEY_8)	{
		frame = 8;
	}
	if(key == GLFW_KEY_9 && action == GLFW_PRESS)	{
		frame = 9;
	}

	if(frame >= 1) {
		//Arms and Hands
		key_frame.leftUpperArm_X=key_frame.leftUpperArm_Y=key_frame.leftUpperArm_Z=10;
		key_frame.leftLowerArm_X = 0;
		key_frame.leftHand_X=0;

		key_frame.rightUpperArm_X=key_frame.rightUpperArm_Y=key_frame.rightUpperArm_Z=10;
		key_frame.rightLowerArm_X = 0;
		key_frame.rightHand_X=0;

		//Bust
		key_frame.bust_X=key_frame.bust_Y=key_frame.bust_Z=0;

		//Leg
		key_frame.leftUpperLeg_X=0;
		key_frame.leftUpperLeg_Y=0;
		key_frame.leftUpperLeg_Z=15;
		key_frame.leftLowerLeg_X =0;
		key_frame.leftFoot_X = 0;

		key_frame.rightUpperLeg_X=0;
		key_frame.rightUpperLeg_Y=0;
		key_frame.rightUpperLeg_Z=15;
		key_frame.rightLowerLeg_X = 0;
		key_frame.rightFoot_X = 0;
		//Head
		key_frame.head_X=key_frame.head_Y=key_frame.head_Z=00;
	}

	if(frame >= 3){
		key_frame.leftHand_X=180;
		key_frame.rightHand_X=180;
	}

	if(frame >= 4){
		key_frame.leftUpperLeg_Z=0;
		key_frame.rightUpperLeg_Z=0;
	}

	if(frame >= 6){
		key_frame.leftFoot_X=-180;
		key_frame.rightFoot_X=-180;
		key_frame.leftUpperArm_X=key_frame.leftUpperArm_Y=key_frame.leftUpperArm_Z=0;
		key_frame.rightUpperArm_X=key_frame.rightUpperArm_Y=key_frame.rightUpperArm_Z=0;
	}

	if(frame >= 8){
		key_frame.rightUpperArm_Y=key_frame.leftUpperArm_Y=180;
	}

	if(frame >= 9){
		key_frame.rightLowerLeg_X=key_frame.leftLowerLeg_X=-180;
	}

	// Debug keys to update angles
	if(key == GLFW_KEY_KP_7) {
		key_frame.hip_X = int(key_frame.hip_X + 5) % 360;
	}
	if(key == GLFW_KEY_KP_4) {
		key_frame.hip_X = int(key_frame.hip_X - 5) % 360;
	}
	if(key == GLFW_KEY_KP_8) {
		key_frame.hip_Y = int(key_frame.hip_Y + 5) % 360;
	}
	if(key == GLFW_KEY_KP_5) {
		key_frame.hip_Y = int(key_frame.hip_Y - 5) % 360;
	}
	if(key == GLFW_KEY_KP_9) {
		key_frame.hip_Z = int(key_frame.hip_Z + 5) % 360;
	}
	if(key == GLFW_KEY_KP_6) {
		key_frame.hip_Z = int(key_frame.hip_Z - 5) % 360;
	}
}

void KeyControls::movement(GLFWwindow* window) {
	int angle = 0;

	if( glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS  && frame==9) {
		key_frame.wheel_angle=0;
		angle = +3;
		
		double x = cos(key_frame.hip_Z * M_PI/180.0);
		double y = sin(key_frame.hip_Z * M_PI/180.0);
		double dist = 0.025;

		if((key_frame.hip_TX-(dist+0.425)* y)<=1.3 && (key_frame.hip_TX-(dist+0.425)*y)>=-1.3 && (key_frame.hip_TZ-(dist+0.425)*x)<=1.3 && (key_frame.hip_TZ-(dist+0.425)*x)>=-1.3){
			key_frame.hip_TX -=   dist * y;
			key_frame.hip_TZ -=   dist * x;
		}
		

		key_frame.wheel_rotate -= (dist * 180) / (0.075 * M_PI);
	}
	else if( glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS  && frame==9) {
		key_frame.wheel_angle=0;
		angle = -3;

		double x = cos(key_frame.hip_Z * M_PI/180.0);
		double y = sin(key_frame.hip_Z * M_PI/180.0);
		
		double dist = 0.025;
	
		if( (key_frame.hip_TX+(dist-0.425)* y)<=1.3 && (key_frame.hip_TX+(dist-0.425)* y)>=-1.3 && (key_frame.hip_TZ+(dist-0.425)* x)<=1.3 && (key_frame.hip_TZ+(dist-0.425)* x)>=-1.3){
			key_frame.hip_TX +=   dist * y;
			key_frame.hip_TZ +=   dist * x;
		}
	
		key_frame.wheel_rotate += (dist * 180) / (0.075 * M_PI);
	}

	if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && frame==9) {
	    key_frame.wheel_angle=20;
		
		if(angle) {

			double x = cos((key_frame.hip_Z+angle) * M_PI/180.0);
			double y = sin((key_frame.hip_Z+angle) * M_PI/180.0);

			double dist = -0.425;
			
			if( (key_frame.hip_TX+dist* y)<=1.3 && (key_frame.hip_TX+dist* y)>=-1.3 && (key_frame.hip_TZ+dist* x)<=1.3 && (key_frame.hip_TZ+dist* x)>=-1.3){
				key_frame.hip_Z += angle;
				if(key_frame.hip_Z > 360) key_frame.hip_Z -= 360;
			}
		}
			
	} else if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && frame==9) {
	    key_frame.wheel_angle=-20;
		if(angle) {
			double x = cos((key_frame.hip_Z-angle) * M_PI/180.0);
			double y = sin((key_frame.hip_Z-angle) * M_PI/180.0);

			double dist = -0.425;
			
			if( (key_frame.hip_TX+dist* y)<=1.3 && (key_frame.hip_TX+dist* y)>=-1.3 && (key_frame.hip_TZ+dist* x)<=1.3 && (key_frame.hip_TZ+dist* x)>=-1.3){
				key_frame.hip_Z -= angle;
				if(key_frame.hip_Z < 0) key_frame.hip_Z += 360;
			}
		}	

	}
}





