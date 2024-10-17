#include <LiquidCrystal.h>
LiquidCrystal lcd(4,5,17,18,8,3);
const int inputPins[] = {0,2,40,37,46}; // Pines para las entradas (similar a PORTD)
const int outputPins[] = {1,41,38,35,48}; // Pines de salida (similar a PORTB)

int productoElejido=0;

int btnPress = 0;

void setup() {
  // Configuración de pines
  for (int i = 0; i < 5; i++) {
    pinMode(inputPins[i], INPUT_PULLDOWN);
    attachInterrupt(inputPins[i], getPressBtn, RISING);
  }

  for (int i = 0; i < 5; i++) {
    pinMode(outputPins[i], OUTPUT);
  }

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Interfacing LCD");

  lcd.setCursor(0,1); 
  lcd.print ("Hello world!");
  

  Serial.begin(9600);  // Inicia la comunicación serial a 9600 bps


}

void MotorDeLED(int motor, char* mensaje, char* precio){
  
  lcd.clear();
  lcd.print(mensaje);

  lcd.setCursor(0,1); 
  lcd.print (precio);

  digitalWrite(motor,HIGH);
  delay(5000);
  digitalWrite(motor,LOW);
  lcd.clear();

}

void getPressBtn(){
  btnPress=0;
  for(int i = 0; i<5; i++){
    btnPress++;
    if(digitalRead(inputPins[i]))
      break;
  }
}

void loop() {
 
  getPressBtn();
  switch (btnPress){
    case 1:
      MotorDeLED(1,"Gansito","$15.00");
      break;
    case 2:
      MotorDeLED(1,"Submarinos","$15.00");
      break;
    case 3:
      MotorDeLED(1,"Pinguinos","$15.00");
      break;
    case 4:
      MotorDeLED(1,"Donitas","$15.00");
      break;
    case 5:
      MotorDeLED(1,"Choco Roles","$15.00");
      break;
    default:
      MotorDeLED(1,"Negrito","$15.00");
      break;
  }

}