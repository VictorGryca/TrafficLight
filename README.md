# Traffic Light

Este projeto implementa um sistema de semáforo para ESP32 em que cada farol é um objeto dentro da clasee trafficLight.

## O que ele pretende fazer?

O código pretende controlar um semáforo de forma não-bloqueante, alternando automaticamente entre os estados. Também pretende ser modular, englobando toda a lógica em uma classe.

## Como funciona?

1. **Inicialização**: 
   - Define os pinos dos LEDs (17 para vermelho, 16 para amarelo, 4 para verde)
   ```cpp
   // iniciamos o objeto da classe com os pinos das LEDs(vermelho, amarelo, verde)
   trafficLight light1(17,16,4);
   ```
   No setup():
   ```cpp
   void setup() {
      light1.begin(); // setup do objeto
      light1.setIntervals(6000, 4000, 2000); // define intervalos que cada LED deve ficar ligada (vermelho, verde, amarelo)
   }
   ```
   - Configura os intervalos de tempo para cada LED (6000ms vermelho, 4000ms verde, 2000ms amarelo)

2. **Execução**:
   ```cpp
   void loop() {
      // roda a logica do farol sem deixar o loop preso em um  "delay()"
      light1.update();
   }
   ```
   - O método `update()` é chamado continuamente no `loop()`
   - A lógica usa temporização não-bloqueante (sem `delay()`), permitindo que o ESP32 execute outras tarefas simultaneamente.

## Hardware

- ESP32 DEV BOARD
- led vermelha
- led amarela 
- led verde
- 3x resitor 330 Ω

![Esquemático](/assets/esquematico.png)

Pensando nas especificações das LEDs, as cores amarelo e vermelho giram em torno de 1,5V a 2,5V, já a verde tem uma tensão um pouco maior, 3V. Todas trabalham até **20mA**. Porém, como os resistores de 330Ω estavam mais disponíveis, e fazem as LEDs operarem com grau satisfatório de brilho, escolhi usar eles para todas as LEDs.

Cálculo usado para mostrar a viabilidade do uso dos resistores:

3.3V-2V = 1.3V

U/R = i -> 1.3V/330Ω -> **4mA** (corrente abaixo dos 20mA de limite)


 [Vídeo para documentação](https://youtu.be/fruQscyJI1c)

