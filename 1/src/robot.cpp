#include <cmath>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <GL/glew.h>

#include "robot.hpp"
#include "blocks.hpp"

using namespace Blocks;

void Robot::initStructuralConstraints()
{
   
    Hip_LeftUpperLeg_Joint=point(3.75,-3.75,0);
    LeftUpperLeg_LeftLowerLeg_Joint=point(0,-5,3.75);
    
    Hip_RightUpperLeg_Joint=point(-3.75,-3.75,0);
    RightUpperLeg_RightLowerLeg_Joint=point(0,-5,3.75);
    
    Bust_Hip_Joint=point(0,3.75,0);
    

    RightShoulder_Bust_Joint=point(-7.5,12.5,0);
    LeftShoulder_Bust_Joint=point(7.5,12.5,0);
    NeckBustJoint=point(0,12.5,0);
    HeadNeckJoint=point(0,0.75,0);
    
    
    LeftShoulder_LeftUpperArmFront_Joint=point(1.25,3.75,3.75);
    LeftUpperArmFront_LeftLowerArmFront_Joint=point(0,-6.25,-6.25);
    RightShoulder_RightUpperArmFront_Joint=point(-1.25,3.75,3.75);
    RightUpperArmFront_RightLowerArmFront_Joint=point(0,-6.25,-6.25);
    
    
    LeftUpperArmFront_LeftUpperArmBehind_Joint=point(1.825,0,-1.25);
    LeftLowerArmFront_LeftLowerArmBehind_Joint=point(1.825,0,-1.25);
    RightUpperArmFront_RightUpperArmBehind_Joint=point(-1.825,0,-1.25);
    RightLowerArmFront_RightLowerArmBehind_Joint=point(-1.825,0,-1.25);
    
   
    LeftLowerArmFront_LeftFrontHand_Joint=point(0,-6.25,-1.25);
    RightLowerArmFront_RightFrontHand_Joint=point(0,-6.25,-1.25);
    LeftLowerLeg_LeftFoot_Joint=point(0,-7.5,3.75);
    RightLowerLeg_RightFoot_Joint=point(0,-7.5,3.75);
    LeftFrontHand_LeftBehindHand_Joint=point(1.825,0,-2.5);
    RightFrontHand_RightBehindHand_Joint=point(-1.825,0,-2.5);

    Bust_Lower_Point=point(0,-12.5,0);
    
   
    Neck_Lower_Point=point(0,-0.75,0);
    Head_Lower_Point=point(0,-3,0);
    Left_Shoulder_Lower_Point=point(-1.25,-3.75,0);
    Right_Shoulder_Lower_Point=point(1.25,-3.75,0);
    
    LeftUpperArmFront_Upper_Point=point(-1.825,6.25,1.25);
    LeftLowerArmFront_Upper_Point=point(0,6.25,-5.25);
    RightUpperArmFront_Upper_Point=point(1.825,6.25,1.25);
    RightLowerArmFront_Upper_Point=point(0,6.25,-5.25);
    
  
    LeftUpperArmBehind_Right_Point=point(1.825,0,1.25);
    LeftLowerArmBehind_Right_Point=point(1.825,0,1.25);
    RightUpperArmBehind_Left_Point=point (-1.825,0,1.25);
    RightLowerArmBehind_Left_Point=point(-1.825,0,1.25);

    LeftFrontHand_Upper_Point=point(0,3.75,-2.5);
    RightFrontHand_Upper_Point=point(0,3.75,-2.5);
    LeftBehindHand_Upper_Point=point(1.825,0,2.5);
    RightBehindHand_Upper_Point=point(-1.825,0,2.5);

    LeftUpperLeg_Upper_Point=point(0,5,0);
    LeftLowerLeg_Upper_Point=point(0,7.5,3.75);
    RightUpperLeg_Upper_Point=point(0,5,0);
    RightLowerLeg_Upper_Point=point(0,7.5,3.75);
    LeftFoot_Behind_Point=point(0,-1.25,-3.75);
    RightFoot_Behind_Point=point(0,-1.25,-3.75);
}




void Robot::initHip()
{
    Hip=glGenLists(1); 
    glNewList(Hip,GL_COMPILE);
    defineTrapizoid(10,7.5,7.5,7.5);
    glEndList();
}

void Robot::initBust()
{
    Bust=glGenLists(1);

    glNewList(Bust,GL_COMPILE);
    defineCuboid(15,25,7.5);
    glEndList();

}

