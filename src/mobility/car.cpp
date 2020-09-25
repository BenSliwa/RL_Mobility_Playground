#include "car.h"
#include <iostream>

Car::Car(const QString &_id, const Vector3d &_position) :
    m_id(_id),
    m_position(_position),
    m_length_m(25),
    m_width_m(15),
    m_height_m(1)
{
    for(int i=0; i<5; i++)
        m_perception.push_back(PerceptionVector());
}

void Car::setPosition(const Vector3d &_position)
{
    m_position = _position;
}

void Car::setOrientation(const Vector3d &_orientation)
{
    m_orientation = _orientation;
}

void Car::move(double _distance_m)
{
    // compute direction vector
    Vector3d dir = Vector3d::fromSphere(90, this->getOrientation().z, _distance_m);
    dir = dir.normed();

    //
    if(_distance_m>=0)
        m_position = m_position + dir * _distance_m;
    else
        m_position = m_position - dir * _distance_m;

    //std::cout << m_position.toString() << "\t\t" << (m_position + dir * _distance_m).toString() << std::endl;

}

void Car::updatePerception()
{
    Vector3d left = Vector3d::fromSphere(90, 90 + this->getOrientation().z, 1);
    Vector3d right = left.rotateLeft().rotateLeft();
    Vector3d back = left.rotateLeft().normed();

    m_perception[0].dir = back * -1;
    m_perception[1].dir = left;
    m_perception[2].dir = right;
    m_perception[3].dir = (m_perception[0].dir+left).normed();
    m_perception[4].dir = (m_perception[0].dir+right).normed();
}

QString Car::getId()
{
    return m_id;
}

Vector3d Car::getPosition()
{
    return m_position;
}

Vector3d Car::getOrientation()
{
    return m_orientation;
}

double Car::getLength()
{
    return m_length_m;
}

double Car::getWidth()
{
    return m_width_m;
}

double Car::getHeight()
{
    return m_height_m;
}

std::vector<PerceptionVector>& Car::getPerception()
{
    return m_perception;
}
