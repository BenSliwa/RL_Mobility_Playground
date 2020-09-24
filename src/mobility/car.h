#ifndef CAR_H
#define CAR_H

#include <QObject>
#include "world/vector3d.h"

class Car
{
public:
    Car(const QString &_id, const Vector3d &_position = Vector3d());


    void setPosition(const Vector3d &_position);
    void setOrientation(const Vector3d &_orientation);

    void move(double _distance_m);

    QString getId();
    Vector3d getPosition();
    Vector3d getOrientation();
    double getLength();
    double getWidth();
    double getHeight();


private:
    QString m_id;
    Vector3d m_position;
    Vector3d m_orientation;

    double m_length_m;
    double m_width_m;
    double m_height_m;

};

#endif // CAR_H
