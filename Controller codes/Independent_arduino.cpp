#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>

Servo s1;
int trigpin = 5;
int echopin = 6;
int forcePin = A0; // Analog pin for force sensor
float distance;
float duration;

Adafruit_LiquidCrystal lcd(0); // LCD pins

void setup() {
  s1.attach(4);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  lcd.begin(16, 2);
  lcd.print("SMART BIN INITIALIZED"); // Initialize LCD display
}

void loop() {
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration * 0.034 / 2);

  float weight = getWeight(); // Get weight from force sensor

  if (distance < 40) {
    s1.write(120);
    delay(3000);
  } else {
    s1.write(0);
    delay(50);
  }

  updateDisplay(weight); // Update LCD display with storage status
}

float getWeight() {
  // Read analog value from force sensor and convert to weight
  int sensorValue = analogRead(forcePin);
  float newton = sensorValue/46.6;
  float weight = newton*1.25;
  // Example calibration: Map sensor value range to weight range (0 to 10 kg)
  // Assuming 1023 as maximum sensor value
  // Convert weight to storage percentage (0% to 100%)
  int storagePercentage = (weight / 12.5) * 100; // Maximum capacity is 10 kg
  return storagePercentage;
}


void updateDisplay(float storagePercentage) {
  lcd.setCursor(0, 0);
  lcd.print("SmartBin Storage:");
  lcd.setCursor(0, 1);
  lcd.print(storagePercentage);
  lcd.print("% full ");
}

