#include <ArduinoBLE.h>
 
BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // Bluetooth® Low Energy LED Service
 
// Bluetooth® Low Energy LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
 
const int outputPins[] = {1,41,38,35,45}; // Pines de salida (similar a PORTB)
 
int Rvalue; // received value from Bluetooth Application
 

//funciones de los leds
void funcion_UnoCero(){
    int time = 300;
    digitalWrite(14,HIGH);
    delay(time);
    for(int i=1;i<5;i++){
      digitalWrite(outputPins[i-1],HIGH);
      digitalWrite(outputPins[i],HIGH);
      delay(time);
      digitalWrite(outputPins[i-1],LOW);
      delay(time);
    }


    for(int i=0; i<5; i++){
      digitalWrite(outputPins[i], LOW);
    }
}

void funcion_CeroUno(){
    int time = 300;
    digitalWrite(10,HIGH);
    delay(time);
    for(int i=4;i>0;i--){
      digitalWrite(outputPins[i],HIGH);
      digitalWrite(outputPins[i-1],HIGH);
      delay(time);
      digitalWrite(outputPins[i],LOW);
      delay(time);
    }


    for(int i=0; i<5; i++){
      digitalWrite(outputPins[i], LOW);
    }
}

void setup() {
  Serial.begin(9600); //Baudrate
   
  // Set all the Relays as output
  for (int i = 0; i < 6; i++) {
    pinMode(outputPins[i], OUTPUT);
  }
   
  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
 
    while (1);
  }
 
  // set advertised local name and service UUID:
  BLE.setLocalName("ESP32-Equipo5");            // this will appear in the App search result.
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
 
bool semaforo=false,serie1=false,serie2=false,serieCOM=false;
bool primeravez=true; 
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
        //41=amarillo 38=verde 1 = rojo

        switch (Rvalue) {
        case 0: semaforo=true; break;
        case 1: serie1=true; break;
        case 2: serie2=true; break;
        case 3: serieCOM=true; break;
        case 4: semaforo=false;serie1=false;serie2=false;serieCOM=false; break;
        }
      }
        if (semaforo) {  
          if(primeravez){
            digitalWrite(38, LOW);
            digitalWrite(1, LOW);
            primeravez=false;
          }

          digitalWrite(38,HIGH);
          delay(5000);
          for(int i=0;i<5;i++){
            digitalWrite(38,HIGH);
            delay(500);
            digitalWrite(38,LOW);
            delay(500);
          }
          digitalWrite(38,LOW);
          
          digitalWrite(41,HIGH);
          delay(2000);
          digitalWrite(41,LOW);

          digitalWrite(1,HIGH);
          delay(5000);
          digitalWrite(1,LOW);
        } 
        else if(serie1){                              
          funcion_UnoCero();    
        }
        else  if (serie2) {  
          funcion_CeroUno();     
        } 
        else if(serieCOM){                              
          funcion_UnoCero();
          funcion_CeroUno();    
        }

    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}