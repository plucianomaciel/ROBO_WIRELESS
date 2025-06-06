#include <SoftwareSerial.h>
#include <Servo.h> // Biblioteca para o servo

SoftwareSerial espSerial(2, 3); // RX, TX do Arduino

#define IN1 10
#define IN2 9
#define IN3 6
#define IN4 5

int potA = 255;
int potB = 255;
int pot_manobra = 150;

char codigo;

// Servo
Servo meuServo;
const int pinoServo = 7; // Pino digital 7

void Frente() {
  analogWrite(IN1, potA);
  analogWrite(IN2, 0);
  analogWrite(IN3, potB);
  analogWrite(IN4, 0);
}

void Re() {
  analogWrite(IN1, 0);
  analogWrite(IN2, potA);
  analogWrite(IN3, 0);
  analogWrite(IN4, potB);
}

void GiroHorario() {
  analogWrite(IN1, pot_manobra);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, pot_manobra);
}

void GiroAntiHorario() {
  analogWrite(IN1, 0);
  analogWrite(IN2, pot_manobra);
  analogWrite(IN3, pot_manobra);
  analogWrite(IN4, 0);
}

void Pare() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}

void AcionarServo() {
  meuServo.write(150); // Gira para 135°
  delay(300);          // Espera 300 ms
  meuServo.write(90);  // Volta para 90°
}

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);

  meuServo.attach(pinoServo);
  meuServo.write(90); // Posição inicial

  Pare();
  delay(2000);
}

void loop() {
  if (espSerial.available()) {
    codigo = espSerial.read();
    Serial.println(codigo);
    switch (codigo) {
      case '1':
        Frente();
        break;
      case '2':
        GiroAntiHorario();
        break;
      case '3':
        GiroHorario();
        break;
      case '4':
        Re();
        break;
      case '0':
        Pare();
        break;
      case '5':
        AcionarServo(); // Aciona o servo!
        break;
    }
  }
}
