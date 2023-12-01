const byte trigPin = 12; // Déclaration des 2 broches du capteur
const byte echoPin = 7;

//variables de programme
long distance_cm = 0;
long intervalle_temps = 0;
int liste[10];
byte last_position = 0;
long distance_average = 0;


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

void setup() 
{
	Serial.begin (9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}


void loop() 
{
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


	Serial.println(distance_average);
	delay(50); // 1/20 seconde sépare chaque prise de mesure
}
