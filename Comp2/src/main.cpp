/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Scott                                            */
/*    Created:      Sun Oct 27 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    3, 13           
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
//#include "motors.h" 
//calling motors.h through void.h so its not calling them twice
#include "void.h"

using namespace vex;


using namespace vex;

competition Competition;

void pre_auton( void ) 
{
  
}
void autonomous( void ) 
{
  DriveOne.setDriveVelocity(75, pct);
  
  DriveOne.driveFor(50, mm);
  
  DriveOne.driveFor(100, mm);
  
  DriveOne.driveFor(-100, mm);

  DriveOne.setDriveVelocity(50, pct);
  DriveOne.turnFor(90, degrees);

  DriveOne.setDriveVelocity(75, pct);
}


int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
