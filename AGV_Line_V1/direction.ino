void bebasGerak() {
  digitalWrite(brake, HIGH);
  delay(20);
}

void stopRotateLeft() {
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(500);
  digitalWrite(brake, HIGH);
  digitalWrite(dira, HIGH);  //kanan
  digitalWrite(dirb, HIGH);  //kiri
  analogWrite(pwma, 30);
  analogWrite(pwmb, 30);
  delay(1500);
  emergency = digitalRead(es1);
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  while (sensorValue[7] == L && sensorValue[10] == L && emergency == LOW) {  //colv = digitalRead(col);
    emergency = digitalRead(es1);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
    digitalWrite(dira, HIGH);  //kanan
    digitalWrite(dirb, HIGH);  //kiri
    analogWrite(pwma, 30);
    analogWrite(pwmb, 30);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
  }
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(500);
  digitalWrite(brake, HIGH);
  delay(500);
  // untuk jalan mundur
  // digitalWrite(brake, HIGH);
  // digitalWrite(dira, LOW);
  // digitalWrite(dirb, HIGH);
  // analogWrite(pwma, 30);
  // analogWrite(pwmb, 30);
  // delay(5000);
  // digitalWrite(brake, LOW);
  // analogWrite(pwma, 0);
  // analogWrite(pwmb, 0);
  // delay(2000);
  // digitalWrite(brake, HIGH);
  // delay(500);
  tandamillis = currentmillis;
  PID_total = 0;
  stopputerkiri = false;
}

void stopRotateRight() {
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  //////////////////////////////
  turun = digitalRead(ls1);
  naik = digitalRead(ls2);
  while (turun == HIGH) {
    turun = digitalRead(ls1);
    naik = digitalRead(ls2);
    digitalWrite(tractor, HIGH);
  }
  digitalWrite(tractor, LOW);
  //////////////////////////////
  delay(500);
  digitalWrite(brake, HIGH);
  digitalWrite(dira, LOW);  //kanan
  digitalWrite(dirb, LOW);  //kiri
  analogWrite(pwma, 30);
  analogWrite(pwmb, 30);
  delay(1500);
  emergency = digitalRead(es1);
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  while (sensorValue[7] == L && sensorValue[10] == L && emergency == LOW) {  //colv = digitalRead(col);
    emergency = digitalRead(es1);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
    digitalWrite(dira, LOW);  //kanan
    digitalWrite(dirb, LOW);  //kiri
    analogWrite(pwma, 30);
    analogWrite(pwmb, 30);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
  }
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  ////////////////////////////////////
  turun = digitalRead(ls1);
  naik = digitalRead(ls2);
  while (naik == HIGH) {
    turun = digitalRead(ls1);
    naik = digitalRead(ls2);
    digitalWrite(tractor, HIGH);
  }
  digitalWrite(tractor, LOW);
  ////////////////////////////////////
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(500);
  digitalWrite(brake, HIGH);
  delay(500);
  // untuk jalan mundur
  // digitalWrite(brake, HIGH);
  // digitalWrite(dira, LOW);
  // digitalWrite(dirb, HIGH);
  // analogWrite(pwma, 30);
  // analogWrite(pwmb, 30);
  // delay(5000);
  // digitalWrite(brake, LOW);
  // analogWrite(pwma, 0);
  // analogWrite(pwmb, 0);
  // delay(2000);
  // digitalWrite(brake, HIGH);
  // delay(500);
  tandamillis = currentmillis;
  PID_total = 0;
  stopputerkanan = false;
}

void stopBackward() {
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(2000);
  digitalWrite(brake, HIGH);
  digitalWrite(dira, LOW);
  digitalWrite(dirb, HIGH);
  analogWrite(pwma, 50);
  analogWrite(pwmb, 50);
  delay(7000);
  digitalWrite(dira, LOW);  //kanan
  digitalWrite(dirb, LOW);  //kiri
  analogWrite(pwma, 50);
  analogWrite(pwmb, 50);
  delay(1500);
  emergency = digitalRead(es1);
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  while (sensorValue[7] == L && sensorValue[10] == L && emergency == LOW) {  //colv = digitalRead(col);
    emergency = digitalRead(es1);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
    digitalWrite(dira, LOW);  //kanan
    digitalWrite(dirb, LOW);  //kiri
    delay(100);
    analogWrite(pwma, 50);
    analogWrite(pwmb, 50);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
  }
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  digitalWrite(brake, LOW);
  delay(1000);
  digitalWrite(brake, HIGH);
  delay(100);
  tandamillis = currentmillis;
  PID_total = 0;
  stopmundur = false;
}

