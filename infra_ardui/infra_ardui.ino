const byte SharpIR_B1 = 1; // Broche signal du senseur Sharp
void setup() {
Serial.begin(9600); // Initialise la communication par le port USB à des fins de débogage
pinMode(SharpIR_B1, INPUT);
}
void loop() {
int val = analogRead(SharpIR_B1);

float volts = analogRead(SharpIR_B1)*0.0048828125; // valeur du senseur * (5/1024)
// 5 V et 1024 valeurs
float val2 = 65*pow(volts, -1.10); // conversion en cm par courbe
// de tendance
Serial.println(val2);
delay(50);
}
