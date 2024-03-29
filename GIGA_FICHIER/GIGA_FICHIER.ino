#include "Iseplogo128.h"
#define lm35Pin PD_2 // capteur de température
const int buttonPin = 2; // le bouton poussoir
const int potentiometrePin = A0;

int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(lm35Pin, INPUT);
  pinMode(buttonPin, INPUT);

  InitI2C();
  InitScreen();

  Display(ficelocorp); // affichage du logo sur l'écran OLED
  
  void test_fft();
}

void capteurTemperature() {
  // Lit la tension sur la broche du capteur LM35
  int sensorValue = analogRead(lm35Pin);

  // Convertit la valeur lue en température en degrés Celsius
  float temperature = (sensorValue * 3.3 / 4096.0) * 100.0;

  // Affiche la température sur le moniteur série
  Serial.print("Valeur numérique = ");
  Serial.print(sensorValue);
  Serial.print(" / Température: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Attend 1 seconde avant de lire à nouveau la température
  delay(1000);
}

void capterBoutonPoussoir() {
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    Serial.println("Bouton appuyé");
  } else {
    // turn LED off:
    Serial.println("Bouton relâché");
  }
}

void capterPotentiometre(){
  int valeurNumerique = analogRead(pinPotentiometer); // Lire la valeur analogique
  float tension = valeurNumerique * (5.0 / 1023.0); // Convertir la valeur en tension (0-5V)

  // Afficher les valeurs
  Serial.print("Valeur numérique = ");
  Serial.print(valeurNumerique);
  Serial.print(" / Tension correspondante = ");
  Serial.print(tension, 3); // Afficher la tension avec 3 chiffres après la virgule
  Serial.println(" Volts.");

  delay(500); // Attendre un court instant avant de lire à nouveau
}

void envoyerBluetooth(){
  Serial1.print( "AT+NAMEG04E");    // envoyer au module Bluetooth
}


}
void loop() {
  // put your main code here, to run repeatedly: 
  capteurTemperature();
  capterBoutonPoussoir();
  capterPotentiometre();
  envoyerBluetooth();
}