void stopForever() {
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  // pwmbb = 0;
  // pwmaa = 0;
  delay(2000);
  digitalWrite(speaker, LOW);
  tandamillis = currentmillis;
  GO = false;
  PID_total = 0;
  delay(100);
}

void stopAwhile() {
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(10000);
  digitalWrite(brake, HIGH);
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);
  analogWrite(pwma, 100);
  analogWrite(pwmb, 100);
  delay(500);
  tandamillis = currentmillis;
  PID_total = 0;
  stopsementara = false;
}

void stopbySensor() {
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(2000);
  digitalWrite(brake, HIGH);
  delay(500);
  PID_total = 0;
  tandamillis = currentmillis;
}

void startGoing() {
  digitalWrite(brake, HIGH);
  delay(10);
  tandamillis = currentmillis;
  GO = true;
  digitalWrite(speaker, HIGH);
  // towingpleasenaik = true;
}

void startGoingSlowly() {
  digitalWrite(brake, HIGH);
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);
  analogWrite(pwma, 100);
  analogWrite(pwmb, 100);
  delay(2000);
  tandamillis = currentmillis;
  GO = true;
  digitalWrite(speaker, HIGH);
  stopseterusnya = false;
}

void tapeOffRight() {
  delay(300);
  digitalWrite(brake, LOW);
  digitalWrite(dira, LOW);
  digitalWrite(dirb, HIGH);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(500);
  digitalWrite(brake, HIGH);
  delay(100);
  // colv = digitalRead(col);
  emergency = digitalRead(es1);
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  while (sensorValue[7] == L && sensorValue[10] == L && emergency == LOW) {  //colv = digitalRead(col);
    emergency = digitalRead(es1);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
    digitalWrite(dira, LOW);  //kanan
    digitalWrite(dirb, LOW);  //kiri
    delay(20);
    analogWrite(pwma, 50);
    analogWrite(pwmb, 50);
  }
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  digitalWrite(brake, LOW);
  delay(500);
  digitalWrite(brake, HIGH);
  delay(100);
  PID_total = 0;
  tandamillis = currentmillis;
}

void tapeOffLeft() {
  delay(300);
  digitalWrite(brake, LOW);
  digitalWrite(dira, LOW);
  digitalWrite(dirb, HIGH);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(500);
  digitalWrite(brake, HIGH);
  delay(100);
  //colv = digitalRead(col);
  emergency = digitalRead(es1);
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  while (sensorValue[7] == L && sensorValue[10] == L && emergency == LOW) {  //colv = digitalRead(col);
    emergency = digitalRead(es1);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
    digitalWrite(dira, HIGH);  //kanan
    digitalWrite(dirb, HIGH);  //kiri
    delay(20);
    analogWrite(pwma, 50);
    analogWrite(pwmb, 50);
  }
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  digitalWrite(brake, LOW);
  delay(500);
  digitalWrite(brake, HIGH);
  delay(100);
  PID_total = 0;
  tandamillis = currentmillis;
}

void PriorityLeft() {
  digitalWrite(brake, HIGH);
  //    digitalWrite(enaa, HIGH);
  //    digitalWrite(enab, HIGH);
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);

  ErrorData errorVal = errorData();

  //    if (slowRun) {
  //      vt = 10;
  //    }

  vt = vt - ((abs(distanceError)) * (vt * 0.08));
  if (millis() > time + periodd) {
    time = millis();
    distanceError = setPointLeft - errorVal.leftSideError;
    PID_p = Kp * distanceError;
    PID_d = Kd * ((distanceError - previousDistanceError) / periodd);

    if (-1 < distanceError && distanceError < 1) {
      PID_i = PID_i + (Ki * distanceError);
    } else {
      PID_i = 0;
    }

    PID_total = PID_p + PID_i + PID_d;

    pwmaa = (vt + PID_total);
    pwmbb = (vt - PID_total);

    pwmaa = constrain(pwmaa, (vt - (vt * 0.3)), (vt + (vt * 0.3)));
    pwmbb = constrain(pwmbb, (vt - (vt * 0.3)), (vt + (vt * 0.3)));

    float vt_f = vt * 1.0;

    //      SerialPlotter(PID_total, vt_f, outPwmLeft, outPwmRight, distanceError);
    //110 - (110 * 0.3)


    analogWrite(pwmb, pwmbb);
    analogWrite(pwma, pwmaa);
    //(output, pwmValue)

    previousDistanceError = distanceError;
  }
  tandamillis = currentmillis;
}

