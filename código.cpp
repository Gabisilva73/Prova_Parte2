#include <WiFi.h>
#include <HTTPClient.h>

#define led_azul 18 // Pino utilizado para controle do led azul
#define led_verde 2 // Pino utilizado para controle do led verde
#define led_vermelho 40 // Pino utilizado para controle do led vermelho
#define led_amarelo 9 // Pino utilizado para controle do led amarelo
#define botaoPino 5

//const int botaoPino = 5;  // o número do pino do botão
int botaoEstado = 0;  // variável para leitura do status do botão

const int ldrPin = 4;  // o número do pino do ldr
int threshold=600;

void setup() {

  // Configuração inicial dos pinos para controle dos leds como OUTPUTs (saídas) do ESP32
  pinMode(led_azul,OUTPUT);
  pinMode(led_verde,OUTPUT);
  pinMode(led_vermelho,OUTPUT);
  pinMode(led_amarelo, OUTPUT);

  // Inicialização das entradas
  pinMode(botaoPino, INPUT); // Inicialize o pino do botão como uma entrada

  digitalWrite(led_azul, LOW);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_vermelho, LOW);

  Serial.begin(9600); // Configuração para debug por interface serial entre ESP e computador com baud rate de 9600
  
      // Verifica estado do botão
  botaoEstado = digitalRead(botaoPino);
  if (botaoEstado == HIGH) {
    Serial.println("Botão pressionado!");
  } else {
    Serial.println("Botão não pressionado!");
  }

}

void loop() {

  int ldrstatus=analogRead(ldrPin);

  if(ldrstatus<=threshold){
    Serial.print("está escuro! ligue o led");
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(9, HIGH);
  delay(1000);

  } else{
    Serial.print("está claro! desligue a luz");
    Serial.println(ldrstatus);
  }
}