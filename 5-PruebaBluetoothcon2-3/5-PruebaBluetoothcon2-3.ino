#include <ArduinoBLE.h>
 
BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // Bluetooth® Low Energy LED Service
 
// Bluetooth® Low Energy LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
 
const int Relay1 = 1; 
const int Relay2 = 41; 
const int Relay3 = 38; 
const int Relay4 = 35; 
const int Relay5 = 48;
 
int Rvalue; // received value from Bluetooth Application
 
 
void setup() {
  Serial.begin(9600); //Baudrate
   
  // Set all the Relays as output
  pinMode(Relay1, OUTPUT);
   pinMode(Relay2, OUTPUT);
     pinMode(Relay3, OUTPUT);
   pinMode(Relay4, OUTPUT);
   
  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
 
    while (1);
  }
 
  // set advertised local name and service UUID:
  BLE.setLocalName("HOME Automation");            // this will appear in the App search result.
  BLE.setAdvertisedService(ledService);
 
  // add the characteristic to the service
  ledService.addCharacteristic(switchCharacteristic);
 
  // add service
  BLE.addService(ledService);
 
  // set the initial value for the characeristic:
  switchCharacteristic.writeValue(0);
 
  // start advertising
  BLE.advertise();
 
  Serial.println("BLE LED Peripheral");
}
 
void loop() {
  // listen for Bluetooth® Low Energy peripherals to connect:
  BLEDevice central = BLE.central();
 
  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());
 
    
  while (central.connected()) {
        if (switchCharacteristic.written()) {
          Rvalue=switchCharacteristic.value(); // received value is stored in variable Rvalue.
 
          // we check the received commands and then accordingly control 
          // all the relays.
          
          if (Rvalue==0) {  
            Serial.println(switchCharacteristic.value() );
            Serial.println("Relay1 OFF");
            digitalWrite(Relay1, LOW); // changed from HIGH to LOW       
          } 
          
          else if(Rvalue==1){                              
            Serial.println(F("Relay1 ON"));
            digitalWrite(Relay1, HIGH); // changed from LOW to HIGH     
          }
          
          else  if (Rvalue==2) {  
            Serial.println(switchCharacteristic.value() );
            Serial.println("Relay2 OFF");
            digitalWrite(Relay2, LOW); // changed from HIGH to LOW       
          } 
          else if(Rvalue==3){                              
            Serial.println(F("Relay2 ON"));
            digitalWrite(Relay2, HIGH); // changed from LOW to HIGH     
          }
          else if (Rvalue==4) {  
            Serial.println(switchCharacteristic.value() );
            Serial.println("Relay3 OFF");
            digitalWrite(Relay3, LOW); // changed from HIGH to LOW       
          } 
          else if(Rvalue==5){                              
            Serial.println(F("Relay3 ON"));
            digitalWrite(Relay3, HIGH); // changed from LOW to HIGH     
          }
            if (Rvalue==6) {  
            Serial.println(switchCharacteristic.value() );
            Serial.println("Relay4 OFF");
            digitalWrite(Relay4, LOW); // changed from HIGH to LOW       
          } else if(Rvalue==7){                              
            Serial.println(F("Relay4 ON"));
            digitalWrite(Relay4, HIGH); // changed from LOW to HIGH     
          }
        }
      }
 
    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}