void PriorityRight() {
  digitalWrite(brake, HIGH);
  //    digitalWrite(enaa, HIGH);
  //    digitalWrite(enab, HIGH);
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);

  ErrorData errorVal = errorData();

  //    if (pelan) {
  //      vt = 10;
  //    }

  vt = vt - ((abs(distanceError)) * (vt * 0.08));
  if (millis() > time + periodd) {
    time = millis();
    distanceError = setPointRight - errorVal.rightSideError;
    PID_p = Kp * distanceError;
    PID_d = Kd * ((distanceError - previousDistanceError) / periodd);

    if (-1 < distanceError && distanceError < 1) {
      PID_i = PID_i + (Ki * distanceError);
    } else {
      PID_i = 0;
    }

    PID_total = PID_p + PID_i + PID_d;

    pwmaa = (vt + PID_total);
    pwmbb = (vt - PID_total);

    pwmaa = constrain(pwmaa, (vt - (vt * 0.3)), (vt + (vt * 0.3)));
    pwmbb = constrain(pwmbb, (vt - (vt * 0.3)), (vt + (vt * 0.3)));

    float vt_f = vt * 1.0;

    //      SerialPlotter(PID_total, vt_f, pwmaa, pwmbb, distanceError);
    //110 - (110 * 0.3)

    analogWrite(pwmb, pwmbb);
    analogWrite(pwma, pwmaa);
    //(output, pwmValue)

    previousDistanceError = distanceError;
  }
  tandamillis = currentmillis;
}

void PriorityMiddle() {
  digitalWrite(brake, HIGH);
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);

  ErrorData errorValue = errorData();

  error = errorValue.error;
  vt = vt - ((abs(distanceError)) * (vt * 0.08));  //ini di comment
  if (millis() > time + periodd) {
    time = millis();
    distanceError = setPointLeft - error;
    PID_p = Kp * distanceError;
    PID_d = Kd * ((distanceError - previousDistanceError) / periodd);

    if (-1 < distanceError && distanceError < 1)  // ini +-1, program if else di tuker
    {
      PID_i = PID_i + (Ki * distanceError);
    } else {
      PID_i = 0;
    }

    PID_total = PID_p + PID_i + PID_d;

    pwmaa = (vt + PID_total);
    pwmbb = (vt - PID_total);

    pwmaa = constrain(pwmaa, (vt - (vt * 0.3)), (vt + (vt * 0.3)));
    pwmbb = constrain(pwmbb, (vt - (vt * 0.3)), (vt + (vt * 0.3)));

    /*
      pwmaa = constrain(pwmaa,0,255);
      pwmbb = constrain(pwmbb,0,255);
       */

    float vt_f = vt * 1.0;

    //      SerialPlotter(PID_total, vt_f, pwmaa, pwmbb, distanceError);
    //110 - (110 * 0.3)


    analogWrite(pwmb, pwmbb);
    analogWrite(pwma, pwmaa);
    //(output, pwmValue)

    previousDistanceError = distanceError;
  }
}

void PriorityMiddleBackward() {
  digitalWrite(brake, HIGH);
  digitalWrite(dira, LOW);
  digitalWrite(dirb, HIGH);

  ErrorData errorValue = errorData();

  error = errorValue.error;
  // vt = vt - ((abs(distanceError)) * (vt * 0.08));  //ini di comment
  if (millis() > time + periodd) {
    time = millis();
    distanceError = setPointLeft - error;
    PID_p = Ka * distanceError;
    PID_d = Kc * ((distanceError - previousDistanceError) / periodd);

    if (-1 < distanceError && distanceError < 1)  // ini +-1, program if else di tuker
    {
      PID_i = PID_i + (Kb * distanceError);
    } else {
      PID_i = 0;
    }

    PID_total = PID_p + PID_i + PID_d;

    pwmaa = (vt - PID_total);
    pwmbb = (vt + PID_total);

    // pwmaa = constrain(pwmaa, (vt - (vt * 0.3)), (vt + (vt * 0.3)));
    // pwmbb = constrain(pwmbb, (vt - (vt * 0.3)), (vt + (vt * 0.3)));

    pwmaa = constrain(pwmaa, 0, 255);
    pwmbb = constrain(pwmbb, 0, 255);


    float vt_f = vt * 1.0;

    //      SerialPlotter(PID_total, vt_f, pwmaa, pwmbb, distanceError);
    //110 - (110 * 0.3)


    analogWrite(pwmb, pwmbb);
    analogWrite(pwma, pwmaa);
    //(output, pwmValue)

    previousDistanceError = distanceError;
  }
}

void turnLeft() {
  // digitalWrite(brake, LOW);
  // analogWrite(pwma, 0);
  // analogWrite(pwmb, 0);
  // delay(500);
  digitalWrite(brake, HIGH);
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);
  analogWrite(pwma, 50);
  analogWrite(pwmb, 30);
  delay(2000);
  // digitalWrite(brake, LOW);
  // delay(500);
  // digitalWrite(brake, HIGH);
  // delay(100);
  tandamillis = currentmillis;
  PID_total = 0;
  prioritaskiri = false;
}

