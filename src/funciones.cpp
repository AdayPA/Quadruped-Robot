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

void moveRL(Servo &sRLArm, Servo &sRLWrist, int delay_, int speed) {
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