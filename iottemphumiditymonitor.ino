#define BLYNK_TEMPLATE_ID "TMPLr07uPbLQ"
#define BLYNK_TEMPLATE_NAME "TemperatureHumidityMoniter"
#define BLYNK_AUTH_TOKEN "97fcBYB-SIrrSC64YUF29XCJlGO2Lj9q"
#define BLYNK_PRINT Serial // Use Serial Monitor for debugging
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN D4 // DHT11 Sensor Pin
#define DHTTYPE DHT11 // DHT11 Sensor Type

char auth[] = "97fcBYB-SIrrSC64YUF29XCJlGO2Lj9q"; // Blynk Auth Token
char ssid[] = "iMaK"; // WiFi SSID
char pass[] = "gate@024"; // WiFi Password

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT11 Sensor

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); // Connect to Blynk IoT
  dht.begin(); // Initialize DHT11 Sensor
}

void loop() {
  Blynk.run(); // Run Blynk IoT
  float temp = dht.readTemperature(); // Read temperature from DHT11 Sensor
  float hum = dht.readHumidity(); // Read humidity from DHT11 Sensor
  if (isnan(temp) || isnan(hum)) { // Check for errors
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }
  Blynk.virtualWrite(V0, temp); // Send temperature value to Blynk IoT
  Blynk.virtualWrite(V1, hum); // Send humidity value to Blynk IoT
  delay(2000); // Wait for 5 seconds
}
