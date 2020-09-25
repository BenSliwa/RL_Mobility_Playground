#ifndef WORLD_H
#define WORLD_H

#include "vector3d.h"

class World
{
public:
    World();

    static World* getInstance();

    Vector3d getSize();

private:
    Vector3d m_size;
};

#endif // WORLD_H
