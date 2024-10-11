
/*
verde = puerto 21
amarillo = 20
rojo = 19
*/
// Definir pines para entradas y salidas
//const int inputPins[] = {2, 3, 4, 5}; // Pines para las entradas (similar a PORTD)
int interuptor0 = 1;
int interuptor1 = 2; 
const int outputPins[] = {14,13,12,11,10,9}; // Pines de salida (similar a PORTB)

// Función para leer el estado de los pines de entrada y formar un valor binario

//LOW, HIGH
void funcion_UnoCero(){
  digitalWrite(13,HIGH);
}
void setup() {
  // Configuración de pines

  pinMode(interuptor0, INPUT);
  pinMode(interuptor1, INPUT);

  for (int i = 0; i < 6; i++) {
    pinMode(outputPins[i], OUTPUT);
  }
}
void loop() {
  if(digitalRead(interuptor0)==1){
    funcion_UnoCero();
  }
  //funcion_CeroUno();
  //funcion_UnoUno();
}
