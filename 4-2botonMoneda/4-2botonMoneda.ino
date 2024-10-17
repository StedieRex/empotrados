/*
INCOVENIENTES
1. se tuvo problemas con el boton por no definir la pantalla
*/ 
#include <LiquidCrystal.h>
const int btnMoneda = 19; // Pines para las entradas (similar a PORTD)
const int MonedaLED = 20; // Pines de salida (similar a PORTB)

LiquidCrystal lcd(4,5,17,18,8,3);

void setup() {

  //configuracion de pantalla
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("Interfacing LCD");

    lcd.setCursor(0,1); 
    lcd.print ("Hello ");

  // Configuración de pines
  pinMode(btnMoneda, INPUT);

  pinMode(MonedaLED, OUTPUT);


}

void loop() {
  bool salida = true;
  digitalWrite(MonedaLED,HIGH);
  while(salida){
      if(digitalRead(btnMoneda)){
        digitalWrite(MonedaLED,LOW);
        salida=false;
        delay(5000);
      }
  }
}
