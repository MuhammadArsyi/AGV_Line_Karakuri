const int pwma = 6;  //motor kiri
const int dira = 7;

const int pwmb = 9;  // motor kanan
const int dirb = 10;

const int ls1 = 26;
const int ls2 = 28;
const int brake = 38;
const int tractor = 40;
//const int relay = 44;
const int speaker = 46;
const int col = 48;
const int es1 = 50;
const int pb1 = 52;

bool H = HIGH;
bool L = LOW;

const int sensor[16] = { 53, 51, 49, 47, 45, 43, 41, 39, 37, 35, 33, 31, 29, 27, 25, 23 };
int sensorValue[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/* Maximum PWM signal */
#define MAX_PWM 100

/* Motor driver function definitions */
#include "motor_driver.h"

/* Encoder driver function definitions */
#include "encoder_driver.h"

/* PID parameters and functions */
#include "diff_controller.h"

/* Run the PID loop at 30 times per second */
#define PID_RATE 30  // Hz

/* Convert the rate into an interval */
const int PID_INTERVAL = 1000 / PID_RATE;

/* Track the next time we make a PID calculation */
unsigned long nextPID = PID_INTERVAL;

// /* Stop the robot if it hasn't received a movement command
//    in this number of milliseconds */
// #define AUTO_STOP_INTERVAL 10000
// long lastMotorCommand = AUTO_STOP_INTERVAL;

String data;
bool stopseterusnya;
bool stopsementara;
bool stopputerkiri;
bool stopputerkanan;
bool stopmundur;
bool mundurputerkanan;
bool mediumspeed;
bool highspeed;
bool tanpaprioritas;
bool tapePresent;
bool PrevTapeLeft;
bool PrevTapeRight;
bool prioritaskanan;
bool prioritaskiri;
bool GO;
bool pelanpelan;
bool sensorcuekin;
bool bengong;

bool pbOn;
bool pbOff;

bool towingpleaseturun;
bool towingpleasenaik;

float elapsedTime, time, timePrev;
int periodd = 50;

unsigned long tandamillis;
unsigned long currentmillis;
const unsigned long period = 5000;

float error = 0;
struct ErrorData {
  float error;
  float leftSideError;
  float rightSideError;
  float leftSideChecker;
  float rightSideChecker;
};

float distanceSetpoint = 8;
float setPointLeft = 8;
float setPointRight = 9;

float PID_p, PID_i, PID_d, PID_total;
float Kp = 2;
float Ki = 0.02;
float Kd = 4000;

// mundur
float Ka = 2;
float Kb = 0.02;
float Kc = 4000;

float distanceError, previousDistanceError;
float pwmaa;
float pwmbb;

int colv;
int start;
int emergency;
int naik;
int turun;
int autospeedup;
int vt;
int vta;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pwmb, OUTPUT);
  pinMode(dirb, OUTPUT);
  pinMode(pwma, OUTPUT);
  pinMode(dira, OUTPUT);
  pinMode(speaker, OUTPUT);
  pinMode(brake, OUTPUT);
  pinMode(tractor, OUTPUT);

  pinMode(col, INPUT_PULLUP);
  pinMode(pb1, INPUT_PULLUP);
  pinMode(es1, INPUT_PULLUP);
  pinMode(ls1, INPUT_PULLUP);
  pinMode(ls2, INPUT_PULLUP);
  for (int i = 0; i < 16; i++) pinMode(sensor[i], INPUT_PULLUP);


  digitalWrite(brake, HIGH);
  autospeedup = 0;
  error = 0;
  PrevTapeRight = false;
  PrevTapeLeft = false;
  stopseterusnya = false;
  stopsementara = false;
  stopputerkiri = false;
  stopputerkanan = false;
  stopmundur = false;
  mundurputerkanan = false;
  prioritaskanan = false;
  prioritaskiri = false;
  tanpaprioritas = true;
  highspeed = false;
  pelanpelan = false;
  sensorcuekin = true;
  bengong = false;

  pbOn = false;
  pbOff = true;

  // towingpleasenaik = false;
  // towingpleaseturun = false;
  vta = -1;
}

