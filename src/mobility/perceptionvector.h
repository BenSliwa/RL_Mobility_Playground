#ifndef PERCEPTIONVECTOR_H
#define PERCEPTIONVECTOR_H

#include "world/vector3d.h"

class PerceptionVector
{
public:
    PerceptionVector();

public:
    Vector3d dir;
    double length;
};

#endif // PERCEPTIONVECTOR_H
