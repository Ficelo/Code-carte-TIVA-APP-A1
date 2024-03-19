const int pinPotentiometer = A0; // Définir la broche à laquelle le potentiomètre est connecté

void setup() {
  Serial.begin(9600); // Initialiser la communication série à 9600 bauds
}

void loop() {
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
