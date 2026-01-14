#pragma once

#include "pros/motor_group.hpp"
#include "PID.h"
#include "TaskBase.h"

namespace Mines
{
class Drivetrain : public TaskBase
{
    public:
        Drivetrain(const pros::MotorGroup& leftMotors, const pros::MotorGroup& rightMotors);

        void setVelocity(double leftVelocity, double rightVelocity);

        void driveDistance(double distance);

        void turnFor(double angle);
        void turnTo(double angle);

        void run() override {};

    private:
        pros::MotorGroup m_leftMotors;
        pros::MotorGroup m_rightMotors;
        Mines::PID m_leftPID;
        Mines::PID m_rightPID;
};
}