ErrorData errorData() {

  ErrorData errorVal;

  int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
  int ax, bx, cx, dx, ex, fx, gx, hx, ix, jx, kx, lx, mx, nx, ox, px;

  sensorValue[15] = !digitalRead(sensor[15]);  //paling kiri
  sensorValue[14] = !digitalRead(sensor[14]);
  sensorValue[13] = !digitalRead(sensor[13]);
  sensorValue[12] = !digitalRead(sensor[12]);
  sensorValue[11] = !digitalRead(sensor[11]);
  sensorValue[10] = !digitalRead(sensor[10]);
  sensorValue[9] = !digitalRead(sensor[9]);
  sensorValue[8] = !digitalRead(sensor[8]);
  sensorValue[7] = !digitalRead(sensor[7]);
  sensorValue[6] = !digitalRead(sensor[6]);
  sensorValue[5] = !digitalRead(sensor[5]);
  sensorValue[4] = !digitalRead(sensor[4]);
  sensorValue[3] = !digitalRead(sensor[3]);
  sensorValue[2] = !digitalRead(sensor[2]);
  sensorValue[1] = !digitalRead(sensor[1]);
  sensorValue[0] = !digitalRead(sensor[0]);  // paling kanan
  if (sensorValue[15] == H) {
    a = 1;
    ax = 1;
  }
  if (sensorValue[14] == H) {
    b = 2;
    bx = 1;
  }
  if (sensorValue[13] == H) {
    c = 3;
    cx = 1;
  }
  if (sensorValue[12] == H) {
    d = 4;
    dx = 1;
  }
  if (sensorValue[11] == H) {
    e = 5;
    ex = 1;
  }
  if (sensorValue[10] == H) {
    f = 6;
    fx = 1;
  }
  if (sensorValue[9] == H) {
    g = 7;
    gx = 1;
  }
  if (sensorValue[8] == H) {
    h = 8;
    hx = 1;
  }
  if (sensorValue[7] == H) {
    i = 9;
    ix = 1;
  }
  if (sensorValue[6] == H) {
    j = 10;
    jx = 1;
  }
  if (sensorValue[5] == H) {
    k = 11;
    kx = 1;
  }
  if (sensorValue[4] == H) {
    l = 12;
    lx = 1;
  }
  if (sensorValue[3] == H) {
    m = 13;
    mx = 1;
  }
  if (sensorValue[2] == H) {
    n = 14;
    nx = 1;
  }
  if (sensorValue[1] == H) {
    o = 15;
    ox = 1;
  }
  if (sensorValue[0] == H) {
    p = 16;
    px = 1;
  }
  if (sensorValue[15] == L) {
    a = 0;
    ax = 0;
  }
  if (sensorValue[14] == L) {
    b = 0;
    bx = 0;
  }
  if (sensorValue[13] == L) {
    c = 0;
    cx = 0;
  }
  if (sensorValue[12] == L) {
    d = 0;
    dx = 0;
  }
  if (sensorValue[11] == L) {
    e = 0;
    ex = 0;
  }
  if (sensorValue[10] == L) {
    f = 0;
    fx = 0;
  }
  if (sensorValue[9] == L) {
    g = 0;
    gx = 0;
  }
  if (sensorValue[8] == L) {
    h = 0;
    hx = 0;
  }
  if (sensorValue[7] == L) {
    i = 0;
    ix = 0;
  }
  if (sensorValue[6] == L) {
    j = 0;
    jx = 0;
  }
  if (sensorValue[5] == L) {
    k = 0;
    kx = 0;
  }
  if (sensorValue[4] == L) {
    l = 0;
    lx = 0;
  }
  if (sensorValue[3] == L) {
    m = 0;
    mx = 0;
  }
  if (sensorValue[2] == L) {
    n = 0;
    nx = 0;
  }
  if (sensorValue[1] == L) {
    o = 0;
    ox = 0;
  }
  if (sensorValue[0] == L) {
    p = 0;
    px = 0;
  }
  //  float errorResult = (a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p) / (ax + bx + cx + dx + ex + fx + gx + hx + ix + jx + kx + lx + mx + nx + ox + px);
  //  Serial.println(errorResult);

  errorVal.error = (a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p) / (ax + bx + cx + dx + ex + fx + gx + hx + ix + jx + kx + lx + mx + nx + ox + px);

  float fltLeftSideError = (a + b + c + d + e + f + g + h) / (ax + ax + cx + dx + ex + fx + gx + hx);
  float fltLeftSideChecker = (ax + ax + cx + dx + ex + fx + gx + hx);

  float fltRightSideError = (i + j + k + l + m + n + o + p) / (ix + jx + kx + lx + mx + nx + ox + px);
  float fltRightSideChecker = (ix + jx + kx + lx + mx + nx + ox + px);

  if (fltLeftSideChecker > 0) {
    errorVal.leftSideError = fltLeftSideError;
  } else {
    errorVal.leftSideError = fltRightSideError;
  }

  if (fltRightSideChecker > 0) {
    errorVal.rightSideError = fltRightSideError;
  } else {
    errorVal.rightSideError = fltLeftSideError;
  }

  return errorVal;
}