void Robot::initNeck()
{
    Neck=glGenLists(1);
    glNewList(Neck,GL_COMPILE);
	glPushMatrix();
	   glRotatef(90,1,0,0);
	   defineCylinder(3.75,1.5,20,1);
	glPopMatrix();
    glEndList();
}
  
void Robot::initHead()
{
    Head=glGenLists(1);
    glNewList(Head,GL_COMPILE);
    defineTrapizoid(10,7.5+0.5,7.5,6.0);
    glEndList();
}

void Robot::initLeftShoulder()
{
   LeftShoulder=glGenLists(1);
    glNewList(LeftShoulder,GL_COMPILE);
	defineCuboid(2.5,7.5,7.5);
	glBegin(GL_TRIANGLES);
	    glVertex3f(-1.25,3.75,3.75);
	    glVertex3f(-2.5,-3.75,3.75);
	    glVertex3f(-1.25,-3.75,3.75);

	    glVertex3f(-1.25,3.75,-3.75);
	    glVertex3f(-2.5,-3.75,-3.75);
	    glVertex3f(-1.25,-3.75,-3.75);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(-1.25,3.75,3.75);
	    glVertex3f(-1.25,3.75,-3.75);
	    glVertex3f(-2.5,-3.75,3.75);
	     glVertex3f(-2.5,-3.75,-3.75);
	glEnd();
    glEndList();
}
void Robot::initRightShoulder()
{
    RightShoulder=glGenLists(1);
    glNewList(RightShoulder,GL_COMPILE);
	defineCuboid(2.5,7.5,7.5);
	glBegin(GL_TRIANGLES);
	    glVertex3f(1.25,3.75,3.75);
	    glVertex3f(2.5,-3.75,3.75);
	    glVertex3f(1.25,-3.75,3.75);

	    glVertex3f(1.25,3.75,-3.75);
	    glVertex3f(2.5,-3.75,-3.75);
	    glVertex3f(1.25,-3.75,-3.75);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(1.25,3.75,3.75);
	    glVertex3f(1.25,3.75,-3.75);
	    glVertex3f(2.5,-3.75,3.75);
	     glVertex3f(2.5,-3.75,-3.75);
	glEnd();
    glEndList();
}
void Robot::initLeftUpperArmFront()
{
    LeftUpperArmFront=glGenLists(1);
    glNewList(LeftUpperArmFront,GL_COMPILE);
    defineCuboid(3.75,12.5,2.5);
    glEndList();
}

void Robot::initLeftLowerArmFront()
{
    LeftLowerArmFront=glGenLists(1);
    glNewList(LeftLowerArmFront,GL_COMPILE);	
    defineCuboid(3.75,12.5,2.5);
    glEndList();
}

void Robot::initRightUpperArmFront()
{
    RightUpperArmFront=glGenLists(1);
    glNewList(RightUpperArmFront,GL_COMPILE);
    defineCuboid(3.75,12.5,2.5);
    glEndList();
}

void Robot::initRightLowerArmFront()
{
    RightLowerArmFront=glGenLists(1);
    glNewList(RightLowerArmFront,GL_COMPILE);
    defineCuboid(3.75,12.5,2.5);
    glEndList();
}
  
void Robot::initLeftUpperArmBehind()
{
    LeftUpperArmBehind=glGenLists(1);
    glNewList(LeftUpperArmBehind,GL_COMPILE);
    defineCuboid(2.75,12.5,2.5);
    glEndList();
}

void Robot::initLeftLowerArmBehind()
{
    LeftLowerArmBehind=glGenLists(1);
    glNewList(LeftLowerArmBehind,GL_COMPILE);
    defineCuboid(2.75,12.5,2.5);
    glEndList();
}

void Robot::initRightUpperArmBehind()
{
  
    RightUpperArmBehind=glGenLists(1);
    glNewList(RightUpperArmBehind,GL_COMPILE);
    defineCuboid(3.75,12.5,2.5);
    glEndList();
}

void Robot::initRightLowerArmBehind()
{
    RightLowerArmBehind=glGenLists(1);
    glNewList(RightLowerArmBehind,GL_COMPILE);
    defineCuboid(3.75,12.5,2.5);
    glEndList();
}

