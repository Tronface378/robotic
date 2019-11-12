#include "vex.h"
#include "motors.h"
//#include "auton.h"
using namespace vex;

  int LiftUp = 50;
  int LiftDown = 50;
  int intake = 100;
  int outTake = 75;

  int driveSpeed = 0;
  int speed = 1;
  int b = 0;


void DriveSpeed() 
{

  if(master.ButtonY.pressing() && driveSpeed == 0)
  {
    Brain.Screen.clearLine(2, 40);
    Brain.Screen.clearLine(2, "#000000");
    master.Screen.clearScreen();
    driveSpeed = 1;
    speed = 2;
    master.Screen.print("Driving at half");
    Brain.Screen.printAt(2, 40,"DRIVING AT HALF SPEED");
    task::sleep(75);
  }
  if(master.ButtonY.pressing() && driveSpeed == 1) 
  {
    Brain.Screen.clearLine(2, 40);
    Brain.Screen.clearLine(2, "#000000");
    master.Screen.clearScreen();
    driveSpeed = 0;
    speed = 1;
    master.Screen.print("Driving at full");
    Brain.Screen.printAt(2, 40,"DRIVING AT FULL SPEED");
    task::sleep(75);
  }
}

void usercontrol( void ) {
    while(1) 
  {
    //ifElseStatements(); 
    DriveSpeed();

    leftMotor.spin(vex::directionType::fwd, master.Axis3.position()/speed, vex::velocityUnits::pct);
    rightMotor.spin(vex::directionType::fwd, master.Axis2.position()/speed, vex::velocityUnits::pct);
    
    task::sleep(10);

    if(master.ButtonR1.pressing()) 
    { 
      LiftL.spin(directionType::fwd, 100, velocityUnits::pct);
      LiftR.spin(directionType::fwd,100, velocityUnits::pct);
    }
    else if(master.ButtonR2.pressing()) 
    {
      LiftL.spin(directionType::rev, 100, velocityUnits::pct);
      LiftR.spin(directionType::rev, 100, velocityUnits::pct);
    }
    else 
    {
      task::sleep(10);
      LiftL.spin(directionType::rev, 0, velocityUnits::pct);
      LiftR.spin(directionType::rev, 0, velocityUnits::pct);
      LiftL.setBrake(vex::brakeType(hold));
      LiftR.setBrake(vex::brakeType(hold));
    }

    if(master.ButtonL1.pressing()) 
    { 
      intakeR.spin(directionType::rev, 100, velocityUnits::pct);
      intakeL.spin(directionType::rev, 100, velocityUnits::pct);
    }
    else if(master.ButtonL2.pressing()) 
    {
      intakeR.spin(directionType::fwd, 100, velocityUnits::pct);
      intakeL.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    else 
    {
      task::sleep(10);
      intakeR.spin(directionType::rev, 0, velocityUnits::pct);
      intakeL.spin(directionType::rev, 0, velocityUnits::pct);

      intakeL.setBrake(vex::brakeType(brake));
      intakeR.setBrake(vex::brakeType(brake));
    
    }   
  

    if(master.ButtonB.pressing() && b == 0)
    {
      Brain.Screen.clearLine(1, 40);
      Brain.Screen.clearLine(1, "#000000");
      master.Screen.clearScreen();
      b = 1;
      master.Screen.print("b is now 1");
      Brain.Screen.printAt(1, 20,"B WAS =0 AND IS NOW =1");
      task::sleep(75);
    }
    else if(master.ButtonB.pressing() && b == 1)
    {
      Brain.Screen.clearLine(1, 40);
      Brain.Screen.clearLine(1, "#000000");
      master.Screen.clearScreen();
      b = 0;
      master.Screen.print("b is now 0");
      Brain.Screen.printAt(1, 20,"B WAS =1 AND IS NOW =0");
      task::sleep(75);
    }




    if(master.ButtonUp.pressing()) 
    { 
      CubeTray.spin(directionType::fwd, 15, velocityUnits::pct); 
    }
    else if(master.ButtonDown.pressing()) 
    {
      CubeTray.spin(directionType::rev, 25, velocityUnits::pct);
    }
    else 
    {
      task::sleep(10);
      CubeTray.spin(directionType::rev, 0, velocityUnits::pct);
      CubeTray.setBrake(vex::brakeType(hold));

    }

  }
}
