#include "keycontrols.hpp"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>

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
		startAnim = 1;
	}

//---------Arm Controls-----------------
/* Left lower arm control*/
	if( key == GLFW_KEY_X && mods == 0) {
		leftLowerArm_X += 5;
	} else if( key == GLFW_KEY_X && mods == GLFW_MOD_SHIFT ) {
		leftLowerArm_X -= 5;
	} 

/* right lower arm control*/
	if( key == GLFW_KEY_Z && mods == 0) {
		rightLowerArm_X += 5;
	} else if( key == GLFW_KEY_Z && mods == GLFW_MOD_SHIFT ) {
		rightLowerArm_X -= 5;
	} 

/* Left Upper arm X control*/
	if( key == GLFW_KEY_S && mods == 0) {
		leftUpperArm_X += 5;
	} else if( key == GLFW_KEY_S && mods == GLFW_MOD_SHIFT ) {
		leftUpperArm_X -= 5;
	} 

/* right Upper arm X control*/
	if( key == GLFW_KEY_A && mods == 0) {
		rightUpperArm_X += 5;
	} else if( key == GLFW_KEY_A && mods == GLFW_MOD_SHIFT ) {
		rightUpperArm_X -= 5;
	} 

/* Left Upper arm Y control*/
	if( key == GLFW_KEY_W && mods == 0) {
		leftUpperArm_Y += 5;
	} else if( key == GLFW_KEY_W && mods == GLFW_MOD_SHIFT ) {
		leftUpperArm_Y -= 5;
	} 

/* right Upper arm Y control*/
	if( key == GLFW_KEY_Q && mods == 0) {
		rightUpperArm_Y += 5;
	} else if( key == GLFW_KEY_Q && mods == GLFW_MOD_SHIFT ) {
		rightUpperArm_Y -= 5;
	} 

/* Left Upper arm Z control*/
	if( key == GLFW_KEY_D && mods == 0) {
		leftUpperArm_Z += 5;
	} else if( key == GLFW_KEY_D && mods == GLFW_MOD_SHIFT ) {
		leftUpperArm_Z -= 5;
	} 

/* right Upper arm Z control*/
	if( key == GLFW_KEY_E && mods == 0) {
		rightUpperArm_Z += 5;
	} else if( key == GLFW_KEY_E && mods == GLFW_MOD_SHIFT ) {
		rightUpperArm_Z -= 5;
	} 

//-------Leg cotrols-------------

/* Left lower Leg control*/
	if( key == GLFW_KEY_B && mods == 0) {
		leftLowerLeg_X += 5;
	} else if( key == GLFW_KEY_B && mods == GLFW_MOD_SHIFT ) {
		leftLowerLeg_X -= 5;
	} 

/* right lower Leg control*/
	if( key == GLFW_KEY_V && mods == 0) {
		rightLowerLeg_X += 5;
	} else if( key == GLFW_KEY_V && mods == GLFW_MOD_SHIFT ) {
		rightLowerLeg_X -= 5;
	} 

/* Left Upper Leg X control*/
	if( key == GLFW_KEY_G && mods == 0) {
		leftUpperLeg_X += 5;
	} else if( key == GLFW_KEY_G && mods == GLFW_MOD_SHIFT ) {
		leftUpperLeg_X -= 5;
	} 

/* right Upper Leg X control*/
	if( key == GLFW_KEY_F && mods == 0) {
		rightUpperLeg_X += 5;
	} else if( key == GLFW_KEY_F && mods == GLFW_MOD_SHIFT ) {
		rightUpperLeg_X -= 5;
	} 

/* Left Upper Leg Y control*/
	if( key == GLFW_KEY_T && mods == 0) {
		leftUpperLeg_Y += 5;
	} else if( key == GLFW_KEY_T && mods == GLFW_MOD_SHIFT ) {
		leftUpperLeg_Y -= 5;
	} 

/* right Upper Leg Y control*/
	if( key == GLFW_KEY_R && mods == 0) {
		rightUpperLeg_Y += 5;
	} else if( key == GLFW_KEY_R && mods == GLFW_MOD_SHIFT ) {
		rightUpperLeg_Y -= 5;
	} 

/* Left Upper Leg Z control*/
	if( key == GLFW_KEY_H && mods == 0) {
		leftUpperLeg_Z += 5;
	} else if( key == GLFW_KEY_H && mods == GLFW_MOD_SHIFT ) {
		leftUpperLeg_Z -= 5;
	} 

