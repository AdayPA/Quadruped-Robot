#include "/home/adaypa/Programming/RobotDog/src/funciones.cpp"

String readString;

void setup()
{
    Serial.begin(115200);
    attachServos();
    standUp();

}

void loop()
{
    while (Serial.available()) {
        char c = Serial.read();  //gets one byte from serial buffer
        readString += c; //makes the string readString
        delay(2);  //slow looping to allow buffer to fill with next character
    }

    if (readString.length() >0) {
        Serial.println(readString);  //so you can see the captured string 
        int n = readString.toInt();  //convert readString into a number

        // auto select appropriate value, copied from someone elses code.
        if(n >= 500)
        {
        Serial.print("writing Microseconds: ");
        Serial.println(n);
        sFRArm.writeMicroseconds(n);
        }
        else
        {   
        Serial.print("writing Angle: ");
        Serial.println(n);
        sFRArm.write(n);
        }
        readString=""; //empty for next input
    } 
}