void Robot::initLeftFrontHand()
{
    LeftFrontHand=glGenLists(1);
    glNewList(LeftFrontHand,GL_COMPILE);
    defineCuboid(3.75,7.5,5);
    glEndList();
}
  
void Robot::initRightFrontHand()
{
  
    RightFrontHand=glGenLists(1);
    glNewList(RightFrontHand,GL_COMPILE);
    defineCuboid(3.75,7.5,5);
    glEndList();
}

void Robot::initLeftBehindHand()
{
  
    LeftBehindHand=glGenLists(1);
    glNewList(LeftBehindHand,GL_COMPILE);
    defineCuboid(3.75,7.5,5);
    glEndList();
}
  
void Robot::initRightBehindHand()
{
    RightBehindHand=glGenLists(1);
    glNewList(RightBehindHand,GL_COMPILE);
    defineCuboid(3.75,7.5,5);
    glEndList();
}

void Robot::initLeftUpperLeg()
{
    LeftUpperLeg=glGenLists(1);
    glNewList(LeftUpperLeg,GL_COMPILE);
    defineCuboid(7.5,10,7.5);
    glEndList();
}

void Robot::initLeftLowerLeg()
{
    LeftLowerLeg=glGenLists(1);
    glNewList(LeftLowerLeg,GL_COMPILE);
    defineCuboid(7.5,15,7.5);
    glEndList();
}
  
void Robot::initRightUpperLeg()
{

    RightUpperLeg=glGenLists(1);
    glNewList(RightUpperLeg,GL_COMPILE);
    defineCuboid(7.5,10,7.5);
    glEndList();
}
  
void Robot::initRightLowerLeg()
{
    RightLowerLeg=glGenLists(1);
    glNewList(RightLowerLeg,GL_COMPILE);
    defineCuboid(7.5,15,7.5);
    glEndList();
}
  
void Robot::initLeftFoot()
{
    LeftFoot=glGenLists(1);
    glNewList(LeftFoot,GL_COMPILE);
    defineCuboid(7.5,2.5,7.5);
    glEndList();
}
  
void Robot::initRightFoot()
{
    RightFoot=glGenLists(1);
    glNewList(RightFoot,GL_COMPILE);
    defineCuboid(7.5,2.5,7.5);
    glEndList();
}

void Robot::makeHip(double tx,double ty,double tz,double angle_x,double angle_y,double angle_z)
{
    glTranslatef(tx,ty,tz);	
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glCallList(Hip);
}
  
void Robot::makeBust(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(Bust_Hip_Joint.x,Bust_Hip_Joint.y,Bust_Hip_Joint.z);
   
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-Bust_Lower_Point.x,-Bust_Lower_Point.y,-Bust_Lower_Point.z);	

    glCallList(Bust);
}

  
void Robot::makeNeck(void)
{
    //Tranformations
    glTranslatef(NeckBustJoint.x,NeckBustJoint.y,NeckBustJoint.z);
    glTranslatef(-Neck_Lower_Point.x,-Neck_Lower_Point.y,-Neck_Lower_Point.z);
    glCallList(Neck);
}
  
void Robot::makeHead(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(HeadNeckJoint.x,HeadNeckJoint.y,HeadNeckJoint.z);
    
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-Head_Lower_Point.x,-Head_Lower_Point.y,-Head_Lower_Point.z);
    glCallList(Head);
}

void Robot::makeLeftShoulder()
{
    //Tranformations
    glTranslatef(LeftShoulder_Bust_Joint.x,LeftShoulder_Bust_Joint.y,LeftShoulder_Bust_Joint.z);
    glTranslatef(-Left_Shoulder_Lower_Point.x,-Left_Shoulder_Lower_Point.y,-Left_Shoulder_Lower_Point.z);
    glCallList(LeftShoulder);
}
void Robot::makeRightShoulder()
{
   //Tranformations
    glTranslatef(RightShoulder_Bust_Joint.x,RightShoulder_Bust_Joint.y,RightShoulder_Bust_Joint.z);
    glTranslatef(-Right_Shoulder_Lower_Point.x,-Right_Shoulder_Lower_Point.y,-Right_Shoulder_Lower_Point.z);	
    glCallList(RightShoulder);
}
  
