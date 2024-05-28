volatile long left_enc_pos = 0L;
volatile long right_enc_pos = 0L;

/* Interrupt routine for LEFT encoder, taking care of actual counting */
ISR(PCINT2_vect) {
  left_enc_pos += 1;  // Increment position for left encoder
}

/* Interrupt routine for RIGHT encoder, taking care of actual counting */
ISR(PCINT0_vect) {
  right_enc_pos += 1;  // Increment position for right encoder
}

/* Wrap the encoder reading function */
long readEncoder(int i) {
  if (i == LEFT) return left_enc_pos;
  else return right_enc_pos;
}

/* Reset the encoder position */
void resetEncoder(int i) {
  if (i == LEFT) {
    left_enc_pos = 0L;  // Reset left encoder position
  } else {
    right_enc_pos = 0L;  // Reset right encoder position
  }
}

void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}