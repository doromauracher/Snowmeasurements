#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include "Adafruit_MCP9600.h"

#define I2C_ADDRESS (0x67)

Adafruit_MCP9600 mcp;

void setup()
{
    Serial.begin(115200);
    while (!Serial) {
      delay(10);
    }
    Serial.println("MCP9600 HW test");

    /* Initialise the driver with I2C_ADDRESS and the default I2C bus. */
    if (! mcp.begin(I2C_ADDRESS)) {
        Serial.println("Sensor not found. Check wiring!");
        while (1);
    }

  Serial.println("Found MCP9600!");

  mcp.setADCresolution(MCP9600_ADCRESOLUTION_18);
  mcp.setThermocoupleType(MCP9600_TYPE_K);
  mcp.setFilterCoefficient(3);
  // mcp.setAlertTemperature(1, 30);
  //mcp.configureAlert(0, true, true);  // alert 1 enabled, rising temp
  mcp.enable(true);
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
    pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
    pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
    pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
}

void loop()
{

 
    digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  for(int i=1;i < 100; i++){
     Serial.print("Relay1 \n");
  Serial.print("Hot Junction: "); Serial.println(mcp.readThermocouple());
  Serial.print("Cold Junction: "); Serial.println(mcp.readAmbient());
  Serial.print("ADC: "); Serial.print(mcp.readADC() * 2); Serial.println(" uV");
  delay(100);
  }
  delay(2000);
  

  
     digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
    for(int i=1;i < 100; i++){
       Serial.print("Relay2 \n");
  Serial.print("Hot Junction: "); Serial.println(mcp.readThermocouple());
  Serial.print("Cold Junction: "); Serial.println(mcp.readAmbient());
  Serial.print("ADC: "); Serial.print(mcp.readADC() * 2); Serial.println(" uV");
    delay(100);
    }
delay(2000);
  
}