/* right Upper Leg Z control*/
	if( key == GLFW_KEY_Y && mods == 0) {
		rightUpperLeg_Z += 5;
	} else if( key == GLFW_KEY_Y && mods == GLFW_MOD_SHIFT ) {
		rightUpperLeg_Z -= 5;
	} 
//--------------------------------------------------

/* bust X control*/
	if( key == GLFW_KEY_U && mods == 0) {
		bust_X += 5;
	} else if( key == GLFW_KEY_U && mods == GLFW_MOD_SHIFT ) {
		bust_X -= 5;
	} 

/* bust Y control*/
	if( key == GLFW_KEY_J && mods == 0) {
		bust_Y += 5;
	} else if( key == GLFW_KEY_J && mods == GLFW_MOD_SHIFT ) {
		bust_Y -= 5;
	} 

/* bust Z control*/
	if( key == GLFW_KEY_M && mods == 0) {
		bust_Z += 5;
	} else if( key == GLFW_KEY_M && mods == GLFW_MOD_SHIFT ) {
		bust_Z -= 5;
	} 
//-------Head----------------------
/* head X control*/
	if( key == GLFW_KEY_I && mods == 0) {
		head_X += 5;
	} else if( key == GLFW_KEY_I && mods == GLFW_MOD_SHIFT ) {
		head_X -= 5;
	} 

/* head Y control*/
	if( key == GLFW_KEY_K && mods == 0) {
		head_Y += 5;
	} else if( key == GLFW_KEY_K && mods == GLFW_MOD_SHIFT ) {
		head_Y -= 5;
	} 
/* head Z control*/
	if( key == GLFW_KEY_COMMA && mods == 0) {
		head_Z += 5;
	} else if( key == GLFW_KEY_COMMA && mods == GLFW_MOD_SHIFT ) {
		head_Z -= 5;
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
		leftUpperArm_X=leftUpperArm_Y=leftUpperArm_Z=10;
		leftLowerArm_X = 0;
		leftHand_X=0;

		rightUpperArm_X=rightUpperArm_Y=rightUpperArm_Z=10;
		rightLowerArm_X = 0;
		rightHand_X=0;

		//Bust
		bust_X=bust_Y=bust_Z=0;

		//Leg
		leftUpperLeg_X=0;
		leftUpperLeg_Y=0;
		leftUpperLeg_Z=15;
		leftLowerLeg_X =0;
		leftFoot_X = 0;

		rightUpperLeg_X=0;
		rightUpperLeg_Y=0;
		rightUpperLeg_Z=15;
		rightLowerLeg_X = 0;
		rightFoot_X = 0;
		//Head
		head_X=head_Y=head_Z=00;
		//Hip
		//hip_TX=hip_TY=hip_TZ=0;
		// hip_Y=0;
	}

	if(frame >= 3){
		leftHand_X=180;
		rightHand_X=180;
	}

	if(frame >= 4){
		leftUpperLeg_Z=0;
		rightUpperLeg_Z=0;
	}

	if(frame >= 6){
		leftFoot_X=-180;
		rightFoot_X=-180;
		leftUpperArm_X=leftUpperArm_Y=leftUpperArm_Z=0;
		rightUpperArm_X=rightUpperArm_Y=rightUpperArm_Z=0;
	}

	if(frame >= 8){
		rightUpperArm_Y=leftUpperArm_Y=180;
	}

	if(frame >= 9){
		rightLowerLeg_X=leftLowerLeg_X=-180;
	}

	/*if( key == GLFW_KEY_LEFT  && frame==9) {
		if(wheel_angle!=20)
		    wheel_angle=20;
			hip_Z += 5;
			if(hip_Z > 360) hip_Z -= 360;

	}
	else if( key == GLFW_KEY_RIGHT && frame==9 ) {
		if(wheel_angle!=-20)
		    wheel_angle=-20;

			hip_Z -= 5;
			if(hip_Z < 0) hip_Z += 360;
	}*/

	// movement(window);

	// Debug keys to update angles
	if(key == GLFW_KEY_KP_7) {
		hip_X = int(hip_X + 5) % 360;
	}
	if(key == GLFW_KEY_KP_4) {
		hip_X = int(hip_X - 5) % 360;
	}
	if(key == GLFW_KEY_KP_8) {
		hip_Y = int(hip_Y + 5) % 360;
	}
	if(key == GLFW_KEY_KP_5) {
		hip_Y = int(hip_Y - 5) % 360;
	}
	if(key == GLFW_KEY_KP_9) {
		hip_Z = int(hip_Z + 5) % 360;
	}
	if(key == GLFW_KEY_KP_6) {
		hip_Z = int(hip_Z - 5) % 360;
	}
}

