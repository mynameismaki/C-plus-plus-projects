#include <Wire.h>
#include <LiquidCrystal_I2C.h>          /// LCD library
#include <virtuabotixRTC.h>             /// RTC library
virtuabotixRTC myRTC(11, 12, 13);

LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <EEPROM.h>
const int pirpin = 2;
const int btnChange = 3;
const int btnOK = 4;
const int btnMode = 5;

const int redpin = 10;
const int greenpin = 9;
const int bluepin = 8; 

const int buzzer = 7;

int alarmHour = 12;
int alarmMinutes = 0;
boolean hourMode = 0;
boolean alarmOn = 1;
int M = 12;
int D = 31;
int Y = 2020;
int day = 7;
int h = 23;
int m = 59;

int addrH[] = {0, 1, 2, 3, 4};
int addrM[] = {5, 6, 7, 8, 9};
int addrActive[] = {10, 11, 12, 13, 14};

int mode = 1;
int submode = 1;
int slot = 0;
int frequency = 300;

long unsigned int lowIn; 
long unsigned int pause = 5000; 

boolean lockLow = true;
boolean takeLowTime; 

byte clockChar[] = {B00000, B01110, B10101, B10101, B10111, B10001, B01110, B00000};
byte alarmChar[] = {B00100, B01110, B01110, B01110, B11111, B00000, B00100, B00000};
byte dateChar[] = {B11111, B00000, B01100, B01010, B01010, B01100, B00000, B11111};

void setup()  {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);   
  pinMode(btnChange, INPUT_PULLUP);
  pinMode(btnOK, INPUT_PULLUP);
  pinMode(btnMode, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);


  lcd.begin(); 
  lcd.backlight();    
  lcd.createChar(0, clockChar);
  lcd.createChar(1, alarmChar);
  lcd.createChar(2, dateChar);

  Serial.begin(9600);
}

void loop()  {

  if (digitalRead(btnMode) == LOW) {
    mode++;
    Serial.println("btnMode press");
    if (mode == 4) {
      mode = 1;
    }
    submode = 0;
    lcd.clear();
    delay(200);
  }

  if (mode == 1) {
    clockDisplay();
    digitalWrite(greenpin, HIGH);
    digitalWrite(bluepin, LOW);
    Serial.println(mode);
    //    delay(200);
  }

  if (mode == 2) {
    digitalWrite(greenpin, LOW);
    alarmMode();
    Serial.println(mode);
    //    delay(200);
  }

  if (mode == 3) {
    digitalWrite(greenpin, LOW);
    updateRTC();
    Serial.println(mode);
    //    delay(200);
  }
  if (mode == 0) {
    digitalWrite(bluepin, LOW);
    digitalWrite(greenpin, LOW);
    alarm();
    Serial.println(mode);
    EEPROM.write(addrActive, 0);
    //    delay(200);
  }
  for (int x = 0; x < 5; x++) {
    if (EEPROM.read(addrActive[x]) == 1) {
      Serial.print("alarm slot active: ");
      Serial.println(x);
      if ( myRTC.hours == EEPROM.read(addrH[x]) && myRTC.minutes == EEPROM.read(addrM[x])) {
        EEPROM.write(addrActive[x], 0);
        mode = 0;
      }
    }
  }
}

/// Alarm ///

void alarm() {
  clockDisplay();
  
  do {
    
    if(takeLowTime){
    lowIn = millis(); 
    takeLowTime = false;
    }

    lcd.noBacklight();
    tone(buzzer, frequency);
    digitalWrite(redpin, HIGH);
    delay(300);
    lcd.backlight();
    noTone(buzzer);
    digitalWrite(redpin, LOW);
    delay(200);
    if(!lockLow && millis() - lowIn > pause){ 
    lockLow = true; 
    delay(50);
    }
    frequency = frequency + 2;
    Serial.println(frequency);
  }
  while(digitalRead(pirpin) != HIGH);
  /// if ever pir sensor cant read motion, that is because of cooldown ///
  frequency = 300;
  if(lockLow) {
      lockLow = false;
      delay(50);
    }
    takeLowTime = true;
    mode = 1;
   
}

