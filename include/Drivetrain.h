#pragma once

//#define DEBUG

#include "pros/motor_group.hpp"
#include "pros/imu.hpp"
#include "pros/rotation.hpp"
#include "PID.h"
#include "TaskBase.h"

#ifdef DEBUG
#define PRINT_D(out) std::cout << out << "\n"
#else
#define PRINT_D(out)
#endif

namespace Mines
{
class Drivetrain
{
    public:

        Drivetrain(pros::AbstractMotor* leftMotors,
                  pros::AbstractMotor* rightMotors,
                  pros::Rotation* rotationSensor,
                  pros::Imu* imu,
                  double gearRatio = 1.0, double wheelDiameter = 2.25);


        /**
         * @brief initializes Drivetrain (call in init function)
         */
        void init() { m_imu->reset(true);};

        /**
         * @brief drives distance in inches
         * @param tol Sets the tolerance in centidegrees?
         * @param settleTime 
         */
        void driveDistance(double distance, int32_t tol = 5000, uint32_t settleTime = 200);


        void capVoltage(int32_t voltageCap) {m_voltageCap = voltageCap;};
        void turnTo(double angle, double tol = 1.0, uint32_t settleTime = 200);

        void setDrivePID(double kp, double ki, double kd, double integralLim) { m_drivePID.setTunings(kp,ki,kd); m_drivePID.setIntegralLimit(integralLim);};
        void setTurnPID(double kp, double ki, double kd, double integralLim) { m_turnPID.setTunings(kp,ki,kd); m_turnPID.setIntegralLimit(integralLim); };
    private:
        int32_t m_voltageCap = 127;
        pros::AbstractMotor* m_leftMotors;
        pros::AbstractMotor* m_rightMotors;
        pros::Rotation* m_rotation;
        pros::Imu* m_imu;
        Mines::PID m_drivePID;
        Mines::PID m_turnPID;


        // stored ratio and a convenient multiplier (wheel revs per motor rev)
        double m_wheelDiameter;    // motor revs per wheel rev
        double m_gearRatio; // wheel revs per motor rev

};
}