#include <Servo.h> // This is for using servo motors

Servo myservo;  // Create servo object to control a servo
Servo myservo2; // This is for the second servo
int pos = 0;    // Variable to store the servo position, it's just an integer

void setup()
{
  myservo.attach(11);  // Attach the servo on pin 11, that's where it's connected
  myservo2.attach(10); // Attach the second servo on pin 10
  Serial.begin(9600);  // Start serial communication at 9600 baud rate

  myservo.write(0);  // Set the first servo to 0 degrees initially
  myservo2.write(0); // Set the second servo to 0 degrees initially

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
  {                                        // Looping from 0 to 90 degrees
    myservo.write(pos);                    // Move the first servo
    Serial.println("\nMy servo 01" + pos); // Print the position for servo 01
    delay(100);                            // Wait for a bit, 100 milliseconds
  }

  // servo 02 - start from 0 turning 90 in 1 deg turns
  delay(1000); // Just a little delay before the next action
  for (pos = 0; pos <= 90; pos += 1)
  {                                        // Looping from 0 to 90 degrees again
    myservo2.write(pos);                   // Move the second servo
    Serial.println("\nMy servo 02" + pos); // Print the position for servo 02
    delay(100);                            // Wait for a bit, 100 milliseconds
  }

  // Both  - start from 90 turning to 0 in 10 deg turns

  delay(500); // Another small delay
  for (pos = 90; pos >= 0; pos -= 10)
  {                      // Now both move from 90 down to 0, in steps of 10
    myservo.write(pos);  // Move the first servo
    myservo2.write(pos); // Move the second servo too
    delay(100);          // Wait for a bit, 100 milliseconds
  }
}