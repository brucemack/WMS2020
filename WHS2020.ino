#define SRCLK 8
#define RCLK 7
#define SER 9

#define FIG_W    0x0001
#define FIG_H    0x0002
#define FIG_S    0x0004
#define FIG_2a   0x0008
#define FIG_0a   0x0010
#define FIG_2b   0x0020
#define FIG_0b   0x0040
#define AUX_0    0x0080
#define AUX_1    0x0100

void setup() {
  
  pinMode(13,OUTPUT);
  pinMode(SRCLK,OUTPUT);
  pinMode(RCLK,OUTPUT);
  pinMode(SER,OUTPUT);
  digitalWrite(SRCLK,0);
  digitalWrite(RCLK,0);

  int d0 = 1000;

  // Diagnostics
  write(0);
  digitalWrite(13,1);
  delay(d0);
  delay(d0);
  delay(d0);
  write(0xffff);
  digitalWrite(13,0);
  delay(d0);
  delay(d0);
  delay(d0);
  write(0);
}

void shift() {
  digitalWrite(SRCLK,1);
  delay(10);
  digitalWrite(SRCLK,0);
}

void latch() {
  digitalWrite(RCLK,1);
  digitalWrite(RCLK,0);
}

void write(unsigned int data) {
  for (int i = 0; i < 16; i++) {
    if (data & 1) {
      digitalWrite(SER,1);
    } else {
      digitalWrite(SER,0);
    }
    shift();
    data = data >> 1;
  }
  latch();
}

void showCycle() {

  int d0 = 125;
  int d1 = 125;
  int d2 = 250;
  int d_long = 200;

  write(0);
  delay(d1);

  for (int i = 0; i < 4; i++) {
    write(FIG_W);
    delay(d1);
    write(FIG_H);
    delay(d1);
    write(FIG_S);
    delay(d1);
    write(FIG_2a);
    delay(d1);
    write(FIG_0a);
    delay(d1);
    write(FIG_2b);
    delay(d1);
    write(FIG_0b);
    delay(d1);
  }

  for (int i  = 0; i < 4; i++) {
    write(FIG_W | FIG_H | FIG_S);
    delay(d2);
    write(FIG_2a | FIG_0a | FIG_2b | FIG_0b);
    delay(d2);
  }

  write(FIG_2a | FIG_0a | FIG_2b | FIG_0b);
  delay(d_long);
}

void loop() {
  showCycle();
}




