#include <SPI.h>
#include <LoRa.h>
#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT11

#define CH4_SENSOR_PIN A0

#define LORA_SS 10
#define LORA_RST 9
#define LORA_DI0 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (1);
  }
  Serial.println("Transmitter initialisation OK!");

  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float CH4_percentage = analogRead(CH4_SENSOR_PIN) * 100.0 / 1024.0;

  String dataPacket = String(temperature) + "," + String(humidity) + "," + String(CH4_percentage);

  LoRa.beginPacket();
  LoRa.print(dataPacket);
  LoRa.endPacket();

  Serial.println("Data sent: " + dataPacket);

  delay(100); 
}
