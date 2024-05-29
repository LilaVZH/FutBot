// CarController.h
#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include <Arduino.h>

// Clase para controlar el movimiento del carro
class CarController {
public:
    // Constructor para inicializar los pines
    CarController(int ma1, int ma2, int mb1, int mb2);

    // Método para mover el carro hacia adelante
    void moveForward();

    // Método para mover el carro hacia atrás
    void moveBackward();

    // Método para girar el carro a la derecha
    void moveRight();

    // Método para girar el carro a la izquierda
    void moveLeft();

    // Método para detener el carro
    void stop();

private:
    int ma1, ma2, mb1, mb2;  // Pines del motor
};

#endif // CARCONTROLLER_H
