#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo motor_left;
Servo motor_right;

const byte trigPin = 12; // Déclaration des 2 broches du capteur
const byte echoPin = 7;



//variables de programme
long distance_cm = 0;
long intervalle_temps = 0;
int liste[10];
byte last_position = 0;
long distance_average = 0;
int pos = 0;    // variable to store the servo position



int readSensor(){
	// le senseur est activé par un pulse HIGH d’au moins 10 microsecondes.
	// à la reception de ce signal il envoie une série de 8 ondes sonores (40KHz) (i.e. ultrason)
	digitalWrite(trigPin, LOW); // reset du trigPin pour la validité du signal HIGH (excès de zèle?)
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	// lecture de la réponse
	intervalle_temps = pulseIn(echoPin, HIGH); // Temps en µs séparant l&#39;envoi de la réception



	distance_cm = (intervalle_temps * 0.03435) / 2;

	Serial.print("distance non smooth: ");
	Serial.println(distance_cm);
	


	last_position++;
	if (last_position == 10)
	{
		last_position = 0;
	}
	return distance_average;
}

void setup() 
{
	Serial.begin (9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  motor_left.attach(3);
  motor_right.attach(6);
}


void loop() 
{
  for (byte i = 0; i <= 180; i =i + 10)
  {
    myservo.write(i);
    //Serial.println(i);
    readSensor();

    motor_left.writeMicroseconds(150);
    motor_right.writeMicroseconds(150);
    delay(50);
  }
  delay(10);
  myservo.write(0);
}
