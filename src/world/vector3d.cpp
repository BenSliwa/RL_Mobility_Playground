#include "vector3d.h"
#include <math.h>

Vector3d::Vector3d(double _x, double _y, double _z) :
    x(_x),
    y(_y),
    z(_z)
{

}

Vector3d Vector3d::fromSphere(double _theta, double _phi, double _r)
{
    double theta = toRad(_theta);
    double phi = toRad(_phi);

    return Vector3d(_r*sin(theta)*cos(phi), _r*sin(theta)*sin(phi), _r*cos(theta));
}

/*************************************
 *            PUBLIC METHODS         *
 ************************************/

double Vector3d::norm()
{
    return sqrt(x*x+y*y+z*z);
}

double Vector3d::norm2d()
{
    return sqrt(x*x+y*y);
}

Vector3d Vector3d::normed()
{
    return *this/norm();
}

Vector3d Vector3d::rotateRight()
{
    return Vector3d(y, -x, z);
}

Vector3d Vector3d::rotateLeft()
{
    return Vector3d(-y, x, z);
}

double Vector3d::cross2d(const Vector3d &_v)
{
    return (x*_v.y) - (y*_v.x);
}

double Vector3d::computePhi()
{
    return toGrad(atan2(y, x));
}

double Vector3d::toRad(double _grad)
{
    return _grad/180.0*3.141592654;
}

double Vector3d::toGrad(double _rad)
{
    return _rad*180.0/3.141592654;
}

std::string Vector3d::toString() const
{
    std::stringstream stream;
    stream << x << "," << y << "," << z;

    return stream.str();
}

/*************************************
 *              OPERATORS            *
 ************************************/

Vector3d operator+(Vector3d _lhs, const Vector3d &_rhs)
{
    return Vector3d(_lhs.x+_rhs.x, _lhs.y+_rhs.y, _lhs.z+_rhs.z);
}

Vector3d operator-(Vector3d _lhs, const Vector3d &_rhs)
{
    return Vector3d(_lhs.x-_rhs.x, _lhs.y-_rhs.y, _lhs.z-_rhs.z);
}

Vector3d operator*(Vector3d _lhs, double _rhs)
{
    return Vector3d(_lhs.x*_rhs, _lhs.y*_rhs, _lhs.z*_rhs);
}

Vector3d operator/(Vector3d _lhs, double _rhs)
{
    return Vector3d(_lhs.x/_rhs, _lhs.y/_rhs, _lhs.z/_rhs);
}

double operator*(Vector3d _lhs, const Vector3d &_rhs)
{
    return _lhs.x*_rhs.x + _lhs.y*_rhs.y + _lhs.z*_rhs.z;
}


/*************************************
 *           PRIVATE METHODS         *
 ************************************/
