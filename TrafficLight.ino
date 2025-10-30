#include "trafficLight.h"

// iniciamos o objeto da classe com os pinos das LEDs(vermelho, amarelo, verde)
trafficLight light1(17,16,4);

void setup() {
  light1.begin(); // setup do objeto
  light1.setIntervals(6000, 4000, 2000); // define intervalos que cada LED deve ficar ligada (vermelho, verde, amarelo)
}

void loop() {
  // roda a logica do farol sem deixar o loop preso em um "delay()"
  light1.update();
}
