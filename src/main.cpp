/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Chase H. - Landon H. - Cole S.                                                     */
/*    Created:      11/20/2023, 9:39:22 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

/*
 ________    __        __        ___      ________     
/\_____  \ /'_ `\    /'_ `\    /'___`\   /\_____  \    
\/___//'/'/\ \L\ \  /\ \L\ \  /\_\ /\ \  \/____//'/'   
    /' /' \/_> _ <_ \/_> _ <_ \/_/// /__      //'/'    
  /' /'     /\ \L\ \  /\ \L\ \   // /_\ \    //'/'___  
 /\_/       \ \____/  \ \____/  /\______/    /\_______\
 \//         \/___/    \/___/   \/_____/     \/_______/
*/
                                      

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

brain Brain;

motor leftMotorA = motor(PORT19, ratio18_1, true);
motor leftMotorB = motor(PORT11, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);

motor rightMotorA = motor(PORT1, ratio18_1, false);
motor rightMotorB = motor(PORT10, ratio18_1, false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);

inertial DrivetrainInertial = inertial(PORT12);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 40, mm, 1);

motor Motor2 = motor(PORT2, ratio18_1, false);
motor Motor7 = motor(PORT7, ratio18_1, false);

motor MotorGroup3MotorA = motor(PORT3, ratio36_1, false);
motor MotorGroup3MotorB = motor(PORT4, ratio36_1, false);
motor_group MotorGroup3 = motor_group(MotorGroup3MotorA, MotorGroup3MotorB);

controller Controller1 = controller(primary);

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
    Brain.Screen.clearScreen();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    LeftDriveSmart.spin(forward, Controller1.Axis3.position() + Controller1.Axis4.position(), pct);
    RightDriveSmart.spin(forward, Controller1.Axis3.position() - Controller1.Axis4.position(), pct);

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
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
