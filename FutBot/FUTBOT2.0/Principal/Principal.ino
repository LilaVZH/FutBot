#include "BluetoothSerial.h"
#include "CarController.h"
#include <functional>  // Librería para std::function y std::bind

const char *pin = "1234";  // Cambia este PIN por uno más seguro.
String device_name = "ESP32-BT-Slave";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth no está habilitado! Por favor, ejecuta `make menuconfig` para habilitarlo
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth no disponible o no habilitado. Solo está disponible para el chip ESP32.
#endif

BluetoothSerial SerialBT;  // Instancia para la comunicación Bluetooth

// Crear una instancia del controlador del carro (Orientación a objetos)
CarController car(15, 2, 4, 16);  // Inicializar con los pines correctos

void setup() {
    Serial.begin(9600);  // Iniciar comunicación serial
    SerialBT.begin(device_name);  // Nombre del dispositivo Bluetooth
    Serial.printf("El dispositivo con el nombre \"%s\" está iniciado.\n¡Ahora puedes emparejarlo con Bluetooth!\n", device_name.c_str());
}

// Definir un tipo de callback para comandos (Callbacks)
using CommandCallback = std::function<void()>;

// Función para manejar los comandos recibidos
void handleCommand(char command, CommandCallback forward, CommandCallback backward, CommandCallback right, CommandCallback left, CommandCallback stop) {
    switch (command) {
        case 'F':
            forward();  // Llamar al callback para mover hacia adelante
            break;
        case 'B':
            backward();  // Llamar al callback para mover hacia atrás
            break;
        case 'R':
            right();  // Llamar al callback para girar a la derecha
            break;
        case 'L':
            left();  // Llamar al callback para girar a la izquierda
            break;
        case '0':
            stop();  // Llamar al callback para detener
            break;
        default:
            break;
    }
}

void loop() {
    if (SerialBT.available()) {  // Si hay datos disponibles en Bluetooth
        char command = SerialBT.read();  // Leer el comando
        // Llamar a handleCommand con los callbacks correspondientes (Callbacks y punteros a funciones)
        handleCommand(command, 
                      std::bind(&CarController::moveForward, &car),  // Asignar la función de mover hacia adelante
                      std::bind(&CarController::moveBackward, &car),  // Asignar la función de mover hacia atrás
                      std::bind(&CarController::moveRight, &car),  // Asignar la función de girar a la derecha
                      std::bind(&CarController::moveLeft, &car),  // Asignar la función de girar a la izquierda
                      std::bind(&CarController::stop, &car));  // Asignar la función de detener
        Serial.write(command);  // Enviar el comando por serial
    }
}
