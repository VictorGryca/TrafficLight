

class trafficLight {

private:
  int pinR, pinY, pinG;

public:
  // construtor 
  trafficLight(int pR, int pY, int pG) : pinR(pR), pinY(pY), pinG(pG) {}

  void begin() {
    pinMode(pinR, OUTPUT);
    pinMode(pinY, OUTPUT);
    pinMode(pinG, OUTPUT);

    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
  }

  // pisca qualquer LED
  void blink(int pin, int d) {
    digitalWrite(pin, HIGH);
    delay(d);
    digitalWrite(pin, LOW);
  }

  // funcoes para cada cor que chamam a funcao principal
  void redBlink(int d)   { blink(pinR, d); }
  void yellowBlink(int d){ blink(pinY, d); }
  void greenBlink(int d) { blink(pinG, d); }

};

trafficLight light1(17,16,4);


void setup() {
  light1.begin();

}

// - 6 segundos no vermelho
// - 4 segundos no verde
// - 2 segundos no amarelo
void loop() {
  light1.redBlink(6000);
  light1.greenBlink(4000);
  light1.yellowBlink(2000);

}
