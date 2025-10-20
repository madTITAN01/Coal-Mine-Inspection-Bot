#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <LoRa.h>

#define LED_PIN_1 3
#define LED_PIN_2 4
#define LED_PIN_3 5
#define BUZZER_PIN 6

#define THRESHOLD_TEMPERATURE 100.0
#define THRESHOLD_HUMIDITY 95.0
#define THRESHOLD_CH4 10.0

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (1);
  }
  Serial.println("Receiver initialisation OK!");

  lcd.init();
  lcd.backlight();

  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (LoRa.parsePacket()) {
    while (LoRa.available()) {
      String receivedData = LoRa.readString();

      float temperature = receivedData.substring(0, receivedData.indexOf(',')).toFloat();
      receivedData.remove(0, receivedData.indexOf(',') + 1);
      int humidity = receivedData.substring(0, receivedData.indexOf(',')).toInt();
      receivedData.remove(0, receivedData.indexOf(',') + 1);
      int CH4_percentage = receivedData.substring(0, receivedData.indexOf(',')).toInt();
      receivedData.remove(0, receivedData.indexOf(',') + 1);

      Serial.println("Temperature: " + String(temperature) + "°C, Humidity: " + String(humidity) + "%, CH4: " + String(CH4_percentage) + "%");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp: " + String(temperature) + "C");
      lcd.setCursor(0, 1);
      lcd.print("Hum:" + String(humidity) + "%  CH4:" + String(CH4_percentage) + "%");

      if (temperature > THRESHOLD_TEMPERATURE) {
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
      } else {
        digitalWrite(LED_PIN_1, LOW);
        digitalWrite(BUZZER_PIN, LOW);
      }
      if (humidity > THRESHOLD_HUMIDITY) {
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
      } else {
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(BUZZER_PIN, LOW);
      }
      if (CH4_percentage > THRESHOLD_CH4) {
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
      } else {
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(BUZZER_PIN, LOW);
      }
    }
  }
}