/// Clock Display ///

void clockDisplay() {
  myRTC.updateTime();
  lcd.setCursor(0, 0);
  lcd.write(0);

  lcd.setCursor(0, 1);
  switch (myRTC.month) {
    case 1: lcd.print("Jan"); break;
    case 2: lcd.print("Feb"); break;
    case 3: lcd.print("Mar"); break;
    case 4: lcd.print("Apr"); break;
    case 5: lcd.print("May"); break;
    case 6: lcd.print("Jun"); break;
    case 7: lcd.print("Jul"); break;
    case 8: lcd.print("Aug"); break;
    case 9: lcd.print("Sep"); break;
    case 10: lcd.print("Oct"); break;
    case 11: lcd.print("Nov"); break;
    case 12: lcd.print("Dec"); break;
  }

  if (myRTC.dayofmonth < 10) {
    lcd.print(" ");
    lcd.print(myRTC.dayofmonth);
  }
  else{
    lcd.print(myRTC.dayofmonth);
  }
  lcd.print(",");
  lcd.print(myRTC.year);

  lcd.setCursor(13, 1);
  switch (myRTC.dayofweek) {
    case 1: lcd.print("Sun"); break;
    case 2: lcd.print("Mon"); break;
    case 3: lcd.print("Tue"); break;
    case 4: lcd.print("Wed"); break;
    case 5: lcd.print("Thu"); break;
    case 6: lcd.print("Fri"); break;
    case 7: lcd.print("Sat"); break;
  }
  lcd.setCursor(3, 0);
  if ((myRTC.hours > 12 && myRTC.hours < 22) || (myRTC.hours > 0 && myRTC.hours < 10)) {
    lcd.print("0");
  }
  if (myRTC.hours == 0) {
    lcd.print("12");
  }
  else if (myRTC.hours <= 12) {
    lcd.print(myRTC.hours);
  }
  else {
    lcd.print(myRTC.hours - 12);
  }
  lcd.print(":");
  if (myRTC.minutes < 10) {
    lcd.print("0");
  }
  lcd.print(myRTC.minutes);
  lcd.print(":");
  if (myRTC.seconds < 10) {
    lcd.print("0");
  }
  lcd.print(myRTC.seconds);
  lcd.print("   ");
  if (myRTC.hours < 12) {
    lcd.print("AM");
  }
  else {
    lcd.print("PM");
  }
}

/// Alarm Mode ///

