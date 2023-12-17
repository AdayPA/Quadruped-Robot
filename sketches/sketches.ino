#include "/home/adaypa/Programming/RobotDog/src/funciones.cpp"
#include "/home/adaypa/Programming/RobotDog/src/pin_config.h"

void setup() {
// ! ||--------------------------------------------------------------------------------||
// ! ||                                    Servo attach                                ||
// ! ||--------------------------------------------------------------------------------||

  sRRArm.attach(rRArm);
  sRRWrist.attach(rRWrist);
  sRRShoulder.attach(rRShoulder);

  sRLArm.attach(rLArm);
  sRLWrist.attach(rLWrist);
  sRLShoulder.attach(rLShoulder);

  sRRShoulder.write(105);
  sRRArm.write(125);
  sRRWrist.write(40);

  sRLShoulder.write(80);
  sRLArm.write(81);
  sRLWrist.write(116);
}

void loop() {
}