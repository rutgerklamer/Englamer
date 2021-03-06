#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include "Englamer/Components/Mesh.h"
#include <SOIL2.h>

namespace textureloader {
  uint load_texture(const char* path)
  {
    //Make a texture
   uint textureID;

   int textureWidth, textureHeight;

   glGenTextures(1, &textureID);
   glBindTexture(GL_TEXTURE_2D, textureID);

   //GL_REPEAT for multiplication in fragment shader
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   //Load SOIL image
   unsigned char* image = SOIL_load_image(path, &textureWidth, &textureHeight, 0, SOIL_LOAD_RGBA);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureWidth, textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

   //Enable alpha

   //Make a mipmap
   glGenerateMipmap(GL_TEXTURE_2D);
   //Delete image since it's already made and stored in textureID
   SOIL_free_image_data(image);
   //Bind default texture
   glBindTexture(GL_TEXTURE_2D, 0);

   return textureID;
  }
};

#endif TEXTURELOADER_H
