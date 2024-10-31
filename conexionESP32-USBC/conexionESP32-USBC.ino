#define DEBUG

#if defined DEBUG
#define DBG_PRINT(x) Serial.print(x)
#define DBG_PRINTLN(x) Serial.println(x)
#else
#define DBG_PRINT(x)
#define DBG_PRINTLN(x)
#endif

#include <ArduinoBLE.h>

BLEService systemService("c515cb47-87e6-4623-89d9-233ce5a508c1");
BLEByteCharacteristic degreeCharacteristic("d7192f62-1a52-4ee0-9c3b-8c29b18ef85b",BLERead | BLEWrite);

uint16_t degree=0;

const int LEDpin = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  pinMode(LEDpin,OUTPUT);

  if(!BLE.begin()){
    DBG_PRINTLN("starting Bluetooth Low Energy module failed!");

    while(1);
  }

  BLE.setLocalName("Arduino_Iot");
  BLE.setAdvertisedService(systemService);
  systemService.addCharacteristic(degreeCharacteristic);
  BLE.addService(systemService);
  degreeCharacteristic.writeValue(0);

  BLE.advertise();
  DBG_PRINTLN("Bluetooth device active, waiting for connections...");
}

void loop() {
  // put your main code here, to run repeatedly:
  BLE.poll();

}


