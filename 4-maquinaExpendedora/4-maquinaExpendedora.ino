#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 17, 18, 8, 3);
const int inputPins[] = {2, 40, 37, 45, 47 }; // Pines para las entradas (similar a PORTD)
const int outputPins[] = {1, 41, 38, 35, 48 }; // Pines de salida (similar a PORTB)

const int btnMoneda = 19; // Pines para las entradas (similar a PORTD)
const int MonedaLED = 20; // Pines de salida (similar a PORTB)

volatile int btnPress = -1;

void setup() {
  // Configuración de pines de entrada
  for (int i = 0; i < 5; i++) {
    pinMode(inputPins[i], INPUT_PULLDOWN);
    attachInterrupt(digitalPinToInterrupt(inputPins[i]), getPressBtn, RISING);
  }

  // Configuración de pines de salida
  for (int i = 0; i < 5; i++) {
    pinMode(outputPins[i], OUTPUT);
  }

  pinMode(btnMoneda, INPUT_PULLDOWN);
  pinMode(MonedaLED,OUTPUT);

  digitalWrite(MonedaLED, LOW);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Interfacing LCD");

  lcd.setCursor(0, 1); 
  lcd.print("Hello world!");

  Serial.begin(9600);  // Inicia la comunicación serial a 9600 bps
}

void MotorDeLED(int motor, const char* mensaje, const char* precio,bool modenda) {
  bool salida = true;

  lcd.clear();
  lcd.print(mensaje);
  lcd.setCursor(0, 1); 
  lcd.print(precio);

  
  digitalWrite(MonedaLED,LOW);
  while(salida){
      if(digitalRead(btnMoneda)){
        digitalWrite(MonedaLED,HIGH);
        salida=false;
        delay(1000);
      }
      digitalWrite(MonedaLED,LOW);
  }

  digitalWrite(motor, HIGH);
  delay(5000);
  digitalWrite(motor, LOW);
  lcd.clear();
}

void getPressBtn() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(inputPins[i])) {
      btnPress = i; // Actualiza btnPress según el botón presionado
      break;
    }
  }
}

void loop() {
  if (btnPress != -1) {
    switch (btnPress) {
      case 0:
        MotorDeLED(outputPins[0], "Gansito", "$15.00");
        break;
      case 1:
        MotorDeLED(outputPins[1], "Submarinos", "$15.00");
        break;
      case 2:
        MotorDeLED(outputPins[2], "Pinguinos", "$15.00");
        break;
      case 3:
        MotorDeLED(outputPins[3], "Donitas", "$15.00");
        break;
      case 4:
        MotorDeLED(outputPins[4], "ChocoRoles", "$15.00");
        break;
      default:
        MotorDeLED(outputPins[5], "Seleccione", "$el producto");
        break;
    }
    btnPress = -1;  // Reinicia la variable para detectar la próxima interrupción
  }
}