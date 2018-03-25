#ifndef SKYBOX_H
#define SKYBOX_H

#include "Englamer/Components/Mesh.h"
#include "Englamer/Components/Material.h"

class Skybox : public Mesh, public Material
{
public:
    Skybox(std::string right, std::string left, std::string up, std::string down, std::string back, std::string front);
    ~Skybox();
private:
};

#endif
