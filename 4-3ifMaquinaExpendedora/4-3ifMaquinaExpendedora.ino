/*
INCOVENIENTES
1. se tuvo problemas con el boton por no definir la pantalla
*/ 
#include <LiquidCrystal.h>
const int inputPins[] = {45,2,40,37,46}; // Pines para las entradas (similar a PORTD)
const int outputPins[] = {1,41,38,35,48}; // Pines de salida (similar a PORTB)

LiquidCrystal lcd(4,5,17,18,8,3);

int productoElejido=0;

void EleccionPago(int motor,int opcion){
  switch (opcion) {
    case 1:
      lcd.clear();
      lcd.print("Gancito $15");
      break;

    case 2:
      lcd.clear();
      lcd.print("a");
      break;

    case 3:
      lcd.clear();
      lcd.print("b");
      break;

    case 4:
      lcd.clear();
      lcd.print("c");
      break;

    case 5:
      lcd.clear();
      lcd.print("d");
      break;
    
  }

  digitalWrite(motor,HIGH);
  delay(5000);
  digitalWrite(motor,LOW);
  lcd.clear();
}

void setup() {

  //configuracion de pantalla
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("Interfacing LCD");

    lcd.setCursor(0,1); 
    lcd.print ("Hello ");

  // Configuración de pines
  for (int i = 0; i < 5; i++) {
    pinMode(inputPins[i], INPUT);
  }

  for (int i = 0; i < 5; i++) {
    pinMode(outputPins[i], OUTPUT);
  }


}
int i=0;
void loop() {
i++;
if(digitalRead(inputPins[i])){
  EleccionPago(outputPins[i], i+1);
}

if(i>=4)
  i=0;

}
