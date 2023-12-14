#include "/home/adaypa/Programming/RobotDog/src/funciones.cpp"
#include "/home/adaypa/Programming/RobotDog/src/pin_config.h"

int delay_ = 5;
int speed = 20;

void setup() {
// ! ||--------------------------------------------------------------------------------||
// ! ||                                    Servo attach                                ||
// ! ||--------------------------------------------------------------------------------||
  sRLArm.attach(rLArm);
  sRLWrist.attach(rLWrist);
  sRLShoulder.attach(rLShoulder);
  sRRArm.attach(rRArm);
  sRRWrist.attach(rRWrist);
  sRRShoulder.attach(rRShoulder);

  sFLArm.attach(fLArm);
  sFLWrist.attach(fLWrist);
  sFLShoulder.attach(fLShoulder);
  sFRArm.attach(fRArm);
  sFRWrist.attach(fRWrist);
  sFRShoulder.attach(fRShoulder);
}

void loop() {
  moveRL(sRLArm,sRLWrist,delay_,speed);
}

/*
81.59978937660634        116.92766301978149
73.338522423467        141.52513353107213
86.06604337823569        160.42852932233336
87.88613930259771        200
35.50432720993205        190.36141597438956
35.50432720993205        133.6223638011749
56.648097576647665        112.15161442078205
*/