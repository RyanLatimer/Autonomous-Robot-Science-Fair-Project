// Define motor control pins
const int leftMotorForwardPin = 14;
const int leftMotorReversePin = 15;
const int rightMotorForwardPin = 26;

// Define ultrasonic sensor pins
const int fTrigPin = 2;
const int fEchoPin = 1;
const int lTrigPin = 7;
const int lEchoPin = 6;
const int rTrigPin = 19;
const int rEchoPin = 18;

void setup() {
  // Initialize motors
  pinMode(leftMotorForwardPin, OUTPUT);
  pinMode(leftMotorReversePin, OUTPUT);
  pinMode(rightMotorForwardPin, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(fTrigPin, OUTPUT);
  pinMode(fEchoPin, INPUT);
  pinMode(lTrigPin, OUTPUT);
  pinMode(lEchoPin, INPUT);
  pinMode(rTrigPin, OUTPUT);
  pinMode(rEchoPin, INPUT);

  // Start Serial communication
  Serial.begin(9600);
}

// Forward Distance Algorithm
float fUltra() {
  digitalWrite(fTrigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(fTrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(fTrigPin, LOW);

  unsigned long signaloff = pulseIn(fEchoPin, LOW);
  unsigned long signalon = pulseIn(fEchoPin, HIGH);

  unsigned long timepassed = signalon - signaloff;

  // Calculate distance
  float distance = (timepassed * 0.0343) / 2;
  Serial.print("Distance ahead: ");
  Serial.print(distance);
  Serial.print(" cm");
  
  return distance;
}

// Left Distance Algorithm
float lUltra() {
  digitalWrite(lTrigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(lTrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(lTrigPin, LOW);

  unsigned long signaloff = pulseIn(lEchoPin, LOW);
  unsigned long signalon = pulseIn(lEchoPin, HIGH);

  unsigned long timepassed = signalon - signaloff;

  // Calculate distance
  float distance = (timepassed * 0.0343) / 2;
  Serial.print("Distance to the Left: ");
  Serial.print(distance);
  Serial.print(" cm");
  
  return distance;
}

// Right Distance Algorithm
float rUltra() {
  digitalWrite(rTrigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(rTrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(rTrigPin, LOW);

  unsigned long signaloff = pulseIn(rEchoPin, LOW);
  unsigned long signalon = pulseIn(rEchoPin, HIGH);

  unsigned long timepassed = signalon - signaloff;

  // Calculate distance
  float distance = (timepassed * 0.0343) / 2;
  Serial.print("Distance to the Right: ");
  Serial.print(distance);
  Serial.print(" cm");

  return distance;
}

// Control Methods
void stop() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
}

void forward() {
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, HIGH);
  delay(100);
}

void rotateLeft() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorReversePin, HIGH);
  digitalWrite(rightMotorForwardPin, HIGH);
  delay(500);  // Adjust time for 90 degree rotation
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
}

void rotateRight() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorReversePin, HIGH);
  digitalWrite(rightMotorForwardPin, HIGH);
  delay(1000);  // Adjust time for 270 degree rotation
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
}

// Main detection and control loop
void detectDistance() {
  float fDistance = fUltra();
  float lDistance = lUltra();
  float rDistance = rUltra();

  delay(5); // Short delay to allow sensor readings to settle

  if (fDistance > 2) {
    forward();
  } else if (fDistance <= 2) {  // Maybe this should be larger
    stop();
    if (lDistance > rDistance) {
      rotateLeft();
    } else if (rDistance > lDistance) {
      rotateRight();
    } else {
      Serial.println("Error in Comparing Left and Right Distance Sensors");
    }
  } else {
    Serial.println("Error in comparing forward distance to 2cm");
  }
}

void loop() {
  detectDistance();
}
