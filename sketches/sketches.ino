#include "/home/adaypa/Programming/RobotDog/src/funciones.cpp"
#include "/home/adaypa/Programming/RobotDog/src/pin_config.h"


void setup() {
// ! ||--------------------------------------------------------------------------------||
// ! ||                                    Servo attach                                ||
// ! ||--------------------------------------------------------------------------------||

  sRRArm.attach(rRArm);
  sRRWrist.attach(rRWrist);
  sRRShoulder.attach(rRShoulder);

  sRRShoulder.write(105);
  sRRArm.write(120);
  sRRWrist.write(40);

}

void loop() {
  moveRR(100,40);
}