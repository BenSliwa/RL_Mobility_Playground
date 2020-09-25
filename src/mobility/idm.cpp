#include "idm.h"
#include <math.h>

IDM::IDM() :
    m_safeTimeHeadway_s(1.5),
    m_maxAcceleration_mpss(1),
    m_maxDeceleration_mpss(3), // high impact on the min distance (safety gap before busy road is considered)
    m_accelerationExponent(4.0),
    m_minDistance_m(2.0)
{

}

/*************************************
 *            PUBLIC METHODS         *
 ************************************/

double IDM::computeAcceleration(double _speed_mps, double _desiredSpeed_mps)
{
    double freeRoadAcceleration = computeFreeRoadCoefficient(_speed_mps, _desiredSpeed_mps);
    double busyRoadAcceleration = 0;
    double acceleration_mpss = m_maxAcceleration_mpss * (1 - freeRoadAcceleration - busyRoadAcceleration);

    return limitAcceleration(acceleration_mpss);
}


/*************************************
 *           PRIVATE METHODS         *
 ************************************/

double IDM::computeFreeRoadCoefficient(double _speed_mps, double _desiredSpeed_mps)
{
    double coefficient = pow((_speed_mps/_desiredSpeed_mps), m_accelerationExponent);
    if(_desiredSpeed_mps==0)
        coefficient = 1;

    return coefficient;
}

double IDM::limitAcceleration(double _acceleration)
{
    double acceleration_mpss = _acceleration;
    if(acceleration_mpss>m_maxAcceleration_mpss)
        acceleration_mpss = m_maxAcceleration_mpss;
    else if(acceleration_mpss<-m_maxAcceleration_mpss)
        acceleration_mpss = -m_maxAcceleration_mpss;



    return acceleration_mpss;
}
