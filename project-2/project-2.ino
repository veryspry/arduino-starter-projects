int switchState = 0;
int activeRedLight = 4;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  
  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    activeRedLight = 4;
    return;
  }

  digitalWrite(3, LOW);

  if (activeRedLight == 4) {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    activeRedLight = 5;
  } else {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    
    activeRedLight = 4;
  }

  delay(250);
}

