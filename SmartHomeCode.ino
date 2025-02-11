#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

// Pins for the RFID sensor
#define SS_PIN 10    // Slave Select Pin for RFID
#define RST_PIN 9    // Reset Pin for RFID

// Pins for the gas sensor, buzzer, and lamp
#define GAS_SENSOR_PIN A0
#define BUZZER_PIN 3
#define LAMP_PIN 4  // Pin for the lamp

// Pin for the servo motor
#define SERVO_PIN 6

// Create RFID and servo motor objects
RFID rfid(SS_PIN, RST_PIN);
Servo servo;

// Variables for timing
unsigned long previousMillis = 0;
const long interval = 1000;  // Gas sensor check interval (1 second)

// Function to open the door
void openDoor() {
  servo.write(90);  // Door opens
  delay(5000);  // Keep door open for 5 seconds
  servo.write(0);  // Door closes
}

void setup() {
  // Initialize serial monitor
  Serial.begin(9600);

  // Initialize RFID
  SPI.begin();
  rfid.init();

  // Initialize servo
  servo.attach(SERVO_PIN);
  servo.write(0);  // Door closed

  // Initialize buzzer and lamp
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);

  // Initialize gas sensor
  pinMode(GAS_SENSOR_PIN, INPUT);
}

void loop() {
  // Read RFID if a card is detected
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      Serial.print("RFID Serial Number: ");
      for (int i = 0; i < 5; i++) {
        Serial.print(rfid.serNum[i]); // Display RFID tag serial number
        Serial.print(" ");
      }
      Serial.println();

      // Check if the tag is valid (e.g., serNum[4] == 135)
      if (rfid.serNum[4] == 135) {  // Replace with a valid tag
        Serial.println("Valid RFID tag.");
        openDoor();
      } else {
        Serial.println("Invalid RFID tag.");
      }

      rfid.halt();  // Stop communication with the card
    }
  }

  // Check gas sensor at regular intervals using millis()
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Read gas sensor (MQ-2 or similar)
    int gasValue = analogRead(GAS_SENSOR_PIN);

    // Display gas sensor value
    Serial.print("Gas Sensor Value: ");
    Serial.println(gasValue);

    // If gas value exceeds threshold (e.g., 300)
    if (gasValue > 300) {
      Serial.println("Gas detected!");
      digitalWrite(BUZZER_PIN, HIGH);  // Turn on buzzer
      digitalWrite(LAMP_PIN, HIGH);    // Turn on lamp
    } else {
      digitalWrite(BUZZER_PIN, LOW);   // Turn off buzzer
      digitalWrite(LAMP_PIN, LOW);     // Turn off lamp
    }
  }
}