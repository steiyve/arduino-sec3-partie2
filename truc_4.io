// L&#39;idée est de maintenir la position du servo à 90 degrés de manière à :
// - Pouvoir ajuster à l&#39;aide d&#39;un tournevis le potentiomètre de
// calibration jusqu&#39;à l&#39;arrêt complet de la rotation.
// - Ce faisant on identifie la correction à appliquer au
// positionnement du palonnier

#include <Servo.h>  

Servo Servo_G;
Servo Servo_D;

void setup ()
{
Servo_G.attach(9); // Liaison des servomoteurs à leur broche signal respective
Servo_D.attach(10);
// positionne les servos à 90 degrés
Servo_G.writeMicroseconds(1500);
Servo_D.writeMicroseconds(1500);
}
// positionne le serovo à 90 degrés maintient la position à 90 degrés
void loop ()
{
}
