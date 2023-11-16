#include <Arduino.h>

const int WaterPump = 5;
const int sensor = A0;
int umidade;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(WaterPump, OUTPUT);
}

void loop() {
  umidade = analogRead(sensor);
  umidade = map(umidade, 1023, 315, 0, 100);
  Serial.print("Umidade encontrada: ");
  Serial.print(umidade);
  Serial.print("% ");

  if (umidade < 50) {
    Serial.println("Status: Solo seco");
    digitalWrite(WaterPump, HIGH);
    delay(5000);
    digitalWrite(WaterPump, LOW);
  }
  else {
   Serial.println("Status: Solo úmido");
  }
  
  delay(500);
}
