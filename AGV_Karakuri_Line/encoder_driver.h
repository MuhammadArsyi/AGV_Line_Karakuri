/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */


//below can be changed, but should be PORTD pins;
//otherwise additional changes in the code are required
#define LEFT_ENC_PIN PK0   //pin A9 - PCINT[17]
#define RIGHT_ENC_PIN PB5  //pin D11 - PCINT[5]

long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
