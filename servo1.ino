#include <Servo.h> // This is for using servo motors

Servo myservo; // Create servo object to control a servo
int pos = 0;   // Variable to store the servo position, it's just an integer

void setup()
{
    myservo.attach(10); // Attach the servo on pin 10, that's where it's connected
    Serial.begin(9600); // Start serial communication at 9600 baud rate

    myservo.write(0); // Set the servo to 0 degrees initially

    while (!Serial)
    {
        delay(1000); // Wait for the serial to be ready, just in case
    }

    Serial.println("Serial UP!\n"); // Just printing that serial is ready
}

void loop()
{
    // servo 01 - start from 0 turning 90 in 1 deg turns
    for (pos = 0; pos <= 90; pos += 1)
    {                                          // Looping from 0 to 90 degrees
        myservo.write(pos);                    // Move the servo
        Serial.println("\nMy servo 01" + pos); // Print the position for servo 01
        delay(100);                            // Wait for a bit
    }

    delay(500); // Another small delay
    for (pos = 90; pos >= 0; pos -= 10)
    {                       // Now the servo moves from 90 down to 0, in steps of 10
        myservo.write(pos); // Move the servo
        delay(100);         // Wait for a bit
    }
}