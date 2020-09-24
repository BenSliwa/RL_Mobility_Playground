#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <sstream>

class Vector3d
{
public:
    Vector3d(double _x=0, double _y=0, double _z=0);

    static Vector3d fromSphere(double _phi, double _theta, double _r);

    double norm();
    double norm2d();
    Vector3d normed();
    Vector3d rotateRight();
    Vector3d rotateLeft();
    double cross2d(const Vector3d &_v);
    double computePhi();

    //
    static double toRad(double _grad);
    static double toGrad(double _rad);

    //
    std::string toString() const;

public:
    double x;
    double y;
    double z;
};

// operators
Vector3d operator+(Vector3d _lhs, const Vector3d &_rhs);
Vector3d operator-(Vector3d _lhs, const Vector3d &_rhs);
Vector3d operator*(Vector3d _lhs, double _rhs);
Vector3d operator/(Vector3d _lhs, double _rhs);
double operator*(Vector3d _lhs, const Vector3d &_rhs);

#endif // VECTOR3D_H
