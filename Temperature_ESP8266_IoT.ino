#include "arduino_secrets.h"
#include "thingProperties.h"
#include <DHTesp.h>

DHTesp dht; // Name the function DHTesp to dht

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  
  dht.setup(5, DHTesp::DHT11); // Connect DHT sensor to GPIO

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Read temperature and humidity every 5 sec.
  float temp = dht.getTemperature();
  float hum = dht.getHumidity();
  
  Serial.print("Temperature = ");
  Serial.println(temp);
  Serial.print("Humidity = ");
  Serial.println(hum);
  
  temperature = temp;
  humidity = hum;
  
  delay(5000);
}

