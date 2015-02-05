
#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "keycontrols.hpp"

class point
{
 public:
    double x;
    double y;
    double z;
    point()
    {
    	x=0;  	y=0;   	z=0;
    }
    point(double a,double b,double c)
    {
    	x=a;   	y=b;   	z=c;
    }
};


class Robot
{
private:
    point HeadNeckJoint;
    point NeckBustJoint;
    point LeftShoulder_LeftUpperArmFront_Joint;
    point RightShoulder_RightUpperArmFront_Joint;
    point Bust_Hip_Joint;
    point Hip_LeftUpperLeg_Joint;
    point Hip_RightUpperLeg_Joint;

    point LeftShoulder_Bust_Joint;
    point RightShoulder_Bust_Joint;

    point LeftUpperArmFront_LeftLowerArmFront_Joint;
    point RightUpperArmFront_RightLowerArmFront_Joint;
    point LeftLowerArmFront_LeftFrontHand_Joint;
    point RightLowerArmFront_RightFrontHand_Joint;

    point LeftFrontHand_LeftBehindHand_Joint;
    point RightFrontHand_RightBehindHand_Joint;
    
    point LeftUpperArmFront_LeftUpperArmBehind_Joint;
    point LeftLowerArmFront_LeftLowerArmBehind_Joint;
    point RightUpperArmFront_RightUpperArmBehind_Joint;
    point RightLowerArmFront_RightLowerArmBehind_Joint;

    point LeftUpperLeg_LeftLowerLeg_Joint;
    point RightUpperLeg_RightLowerLeg_Joint;
    point LeftLowerLeg_LeftFoot_Joint;
    point RightLowerLeg_RightFoot_Joint;


    point Bust_Lower_Point;
    point Neck_Lower_Point;
    point Head_Lower_Point;
    point Left_Shoulder_Lower_Point;
    point Right_Shoulder_Lower_Point;
    point LeftUpperArmFront_Upper_Point;
    point LeftLowerArmFront_Upper_Point;
    point RightUpperArmFront_Upper_Point;
    point RightLowerArmFront_Upper_Point;
    
    point LeftUpperArmBehind_Right_Point;
    point LeftLowerArmBehind_Right_Point;
    point RightUpperArmBehind_Left_Point;
    point RightLowerArmBehind_Left_Point;
    point LeftFrontHand_Upper_Point;
    point RightFrontHand_Upper_Point;
    point LeftBehindHand_Upper_Point;
    point RightBehindHand_Upper_Point;

    point LeftUpperLeg_Upper_Point;
    point LeftLowerLeg_Upper_Point;
    point RightUpperLeg_Upper_Point;
    point RightLowerLeg_Upper_Point;
    point LeftFoot_Behind_Point;
    point RightFoot_Behind_Point;
    int behindArmAngle;


//Some more structural constraints and structural parameters.
    GLuint Hip;
    GLuint Bust;
    GLuint Neck;
    GLuint Head;
    GLuint LeftShoulder;
    GLuint RightShoulder;

    GLuint LeftUpperArmFront;
    GLuint LeftLowerArmFront;
    GLuint RightUpperArmFront;
    GLuint RightLowerArmFront;
    
    GLuint LeftUpperArmBehind;
    GLuint LeftLowerArmBehind;
    GLuint RightUpperArmBehind;
    GLuint RightLowerArmBehind;

    GLuint LeftFrontHand;
    GLuint RightFrontHand;

    GLuint LeftBehindHand;
    GLuint RightBehindHand;

    GLuint LeftUpperLeg;
    GLuint RightUpperLeg;
    GLuint LeftLowerLeg;
    GLuint RightLowerLeg;
    GLuint LeftFoot;
    GLuint RightFoot;
    
    GLuint* texture;

    
    enum {LOGO,BLUE,RED,HEAD,WHEEL,HIP,BUST_LEFT,
    RIGHT_FOOT_RIGHT};

public:
    
    KeyControls keys;
    Robot()
    {
      initStructuralConstraints();
      
      initTexture();
      //initLights();
      
      initHip();
      initBust();
      initNeck();
      initHead();
      initLeftShoulder();
      initRightShoulder();

      initLeftUpperArmFront();
      initLeftLowerArmFront();
      initRightUpperArmFront();
      initRightLowerArmFront();

      initLeftUpperArmBehind();
      initLeftLowerArmBehind();
      initRightUpperArmBehind();
      initRightLowerArmBehind();
      initLeftFrontHand();
      initRightFrontHand();
      initLeftBehindHand();
      initRightBehindHand();
      initLeftUpperLeg();
      initLeftLowerLeg();
      initRightUpperLeg();
      initRightLowerLeg();
      initLeftFoot();
      initRightFoot();    
      behindArmAngle=0;
      keys = KeyControls();

    }

  void initTexture();

  //void initLights();
  //void setLights();
  void setRobotProperties();

  void initStructuralConstraints();
  //initilize Hip structure
  void initHip();

  //initilize Bust structure
  void initBust();

  void initNeck();
  void initHead();
  void initLeftShoulder();
  void initRightShoulder();



  void initLeftUpperArmFront();
  void initLeftLowerArmFront();
  void initRightUpperArmFront();
  void initRightLowerArmFront();

  void initLeftUpperArmBehind();
  void initLeftLowerArmBehind();
  void initRightUpperArmBehind();
  void initRightLowerArmBehind();

  void initLeftFrontHand();
  void initRightFrontHand();

  void initLeftBehindHand();
  void initRightBehindHand();


  void initLeftUpperLeg();
  void initLeftLowerLeg();
  void initRightUpperLeg();
  void initRightLowerLeg();
  void initLeftFoot();
  void initRightFoot();


  void makeHip(double tx,double ty,double tz,double angle_x,double angle_y,double angle_z);
  void makeBust(double angle_x,double angle_y,double angle_z);

  void makeNeck(void);
  void makeHead(double angle_x,double angle_y,double angle_z);
  void makeLeftShoulder();
  void makeRightShoulder();

  void makeLeftUpperArmFront(double angle_x,double angle_y,double angle_z);
  void makeLeftLowerArmFront(double angle_x);
  void makeRightUpperArmFront(double angle_x,double angle_y,double angle_z);
  void makeRightLowerArmFront(double angle_x);

  void makeLeftUpperArmBehind(double angle_y);
  void makeLeftLowerArmBehind(double angle_y);
  void makeRightUpperArmBehind(double angle_y);
  void makeRightLowerArmBehind(double angle_y);

  void makeLeftFrontHand(double angle_x);
  void makeRightFrontHand(double angle_x);
  void makeLeftBehindHand(double angle_y);
  void makeRightBehindHand(double angle_y);


  void makeLeftUpperLeg(double angle_x,double angle_y,double angle_z);
  void makeLeftLowerLeg(double angle_x);
  void makeRightUpperLeg(double angle_x,double angle_y,double angle_z);
  void makeRightLowerLeg(double angle_x);
  void makeLeftFoot(double angle_x);
  void makeRightFoot(double angle_x);

  void makeRobot(void);
  void makeRobot(float* vector);
  void setFrameConstraints();

  void animate();
}; 

#endif
