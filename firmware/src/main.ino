const int CONSISTENT_PACKETS = 10;
int packets[CONSISTENT_PACKETS];

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  boolean allMatch = true;
  for (int i = 0; i < CONSISTENT_PACKETS; i++) {
    int packet = getPacket();
    packets[i] = packet;

    if (( i > 0 && packets[i - 1] != packet ) || packet == -1) {
      allMatch = false;
      break;
    }
  }

  if (allMatch) {
    Serial.print("Height: ");
    Serial.print(packets[0]);
    Serial.println("mm");
  }
}

void waitForSerial() {
  while (Serial1.available() <= 0) {}
}

int getPacket() {
  waitForSerial();

  int leaderByte1 = Serial1.read();
  if (leaderByte1 != 1) {
    return -1;
  }

  waitForSerial();
  int leaderByte2 = Serial1.read();
  if (leaderByte2 != 1) {
    return -1;
  }

  waitForSerial();
  int highByte = Serial1.read();

  waitForSerial();
  int lowByte = Serial1.read();

  // Known range of high byte for desk
  if (highByte >= 2 && highByte <= 4) {
    int value = ((unsigned int)highByte << 8) + lowByte;
    return value;
  }

  return -1;
}
