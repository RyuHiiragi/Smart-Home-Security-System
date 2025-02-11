# Smart Home Security System

This project implements a simple Smart Home Security System using an RFID sensor, gas sensor, and servo motor. The system opens the door when a valid RFID tag is detected, and monitors the gas levels for safety. If dangerous gas levels are detected, the system triggers an alarm using a buzzer and turns on a lamp to alert the user.

# Features

- RFID Access Control: Opens the door when a valid RFID tag is detected.
- Gas Leak Detection: Monitors the gas levels and triggers an alarm if dangerous levels are detected.
- Servo Motor Control: Controls a servo motor to open/close the door based on RFID authentication.
- Alert System: Turns on a buzzer and lamp when gas levels exceed a safety threshold.

# Components

- RFID Module (for access control)
- Gas Sensor (MQ-2 or similar for gas detection)
- Servo Motor (for door control)
- Buzzer (for alerting gas detection)
- Lamp (for visual alert on gas detection)

# Wiring Diagram

- RFID Module:
- SS_PIN: Pin 10
- RST_PIN: Pin 9
- Gas Sensor:
- GAS_SENSOR_PIN: A0 (analog pin for reading gas levels)
- Buzzer:
- BUZZER_PIN: Pin 3
- Lamp:
- LAMP_PIN: Pin 4
- Servo Motor:
- SERVO_PIN: Pin 6

# How to Use

1. Set up the hardware: 
- Connect all components to your Arduino board according to the wiring diagram.
2. Upload the code: 
- Open the Arduino IDE, paste the provided code into a new sketch, and upload it to your Arduino board.

3. Testing:
- The system will detect when a valid RFID tag is presented, and it will open the door.
- It will also continuously monitor gas levels; if a dangerous gas concentration is detected, it will trigger the buzzer and lamp.

4. Valid RFID Tag: 
- The default valid RFID tag is defined by the serial number rfid.serNum[4] == 135. You can replace 135 with the serial number of your own RFID tag.

# Code Explanation

- RFID: The system uses an RFID module to detect and authenticate tags. If a valid tag is scanned, the door opens for 5 seconds.
- Gas Sensor: The gas sensor (MQ-2 or similar) is used to detect the gas levels. If the gas levels exceed a threshold (set to 300), the buzzer sounds and the lamp turns on.
- Servo Motor: The servo motor is used to simulate a door. The door opens when a valid RFID tag is scanned.

# Dependencies

This project uses the following libraries:
- SPI: Standard Arduino library for SPI communication.
- RFID: Library to interface with RFID modules.
- Servo: Library to control servo motors.

You can install these libraries through the Arduino Library Manager.


# Acknowledgments

- Inspired by DIY smart home security projects.
- Special thanks to the open-source community for providing the libraries used in this project.
-

