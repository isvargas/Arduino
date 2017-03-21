/*
 * Acende um led qdo o LDR deixa de receber luz
 */

int LED = 13;
int LDR = 0;
int VALOR = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // le o valor do ldr
  VALOR = analogRead(LDR);

  //se o valor lido for maior que 500, liga o led
  if (VALOR >= 500)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);

  //imprime o valor lido do LDR no monitor serial
  Serial.println(VALOR);
  
  delay(100);
}
