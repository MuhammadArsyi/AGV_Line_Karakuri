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
      digitalWrite(brake, HIGH);
      digitalWrite(dira, HIGH);
      analogWrite(pwma, spd);
    } else if (reverse == 1) {
      digitalWrite(brake, HIGH);
      digitalWrite(dira, LOW);
      analogWrite(pwma, spd);
    }
  } else /*if (i == RIGHT) //no need for condition*/ {
    if (reverse == 0) {
      digitalWrite(brake, HIGH);
      digitalWrite(dirb, LOW);
      analogWrite(pwmb, spd);
    } else if (reverse == 1) {
      digitalWrite(brake, HIGH);
      digitalWrite(dirb, HIGH);
      analogWrite(dirb, spd);
    }
  }
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  setMotorSpeed(LEFT, leftSpeed);
  setMotorSpeed(RIGHT, rightSpeed);
}