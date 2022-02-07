// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include "RTClib.h"
#include <LiquidCrystal.h>

const int rs = 32, en = 30, d4 = 28, d5 = 26, d6 = 24, d7 = 22;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void setup () {
  Serial.begin(9600);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // February 01, 2021 at 15h38m00 you would call:
    // rtc.adjust(DateTime(2021, 2, 3, 16, 38, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // February 01, 2021 at 15h38m00 you would call:
  // rtc.adjust(DateTime(2021, 2, 3, 16, 38, 0));
  
  lcd.begin(16,2);
  lcd.display();
  delay(50);
}

void loop () {
    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Date : ");
    lcd.setCursor(0,1);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(" ");
    lcd.print(now.hour());
    lcd.print("/");
    lcd.print(now.minute());
    lcd.print("/");
    lcd.print(now.second());

    delay(1000);
}
