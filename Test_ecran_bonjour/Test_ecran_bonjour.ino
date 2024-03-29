void setup() {
  Serial.begin(9600);
  Serial.println("--- Bonjour");
}

int n = 0;

void loop() {
  Serial.println("n= "); 
  Serial.println(n++);
  
}
