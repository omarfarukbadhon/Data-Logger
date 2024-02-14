
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ArduinoJson.h>

StaticJsonDocument<120> doc;

// Data wire is plugged into port 12 on the Arduino
#define ONE_WIRE_BUS 12
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
//28  11  58  77  91  14  02  1F 
//28  84  42  77  91  0F  02  4B
// We'll use this variable to store device address
DeviceAddress tempDeviceAddress1= {0x28, 0xB0, 0xD6, 0x03, 0x00, 0x00, 0x00, 0x53}; 
DeviceAddress tempDeviceAddress2= {0x28, 0xC4, 0xCC, 0x02, 0x00, 0x00, 0x00, 0x59}; 
DeviceAddress tempDeviceAddress3= {0x28, 0x11, 0x58, 0x77, 0x91, 0x14, 0x02, 0x1F};
DeviceAddress tempDeviceAddress4= {0x28, 0x84, 0x42, 0x77, 0x91, 0x0F, 0x02, 0x4B};  
DeviceAddress tempDeviceAddress5= {0x28, 0x06, 0xED, 0x03, 0x00, 0x00, 0x00, 0x12}; 
DeviceAddress tempDeviceAddress6= {0x28, 0x69, 0x72, 0x03, 0x00, 0x00, 0x00, 0x2D}; 
DeviceAddress tempDeviceAddress7= {0x28, 0x25, 0x48, 0x03, 0x00, 0x00, 0x00, 0x1C}; 
DeviceAddress tempDeviceAddress8= {0x28, 0x4D, 0x8E, 0x03, 0x00, 0x00, 0x00, 0xC0}; 


void setup(void) {
  // start serial port
  Serial.begin(9600);
  
  // Start up the library
  sensors.begin();
  
  }

  
void loop(void) { 
    sensors.requestTemperatures(); // Send the command to get temperatures
    float tempC = sensors.getTempC(tempDeviceAddress1);
    doc["T1"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress2);
    doc["T2"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress3);
    doc["T3"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress4);
    doc["T4"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress5);
    doc["T5"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress6);
    doc["T6"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress7);
    doc["T7"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress8);
    doc["T8"] = tempC;


    float sensorValue = map(analogRead(A0),0,1023,0,1023);
    //sensorValue=(sensorValue-50)*0.0075;
    if (sensorValue<0){
      sensorValue=0;
      }
    doc["P1"] = sensorValue;
    sensorValue = map(analogRead(A1),0,1023,0,1023);
    //sensorValue=(sensorValue-50)*0.0075;
    if (sensorValue<0){
      sensorValue=0;
      }
    doc["P2"] = sensorValue;
    sensorValue = map(analogRead(A2),0,1023,0,1023);
    //sensorValue=(sensorValue-50)*0.0075;
    if (sensorValue<0){
      sensorValue=0;
      }
    doc["P3"] = sensorValue;
    sensorValue = map(analogRead(A3),0,1023,0,1023);
    //sensorValue=(sensorValue-50)*0.0075;
    if (sensorValue<0){
      sensorValue=0;
      }
    doc["P4"] = sensorValue;
     
  serializeJson(doc, Serial);
  Serial.println();
    


    
    delay(1000);
}
  
