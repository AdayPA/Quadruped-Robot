#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "/home/adaypa/Programming/RobotDog/src/librerias.h"
#include "/home/adaypa/Programming/RobotDog/src/pin_config.h"

void moveServos2(int pos_s1, int pos_s2, Servo servo1, Servo servo2, int vel);
void moveServos3(int pos_s1, int pos_s2, int pos_s3, Servo servo1, Servo servo2, Servo servo3, int vel);
void moveServos2Millis(int pos_s1, int pos_s2, Servo &servo1, Servo &servo2, int vel, unsigned long &previousMillis);
void moveServos3Millis(int pos_s1, int pos_s2, int pos_s3, Servo &servo1, Servo &servo2, Servo &servo3, int vel, unsigned long &previousMillis);
void moveRL(int delay_, int speed);
void moveRR(int delay_, int speed);
void moveFR(int delay_, int speed);


void moveRRMillis(int delay_, int speed, unsigned long prevInterval, const long intervalFunc);
void moveFRMiliis(int delay_, int speed, unsigned long prevInterval, const long intervalFunc);

void moveServosTest(int pos_s1, int pos_s2, Servo servo1, Servo servo2, int vel);
void moveServosRecursive(int pos_s1, int pos_s2, Servo servo1, Servo servo2, int vel);

void attachServos();
void standUp();


#endif