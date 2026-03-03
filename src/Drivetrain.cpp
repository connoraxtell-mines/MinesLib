#include "Drivetrain.h"
namespace Mines{
//=======================================
// Member Variables
//=======================================

//pros::MotorGroup m_leftMotors;
//pros::MotorGroup m_rightMotors;
//Mines::PID m_drivePID;
//Mines::PID m_turnPID;


Drivetrain::Drivetrain(pros::AbstractMotor& leftMotors,
                             pros::AbstractMotor& rightMotors,
                             double gearRatio)
: m_leftMotors(leftMotors),
  m_rightMotors(rightMotors),
  m_drivePID(5, .001, .5, .5),
  m_turnPID(5, .001, .5, .5),
  m_gearRatio(gearRatio)
{
    
}


void Drivetrain::setVelocity(double leftVelocity, double rightVelocity)
{

    return;
}

void Drivetrain::driveDistance(double distance)
{

    return;
}

void Drivetrain::turnFor(double angle)
{

    return;
}
void Drivetrain::turnTo(double angle)
{

    return;
}

// conversion helpers (could be used by the PID routines, etc.)
double Drivetrain::motorRevsToWheelRevs(double motorRevs) const
{
    return motorRevs * m_wheelPerMotor;
}

double Drivetrain::wheelRevsToMotorRevs(double wheelRevs) const
{
    return wheelRevs / m_wheelPerMotor;
}
}