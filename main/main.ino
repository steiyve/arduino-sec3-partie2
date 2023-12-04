#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const byte trigPin = 12; // Déclaration des 2 broches du capteur
const byte echoPin = 7;



//variables de programme
long distance_cm = 0;
long intervalle_temps = 0;
int liste[10];
byte last_position = 0;
long distance_average = 0;
int pos = 0;    // variable to store the servo position
int allPos[18];


// fonction de calcul de la moyenne
float running_average()
{
    float moyenne = 0;
    for (int i = 0; i < 10; i++)
    {
        moyenne += liste[i];
    }
    moyenne = moyenne / 10;
    return moyenne;
}

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
	liste[last_position] = distance_cm;
	distance_average = running_average();

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
}


void loop() 
{
	for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees
		// in steps of 15 degree
		myservo.write(pos);              // tell servo to go to position in variable 'pos'
		delay(15); 						 // waits 15ms for the servo to reach the position
		allPos[pos] = readSensor();
		Serial.println(distance_average);
		delay(50); // 1/20 seconde sépare chaque prise de mesure
	}


}
