#ifndef _BLOCKS_HPP_
#define _BLOCKS_HPP_

#include <GL/glew.h>
#include <cmath>


namespace Blocks {

	void defineCuboid(double length,double width,double height);
	void defineTrapizoid(double top_length,double bottom_length, double width, double height);
	void defineSphere(double r, int lats, int longs);
	void defineCylinder(double radius,double length,double numsteps,double color);
}

#endif
