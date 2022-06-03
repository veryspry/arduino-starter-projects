#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


double temp;

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

// Analog input from temperature sensor
const int sensorPin = A0;

struct lines {
  String one;
  String two;
};

struct lines get(double temp) {
  struct lines res;
  res.one = "Howdy, Buccaneer!";
  res.two = "Temp is: " + String(temp);
  return res;
}

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  temp = (double)sensorVal / 1024;
  temp = temp * 5;
  temp = temp - 0.5;
  temp = temp * 100;
  
  struct lines a = get(temp);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(a.one);
  lcd.setCursor(0, 1);
  lcd.print(a.two);
  delay(500);
}

