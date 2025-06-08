// Define the pins for the DC motors
// Motor 1 (Left Motor) control pins
const int motor1Input1 = 7;
const int motor1Input2 = 6;

// Motor 2 (Right Motor) control pins
const int motor2Input1 = 5;
const int motor2Input2 = 4;

const int motor2Input12 = 12; // An extra pin used

// If you are controlling ENA/ENB for speed or on/off, uncomment and define them.
// Otherwise, ensure the jumpers are on the L298N board for full speed.
// const int enablePinA = 9; // For L298N ENA
// const int enablePinB = 10; // For L298N ENB

void setup() {
  // Set all motor control pins as OUTPUTs
  pinMode(motor1Input1, OUTPUT);
  pinMode(motor1Input2, OUTPUT);
  pinMode(motor2Input1, OUTPUT);
  pinMode(motor2Input2, OUTPUT);
  pinMode(12, OUTPUT);

  // Spin both motors forward constantly
  // Motor 1 (Left Motor)
  digitalWrite(motor1Input1, HIGH);
  digitalWrite(motor1Input2, LOW);

  // Motor 2 (Right Motor)
  digitalWrite(motor2Input1, HIGH);
  digitalWrite(motor2Input2, LOW);

  Serial.begin(9600); // Starting serial communication
  Serial.println("Motors are now spinning constantly...");
}

void loop() {
  // Motors run continuously from setup().
  digitalWrite(12,HIGH); // Setting this pin HIGH.
}
