void setMotorSpeed(int i, int spd) {
  unsigned char reverse = 0;

  if (spd < 0) {
    spd = -spd;
    reverse = 1;
  }
  if (spd > 255)
    spd = 255;

  if (i == LEFT) {
    if (reverse == 0) {
      digitalWrite(BRAKE_MOTOR_LEFT, LOW);
      digitalWrite(DIRECTION_MOTOR_LEFT, LOW);
      analogWrite(PWM_MOTOR_LEFT, spd);
    } else if (reverse == 1) {
      digitalWrite(BRAKE_MOTOR_LEFT, LOW);
      digitalWrite(DIRECTION_MOTOR_LEFT, HIGH);
      analogWrite(PWM_MOTOR_LEFT, spd);
    }
  } else /*if (i == RIGHT) //no need for condition*/ {
    if (reverse == 0) {
      digitalWrite(BRAKE_MOTOR_RIGHT, LOW);
      digitalWrite(DIRECTION_MOTOR_RIGHT, LOW);
      analogWrite(PWM_MOTOR_RIGHT, spd);
    } else if (reverse == 1) {
      digitalWrite(BRAKE_MOTOR_RIGHT, LOW);
      digitalWrite(DIRECTION_MOTOR_RIGHT, HIGH);
      analogWrite(PWM_MOTOR_RIGHT, spd);
    }
  }
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  setMotorSpeed(LEFT, leftSpeed);
  setMotorSpeed(RIGHT, rightSpeed);
}