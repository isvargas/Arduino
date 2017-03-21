/*
 * Acende o led conforme o que receber na Serial
 * L -> Liga
 * D -> Desliga
 */

int LED = 13;
int valor = 0;
 
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    
    valor = Serial.read();
    
    if (valor == 'L') {
      digitalWrite(LED, HIGH);
    }

    if (valor == 'D') {
      digitalWrite(LED, LOW); 
    } 
         
  }
}
