/*
verde = puerto 21
amarillo = 20
rojo = 19
*/
// Definir pines para entradas y salidas
//const int inputPins[] = {2, 3, 4, 5}; // Pines para las entradas (similar a PORTD)
int interuptor0 = 1;
int interuptor1 = 2; 
const int outputPins[] = {14,13,12,11,10}; // Pines de salida (similar a PORTB)

// Función para leer el estado de los pines de entrada y formar un valor binario

//LOW, HIGH
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
  // Configuración de pines

  pinMode(interuptor0, INPUT);
  pinMode(interuptor1, INPUT);

  for (int i = 0; i < 6; i++) {
    pinMode(outputPins[i], OUTPUT);
  }
}
void loop() {
  if(digitalRead(interuptor0))
    funcion_UnoCero();

  if(digitalRead(interuptor1))
    funcion_CeroUno();
  
  if(digitalRead(interuptor0)&&digitalRead(interuptor1)){
    
    funcion_UnoCero();
    funcion_CeroUno();
  }
}