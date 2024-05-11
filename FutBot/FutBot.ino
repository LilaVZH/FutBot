#include "BluetoothSerial.h"

//#define USE_PIN // Uncomment this to use PIN during pairing. The pin is specified on the line below
const char *pin = "1234";  // Change this to more secure PIN.

String device_name = "ESP32-BT-Slave";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

char estado = 'g';

const int MA1 = 15;
const int MA2 = 2;
const int MB1 = 4;
const int MB2 = 16;

void setup() {
  Serial.begin(9600);
  SerialBT.begin(device_name);  //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);

  // delay(3000);
}


void loop() {

  if (SerialBT.available()) {
    estado = SerialBT.read();
    //BTserial.print(num);
    if (estado == 'F') {

      mov_adel();
      Serial.write(estado);
      //tiempo = 0;
    } else if (estado == 'B') {
      mov_atras();
      Serial.write(estado);
      //tiempo = 0;
    } else if (estado == 'R') {
      mov_der();
      Serial.write(estado);
      //tiempo = 0;
    } else if (estado == 'L') {
      mov_izq();
      Serial.write(estado);
      //tiempo = 0;
    }

    else if (estado == '0') {
      Stop();
      Serial.write(estado);
      //      tiempo = 0;
    }

  }
}
void mov_adel() {
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);

}

void mov_atras() {
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
}
void mov_der() {
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);
}

void mov_izq() {
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
}

void Stop() {
  digitalWrite(MA1, 0);
  digitalWrite(MA2, 0);
  digitalWrite(MB1, 0);
  digitalWrite(MB2, 0);
}


