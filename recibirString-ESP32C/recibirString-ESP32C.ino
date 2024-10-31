#define DEBUG

#if defined DEBUG
#define DBG_PRINT(x) Serial.print(x)
#define DBG_PRINTLN(x) Serial.println(x)
#else
#define DBG_PRINT(x)
#define DBG_PRINTLN(x)
#endif

#include <ArduinoBLE.h>

// Definición del servicio y la característica BLE
BLEService systemService("c515cb47-87e6-4623-89d9-233ce5a508c1");
BLECharacteristic ledCharacteristic("d7192f62-1a52-4ee0-9c3b-8c29b18ef85b", BLERead | BLEWrite, 20); // Tamaño 20 bytes

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    DBG_PRINTLN("Starting Bluetooth Low Energy module failed!");
    while (1);
  }

  BLE.setLocalName("Arduino_Iot");
  BLE.setAdvertisedService(systemService);
  systemService.addCharacteristic(ledCharacteristic);
  BLE.addService(systemService);
  ledCharacteristic.writeValue("0"); // Estado inicial apagado

  BLE.advertise();
  DBG_PRINTLN("Bluetooth device active, waiting for connections...");
}

void loop() {
  BLE.poll();

  // Verificamos si el valor de la característica ha cambiado
  if (ledCharacteristic.written()) {
    // Convertimos el valor de uint8_t* a String
    String receivedString((const char*)ledCharacteristic.value(), ledCharacteristic.valueLength());
    
    // Imprimir el string recibido en el monitor serial
    Serial.print("Mensaje recibido como string: ");
    Serial.println(receivedString);
  }
}
