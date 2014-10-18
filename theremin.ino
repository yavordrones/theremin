const int trigger = 12; // Pin, an dem der Trigger-Input des HC-SR04 hängt.
const int echo = 13; // wie oben, nur mit Echo-Output
const int speaker = 9; // Pin, an dem der Lautsprecher hängt.

void setup() {
  pinMode(trigger, OUTPUT); // Definition der Pins als Input/Output.
  pinMode(echo, INPUT);
  pinMode(speaker, OUTPUT);
}

void loop() {
  digitalWrite(trigger, LOW); // Diese Sequenz ist notwendig, um die Messung zu starten.
  delay(2);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  int distance = pulseIn(echo, HIGH); // Über die Pulslänge am Echo-Output erhalten wir die Distanz.
  if (distance < 2500) { // Damit das Theremin nicht dauernd Töne von sich gibt, ab einer gewissen Distanz stumm.
    tone(speaker,((distance/4)+800)); // Distanz wird in eine Frequenz (in Hertz) umgerechnet und ausgegeben.
  } else {
    noTone(speaker); // Damit der Ton auch wieder aufhört, wenn die Distanz zu groß ist.
  }
}
