#ifndef _BLOCKS_HPP_
#define _BLOCKS_HPP_

#include <GL/glew.h>
#include <cmath>

#include "texture.hpp"

namespace Blocks {

	void defineCuboid(double length,double width,double height, TextureFaces &tf);
	void defineTrapizoid(double top_length,double bottom_length, double width, double height,TextureFaces &tf);
	void defineSphere(double r, int lats, int longs);
	void defineCylinder(double radius,double length,double numsteps,double color);
}

#endif