void alarmMode() {
  digitalWrite(bluepin, HIGH);
  if (submode == 0) {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.setCursor(2, 0);
    lcd.print("Select:");

    if (digitalRead(btnChange) == LOW) {
      slot++;
      if (slot > 4 ) {
        slot = 0;
      }
      delay(200);
    }
    lcd.setCursor(10, 0);
    lcd.print("Slot#");
    lcd.print(slot + 1);
    lcd.setCursor(0, 1);
    if (EEPROM.read(addrH[slot]) > 23) {
      EEPROM.write(addrH[slot], 0);
    }
    if (EEPROM.read(addrM[slot]) > 59) {
      EEPROM.write(addrM[slot], 0);
    }
    if (EEPROM.read(addrActive[slot]) > 1) {
      EEPROM.write(addrActive[slot], 0);
    }
    if ((EEPROM.read(addrH[slot]) > 12 && EEPROM.read(addrH[slot]) < 22) || (EEPROM.read(addrH[slot]) > 0 && EEPROM.read(addrH[slot]) < 10)) {
      lcd.print("0");
    }
    if (EEPROM.read(addrH[slot]) == 0) {
      lcd.print("12");
      alarmHour = 12;
    }
    else if (EEPROM.read(addrH[slot]) <= 12) {
      lcd.print(EEPROM.read(addrH[slot]));
      alarmHour = EEPROM.read(addrH[slot]);
    }
    else {
      lcd.print(EEPROM.read(addrH[slot]) - 12);
      alarmHour = EEPROM.read(addrH[slot]) - 12;
    }
    lcd.print(":");
    if (EEPROM.read(addrM[slot]) < 10) {
      lcd.print("0");
    }
    lcd.print(EEPROM.read(addrM[slot]));
    alarmMinutes = EEPROM.read(addrM[slot]);
    lcd.print(" ");
    if (EEPROM.read(addrH[slot]) < 12) {
      lcd.print("AM");
      hourMode = 0;
    }
    else {
      lcd.print("PM");
      hourMode = 1;
    }
    lcd.print("   ");
    if (EEPROM.read(addrActive[slot]) == 1) {
      lcd.print("ON ");
    }
    else {
      lcd.print("OFF");
    }
  }
  else {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.setCursor(2, 0);
    lcd.print("Set ||");
    lcd.setCursor(0, 1);
    lcd.print("Alarm ||");
    lcd.setCursor(9, 1);
    if (alarmHour < 10) {
      lcd.print("0");
      lcd.setCursor(10, 1);
    }
    lcd.print(alarmHour);
    lcd.setCursor(11, 1);
    lcd.print(":");
    lcd.setCursor(12, 1);
    if (alarmMinutes < 10) {
      lcd.print("0");
      lcd.setCursor(13, 1);
    }
    lcd.print(alarmMinutes);
    if (hourMode == 0) {
      lcd.print("AM");
    }
    else {
      lcd.print("PM");
    }
  }
  //  lcd.print(alarmMinutes);
  if (digitalRead(btnOK) == LOW) {
    submode++;
    if (submode > 4) {
      submode = 0;
    }
    delay(200);
    lcd.clear();
  }
  if (submode == 1) {
    lcd.setCursor(9, 0);
    lcd.write(1);
    lcd.write(1);
    if (digitalRead(btnChange) == LOW) {
      alarmHour++;
      if (alarmHour > 12) {
        alarmHour = 1;
      }
      delay(500);
    }
  }
  if (submode == 2) {
    lcd.setCursor(12, 0);
    lcd.write(1);
    lcd.write(1);
    if (digitalRead(btnChange) == LOW) {
      alarmMinutes++;
      if (alarmMinutes >= 60) {
        alarmMinutes = 0;
      }
      delay(500);
    }
  }
  if (submode == 3) {
    lcd.setCursor(14, 0);
    lcd.write(1);
    lcd.write(1);
    if (digitalRead(btnChange) == LOW) {
      hourMode = !hourMode;
      delay(500);
    }
  }
  while (submode == 4) {
    lcd.setCursor(0, 0);
    lcd.print("Activate Alarm?");
    lcd.setCursor(0, 1);
    lcd.print("Slot #");
    lcd.print(slot + 1);
    lcd.print("   ");
    if(alarmOn==1){
      lcd.print("ON ");
    }
    else{
      lcd.print("OFF");
    }
    if (digitalRead(btnChange) == LOW) {
      alarmOn = !alarmOn;
      delay(200);
    }

    if (digitalRead(btnOK) == LOW && alarmOn == 1) {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("Saving.");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      if (hourMode == 1 && alarmHour != 12) {
        EEPROM.write(addrH[slot], alarmHour + 12);
      }
      else if (hourMode == 0 && alarmHour == 12) {
        EEPROM.write(addrH[slot], 0);
      }
      else {
        EEPROM.write(addrH[slot], alarmHour);
      }

      EEPROM.write(addrM[slot], alarmMinutes);
      EEPROM.write(addrActive[slot], 1);
      submode = 0;
      mode = 1;
      lcd.clear();
    }
    if (digitalRead(btnOK) == LOW && alarmOn == 0)  {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Alarm Slot#");
      lcd.print(slot + 1);
      lcd.setCursor(0, 1);
      lcd.print(" OFF      ");
      
      EEPROM.write(addrActive[slot], 0);
      submode = 0;

      digitalWrite(bluepin, LOW);
      mode = 1;
      
      delay(2000);
      lcd.clear();
    }
  }
}

