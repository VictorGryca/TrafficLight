
#include "trafficLight.h"
#include <Arduino.h>

// fazemos referencia da classe que estamos trabalhando para que o compilador entenda
trafficLight::trafficLight(int pR, int pY, int pG) : pinR(pR), pinY(pY), pinG(pG) { // passamos os valores da inicializacao para as variaveis privadas
  // e inicializamos as variaveis de rotacao da LED
  state = 0;
  previousMillis = 0;
} 

// logica da funcao de inicializacao
void trafficLight::begin() {
    pinMode(pinR, OUTPUT);
    pinMode(pinY, OUTPUT);
    pinMode(pinG, OUTPUT);
  // jogamos todos os pinos para LOW como incializacao
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
}

void trafficLight::setIntervals(int tR, int tG, int tY){
  intervals[0] = tR;
  intervals[1] = tG;
  intervals[2] = tY;
}

// logica que mantem o farol funcionando sem parar o void loop()
void trafficLight::update(){
  // define a variavel para o tempo atual
  unsigned long currentMillis = millis();
  // caso o tempo passado desde a ultima ativacao seja maior do que o tempo da LED da sequencia, ele entra no if()
  if(currentMillis - previousMillis > intervals[state]){
    previousMillis = currentMillis;

    // apaga todas as LED (reinicia)
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);

    // avanca para o proximo estado, mas se chegar a 3, volta para 0
    state = (state + 1)%3;

    // liga a led correspondente a 'state'
    switch(state){
      case 0: 
        digitalWrite(pinR, HIGH);
        break;

      case 1: 
        digitalWrite(pinG, HIGH);
        break;

      case 2: 
        digitalWrite(pinY, HIGH);
        break;
    }
  }
}
