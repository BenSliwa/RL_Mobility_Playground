#ifndef IDM_H
#define IDM_H


class IDM
{
public:
    IDM();

    double computeAcceleration(double _speed_mps, double _desiredSpeed_mps);

private:
    double computeFreeRoadCoefficient(double _speed_mps, double _desiredSpeed_mps);
    double limitAcceleration(double _acceleration);

private:
    double m_safeTimeHeadway_s;
    double m_maxAcceleration_mpss;
    double m_maxDeceleration_mpss;
    double m_accelerationExponent;
    double m_minDistance_m;
};

#endif // IDM_H