void KeyControls::updateVector(float* vector){
  		hip_TX = vector[0];
 		hip_TY = vector[1];
		hip_TZ = vector[2];
		hip_X = vector[4];
		hip_Y = vector[5];
		hip_Z = vector[3];
		leftUpperLeg_X = vector[7];
		leftUpperLeg_Y = vector[8];
		leftUpperLeg_Z = vector[6];
		leftLowerLeg_X = vector[10];
		leftFoot_X = vector[13];
		rightUpperLeg_X = vector[16]; 
 		rightUpperLeg_Y = vector[17];
		rightUpperLeg_Z = vector[15];
		rightLowerLeg_X = vector[19];
		rightFoot_X = vector[22];
		bust_X = vector[25];
		bust_Y = vector[26];
		bust_Z = vector[24];
		leftUpperArm_X = vector[34]; 
 		leftUpperArm_Y = vector[35];
		leftUpperArm_Z = vector[33];
		leftLowerArm_X = vector[37];
		leftHand_X = vector[40];
		rightUpperArm_X = vector[46];  
		rightUpperArm_Y = vector[47];
		rightUpperArm_Z = vector[45];
		rightLowerArm_X = vector[49];
		rightHand_X = vector[52];
		head_X = vector[58];
 		head_Y = vector[59];
		head_Z = vector[57];
}

void KeyControls::movement(GLFWwindow* window) {
	int angle = 0;

	if( glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS  && frame==9) {
		wheel_angle=0;
		angle = +3;
		
		double x = cos(hip_Z * M_PI/180.0);
		double y = sin(hip_Z * M_PI/180.0);
		double dist = 0.025;

		if((hip_TX-(dist+0.425)* y)<=1.3 && (hip_TX-(dist+0.425)*y)>=-1.3 && (hip_TZ-(dist+0.425)*x)<=1.3 && (hip_TZ-(dist+0.425)*x)>=-1.3){
			hip_TX -=   dist * y;
			hip_TZ -=   dist * x;
		}
		

		wheel_rotate -= (dist * 180) / (0.075 * M_PI);
	}
	else if( glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS  && frame==9) {
		wheel_angle=0;
		angle = -3;

		double x = cos(hip_Z * M_PI/180.0);
		double y = sin(hip_Z * M_PI/180.0);
		
		double dist = 0.025;
	
		if( (hip_TX+(dist-0.425)* y)<=1.3 && (hip_TX+(dist-0.425)* y)>=-1.3 && (hip_TZ+(dist-0.425)* x)<=1.3 && (hip_TZ+(dist-0.425)* x)>=-1.3){
			hip_TX +=   dist * y;
			hip_TZ +=   dist * x;
		}
	
		wheel_rotate += (dist * 180) / (0.075 * M_PI);
	}

	if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && frame==9) {
	    wheel_angle=20;
		
		if(angle) {

			double x = cos((hip_Z+angle) * M_PI/180.0);
			double y = sin((hip_Z+angle) * M_PI/180.0);

			double dist = -0.425;
			
			if( (hip_TX+dist* y)<=1.3 && (hip_TX+dist* y)>=-1.3 && (hip_TZ+dist* x)<=1.3 && (hip_TZ+dist* x)>=-1.3){
				hip_Z += angle;
				if(hip_Z > 360) hip_Z -= 360;
			}
		}
			
	} else if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && frame==9) {
	    wheel_angle=-20;
		if(angle) {
			double x = cos((hip_Z-angle) * M_PI/180.0);
			double y = sin((hip_Z-angle) * M_PI/180.0);

			double dist = -0.425;
			
			if( (hip_TX+dist* y)<=1.3 && (hip_TX+dist* y)>=-1.3 && (hip_TZ+dist* x)<=1.3 && (hip_TZ+dist* x)>=-1.3){
				hip_Z -= angle;
				if(hip_Z < 0) hip_Z += 360;
			}
		}	

	}
}
