// Definir el pin GPIO 10
const int pin = 13;

void setup() {
  // Configura el pin como salida
  pinMode(pin, OUTPUT);

  // Coloca el pin en estado alto (HIGH)
  digitalWrite(pin, HIGH);
}

void loop() {
  // No se necesita código en el loop para mantener el pin en alto
}

