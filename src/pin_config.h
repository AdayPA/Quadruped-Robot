// Archivo: pin_config.h
#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include "/home/adaypa/Programming/RobotDog/src/librerias.h"

// ! ||--------------------------------------------------------------------------------||
// ! ||                             Definiciones de pines                              ||
// ! ||--------------------------------------------------------------------------------||

/*
 *   Nomenclatura:
 *   ____________ + ____________ + ____________
 *   ^              ^              ^
 *   Front/Back     Left/Right     Arm/Wrist/Shoulder
 */

const int fRArm = 4;            //
const int fRWrist = 5;          //
const int fRShoulder = 6;       //         FRONT SERVOS
const int fLArm = 2;            //  
const int fLWrist = A0;         //
const int fLShoulder = 3;       //

const int rRArm = 12;           //
const int rRWrist = 11;         //
const int rRShoulder = 10;      //          REAR SERVOS
const int rLArm = 9;            //         
const int rLWrist = 8;          //
const int rLShoulder = 7;       //


// ! ||--------------------------------------------------------------------------------||
// ! ||                             Declaracion de objetos                             ||
// ! ||--------------------------------------------------------------------------------||


Servo sRLArm;
Servo sRLWrist;
Servo sRLShoulder;
Servo sRRArm;
Servo sRRWrist;
Servo sRRShoulder;
Servo sFLArm;
Servo sFLWrist;
Servo sFLShoulder;
Servo sFRArm;
Servo sFRWrist;
Servo sFRShoulder;


// ! ||--------------------------------------------------------------------------------||
// ! ||                            Declaracion de variables                            ||
// ! ||--------------------------------------------------------------------------------||

int delay_;
int speed;


#endif // PIN_CONFIG_H