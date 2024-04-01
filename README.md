Arduino Temperature Sensor with DS18B20
This Arduino sketch demonstrates how to use the DS18B20 temperature sensor to measure temperature and display the results on the serial monitor. The DS18B20 is a digital temperature sensor that uses the OneWire protocol for communication with the Arduino board.

Components Required:
Arduino board (e.g., Arduino Uno)
DS18B20 temperature sensor
Breadboard and jumper wires
Installation:
Connect the DS18B20 sensor to your Arduino board as follows:

VCC (+): Connect to the Arduino's 5V pin.
GND (-): Connect to the Arduino's GND pin.
DATA: Connect to digital pin 2 (you can change this pin in the code if needed).
Install the OneWire library:

Open Arduino IDE.
Go to "Sketch" -> "Include Library" -> "Manage Libraries...".
Search for "OneWire" and install the library by Jim Studt, Paul Stoffregen, and others.
Install the DallasTemperature library:

Go to "Sketch" -> "Include Library" -> "Manage Libraries...".
Search for "DallasTemperature" and install the library by Miles Burton and others.
Usage:
Open the code5f.ino file in the Arduino IDE.
Verify that the correct Arduino board and port are selected under the "Tools" menu.
Click the "Upload" button to upload the code to your Arduino board.
Open the serial monitor (Tools -> Serial Monitor) to view the temperature readings.
The temperature readings will be displayed in degrees Celsius.
SNTP Configuration:
This sketch utilizes the Simple Network Time Protocol (SNTP) to synchronize the Arduino's internal clock with an internet time server. SNTP configuration settings can be adjusted in the code to match your network's requirements.

Email Alert Configuration:
The code also includes functionality to send email alerts using Google SMTP. Ensure you have a valid Gmail account and configure the emailSenderAccount and emailSenderPassword variables with your credentials. Make sure to enable less secure app access for your Gmail account.

Notes:
Ensure proper wiring of the DS18B20 sensor to your Arduino board.
You may need to adjust the code if you use a different pin for connecting the DATA wire of the DS18B20 sensor.
