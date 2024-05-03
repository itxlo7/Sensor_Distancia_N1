// Definición de pines
const int trigPin = 4;
const int echoPin = 5;
const int greenLED = 10;
const int yellowLED = 9;
const int redLED = 8;
const int pinBuzzer = 7;

void setup() {
  pinMode(trigPin, OUTPUT); // El pin de Trig como salida
  pinMode(echoPin, INPUT);  // El pin de Echo como entrada
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Calcula la distancia en centímetros

  // Control de LEDs y Buzzer
  if (distance > 17 || distance <= 0) {
    // Nada cerca
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    noTone(pinBuzzer);
  } else if (distance > 10 && distance <= 17) {
    // Algo detectado a distancia moderada
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    noTone(pinBuzzer);
  } else if (distance <= 10) {
    // Algo muy cerca
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    tone(pinBuzzer, 1000);
  }

  delay(100); // Breve pausa entre mediciones
}