#include "car.h"
#include <iostream>

Car::Car(const QString &_id, const Vector3d &_position) :
    m_id(_id),
    m_position(_position),
    m_length_m(50),
    m_width_m(20),
    m_height_m(1)
{
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
