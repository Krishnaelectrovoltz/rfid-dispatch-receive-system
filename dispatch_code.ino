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
int day = 30;

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
          month =
