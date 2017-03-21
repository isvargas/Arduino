/*
 * Controlar motor com Drive Ponte H
 * 
 * MOTOR          IN1/IN3    IN2/IN4
 * ---------------------------------
 * HORARIO          HIGH       LOW
 * ANTI HORARIO     LOW        HIGH
 * PONTO MORTO      LOW        LOW
 * FREIO            HIGH       HIGH
 *
 * Ivan S. Vargas - contato@is5.com.br
 */

//pinos que controlam Motor A
int IN1 = 7;
int IN2 = 8;

void setup() {
  // configura pinos
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Girar sentido horario");
  // gira o motor A no sentido horario por 5 segundos
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(5000);

  Serial.println("Parar por 2 segundos");
  // para por 2 segundos
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(2000);

  Serial.println("Girar sentido anti-horario");
  // gira o motor A no sentido antihorario por 5 segundos
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(5000);

  Serial.println("Parar por 2 segundos");
  // para por 2 segundos
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(2000);
}
