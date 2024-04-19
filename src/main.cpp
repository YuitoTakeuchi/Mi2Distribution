#include <Arduino.h>

#include "control.hpp"
#include "MiController.hpp"

// hardware configuration
HardwareSerial& sbus_serial = Serial2;
TwoWire& bmx055_wire = Wire;
const int N_servo = 3;
const std::vector<int> servo_pins = {2, 3, 4};

// initialize MiController
MiController mi_controller(sbus_serial, bmx055_wire, N_servo, servo_pins);

void setup() {
    // setup controller
    mi_controller.setup();
}

void loop() {
    // Get sensor values and estimated attitude.
    float euler[3], acc[3], gyro[3], mag[3], rc[16];
    mi_controller.estimate(euler, acc, gyro, mag, rc);

    // generate control command
    std::vector<float> servo_output(N_servo);
    control(euler, acc, gyro, mag, rc, servo_output);

    // servo
    mi_controller.control(servo_output);
}