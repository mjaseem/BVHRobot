#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include <cstdlib>
#include <stdio.h>
#include <GL/glew.h>

class TextureFaces {
public:
    GLuint front,back,top,bottom,left,right;
    TextureFaces() {
        front=back=top=bottom=left=right=-1;
    }
    TextureFaces(GLuint all) {
        front=back=top=bottom=left=right=all;
    }
};

namespace Texture {

    void makeTexture(const char* FilePath,GLuint gltexture);
}

#endif
