#include <DHT.h> // Biblioteca usada para realizar a leitura de dados
#include <SoftwareSerial.h>

#define tipoDHT DHT11


//Declaração de vetores relacionadas aos pinos
int sensorUmi[2] = {A5, A0};
int sensorDHT[2] = {A4, A1};
int sensorLDR[2] = {A3, A2};

SoftwareSerial bluetooth(0, 1);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  //Laço que seta todos os pinos para ENTRADA
  for (int i=0;i<2;i++) {
    pinMode(sensorUmi[i], INPUT);
    pinMode(sensorDHT[i], INPUT);
    pinMode(sensorLDR[i], INPUT);
  }
}



void loop() {
  for (int i=0;i<2;i++) {
    // Cria um TAD da biblioteca DHT.h referente ao conjunto de sensores
    DHT dht(sensorDHT[i], tipoDHT);
    bluetooth.print("[");
    bluetooth.print(i+1);
    bluetooth.print(";");
    bluetooth.print(analogRead(sensorUmi[i]));
    bluetooth.print(";");
    bluetooth.print(dht.readTemperature());
    bluetooth.print(";");
    bluetooth.print(dht.readHumidity());
    bluetooth.print(";");
    bluetooth.print(analogRead(sensorLDR[i]));
    bluetooth.print("]");
    
    Serial.print("[");
    Serial.print(i+1);
    Serial.print(";");
    Serial.print(analogRead(sensorUmi[i]));
    Serial.print(";");
    Serial.print(dht.readTemperature());
    Serial.print(";");
    Serial.print(dht.readHumidity());
    Serial.print(";");
    Serial.print(analogRead(sensorLDR[i]));
    Serial.println("]");
    delay(1000);
  }
  delay(1000);
}
