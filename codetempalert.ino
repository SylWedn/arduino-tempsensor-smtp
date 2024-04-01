#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "ESP32_MailClient.h"

const char* ssid = "";
const char* password = "";

#define emailSenderAccount ""
#define emailSenderPassword ""
#define emailRecipient ""
#define smtpServer "smtp.gmail.com"
#define smtpServerPort 465
#define emailSubject "ESP32 Temperature Alert"

// Data wire is connected to GPIO 15
#define ONE_WIRE_BUS 15

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

SMTPData smtpData;

void setup() {
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("*");
    WiFi.begin(ssid, password);
    delay(200);
  }
  Serial.println("WiFi is Connected");

  sensors.begin();
}

void loop() {
  smtpData.setLogin(smtpServer, smtpServerPort, emailSenderAccount, emailSenderPassword);
  smtpData.setSender("ESP32 Sender", emailSenderAccount);
  smtpData.setPriority("High");
  smtpData.setSubject(emailSubject);

  sensors.requestTemperatures(); // Send the command to get temperature readings

  float temperatureC = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.println(temperatureC);

  if (temperatureC >= 25.0) {
    smtpData.setMessage("Temperature is above 25C: " + String(temperatureC) + "C", false);
    if (!MailClient.sendMail(smtpData))
      Serial.println("Error in Sending the Email: " + MailClient.smtpErrorReason());

    smtpData.empty();

    // Wait for some time before sending another email to avoid spamming
    delay(60000); // Wait for 1 minute
  }

  delay(5000); // Check temperature every 5 seconds
}
