
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);

  // remplacer le "G02x" par votre numero d'équipe dans les 2 lignes suivantes
  Serial.println("AT+NAMEG02x");	// visualiser sur la console pour verification
  Serial1.print( "AT+NAMEG02x");		// envoyer au module Bluetooth
}

void loop()
{
  
  while(1)
    ;
  
}
