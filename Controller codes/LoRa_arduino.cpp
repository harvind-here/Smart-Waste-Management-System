#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <LoRa.h>
#define PRESSURE_SENSOR_PIN A0
#define ULTRASONIC_TRIG_PIN 2
#define ULTRASONIC_ECHO_PIN 3
#define SERVO_PIN 9

Servo lidServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int csPin = 10;
const int resetPin = 9;
const int irqPin = 2;

void setup() {
  Serial.begin(9600);
  lidServo.attach(SERVO_PIN);
  lcd.begin();
  lcd.backlight();
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
 
  LoRa.setPins(csPin, resetPin, irqPin);
  if (!LoRa.begin(915E6)) {
    Serial.println("LoRa initialization failed!");
    while (1);
  }
}

void loop() {
  int pressureValue = analogRead(PRESSURE_SENSOR_PIN);
  long duration, distance;
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;
  updateDisplay(weight);

  if (distance < 40) {
    lidServo.write(120); // Open the lid
  } else {
    lidServo.write(0); // Close the lid
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Storage Level:");
  lcd.print(storage)
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
  }

  LoRa.beginPacket();
  LoRa.print("Distance: ");
  LoRa.print(distance);
  LoRa.endPacket();

  delay(2000);
}
void updateDisplay(float storagePercentage) {
  lcd.setCursor(0, 0);
  lcd.print("SmartBin Storage:");
  lcd.setCursor(0, 1);
  lcd.print(storagePercentage);
  lcd.print("% full ");
}