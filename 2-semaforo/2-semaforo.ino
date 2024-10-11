
/*
verde = puerto 21
amarillo = 20
rojo = 19
*/
// Definir pines para entradas y salidas
const int inputPins[] = {2, 3, 4, 5}; // Pines para las entradas (similar a PORTD)
const int outputPins[] = {21, 20, 19}; // Pines de salida (similar a PORTB)

// Función para leer el estado de los pines de entrada y formar un valor binario
int readInputs() {
  int value = 0;
  for (int i = 0; i < 4; i++) {
    value |= digitalRead(inputPins[i]) << i;
  }
  return value;
}

void parpadeo(){
  digitalWrite(21,HIGH);
  delay(1000);
  digitalWrite(20,LOW);
  delay(1000);
}

void setup() {
  // Configuración de pines
  for (int i = 0; i < 4; i++) {
    pinMode(inputPins[i], INPUT);
  }

  for (int i = 0; i < 3; i++) {
    pinMode(outputPins[i], OUTPUT);
  }
}
//LOW, HIGH
bool primeravez=true;
void loop() {
  if(primeravez){
    digitalWrite(20, LOW);
    digitalWrite(21, LOW);
    primeravez=false;
  }

  digitalWrite(21,HIGH);
  delay(5000);
  for(int i=0;i<5;i++){
    digitalWrite(21,HIGH);
    delay(500);
    digitalWrite(21,LOW);
    delay(500);
  }
  digitalWrite(21,LOW);
  
  digitalWrite(20,HIGH);
  delay(2000);
  digitalWrite(20,LOW);

  digitalWrite(19,HIGH);
  delay(5000);
  digitalWrite(19,LOW);

}
