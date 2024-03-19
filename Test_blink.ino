#define voltage PA_2

void setup() {
  Serial:Begin(9600);
  pinMode(voltage, OUTPUT);
}

void loop() {
  digitalWrite(voltage, HIGH);
  delay(1000);
  digitalWrite(voltage, LOW);
  delay(1000);
}
