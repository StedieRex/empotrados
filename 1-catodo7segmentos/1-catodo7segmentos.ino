
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

// Función para mostrar valores en los pines de salida (simulando un display de 7 segmentos)
void displayOutput(int val) {
  switch (val) {
    case 0b0000: // Muestra 0
      digitalWrite(outputPins[0], HIGH);
      digitalWrite(outputPins[1], HIGH);
      digitalWrite(outputPins[2], HIGH);
      digitalWrite(outputPins[3], LOW);
      digitalWrite(outputPins[4], LOW);
      digitalWrite(outputPins[5], LOW);
      digitalWrite(outputPins[6], HIGH);
      break;
    case 0b0001: // Muestra 1
      digitalWrite(outputPins[0], LOW);
      digitalWrite(outputPins[1], HIGH);
      digitalWrite(outputPins[2], LOW);
      digitalWrite(outputPins[3], LOW);
      digitalWrite(outputPins[4], HIGH);
      digitalWrite(outputPins[5], LOW);
      digitalWrite(outputPins[6], LOW);
      break;
    case 0b0010: // Muestra 2
      digitalWrite(outputPins[0], HIGH);
      digitalWrite(outputPins[1], HIGH);
      digitalWrite(outputPins[2], LOW);
      digitalWrite(outputPins[3], HIGH);
      digitalWrite(outputPins[4], HIGH);
      digitalWrite(outputPins[5], LOW);
      digitalWrite(outputPins[6], HIGH);
      break;
    case 0b0011: // Muestra 3
      digitalWrite(outputPins[0], HIGH);
      digitalWrite(outputPins[1], HIGH);
      digitalWrite(outputPins[2], HIGH);
      digitalWrite(outputPins[3], HIGH);
      digitalWrite(outputPins[4], LOW);
      digitalWrite(outputPins[5], LOW);
      digitalWrite(outputPins[6], HIGH);
      break;
    case 0b0100: // Muestra 4
      digitalWrite(outputPins[0], LOW);
      digitalWrite(outputPins[1], HIGH);
      digitalWrite(outputPins[2], HIGH);
      digitalWrite(outputPins[3], LOW);
      digitalWrite(outputPins[4], LOW);
      digitalWrite(outputPins[5], HIGH);
      digitalWrite(outputPins[6], HIGH);
      break;
    case 0b0101: // Muestra 5
      digitalWrite(outputPins[0], HIGH);
      digitalWrite(outputPins[1], LOW);
      digitalWrite(outputPins[2], HIGH);
      digitalWrite(outputPins[3], HIGH);
      digitalWrite(outputPins[4], LOW);
      digitalWrite(outputPins[5], HIGH);
      digitalWrite(outputPins[6], HIGH);
      break;
    case 0b0110: // Muestra 6
      digitalWrite(outputPins[0], HIGH);
      digitalWrite(outputPins[1], LOW);
      digitalWrite(outputPins[2], HIGH);
      digitalWrite(outputPins[3], HIGH);
      digitalWrite(outputPins[4], HIGH);
      digitalWrite(outputPins[5], HIGH);
      digitalWrite(outputPins[6], HIGH);
      break;
    case 0b0111: // Muestra 7
      digitalWrite(outputPins[0], HIGH);
      digitalWrite(outputPins[1], HIGH);
      digitalWrite(outputPins[2], HIGH);
      digitalWrite(outputPins[3], LOW);
      digitalWrite(outputPins[4], LOW);
      digitalWrite(outputPins[5], LOW);
      digitalWrite(outputPins[6], LOW);
      break;
    default:
      // Apaga todos los segmentos si no hay coincidencia
      for (int i = 0; i < 7; i++) {
        digitalWrite(outputPins[i], LOW);
      }
      break;
  }
}

void setup() {
  // Configuración de pines
  for (int i = 0; i < 4; i++) {
    pinMode(inputPins[i], INPUT);
  }

  for (int i = 0; i < 7; i++) {
    pinMode(outputPins[i], OUTPUT);
  }
}

void loop() {
  int op = readInputs();
  displayOutput(op);
}