void Robot::makeLeftUpperArmFront(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(LeftShoulder_LeftUpperArmFront_Joint.x,LeftShoulder_LeftUpperArmFront_Joint.y,LeftShoulder_LeftUpperArmFront_Joint.z);

    glRotatef(angle_z,0,0,1);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-LeftUpperArmFront_Upper_Point.x,-LeftUpperArmFront_Upper_Point.y,-LeftUpperArmFront_Upper_Point.z);	
    
    glCallList(LeftUpperArmFront);
}  
void Robot::makeLeftLowerArmFront(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftLowerArmFront_Joint.x,LeftUpperArmFront_LeftLowerArmFront_Joint.y,LeftUpperArmFront_LeftLowerArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-LeftLowerArmFront_Upper_Point.x,-LeftLowerArmFront_Upper_Point.y,-LeftLowerArmFront_Upper_Point.z);	
    
    glCallList(LeftLowerArmFront);
}
  
void Robot::makeRightUpperArmFront(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(RightShoulder_RightUpperArmFront_Joint.x,RightShoulder_RightUpperArmFront_Joint.y,RightShoulder_RightUpperArmFront_Joint.z);
   
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightUpperArmFront_Upper_Point.x,-RightUpperArmFront_Upper_Point.y,-RightUpperArmFront_Upper_Point.z);	
    glCallList(RightUpperArmFront);

}
  
void Robot::makeRightLowerArmFront(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftLowerArmFront_Joint.x,LeftUpperArmFront_LeftLowerArmFront_Joint.y,LeftUpperArmFront_LeftLowerArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-RightLowerArmFront_Upper_Point.x,-RightLowerArmFront_Upper_Point.y,-RightLowerArmFront_Upper_Point.z);	
    glCallList(RightLowerArmFront);
}


void Robot::makeLeftUpperArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftUpperArmBehind_Joint.x,LeftUpperArmFront_LeftUpperArmBehind_Joint.y,LeftUpperArmFront_LeftUpperArmBehind_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-LeftUpperArmBehind_Right_Point.x,-LeftUpperArmBehind_Right_Point.y,-LeftUpperArmBehind_Right_Point.z);	
    glCallList(LeftUpperArmBehind);
}

void Robot::makeLeftLowerArmBehind(double angle_y)
{
    //Tranformations
    glTranslatef(LeftLowerArmFront_LeftLowerArmBehind_Joint.x,LeftLowerArmFront_LeftLowerArmBehind_Joint.y,LeftLowerArmFront_LeftLowerArmBehind_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-LeftLowerArmBehind_Right_Point.x,-LeftLowerArmBehind_Right_Point.y,-LeftLowerArmBehind_Right_Point.z);	
    glCallList(LeftLowerArmBehind);
}

void Robot::makeRightUpperArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(RightUpperArmFront_RightUpperArmBehind_Joint.x,RightUpperArmFront_RightUpperArmBehind_Joint.y,RightUpperArmFront_RightUpperArmBehind_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightUpperArmBehind_Left_Point.x,-RightUpperArmBehind_Left_Point.y,-RightUpperArmBehind_Left_Point.z);	
    glCallList(RightUpperArmBehind);
}

void Robot::makeRightLowerArmBehind(double angle_y)
{
    //Tranformations
    glTranslatef(RightLowerArmFront_RightLowerArmBehind_Joint.x,RightLowerArmFront_RightLowerArmBehind_Joint.y,RightLowerArmFront_RightLowerArmBehind_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightLowerArmBehind_Left_Point.x,-RightLowerArmBehind_Left_Point.y,-RightLowerArmBehind_Left_Point.z);	
    glCallList(RightLowerArmBehind);
}
  
void Robot::makeLeftFrontHand(double angle_x)
{
    //Tranformations
    glTranslatef(LeftLowerArmFront_LeftFrontHand_Joint.x,LeftLowerArmFront_LeftFrontHand_Joint.y,LeftLowerArmFront_LeftFrontHand_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-LeftFrontHand_Upper_Point.x,-LeftFrontHand_Upper_Point.y,-LeftFrontHand_Upper_Point.z);	
    glCallList(LeftFrontHand);
}
  
void Robot::makeRightFrontHand(double angle_x)
{
    //Tranformations
     glTranslatef(RightLowerArmFront_RightFrontHand_Joint.x,RightLowerArmFront_RightFrontHand_Joint.y,RightLowerArmFront_RightFrontHand_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-RightFrontHand_Upper_Point.x,-RightFrontHand_Upper_Point.y,-RightFrontHand_Upper_Point.z);	
    glCallList(RightFrontHand);
}

