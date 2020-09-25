#ifndef CAR_H
#define CAR_H

#include <QObject>
#include "world/vector3d.h"
#include "perceptionvector.h"
#include <vector>

class Car
{
public:
    Car(const QString &_id, const Vector3d &_position = Vector3d());


    void setPosition(const Vector3d &_position);
    void setOrientation(const Vector3d &_orientation);

    void move(double _distance_m);
    void updatePerception();

    QString getId();
    Vector3d getPosition();
    Vector3d getOrientation();
    double getLength();
    double getWidth();
    double getHeight();
    std::vector<PerceptionVector>& getPerception();

private:
    QString m_id;
    Vector3d m_position;
    Vector3d m_orientation;
    std::vector<PerceptionVector> m_perception;

    double m_length_m;
    double m_width_m;
    double m_height_m;

};

#endif // CAR_H
