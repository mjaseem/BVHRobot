#ifndef _FRAME_HPP_
#define _FRAME_HPP_

#include <iostream>
#include <sstream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

class Frame {
public:
    double bust_X,bust_Y,bust_Z;

    double head_X,head_Y,head_Z;

    double leftUpperArm_X,leftUpperArm_Y,leftUpperArm_Z;
    double leftLowerArm_X;
    double rightUpperArm_X,rightUpperArm_Y,rightUpperArm_Z;
    double rightLowerArm_X;

    double leftHand_X;
    double rightHand_X;
    double leftUpperLeg_X,leftUpperLeg_Y,leftUpperLeg_Z;
    double leftLowerLeg_X;
    double rightUpperLeg_X,rightUpperLeg_Y,rightUpperLeg_Z;
    double rightLowerLeg_X;
    double leftFoot_X;
    double rightFoot_X;
    double hip_TX,hip_TY,hip_TZ,hip_X,hip_Y,hip_Z;
    int wheel_angle,wheel_rotate;

    bool valid;
    Frame() {
		//Arms
		leftUpperArm_X=leftUpperArm_Y=leftUpperArm_Z=10;
		leftLowerArm_X = 10;
		leftHand_X=10;

		rightUpperArm_X=rightUpperArm_Y=rightUpperArm_Z=10;
		rightLowerArm_X =10;
		rightHand_X=10;

		//Bust
		bust_X=bust_Y=bust_Z=0;

		//Leg
		leftUpperLeg_X=leftUpperLeg_Y=10;
		leftUpperLeg_Z=10;
		leftLowerLeg_X =0;
		leftFoot_X = 0;

		rightUpperLeg_X=rightUpperLeg_Y=10;
		rightUpperLeg_Z=0;
		rightLowerLeg_X =0;
		rightFoot_X = 0;

		//Head
		head_X=head_Y=head_Z=0;

		//Hip
		hip_TX=0;
		hip_TZ=-0.8	;
		hip_TY=-0.5;
		hip_X=hip_Y=hip_Z=0;

		wheel_angle=0;
		wheel_rotate=0;

		valid = true;
	}

	string getCurrentVector() {

		ostringstream str;

		str << bust_X << " " << bust_Y << " " << bust_Z << " ";
		str << head_X << " " << head_Y << " " << head_Z << " ";
		str << leftUpperArm_X << " " << leftUpperArm_Y << " " << leftUpperArm_Z << " ";
		str << leftLowerArm_X << " ";
		str << rightUpperArm_X << " " << rightUpperArm_Y << " " << rightUpperArm_Z << " ";
		str << rightLowerArm_X << " ";
		str << leftHand_X << " " <<rightHand_X << " ";
		str << leftUpperLeg_X << " " << leftUpperLeg_Y << " " << leftUpperLeg_Z << " ";
		str << leftLowerLeg_X << " ";
		str << rightUpperLeg_X << " " << rightUpperLeg_Y << " " << rightUpperLeg_Z << " ";
		str << rightLowerLeg_X << " ";
		str << leftFoot_X << " " << rightFoot_X << " ";
		str << hip_TX << " " << hip_TY << " " << hip_TZ << " ";
		str << hip_X << " " << hip_Y << " " << hip_Z << " ";

		string out = str.str();

		return out;
	}

	void updateFrameFromVector(float* vector) {
		
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
};


#endif
