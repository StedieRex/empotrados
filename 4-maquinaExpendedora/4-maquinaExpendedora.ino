/*
INCOVENIENTES
1. se tuvo problemas con el boton por no definir la pantalla
*/ 
#include <LiquidCrystal.h>
const int inputPins[] = {0,2,40,37,46}; // Pines para las entradas (similar a PORTD)
const int outputPins[] = {1,41,38,35,48}; // Pines de salida (similar a PORTB)

LiquidCrystal lcd(4,5,17,18,8,3);

int productoElejido=0;

void MotorDeLED(int motor){
  lcd.clear();
  lcd.print("Gancito $15");

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
    lcd.print ("Hello world!");

  // Configuración de pines
  for (int i = 0; i < 5; i++) {
    pinMode(inputPins[i], INPUT);
  }

  for (int i = 0; i < 5; i++) {
    pinMode(outputPins[i], OUTPUT);
  }


}

void loop() {
  digitalRead()
  int opcion=0;
  bool salir=true;
  int i=0;
  do{
    if(digitalRead(inputPins[i])){
      opcion=i;
      salida=false;
    }
      
    i++;
    if(i<5)
      i=0
  }while(salir);

  switch (opcion) {
      case 1:
        MotorDeLED(1);
        break;
      case 2:
        MotorDeLED(1);
        break;
      case 3:
        MotorDeLED(1);
        break;
      case 4;
        MotorDeLED(1);
        break;
      case 5;
        MotorDeLED(1);
        break;
      default:
          break;
  }

}