void turnRight() {
  // digitalWrite(brake, LOW);
  // analogWrite(pwma, 0);
  // analogWrite(pwmb, 0);
  // delay(500);
  digitalWrite(brake, HIGH);
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);
  analogWrite(pwma, 30);
  analogWrite(pwmb, 50);
  delay(2000);
  // digitalWrite(brake, LOW);
  // delay(500);
  // digitalWrite(brake, HIGH);
  // delay(100);
  tandamillis = currentmillis;
  PID_total = 0;
  prioritaskanan = false;
}

void gerakanStationA() {
  // stop kopel turun
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  //////////////////////////////
  turun = digitalRead(ls1);
  naik = digitalRead(ls2);
  while (turun == HIGH) {
    turun = digitalRead(ls1);
    naik = digitalRead(ls2);
    digitalWrite(tractor, HIGH);
  }
  digitalWrite(tractor, LOW);
  //////////////////////////////
  delay(2000);

  // mundur
  digitalWrite(brake, HIGH);
  digitalWrite(dira, LOW);
  digitalWrite(dirb, HIGH);
  analogWrite(pwma, 40);
  analogWrite(pwmb, 40);
  delay(5000);

  // rotasi
  digitalWrite(dira, LOW);  //kanan
  digitalWrite(dirb, LOW);  //kiri
  analogWrite(pwma, 30);
  analogWrite(pwmb, 30);
  delay(1500);
  emergency = digitalRead(es1);
  sensorValue[14] = !digitalRead(sensor[14]);
  sensorValue[16] = !digitalRead(sensor[16]);
  while (sensorValue[14] == L && sensorValue[16] == L && emergency == LOW) {  //colv = digitalRead(col);
    emergency = digitalRead(es1);
    sensorValue[14] = !digitalRead(sensor[14]);
    sensorValue[16] = !digitalRead(sensor[16]);
    digitalWrite(dira, LOW);  //kanan
    digitalWrite(dirb, LOW);  //kiri
    delay(100);
    analogWrite(pwma, 30);
    analogWrite(pwmb, 30);
    sensorValue[14] = !digitalRead(sensor[14]);
    sensorValue[16] = !digitalRead(sensor[16]);
  }
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  digitalWrite(brake, LOW);
  delay(1000);

  // mundur
  digitalWrite(brake, HIGH);
  digitalWrite(dira, LOW);
  digitalWrite(dirb, HIGH);
  analogWrite(pwma, 40);
  analogWrite(pwmb, 40);
  delay(6500);

  // stop kopel naik
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  ////////////////////////////////////
  turun = digitalRead(ls1);
  naik = digitalRead(ls2);
  while (naik == HIGH) {
    turun = digitalRead(ls1);
    naik = digitalRead(ls2);
    digitalWrite(tractor, HIGH);
  }
  digitalWrite(tractor, LOW);
  ////////////////////////////////////
  delay(2000);
  digitalWrite(brake, HIGH);
  delay(500);

  tandamillis = currentmillis;
  PID_total = 0;
  stopmundur = false;
}

void gerakanStationB() {
  digitalWrite(brake, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(2000);
  digitalWrite(brake, HIGH);
  digitalWrite(dira, LOW);
  digitalWrite(dirb, HIGH);
  analogWrite(pwma, 50);
  analogWrite(pwmb, 50);
  delay(7000);
  digitalWrite(dira, LOW);  //kanan
  digitalWrite(dirb, LOW);  //kiri
  analogWrite(pwma, 50);
  analogWrite(pwmb, 50);
  delay(1500);
  emergency = digitalRead(es1);
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[10] = !digitalRead(sensor[10]);
  while (sensorValue[7] == L && sensorValue[10] == L && emergency == LOW) {  //colv = digitalRead(col);
    emergency = digitalRead(es1);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
    digitalWrite(dira, LOW);  //kanan
    digitalWrite(dirb, LOW);  //kiri
    delay(100);
    analogWrite(pwma, 50);
    analogWrite(pwmb, 50);
    sensorValue[7] = !digitalRead(sensor[7]);
    sensorValue[10] = !digitalRead(sensor[10]);
  }
  digitalWrite(dira, HIGH);
  digitalWrite(dirb, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  digitalWrite(brake, LOW);
  delay(1000);
  digitalWrite(brake, HIGH);
  digitalWrite(dira, LOW);
  digitalWrite(dirb, HIGH);
  analogWrite(pwma, 50);
  analogWrite(pwmb, 50);
  delay(7000);
  tandamillis = currentmillis;
  PID_total = 0;
  stopmundur = false;
}
