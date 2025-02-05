// Define global constants
const int rightMotorPin = 6;
const int leftMotorPin = 15;

// All the stuff containing the motor class
class Motor {
public:
    Motor(int pin); // Constructor declaration
    void begin();
    void on();
    void off();
    void setSpeed(int speed);

private:
    int motorPin;
    int motorSpeed;
};

// Motor class constructor
Motor::Motor(int pin) : motorPin(pin), motorSpeed(0) {}

// Initialize the motor
void Motor::begin() {
    pinMode(motorPin, OUTPUT);
    digitalWrite(motorPin, LOW);
}

// Turn the motor on
void Motor::on() {
    digitalWrite(motorPin, HIGH);
}

// Turn the motor off
void Motor::off() {
    digitalWrite(motorPin, LOW);
}

// Set the motor speed
void Motor::setSpeed(int speed) {
    motorSpeed = speed;
    analogWrite(motorPin, motorSpeed);
}

// Initialize the instance of left and right motor

Motor leftMotor(leftMotorPin);
Motor rightMotor(rightMotorPin);

void setup() {
  // Begin Serial Connection
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for Serial Connection to be established
  }
  Serial.println("Serial Port Connection Established");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);

}

void loop() {
  digitalWrite(rightMotorPin, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(rightMotorPin, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  Serial.println("One Run Has been Completed");
}
