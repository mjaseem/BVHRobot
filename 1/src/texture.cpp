#include "texture.hpp"

void Texture::makeTexture(const char* FilePath,GLuint gltexture)
{
    FILE* TextureImage;
    unsigned char* TextureData; 

    TextureImage=fopen(FilePath,"rb");

    if( ! TextureImage ) {
        printf("Cannot open file : %s\n", FilePath );
        return;
    }

    unsigned char header[54];
    fread(header,1,54,TextureImage); //read header

    int width      = *(int*)&(header[0x12]);
    int height     = *(int*)&(header[0x16]);

    fseek ( TextureImage , 128 , SEEK_SET );
    
    TextureData=(unsigned char *)malloc(width*height*3);
    fread(TextureData,width*height,3,TextureImage);
    fclose(TextureImage);

    glBindTexture(GL_TEXTURE_2D,gltexture);
    glPixelStorei(GL_UNPACK_ALIGNMENT,2);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR,GL_MODULATE);

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_BGR,GL_UNSIGNED_BYTE,TextureData);
    
    delete TextureData;
}