/// Settings ///

void updateRTC() {
  digitalWrite(bluepin, HIGH);
  lcd.setCursor(0, 0);
  lcd.write(2);
  if (digitalRead(btnOK) == LOW) {
    submode++;
    if (submode > 7) {
      submode = 0;
    }
    delay(200);
    lcd.clear();
  }

  if (submode == 0) {
    lcd.setCursor(2, 0);
    lcd.print(" Set Date/Time?");
    lcd.setCursor(0, 1);
    lcd.print("Press OK button");
  }
  if (submode == 1) {
    lcd.setCursor(2, 0);
    lcd.print("Set Month");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      M++;
      if (M == 13) {
        M = 1;
      }
      delay(200);
    }
    switch (M) {
      case 1: lcd.print("January     ");
        break;
      case 2: lcd.print("February    ");
        break;
      case 3: lcd.print("March       ");
        break;
      case 4: lcd.print("April       ");
        break;
      case 5: lcd.print("May         ");
        break;
      case 6: lcd.print("June        ");
        break;
      case 7: lcd.print("July        ");
        break;
      case 8: lcd.print("August      ");
        break;
      case 9: lcd.print("September   ");
        break;
      case 10: lcd.print("October     ");
        break;
      case 11: lcd.print("November    ");
        break;
      case 12: lcd.print("December    ");
        break;
    }
  }
  if (submode == 2) {
    lcd.setCursor(2, 0);
    lcd.print("Set Day");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      D++;
      if (D == 32) {
        D = 1;
      }
      delay(200);
    }
    lcd.print(D);
    lcd.print(" ");
  }

  if (submode == 3) {
    lcd.setCursor(2, 0);
    lcd.print("Set Year");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      Y++;
      if (Y == 2099) {
        Y = 2000;
      }
      delay(200);
    }
    lcd.print(Y);
  }
  if (submode == 4) {
    lcd.setCursor(2, 0);
    lcd.print("Set Day of the Week");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      day++;
      if (day == 😎 {
        day = 1;
      }
      delay(200);
    }
    switch (day) {
      case 1: lcd.print("Sunday      ");
        break;
      case 2: lcd.print("Monday      ");
        break;
      case 3: lcd.print("Tuesday     ");
        break;
      case 4: lcd.print("Wednesday   ");
        break;
      case 5: lcd.print("Thursday    ");
        break;
      case 6: lcd.print("Friday      ");
        break;
      case 7: lcd.print("Saturday    ");
        break;
    }
  }
  if (submode == 5) {
    lcd.setCursor(2, 0);
    lcd.print("Set Hour");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      h++;
      if (h == 24) {
        h = 0;
      }
      delay(200);
    }
    if (h > 12) {
      lcd.print(h - 12);
      lcd.print(" ");
    }
    else if (h == 0) {
      lcd.print("12");
      lcd.print(" ");
    }
    else {
      lcd.print(h);
      lcd.print(" ");

    }
    if (h >= 12) {
      lcd.setCursor(9, 1);
      lcd.print("PM");
    }
    else {
      lcd.setCursor(9, 1);
      lcd.print("AM");
    }

  }
  if (submode == 6) {
    lcd.setCursor(2, 0);
    lcd.print("Set Minutes");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      m++;
      if (m == 60) {
        m = 0;
      }
      delay(200);
    }
    lcd.print(m);
    lcd.print(" ");
  }
  if (submode == 7) {
    lcd.setCursor(2, 0);
    lcd.print("Date & Time");
    lcd.setCursor(0, 1);
    lcd.print("Updating");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    myRTC.setDS1302Time(00, m, h, day, D, M, Y);
    delay(200);
    lcd.clear();
    digitalWrite(bluepin, LOW);
    mode = 1;
  }
}