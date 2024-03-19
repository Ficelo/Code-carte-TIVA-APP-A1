// Définition de la broche à laquelle le capteur LM35 est connecté
#define lm35Pin PD_2

void setup() {
  // Démarre la communication série à une vitesse de 9600 bauds
  Serial.begin(9600);
  pinMode(lm35Pin, INPUT);
}

void loop() {
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
