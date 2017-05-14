#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
    Serial.print("Read DHT11 failed.");
    return;
  }
  if (Serial.available()){
    char strcome = Serial.read();
    Serial.print(strcome);
  }
  Serial.print("SEND|");
  Serial.print("258162066:AAG4hY807MImx0HtZVPrMvTRK0RHa42HTiY");
  Serial.print("|");
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" %");

  // DHT11 sampling rate is 1HZ.
  delay(1000);
}
