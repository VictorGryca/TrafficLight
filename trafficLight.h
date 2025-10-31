class trafficLight {

private:
  // pinos das LEDs e state para definir de qual LED eh a vez
  int pinR, pinY, pinG, state;
  // tempo antigo, para comparar com o tempo atual e ver delay
  unsigned long previousMillis;
  // para organizar os intervalos das LEDs em um array
  int intervals[3];


public:
  // construtor 
  trafficLight(int pR, int pY, int pG);
  // declaracao da funcao de inicializacao
  void begin();
  // declaracao a funcao que guarda o tempo que cada LED deve ficar ligada
  void setIntervals(int tR, int tY, int tG);
  // declaramos a funcao de atualizacao da logica do farol
  void update();

};
