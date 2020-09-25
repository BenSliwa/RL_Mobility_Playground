#include "world.h"

World::World() :
    m_size(Vector3d(1200, 800))
{

}

World* World::getInstance()
{
    static World instance;
    return &instance;
}

Vector3d World::getSize()
{
    return m_size;
}
