#include "blocks.hpp"

namespace Blocks {

	void defineCuboid(double length,double width,double height,TextureFaces &tf)
	{
		//std::cout<<"Cuboid";
		double half_length,half_width,half_height;
		half_length=length/2;
		half_width=width/2;
		half_height=height/2;

		glBindTexture(GL_TEXTURE_2D,tf.front);
		glBegin(GL_QUADS);
		    glNormal3f(0.0f, 0.0f, -1.0f);
		    glTexCoord2d(0.0,0.0);	    
		    glVertex3f(-half_length,-half_width,half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(half_length,-half_width,half_height);
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(half_length,half_width,half_height);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(-half_length,half_width,half_height);
		glEnd();

		glBindTexture(GL_TEXTURE_2D,tf.top);
		glBegin(GL_QUADS);    
			glNormal3f(0.0f, -1.0f,0.0f);
		    glTexCoord2d(0.0,0.0);	
		    glVertex3f(half_length,half_width,half_height);
	        glTexCoord2d(1.0,0.0);
		    glVertex3f(-half_length,half_width,half_height);
            glTexCoord2d(1.0,1.0);
		    glVertex3f(-half_length,half_width,-half_height);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(half_length,half_width,-half_height);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D,tf.back);
		glBegin(GL_QUADS);    
			glNormal3f(0.0f, 0.0f, 1.0f);
	        glTexCoord2d(0.0,0.0);
		    glVertex3f(half_length,half_width,-half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(-half_length,half_width,-half_height);
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(-half_length,-half_width,-half_height);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(half_length,-half_width,-half_height);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D,tf.bottom);
		glBegin(GL_QUADS);    
			glNormal3f(0.0f, 1.0f,0.0f);
		    glTexCoord2d(0.0,0.0);
		    glVertex3f(half_length,-half_width,-half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(-half_length,-half_width,-half_height);
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(-half_length,-half_width,half_height);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(half_length,-half_width,half_height);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D,tf.left);
		glBegin(GL_QUADS);    
			glNormal3f(-1.0f, 0.0f,0.0f);
		    glTexCoord2d(0.0,0.0);
		    glVertex3f(half_length,half_width,-half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(half_length,-half_width,-half_height);
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(half_length,-half_width,half_height);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(half_length,half_width,half_height);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D,tf.right);
		glBegin(GL_QUADS);    
			glNormal3f(1.0f, 0.0f,0.0f);
		    glTexCoord2d(0.0,0.0);
		    glVertex3f(-half_length,half_width,-half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(-half_length,-half_width,-half_height);
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(-half_length,-half_width,half_height);
		    glTexCoord2d(0.0f,1.0);
		    glVertex3f(-half_length,half_width,half_height);
		glEnd();
	}

	void defineTrapizoid(double top_length,double bottom_length, double width, double height, TextureFaces &tf) {

		double half_top_length, half_bottom_length,half_width,half_height;

		half_top_length = top_length / 2;
		half_bottom_length = bottom_length / 2;
		half_width = width/2;
		half_height = height/2;

#define 	POINT_A		glVertex3f(-half_top_length,half_height,-half_width)
#define 	POINT_B		glVertex3f(half_top_length,half_height,-half_width)
#define 	POINT_C		glVertex3f(half_bottom_length,-half_height,-half_width)
#define 	POINT_D		glVertex3f(-half_bottom_length,-half_height,-half_width)
#define 	POINT_E		glVertex3f(-half_bottom_length,-half_height,half_width)
#define 	POINT_F		glVertex3f(half_bottom_length,-half_height,half_width)
#define 	POINT_G		glVertex3f(half_top_length,half_height,half_width)
#define 	POINT_H		glVertex3f(-half_top_length,half_height,half_width)

		glBindTexture(GL_TEXTURE_2D,tf.top);
		glBegin(GL_QUADS);
			/* Top face*/
			glNormal3f(0.0f, -1.0f,0.0f);
			glTexCoord2d(0,0);
			POINT_A;
			glTexCoord2d(1,0);
			POINT_B;
			glTexCoord2d(1,1);
			POINT_G;
			glTexCoord2d(0,1);
			POINT_H;
		glEnd();

		glBindTexture(GL_TEXTURE_2D,tf.bottom);
		glBegin(GL_QUADS);		 
			/* Bottom face*/
			glNormal3f(0.0f, 1.0f,0.0f);
			glTexCoord2d(0,0);
			POINT_D;
			glTexCoord2d(1,0);
			POINT_C;
			glTexCoord2d(1,1);
			POINT_F;
			glTexCoord2d(0,1);
			POINT_E;
		glEnd();

		glBindTexture(GL_TEXTURE_2D,tf.front);
		glBegin(GL_QUADS);

			/* Front face */
			glNormal3f(0.0f, 0.0f,1.0f);
			glTexCoord2d(0,0);
			POINT_D;
			glTexCoord2d(1,0);
			POINT_C;
			glTexCoord2d(1,1);
			POINT_B;
			glTexCoord2d(0,1);
			POINT_A;
		glEnd();
		  
		glBindTexture(GL_TEXTURE_2D,tf.left);
		glBegin(GL_QUADS);
			/*Left face*/
			glNormal3f(1.0f, 0.0f,0.0f);
			glTexCoord2d(0,0);
			POINT_E;
			glTexCoord2d(0,1);
			POINT_H;
			glTexCoord2d(1,1);
			POINT_A;
			glTexCoord2d(1,0);
			POINT_D;
		glEnd();
		  
		glBindTexture(GL_TEXTURE_2D,tf.right);
		glBegin(GL_QUADS);
			/*Right face*/
			glNormal3f(-1.0f, 0.0f,0.0f);
			glTexCoord2d(0,0);
			POINT_C;
			glTexCoord2d(1,0);
			POINT_F;
			glTexCoord2d(1,1);
			POINT_G;
			glTexCoord2d(0,1);
			POINT_B;
		glEnd();
		 
		glBindTexture(GL_TEXTURE_2D,tf.back);
		glBegin(GL_QUADS);
			/*Back face*/
			glNormal3f(0.0f, 0.0f,-1.0f);
			glTexCoord2d(0.0,1.0);
			POINT_H;
			glTexCoord2d(1.0,1.0);
			POINT_G;
			glTexCoord2d(1.0,0.0);
			POINT_F;
			glTexCoord2d(0.0,0.0);
			POINT_E;
		glEnd();

	}
	void defineSphere(double r, int lats, int longs) {
     int i, j;
     for(i = 0; i <= lats; i++) {
         double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
         double z0  = sin(lat0);
         double zr0 =  cos(lat0);

         double lat1 = M_PI * (-0.5 + (double) i / lats);
         double z1 = sin(lat1);
         double zr1 = cos(lat1);
         
         glBegin(GL_QUAD_STRIP);
         for(j = 0; j <= longs; j++) {
             double lng = 2 * M_PI * (double) (j - 1) / longs;
             double x = cos(lng);
             double y = sin(lng);
             glNormal3f(r * x * zr0, r * y * zr0, r * z0);
             glVertex3f(r * x * zr0, r * y * zr0, r * z0);
             glNormal3f(r * x * zr1, r * y * zr1, r * z1);
             glVertex3f(r * x * zr1, r * y * zr1, r * z1);
         }
         glEnd();
	     }
	 }

	 void defineCylinder(double radius,double length,double numSteps,double color) {
	 	double hl = length * 0.5f;
		double a = 0.0f;
		double step = 2 * (M_PI / (double)numSteps);
		
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_TRIANGLE_STRIP);
		for (int i = 0; i < numSteps; ++i)
		{
		    double x = cos(a) * radius;
		    double y = sin(a) * radius;
		    glVertex3f(x,y,-hl);
		    glNormal3f(x,y,-hl);
		    glVertex3f(x,y, hl);
		    glNormal3f(x,y, hl);
		 
		    a += step;
		}
		glEnd();
		glColor3f(color,color,color);

		a = 0;
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0,0,-1);
		for (int i = 0; i < numSteps; ++i)
		{
		    double x = cos(a) * radius;
		    double y = sin(a) * radius;

		    	glTexCoord2d(cos(a)*0.5+0.5,sin(a)*0.5+0.5);
		    glVertex3f(x,y, hl);
		 
		    a += step;
		}
		glEnd();

		a=0;
		glBegin(GL_POLYGON);
		glNormal3f(0,0,1);	
		for (int i = 0; i < numSteps; ++i)
		{
		    double x = cos(a) * radius;
		    double y = sin(a) * radius;

		    glTexCoord2d(cos(a)*0.5+0.5,sin(a)*0.5+0.5);
		    glVertex3f(x,y, -hl);
		 
		    a += step;
		}
		glEnd();

		glColor3f(1,1,1);
	 }

}