void loop() {
  currentmillis = millis();
  if (emergency == HIGH /*&& pbOff == true*/) {
    stopForever();
  }
  while (Serial.available() > 0) {
    delay(10);
    char d = Serial.read();
    data += d;
  }

  if (millis() > nextPID) {
    updatePID();
    nextPID += PID_INTERVAL;
  }

  // // Check to see if we have exceeded the auto-stop interval
  // if ((millis() - lastMotorCommand) > AUTO_STOP_INTERVAL) {
  //   ;
  //   setMotorSpeeds(0, 0);
  //   moving = 0;
  // }

  if (data.length() > 0) {
    if (data == "1") {  //stop seterusnya
      stopseterusnya = true;
      stopsementara = false;
      prioritaskanan = false;
      prioritaskiri = false;
      tanpaprioritas = false;
      pelanpelan = false;
    } else if (data == "2") {  //stop sementara
      stopseterusnya = false;
      stopsementara = true;
      prioritaskanan = false;
      prioritaskiri = false;
      tanpaprioritas = false;
      pelanpelan = false;
    } else if (data == "3") {  //prioritas kanan
      // stopseterusnya = false;
      // stopsementara = false;
      prioritaskanan = true;
      // prioritaskiri = false;
      // tanpaprioritas = false;
      // pelanpelan = false;
    } else if (data == "4") {  //prioritas kiri
      // stopseterusnya = false;
      // stopsementara = false;
      // prioritaskanan = false;
      prioritaskiri = true;
      // tanpaprioritas = false;
      // pelanpelan = false;
    } else if (data == "5") {  //tanpa prioritas
      stopseterusnya = false;
      stopsementara = false;
      prioritaskanan = false;
      prioritaskiri = false;
      tanpaprioritas = true;
      pelanpelan = false;
    } else if (data == "6") {  //pelan pelan agv-nya
      stopseterusnya = false;
      stopsementara = false;
      prioritaskanan = false;
      prioritaskiri = false;
      tanpaprioritas = true;
      pelanpelan = true;
    } else if (data == "7") {  // puter kiri
      stopputerkiri = true;
    } else if (data == "8") {  // puter kanan
      stopputerkanan = true;
    } else if (data == "9") {  // mundur
      stopmundur = true;
    } else if (data == "start") {
      stopseterusnya = false;
      stopsementara = false;
      prioritaskanan = false;
      prioritaskiri = false;
      tanpaprioritas = true;
      pelanpelan = false;
      startGoingSlowly();
      tandamillis = millis();
    } else if (data == "stop") {
      stopForever();
    } else if (data.indexOf("kecepatan:") != -1){
      String part02 = getValue(data,':',1);
      vta = part02.toInt();
      // digitalWrite(speaker, HIGH);
    } else if (data == "On") {
      pbOn = true;
      pbOff = false;
    } else if (data == "Off") {
      pbOff = true;
      pbOn = false;
    }
    data = "";
    Serial.println("Received");
  }
  readSensor();
  ErrorData errorValue = errorData();
  error = errorValue.error;
  if (sensorValue[0] == L && sensorValue[1] == L && sensorValue[2] == L && sensorValue[3] == L && sensorValue[4] == L && sensorValue[5] == L && sensorValue[6] == L && sensorValue[7] == L && sensorValue[8] == L && sensorValue[9] == L && sensorValue[10] == L && sensorValue[11] == L && sensorValue[12] == L && sensorValue[13] == L && sensorValue[14] == L && sensorValue[15] == L) {
    delay(300);
    readSensor();
    if (sensorValue[0] == L && sensorValue[1] == L && sensorValue[2] == L && sensorValue[3] == L && sensorValue[4] == L && sensorValue[5] == L && sensorValue[6] == L && sensorValue[7] == L && sensorValue[8] == L && sensorValue[9] == L && sensorValue[10] == L && sensorValue[11] == L && sensorValue[12] == L && sensorValue[13] == L && sensorValue[14] == L && sensorValue[15] == L) {
      tapePresent = false;
      PID_total = 0;
    }
  }
  if (sensorValue[0] == H || sensorValue[1] == H || sensorValue[2] == H || sensorValue[3] == H || sensorValue[4] == H || sensorValue[5] == H || sensorValue[6] == H || sensorValue[7] == H || sensorValue[8] == H || sensorValue[9] == H || sensorValue[10] == H || sensorValue[11] == H || sensorValue[12] == H || sensorValue[13] == H || sensorValue[14] == H || sensorValue[15] == H) {
    tapePresent = true;
  }
  if (distanceError > 3 || distanceError < -3) {
    tandamillis = currentmillis;
    PID_total = 0;
  }

  if (GO == true && vta < 0) {
    vt = 50;
  }
  if (GO == true && vta >= 0) {
    vt = vta;
  }
  // if (GO == true && tanpaprioritas == true && pelanpelan == true) {
  //   vt = 50;
  // }
  // if (GO == true && (currentmillis - tandamillis <= period) && tanpaprioritas == true && pelanpelan == false) {
  //   vt = part02.toInt();
  // }
  // if (GO == true && (currentmillis - tandamillis > period) && tanpaprioritas == true && pelanpelan == false) {
  //   vt = part02.toInt();
  // }
  // if (GO == true && (prioritaskanan == true || prioritaskiri == true)) {
  //   vt = 50;
  // }
  ////////////////
  if (start == LOW  && emergency == LOW && GO == false && stopseterusnya == false /*&& pbOn == true*/ ) {
    startGoing();
    tandamillis = millis();
  }
  if (start == LOW  &&  emergency == LOW && GO == false && stopseterusnya == true /*&& pbOn == true */) {
    startGoingSlowly();
    tandamillis = millis();
  }
  ///////////////
  if (tapePresent == false && GO == true && PrevTapeRight == true)  // ngga ada tape tapi maju (cari tape kanan)
  {
    tapeOffRight();
  }
  if (tapePresent == false && GO == true && PrevTapeLeft == true)  // ngga ada tape tapi maju
  {
    tapeOffLeft();
  }
  ///////////////////
  if (tapePresent == true && GO == true && stopseterusnya == true) {
    stopForever();
  }
  if (tapePresent == true && GO == true && stopsementara == true) {
    stopAwhile();
  }
  if (tapePresent == true && GO == true && stopputerkiri == true) {
    stopRotateLeft();
  }
  if (tapePresent == true && GO == true && stopputerkanan == true) {
    stopRotateRight();
  }
  if (tapePresent == true && GO == true && stopmundur == true) {
    // stopBackward();
    gerakanStation();
  }
  if (tapePresent == true && GO == true && sensorcuekin == true && colv == LOW) {
    stopbySensor();
  }
  if (tapePresent == true && GO == true && prioritaskanan == true) {
    // PriorityRight();
    turnRight();
  }
  if (tapePresent == true && GO == true && prioritaskiri == true) {
    // PriorityLeft();
    turnLeft();
  }
  if (tapePresent == true && GO == true && tanpaprioritas == true)  // deteksi tape dan jalan
  {
    PriorityMiddle();
    // PriorityMiddleBackward();
  }
  /////////////////////if (emergency == LOW)
  if (emergency == LOW && GO == false && bengong == true) {
    bebasGerak();
  }

  // if (pbOff == true) {
  //   stopForever();
  // }
  //////////////////////////////////////
  // if (towingpleasenaik == true) {
  //   turun = digitalRead(ls1);
  //   naik = digitalRead(ls2);
  //   while (naik == HIGH) {
  //     turun = digitalRead(ls1);
  //     naik = digitalRead(ls2);
  //     digitalWrite(tractor, HIGH);
  //   }
  //   towingpleasenaik = false;
  //   digitalWrite(tractor, LOW);
  // }
  // if (towingpleaseturun == true) {
  //   turun = digitalRead(ls1);
  //   naik = digitalRead(ls2);
  //   while (turun == HIGH) {
  //     turun = digitalRead(ls1);
  //     naik = digitalRead(ls2);
  //     digitalWrite(tractor, HIGH);
  //   }
  //   towingpleaseturun = false;
  //   digitalWrite(tractor, LOW);
  // }
  //////////////////////////////////////
  if ((sensorValue[15] == H || sensorValue[14] == H || sensorValue[13] == H) && sensorValue[0] == L)  // ini kalo tape ada di sensor kiri
  {
    PrevTapeRight = false;
    PrevTapeLeft = true;
  }
  if ((sensorValue[2] == H || sensorValue[1] == H || sensorValue[0] == H) && sensorValue[15] == L)  //ini kalo tapi ada di sensor kanan
  {
    PrevTapeRight = true;
    PrevTapeLeft = false;
  }
}

void readSensor() {
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
  colv = digitalRead(col);
  start = digitalRead(pb1);
  emergency = digitalRead(es1);
  turun = digitalRead(ls1);
  naik = digitalRead(ls2);
}

void SerialPlotter(float a, float b, float x, float y, float z) {
  Serial.print("a:");
  Serial.print(a);
  Serial.print(",");
  Serial.print("b:");
  Serial.print(b);
  Serial.print(",");
  Serial.print("x:");
  Serial.print(x);
  Serial.print(",");
  Serial.print("y:");
  Serial.print(y);
  Serial.print(",");
  Serial.print("z:");
  Serial.println(z);
}

String getValue(String dataSrc, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = dataSrc.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(dataSrc.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found>index ? dataSrc.substring(strIndex[0], strIndex[1]) : "";
}
