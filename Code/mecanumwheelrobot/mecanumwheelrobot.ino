#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(2, 3);

Servo ballHolderServo;
Servo ballArmServo;
Servo gripperServo;

#define FL_IN1 4
#define FL_IN2 5
#define FR_IN1 6
#define FR_IN2 7

#define BL_IN1 A0
#define BL_IN2 A1
#define BR_IN1 A2
#define BR_IN2 A3

const int HOLDER_LOAD   = 0;
const int HOLDER_UNLOAD = 70;

const int ARM_DOWN = 6;
const int ARM_UP   = 100;

const int GRIP_CLOSE = 0;
const int GRIP_OPEN  = 30;

int currentHolder = HOLDER_LOAD;
int currentArm    = ARM_DOWN;
int currentGrip   = GRIP_CLOSE;

void setup() {
  pinMode(FL_IN1, OUTPUT); pinMode(FL_IN2, OUTPUT);
  pinMode(FR_IN1, OUTPUT); pinMode(FR_IN2, OUTPUT);
  pinMode(BL_IN1, OUTPUT); pinMode(BL_IN2, OUTPUT);
  pinMode(BR_IN1, OUTPUT); pinMode(BR_IN2, OUTPUT);

  stopMotors();

  ballHolderServo.attach(9);
  ballArmServo.attach(10);
  gripperServo.attach(11);

  ballHolderServo.write(HOLDER_LOAD);
  ballArmServo.write(ARM_DOWN);
  gripperServo.write(GRIP_CLOSE);

  bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Mecanum Robot Ready - Directions Updated per Table");
  Serial.println("Movement: F B L R S G H I J X Y");
  Serial.println("Other:    C O U D M N");
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();
    Serial.print("Cmd: "); Serial.println(command);

    switch (command) {
      case 'F': moveForward();   break;
      case 'B': moveBackward();  break;
      case 'L': strafeLeft();    break;
      case 'R': strafeRight();   break;
      case 'S': stopMotors();    break;

      case 'G': diagonalFrontLeft();  break; 
      case 'H': diagonalFrontRight(); break; 
      case 'I': diagonalBackLeft();   break; 
      case 'J': diagonalBackRight();  break; 

      case 'X': rotateClockwise();        break;
      case 'Y': rotateCounterClockwise(); break;

      case 'C': setGripper(GRIP_CLOSE); break;
      case 'O': setGripper(GRIP_OPEN);  break;

      case 'U': moveArmTo(ARM_UP);   break;
      case 'D': moveArmTo(ARM_DOWN); break;

      case 'M': setBallHolder(HOLDER_LOAD);   break;
      case 'N': setBallHolder(HOLDER_UNLOAD); break;
    }
  }
}

void moveForward() {
  digitalWrite(FL_IN1, HIGH); digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, HIGH); digitalWrite(FR_IN2, LOW);
  digitalWrite(BL_IN1, HIGH); digitalWrite(BL_IN2, LOW);
  digitalWrite(BR_IN1, HIGH); digitalWrite(BR_IN2, LOW);
}

void moveBackward() {
  digitalWrite(FL_IN1, LOW);  digitalWrite(FL_IN2, HIGH);
  digitalWrite(FR_IN1, LOW);  digitalWrite(FR_IN2, HIGH);
  digitalWrite(BL_IN1, LOW);  digitalWrite(BL_IN2, HIGH);
  digitalWrite(BR_IN1, LOW);  digitalWrite(BR_IN2, HIGH);
}

void strafeLeft() {
  digitalWrite(FL_IN1, LOW);  digitalWrite(FL_IN2, HIGH);
  digitalWrite(FR_IN1, HIGH); digitalWrite(FR_IN2, LOW);
  digitalWrite(BL_IN1, HIGH); digitalWrite(BL_IN2, LOW);
  digitalWrite(BR_IN1, LOW);  digitalWrite(BR_IN2, HIGH);
}

void strafeRight() {
  digitalWrite(FL_IN1, HIGH); digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, LOW);  digitalWrite(FR_IN2, HIGH);
  digitalWrite(BL_IN1, LOW);  digitalWrite(BL_IN2, HIGH);
  digitalWrite(BR_IN1, HIGH); digitalWrite(BR_IN2, LOW);
}

void diagonalFrontLeft() {
  digitalWrite(FL_IN1, HIGH); digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, LOW);  digitalWrite(FR_IN2, LOW);
  digitalWrite(BL_IN1, LOW);  digitalWrite(BL_IN2, LOW);
  digitalWrite(BR_IN1, HIGH); digitalWrite(BR_IN2, LOW);
}

void diagonalFrontRight() {
  digitalWrite(FL_IN1, LOW);  digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, HIGH); digitalWrite(FR_IN2, LOW);
  digitalWrite(BL_IN1, HIGH); digitalWrite(BL_IN2, LOW);
  digitalWrite(BR_IN1, LOW);  digitalWrite(BR_IN2, LOW);
}

void diagonalBackLeft() {
  digitalWrite(FL_IN1, LOW);  digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, LOW);  digitalWrite(FR_IN2, LOW);
  digitalWrite(BL_IN1, HIGH); digitalWrite(BL_IN2, LOW);
  digitalWrite(BR_IN1, LOW);  digitalWrite(BR_IN2, HIGH);
}

void diagonalBackRight() {
  digitalWrite(FL_IN1, HIGH); digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, LOW);  digitalWrite(FR_IN2, HIGH);
  digitalWrite(BL_IN1, LOW);  digitalWrite(BL_IN2, LOW);
  digitalWrite(BR_IN1, LOW);  digitalWrite(BR_IN2, LOW);
}

void rotateClockwise() {
  digitalWrite(FL_IN1, HIGH); digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, LOW);  digitalWrite(FR_IN2, HIGH);
  digitalWrite(BL_IN1, HIGH); digitalWrite(BL_IN2, LOW);
  digitalWrite(BR_IN1, LOW);  digitalWrite(BR_IN2, HIGH);
}

void rotateCounterClockwise() {
  digitalWrite(FL_IN1, LOW);  digitalWrite(FL_IN2, HIGH);
  digitalWrite(FR_IN1, HIGH); digitalWrite(FR_IN2, LOW);
  digitalWrite(BL_IN1, LOW);  digitalWrite(BL_IN2, HIGH);
  digitalWrite(BR_IN1, HIGH); digitalWrite(BR_IN2, LOW);
}

void stopMotors() {
  digitalWrite(FL_IN1, LOW); digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, LOW); digitalWrite(FR_IN2, LOW);
  digitalWrite(BL_IN1, LOW); digitalWrite(BL_IN2, LOW);
  digitalWrite(BR_IN1, LOW); digitalWrite(BR_IN2, LOW);
}

void setBallHolder(int target) {
  if (target == currentHolder) return;
  ballHolderServo.write(target);
  currentHolder = target;
  delay(300);
}

void setGripper(int target) {
  if (target == currentGrip) return;
  gripperServo.write(target);
  currentGrip = target;
  delay(300);
}

void moveArmTo(int target) {
  if (target == currentArm) return;

  int start = currentArm;
  int step = (target > start) ? 1 : -1;
  int delayMs = 30;

  for (int pos = start; pos != target; pos += step) {
    ballArmServo.write(pos);
    delay(delayMs);
  }
  ballArmServo.write(target);
  currentArm = target;
}