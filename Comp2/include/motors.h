#include "vex.h"
using namespace vex;
// brain brain;
motor leftMotor(PORT3, gearSetting::ratio18_1, false);
motor rightMotor(PORT13, gearSetting::ratio18_1, true);
motor LiftL(PORT2, gearSetting::ratio36_1, false);
motor LiftR(PORT5,gearSetting::ratio36_1, true);

motor intakeR(PORT4, gearSetting::ratio18_1, false);
motor intakeL(PORT10, gearSetting::ratio18_1, true);
motor CubeTray(PORT20, gearSetting::ratio36_1, false);
extern drivetrain DriveOne;
drivetrain DriveOne = drivetrain(leftMotor, rightMotor, 319.19, 295, 130, mm, 1);

// motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
// motor RightDriveSmart = motor(PORT10, ratio18_1, true);
// drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 130, mm, 1);

// motor leftfront(PORT10, gearSetting::ratio36_1, false);
// motor rightfront(PORT20, gearSetting::ratio36_1, true);
// motor leftback(PORT1, gearSetting::ratio36_1, false);
// motor rightback(PORT11, gearSetting::ratio36_1, true);
 
  // drivetrain Drive = Drive(leftMotor, rightMotor, 319, 295, distanceUnits::mm);
controller master;