void Robot::makeLeftBehindHand(double angle_y)
{
    //Tranformations
    glTranslatef(LeftFrontHand_LeftBehindHand_Joint.x,LeftFrontHand_LeftBehindHand_Joint.y,LeftFrontHand_LeftBehindHand_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-LeftBehindHand_Upper_Point.x,-LeftBehindHand_Upper_Point.y,-LeftBehindHand_Upper_Point.z);	
    glCallList(LeftBehindHand);
}
  
void Robot::makeRightBehindHand(double angle_y)
{
    //Tranformations
     glTranslatef(RightFrontHand_RightBehindHand_Joint.x,RightFrontHand_RightBehindHand_Joint.y,RightFrontHand_RightBehindHand_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightBehindHand_Upper_Point.x,-RightBehindHand_Upper_Point.y,-RightBehindHand_Upper_Point.z);	
  
    glCallList(RightBehindHand);
}
  
void Robot::makeLeftUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_LeftUpperLeg_Joint.x,Hip_LeftUpperLeg_Joint.y,Hip_LeftUpperLeg_Joint.z);

    glRotatef(angle_z,0,0,1);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-LeftUpperLeg_Upper_Point.x,-LeftUpperLeg_Upper_Point.y, -LeftUpperLeg_Upper_Point.z);	
    glCallList(LeftUpperLeg);
}
  
void Robot::makeLeftLowerLeg(double angle_x)
{
    glTranslatef(LeftUpperLeg_LeftLowerLeg_Joint.x,LeftUpperLeg_LeftLowerLeg_Joint.y,LeftUpperLeg_LeftLowerLeg_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-LeftLowerLeg_Upper_Point.x,-LeftLowerLeg_Upper_Point.y,-LeftLowerLeg_Upper_Point.z);
    
    glCallList(LeftLowerLeg);
}
  
void Robot::makeRightUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_RightUpperLeg_Joint.x,Hip_RightUpperLeg_Joint.y,Hip_RightUpperLeg_Joint.z);
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightUpperLeg_Upper_Point.x,-RightUpperLeg_Upper_Point.y,-RightUpperLeg_Upper_Point.z);    
    glCallList(RightUpperLeg);

}
  
void Robot::makeRightLowerLeg(double angle_x)
{
   glTranslatef(RightUpperLeg_RightLowerLeg_Joint.x,RightUpperLeg_RightLowerLeg_Joint.y,RightUpperLeg_RightLowerLeg_Joint.z);
   glRotatef(angle_x,1,0,0);
   glTranslatef(-RightLowerLeg_Upper_Point.x,-RightLowerLeg_Upper_Point.y,-RightLowerLeg_Upper_Point.z);
   glCallList(RightLowerLeg);
}
  
void Robot::makeLeftFoot(double angle_x)
{
  //Tranformations
   glTranslatef(LeftLowerLeg_LeftFoot_Joint.x,LeftLowerLeg_LeftFoot_Joint.y,LeftLowerLeg_LeftFoot_Joint.z);
   glRotatef(angle_x,1,0,0);
   glTranslatef(-LeftFoot_Behind_Point.x,-LeftFoot_Behind_Point.y,-LeftFoot_Behind_Point.z);
   glCallList(LeftFoot);
}
  
void Robot::makeRightFoot(double angle_x)
{
  //Tranformations
    glTranslatef(RightLowerLeg_RightFoot_Joint.x,RightLowerLeg_RightFoot_Joint.y,RightLowerLeg_RightFoot_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-RightFoot_Behind_Point.x,-RightFoot_Behind_Point.y,-RightFoot_Behind_Point.z);
    glCallList(RightFoot);
}



void Robot::setRobotProperties(){
    GLfloat scene_specular[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat scene_diffuse[4]={1.0, 0.7, 0.7, 1.0};
    glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);
    glMaterialfv(GL_FRONT, GL_SPECULAR, scene_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, scene_diffuse);
}



