/*
 * Controlar motor com Drive Ponte H e IRremote
 * 
 * Ivan S. Vargas - contato@is5.com.br
 * 
 * MOTOR          IN1/IN3    IN2/IN4
 * ---------------------------------
 * HORARIO          HIGH       LOW
 * ANTI HORARIO     LOW        HIGH
 * PONTO MORTO      LOW        LOW
 * FREIO            HIGH       HIGH
 */

#include <IRremote.h>

//pinos que controlam Motor A
int IN1 = 8;
int IN2 = 9;

//pinos que controlam Motor B
//ATENCAO, COMO ESTE MOTOR ESTA EM SENTIDO OPOSTO AO MOTOR B
//A PINAGEM AKI DEVE SER AO CONTRARIO, PARA QUE AMBOS GIREM NO
//MESMO SENTIDO (SE NAO, QDO UM ESTIVER HORARIO O OUTRO
//ESTARA ANTIHORARIO)
int IN3 = 11;
int IN4 = 10;

//receptor inframevermelho
int RECV = 13;

float valor;

IRrecv irrecv(RECV);
decode_results results;

void paraFrente() {
  //os dois motores girando no mesmo sentido antihorario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void paraTras() {
  //os dois motores no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void paraDireita() {
  //motor A sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  //motor B sentido antihorario
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void paraEsquerda() {
  //motor A sentido antihorario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  //motor B sentido horario
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void frear() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void pontoMorto() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Valor lido: ");
    Serial.println(results.value, HEX);
    
    valor = (results.value);
    
    if (valor == 0xFF629D) { 
      //UP = para frente
      Serial.println("Para frente...");
      paraFrente();
    }
    else if (valor == 0xFFA857) {
      //DOWN = para tras
      Serial.println("Para tras...");
      paraTras();
    }
    else if (valor == 0xFF22DD) {
      //eskerda
      Serial.println("Para esquerda...");
      paraEsquerda();
    }
    else if (valor == 0xFFC23D) {
      //direita
      Serial.println("Para direita...");
      paraDireita();
    }
    else if (valor == 0xFF02FD) {
      //parar
      Serial.println("Frear...");
      frear();      
    }
    //le o proximo valor
    irrecv.resume();
  }
  delay(200);
}
