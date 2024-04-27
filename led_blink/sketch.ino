String command;
#define LEDPIN 2

void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    command = Serial.readStringUntil('\n');
    if (command == "on") {
      digitalWrite(LEDPIN, HIGH);
      Serial.write("LED ON");    
    } else if (command == "of") {
      digitalWrite(LEDPIN, LOW);
    } else {
      Serial.write("invalid input");
    }
  }
}