void Robot::makeRobot(void)
{   
    keys.movement(glfwGetCurrentContext());
    

    glPushMatrix();
    makeHip(keys.hip_TX,keys.hip_TY,keys.hip_TZ,keys.hip_X,keys.hip_Y,keys.hip_Z);

    glPushMatrix();
        makeLeftUpperLeg(keys.leftUpperLeg_X,keys.leftUpperLeg_Y,keys.leftUpperLeg_Z);
        makeLeftLowerLeg(keys.leftLowerLeg_X);
        makeLeftFoot(keys.leftFoot_X);
    glPopMatrix();

    glPushMatrix();
        makeRightUpperLeg(keys.rightUpperLeg_X,keys.rightUpperLeg_Y,keys.rightUpperLeg_Z);
        makeRightLowerLeg(keys.rightLowerLeg_X);
        makeRightFoot(keys.rightFoot_X);
    glPopMatrix();

    glPushMatrix();
        makeBust(keys.bust_X,keys.bust_Y,keys.bust_Z);

        glPushMatrix();
	        makeLeftShoulder();
            makeLeftUpperArmFront(keys.leftUpperArm_X,keys.leftUpperArm_Y,keys.leftUpperArm_Z);
    		glPushMatrix();
    		    makeLeftUpperArmBehind(behindArmAngle);
    		glPopMatrix();
                makeLeftLowerArmFront(keys.leftLowerArm_X);
    		glPushMatrix();
    		    makeLeftLowerArmBehind(behindArmAngle);
    		glPopMatrix();
                makeLeftFrontHand(keys.leftHand_X);
    		glPushMatrix();
    		    makeLeftBehindHand(behindArmAngle);
    		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
	        makeRightShoulder();
            makeRightUpperArmFront(keys.rightUpperArm_X,keys.rightUpperArm_Y,keys.rightUpperArm_Z);
    		glPushMatrix();
    		    makeRightUpperArmBehind(behindArmAngle);
    		glPopMatrix();
                makeRightLowerArmFront(keys.rightLowerArm_X);
    		glPushMatrix();
    		    makeRightLowerArmBehind(behindArmAngle);
    		glPopMatrix();
                makeRightFrontHand(keys.rightHand_X);
    		glPushMatrix();
    		    makeRightBehindHand(behindArmAngle);
    		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            makeNeck();
            makeHead(keys.head_X,keys.head_Y,keys.head_Z);
        glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void Robot::makeRobot(float* vector){
   keys.updateVector(vector);
   keys.movement(glfwGetCurrentContext());

    glPushMatrix();
    makeHip(keys.hip_TX,keys.hip_TY,keys.hip_TZ,keys.hip_X,keys.hip_Y,keys.hip_Z);

    glPushMatrix();
        makeLeftUpperLeg(keys.leftUpperLeg_X,keys.leftUpperLeg_Y,keys.leftUpperLeg_Z);
        makeLeftLowerLeg(keys.leftLowerLeg_X);
        makeLeftFoot(keys.leftFoot_X);
    glPopMatrix();

    glPushMatrix();
        makeRightUpperLeg(keys.rightUpperLeg_X,keys.rightUpperLeg_Y,keys.rightUpperLeg_Z);
        makeRightLowerLeg(keys.rightLowerLeg_X);
        makeRightFoot(keys.rightFoot_X);
    glPopMatrix();

    glPushMatrix();
        makeBust(keys.bust_X,keys.bust_Y,keys.bust_Z);

        glPushMatrix();
	        makeLeftShoulder();
            makeLeftUpperArmFront(keys.leftUpperArm_X,keys.leftUpperArm_Y,keys.leftUpperArm_Z);
    		glPushMatrix();
    		    makeLeftUpperArmBehind(behindArmAngle);
    		glPopMatrix();
                makeLeftLowerArmFront(keys.leftLowerArm_X);
    		glPushMatrix();
    		    makeLeftLowerArmBehind(behindArmAngle);
    		glPopMatrix();
                makeLeftFrontHand(keys.leftHand_X);
    		glPushMatrix();
    		    makeLeftBehindHand(behindArmAngle);
    		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
	        makeRightShoulder();
            makeRightUpperArmFront(keys.rightUpperArm_X,keys.rightUpperArm_Y,keys.rightUpperArm_Z);
    		glPushMatrix();
    		    makeRightUpperArmBehind(behindArmAngle);
    		glPopMatrix();
                makeRightLowerArmFront(keys.rightLowerArm_X);
    		glPushMatrix();
    		    makeRightLowerArmBehind(behindArmAngle);
    		glPopMatrix();
                makeRightFrontHand(keys.rightHand_X);
    		glPushMatrix();
    		    makeRightBehindHand(behindArmAngle);
    		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            makeNeck();
            makeHead(keys.head_X,keys.head_Y,keys.head_Z);
        glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}
