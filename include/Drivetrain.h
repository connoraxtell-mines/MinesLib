#pragma once

#include "pros/motor_group.hpp"
#include "PID.h"
#include "TaskBase.h"

namespace Mines
{
class Drivetrain
{
    public:
        Drivetrain(pros::AbstractMotor& LeftMotors, pros::AbstractMotor& rightMotors);

        void setVelocity(double leftVelocity, double rightVelocity);

        void driveDistance(double distance);

        void turnFor(double angle);
        void turnTo(double angle);

    private:
        pros::MotorGroup m_leftMotors;
        pros::MotorGroup m_rightMotors;
        Mines::PID m_drivePID;
        Mines::PID m_turnPID;
};
}