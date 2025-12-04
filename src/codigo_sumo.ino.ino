//Definir os motores
#define motor1A 2
#define motor1B 3

#define motor2A 4
#define motor2B 5

//Definir os sensores ultrassônicos
#define trigFrente 8
#define trigEsq 10
#define trigDir 6
#define echoFrente 9
#define echoEsq 11
#define echoDir 7


const int linEsq = A1;
const int linDir = A0;
const int linTra = A2;
float distanciaFrente, distanciaEsquerda, distanciaDireita;

//Definir os tipos de cada porta e o estado inicial
void setup() {
  delay(5000);
  pinMode(linEsq, INPUT);
  pinMode(linDir, INPUT);
  pinMode(linTra, INPUT);
 
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  digitalWrite(motor1A,LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A,LOW);
  digitalWrite(motor2B, LOW);
 
  pinMode(trigFrente, OUTPUT);
  pinMode(echoFrente, INPUT);
  pinMode(trigEsq, OUTPUT);
  pinMode(echoEsq, INPUT);
  pinMode(trigDir, OUTPUT);
  pinMode(echoDir, INPUT);
  Serial.begin(9600);
}

// Calcular distancia dos sensores ultrassônicos
long distanciaCM(int trig, int echo) {
  float distancia;
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
 
  distancia = pulseIn(echo, HIGH, 15000);
  if (distancia == 0) return 100;
  return distancia / 58;
}

// Funções para comandos do carro
void frente() {
 
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
 
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void tras() {

  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
 
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

void direita() {

  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
 
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void esquerda() {

  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
 
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

void parar() {

  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
 
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}

// Função principal
void loop() {

// Leituras
  int valorEsq = analogRead(linEsq);
  int valorDir = analogRead(linDir);
  int valorTra = analogRead(linTra);
  distanciaFrente = distanciaCM(trigFrente, echoFrente);
  distanciaEsquerda = distanciaCM(trigEsq, echoEsq);
  distanciaDireita = distanciaCM(trigDir, echoDir);

// Apenas mostrar no monitor serial
  Serial.print(distanciaEsquerda);
  Serial.print(" ");
  Serial.print(distanciaFrente);
  Serial.print(" ");
  Serial.print(distanciaDireita);
  Serial.print(" ");
  Serial.print(valorEsq);
  Serial.print(" ");
  Serial.print(valorTra);
  Serial.print(" ");
  Serial.println(valorDir);

// Lógica de combate
  // SÓ EXECUTA SE ESTIVER SEGURO
  if (valorEsq > 400 && valorDir > 400 && valorTra > 400) {
    if (distanciaFrente < 60) {
      frente(); //Avança para o inimigo caso ele esteja reto
    } else if (distanciaDireita < 60) {
      direita();
    } else if (distanciaEsquerda < 60) {
      esquerda();

    } else {
      direita(); // Girar para procurar o inimigo
    }
  
  // Lógica para se manter na arena
  } else {
    if (valorTra < 400) {
      frente();
      delay(300);
      return;
    }
    if (valorEsq < 400) {
      parar();
      delay(50);
      tras();
      delay(500);
      direita();
      delay(300);
      return;
    }
    if (valorDir < 400) {
      parar();
      delay(50);
      tras();
      delay(300);
      esquerda();
      delay(300);
      return;
    }
  }
}