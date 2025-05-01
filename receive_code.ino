#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN   PA4 
#define RST_PIN  PB0

MFRC522 mfrc522(SS_PIN, RST_PIN);

unsigned long previousMillis = 0;
unsigned long seconds = 0;
unsigned long minutes = 30;
unsigned long hours = 14;

int year = 2025;
int month = 4;
int day = 29;

int daysInMonth(int month, int year) {
  if (month == 2) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
      return 29;
    else
      return 28;
  }
  if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  return 31;
}

void updateTime() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    seconds++;
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
    }
    if (minutes >= 60) {
      minutes = 0;
      hours++;
    }
    if (hours >= 24) {
      hours = 0;
      day++;
      if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
          month = 1;
          year++;
        }
      }
    }
  }
}

String getProductName(byte *uid, byte size) {
  if (size == 4 && uid[0] == 0xDE && uid[1] == 0xAD && uid[2] == 0xBE && uid[3] == 0xEF) {
    return "Product A";
  }
  if (size == 4 && uid[0] == 0x12 && uid[1] == 0x34 && uid[2] == 0x56 && uid[3] == 0x78) {
    return "Product B";
  }
  return "IPHONE";
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan a product tag...");
  previousMillis = millis();
}

void loop() {
  updateTime();
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println("========== SCAN RESULT ==========");
  Serial.print("UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  String product = getProductName(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println("Product: " + product);

  Serial.print("Received Date: ");
  Serial.print(year); Serial.print("-");
  if (month < 10) Serial.print("0");
  Serial.print(month); Serial.print("-");
  if (day < 10) Serial.print("0");
  Serial.println(day);

  Serial.print("Received Time: ");
  if (hours < 10) Serial.print("0"); 
  Serial.print(hours); Serial.print(":");
  if (minutes < 10) Serial.print("0");
  Serial.print(minutes); Serial.print(":");
  if (seconds < 10) Serial.print("0");
  Serial.println(seconds);

  Serial.println("=================================\n");

  mfrc522.PICC_HaltA();
  delay(2000);
}
