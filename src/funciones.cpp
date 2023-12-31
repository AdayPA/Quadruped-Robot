#include "funciones.h"


void moveServos2(int pos_s1, int pos_s2, Servo servo1, Servo servo2, int vel)
{
    int servo1_delta = pos_s1 - servo1.read();
    int servo2_delta = pos_s2 - servo2.read();
    float servo1_increment = servo1_delta > 0 ? 1.0 : -1.0;
    float servo2_increment = servo2_delta > 0 ? 1.0 : -1.0;

    while (servo1.read() != pos_s1 || servo2.read() != pos_s2)
    {
        if (servo1.read() != pos_s1)
        {
            servo1.write(servo1.read() + servo1_increment);
        }

        if (servo2.read() != pos_s2)
        {
            servo2.write(servo2.read() + servo2_increment);
        }

        delay(vel);
    }
}

void moveServos3(int pos_s1, int pos_s2, int pos_s3, Servo servo1, Servo servo2, Servo servo3, int vel)
{
    int servo1_delta = pos_s1 - servo1.read();
    int servo2_delta = pos_s2 - servo2.read();
    int servo3_delta = pos_s3 - servo3.read();

    float servo1_increment = servo1_delta > 0 ? 1.0 : -1.0;
    float servo2_increment = servo2_delta > 0 ? 1.0 : -1.0;
    float servo3_increment = servo3_delta > 0 ? 1.0 : -1.0;

    while (servo1.read() != pos_s1 || servo2.read() != pos_s2 || servo3.read() != pos_s3)
    {
        if (servo1.read() != pos_s1)
        {
            servo1.write(servo1.read() + servo1_increment);
        }

        if (servo2.read() != pos_s2)
        {
            servo2.write(servo2.read() + servo2_increment);
        }

        if (servo3.read() != pos_s3)
        {
            servo3.write(servo3.read() + servo3_increment);
        }

        delay(vel);
    }
}

void moveServos2Millis(int pos_s1, int pos_s2, Servo &servo1, Servo &servo2, int vel, unsigned long &previousMillis)
{
    int servo1_delta = pos_s1 - servo1.read();
    int servo2_delta = pos_s2 - servo2.read();
    float servo1_increment = servo1_delta > 0 ? 1.0 : -1.0;
    float servo2_increment = servo2_delta > 0 ? 1.0 : -1.0;

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= vel)

    {
        previousMillis = currentMillis;

        if (servo1.read() != pos_s1)
        {
            servo1.write(servo1.read() + servo1_increment);
        }

        if (servo2.read() != pos_s2)
        {
            servo2.write(servo2.read() + servo2_increment);
        }
    }
}

void moveServos3Millis(int pos_s1, int pos_s2, int pos_s3, Servo &servo1, Servo &servo2, Servo &servo3, int vel, unsigned long &previousMillis)
{
    int servo1_delta = pos_s1 - servo1.read();
    int servo2_delta = pos_s2 - servo2.read();
    int servo3_delta = pos_s3 - servo3.read();

    float servo1_increment = servo1_delta > 0 ? 1.0 : -1.0;
    float servo2_increment = servo2_delta > 0 ? 1.0 : -1.0;
    float servo3_increment = servo3_delta > 0 ? 1.0 : -1.0;

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= vel)
    {
        previousMillis = currentMillis;

        if (servo1.read() != pos_s1)
        {
            servo1.write(servo1.read() + servo1_increment);
        }

        if (servo2.read() != pos_s2)
        {
            servo2.write(servo2.read() + servo2_increment);
        }

        if (servo3.read() != pos_s3)
        {
            servo3.write(servo3.read() + servo3_increment);
        }
    }
}

void moveRL( int delay_, int speed) {
  moveServos2(81,116,sRLArm,sRLWrist,speed);
  delay(delay_);
  moveServos2(73,141,sRLArm,sRLWrist,speed);
  delay(delay_);
  moveServos2(86,160,sRLArm,sRLWrist,speed);
  delay(delay_);
  moveServos2(87,180,sRLArm,sRLWrist,speed);
  delay(delay_);
  moveServos2(35,180,sRLArm,sRLWrist,speed);
  delay(delay_);
  moveServos2(35,133,sRLArm,sRLWrist,speed);
  delay(delay_);
  moveServos2(56,112,sRLArm,sRLWrist,speed);
}

void moveRR( int delay_, int speed) {
  moveServos2(125,40,sRRArm,sRRWrist,speed);
  delay(delay_);
  moveServos2(110,20,sRRArm,sRRWrist,speed);
  delay(delay_);
  moveServos2(160,0,sRRArm,sRRWrist,speed);
  delay(delay_);
  moveServos2(160,50,sRRArm,sRRWrist,speed);
  delay(delay_);
  moveServos2(102,80,sRRArm,sRRWrist,speed);
  delay(delay_);
}

void moveFR( int delay_, int speed) {
  moveServos2(125,40,sFRArm,sFRWrist,speed);
  delay(delay_);
  moveServos2(110,20,sFRArm,sFRWrist,speed);
  delay(delay_);
  moveServos2(160,0,sFRArm,sFRWrist,speed);
  delay(delay_);
  moveServos2(160,50,sFRArm,sFRWrist,speed);
  delay(delay_);
  moveServos2(102,80,sFRArm,sFRWrist,speed);
  delay(delay_);
}

void moveServos(int pos[], Servo servos[], int numServos, int vel)
{
    float increments[numServos];

    for (int i = 0; i < numServos; ++i)
    {
        int delta = pos[i] - servos[i].read();
        increments[i] = delta > 0 ? 1.0 : -1.0;
    }

    bool anyServoMoving = true;

    while (anyServoMoving)
    {
        anyServoMoving = false;

        for (int i = 0; i < numServos; ++i)
        {
            if (servos[i].read() != pos[i])
            {
                servos[i].write(servos[i].read() + increments[i]);
                anyServoMoving = true;
            }
        }

        delay(vel);
    }
}

void attachServos() {
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

void standUp() {
    sRLShoulder.write(85);
    sRRShoulder.write(100);
    sFLShoulder.write(105);
    sFRShoulder.write(85);
    sRRArm.write(60);
    sRRWrist.write(80);
    sFRArm.write(60);
    sFRWrist.write(80);
    sRLWrist.write(120);
    sRLArm.write(130);
    sFLWrist.write(120);
    sFLArm.write(100);
}
