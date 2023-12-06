// Archivo: pin_config.h
#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H


// ! ||--------------------------------------------------------------------------------||
// ! ||                             Definiciones de pines                              ||
// ! ||--------------------------------------------------------------------------------||

/*
 *   Nomenclatura:
 *   ____________ + ____________ + ____________
 *   ^              ^              ^
 *   Front/Back     Left/Right     Arm/Wrist/Shoulder
 */

const int fRArm = 13;           //
const int fRWrist = 11;         //
const int fRShoulder = 8;       //         FRONT SERVOS
const int fLArm = 7;            //  
const int fLWrist = 5;          //
const int fLShoulder = 3;       //

const int rRArm = 12;           //
const int rRWrist = 10;         //
const int rRShoulder = 9;       //          REAR SERVOS
const int rLArm = 5;            //         
const int rLWrist = 6;          //
const int rLShoulder = 7;       //


// ! ||--------------------------------------------------------------------------------||
// ! ||                             Declaracion de objetos                             ||
// ! ||--------------------------------------------------------------------------------||


Servo sRLArm;
Servo sRLWrist;
Servo sRLShoulder;

#endif // PIN_CONFIG_H