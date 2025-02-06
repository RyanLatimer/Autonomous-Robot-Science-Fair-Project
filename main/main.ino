const int controlRight = 6;
const int controlLeft = 5;
const int trigPin = 9;
const int echoPin = 10;

void start() {
  digitalWrite(controlRight, HIGH);
  digitalWrite(controlLeft, HIGH);
}

void stop() {
  digitalWrite(controlRight, LOW);
  digitalWrite(controlLeft, LOW);
}

int measure() {
  long duration;
  int distance;

  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  return distance;
}

void setup() {
  pinMode(controlRight, OUTPUT);
  pinMode(controlLeft, OUTPUT);

  digitalWrite(controlRight, LOW);
  digitalWrite(controlLeft, LOW);

  Serial.begin(9600); // Start serial communication at 9600 baud
  pinMode(trigPin, OUTPUT); // Set trigPin as an output
  pinMode(echoPin, INPUT);  // Set echoPin as an input
}

void loop() {
  if (measure() > 10) {
    start();
  } else {
    stop();
  }
}