#include "Drivetrain.h"
namespace Mines{
//=======================================
// Member Variables
//=======================================

//pros::MotorGroup m_leftMotors;
//pros::MotorGroup m_rightMotors;
//Mines::PID m_drivePID;
//Mines::PID m_turnPID;


Drivetrain::Drivetrain(pros::AbstractMotor& leftMotors, pros::AbstractMotor& rightMotors)
: m_leftMotors(leftMotors), m_rightMotors(rightMotors), m_drivePID(5, .001, .5, .5), m_turnPID(5, .001, .5, .5)
{

}


void setVelocity(double leftVelocity, double rightVelocity)
{

    return;
}

void driveDistance(double distance)
{

    return;
}

void turnFor(double angle)
{

    return;
}
void turnTo(double angle)
{

    return;
}
}