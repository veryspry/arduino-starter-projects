const int sensorPin = A0;
const float baselineTemp = 16.0;

void setup() {
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;

  // Serial.print("Sensor Val: ");
  // Serial.print(sensorVal);
  // Serial.print("\n");

  // Serial.print("Voltage: ");
  // Serial.print(voltage);
  // Serial.print("\n");

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("\n");

  /**
   * 2 - Blue
   * 3 - Green
   * 4 - Yellow
   * 5 - Red
   */
  int onPin = 2;

  if (temperature >= baselineTemp + 4) {
    onPin = 5;
  } else if (temperature >= baselineTemp + 2) {
    onPin = 4;
  } else if (temperature >= baselineTemp) {
    onPin = 3;
  } else {
    onPin = 2;
  }

  Serial.print("On pin ");
  Serial.print(onPin);
  Serial.print("\n");

  for (int i = 2; i < 6; i++) {
    if (i == onPin) {
      digitalWrite(i, HIGH);
    } else {
      digitalWrite(i, LOW);
    }
  }

  delay(100);
}

