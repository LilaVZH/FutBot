// CarController.cpp
#include "CarController.h"

// Constructor para inicializar los pines
CarController::CarController(int ma1, int ma2, int mb1, int mb2) 
    : ma1(ma1), ma2(ma2), mb1(mb1), mb2(mb2) {
    pinMode(ma1, OUTPUT);
    pinMode(ma2, OUTPUT);
    pinMode(mb1, OUTPUT);
    pinMode(mb2, OUTPUT);
}

// Método para mover el carro hacia adelante
void CarController::moveForward() {
    digitalWrite(ma1, HIGH);
    digitalWrite(ma2, LOW);
    digitalWrite(mb1, LOW);
    digitalWrite(mb2, HIGH);
}

// Método para mover el carro hacia atrás
void CarController::moveBackward() {
    digitalWrite(ma1, LOW);
    digitalWrite(ma2, HIGH);
    digitalWrite(mb1, HIGH);
    digitalWrite(mb2, LOW);
}

// Método para girar el carro a la derecha
void CarController::moveRight() {
    digitalWrite(ma1, LOW);
    digitalWrite(ma2, HIGH);
    digitalWrite(mb1, LOW);
    digitalWrite(mb2, HIGH);
}

// Método para girar el carro a la izquierda
void CarController::moveLeft() {
    digitalWrite(ma1, HIGH);
    digitalWrite(ma2, LOW);
    digitalWrite(mb1, HIGH);
    digitalWrite(mb2, LOW);
}

// Método para detener el carro
void CarController::stop() {
    digitalWrite(ma1, LOW);
    digitalWrite(ma2, LOW);
    digitalWrite(mb1, LOW);
    digitalWrite(mb2, LOW);
}
