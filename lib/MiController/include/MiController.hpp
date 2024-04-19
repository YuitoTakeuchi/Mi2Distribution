#pragma once

#include "PWMServo.h"
#include <Wire.h>

class MiController {
public:
    MiController(HardwareSerial& sbus_serial = Serial2, TwoWire& bmx055_wire = Wire, int N_servo = 3, std::vector<int> servo_pins = {2, 3, 4});
    ~MiController();
    void setup();
    void estimate(float euler[3], float acc[3], float gyro[3], float mag[3], float rc[16]);
    void control(const std::vector<float>& servo_output);

    // sensor alignment
    void set_sensor_alignment_matrix(float mat[3][3]);

    void get_position(float pos[3]);
    void get_velocity(float vel[3]);
    void get_acc_bias(float acc_bias[3]);
    void get_gyro_bias(float gyro_bias[3]);

    // set estimated state covariance matrix
    void set_P_position(float val);
    void set_P_velocity(float val);
    void set_P_attitude(float val);
    void set_P_acc_bias(float val);
    void set_P_gyro_bias(float val);

    // set process noise covariance matrix
    void set_Q_velocity(float val);
    void set_Q_attitude(float val);
    void set_Q_acc_bias(float val);
    void set_Q_gyro_bias(float val);

    // set observation noise covariance matrix
    void set_R_acc(float val);
    void set_R_acc_dynamic(float val);
    void set_R_mag(float val);
    void set_R_acc_bias(float val); // observation noise covariance matrix with respect to constraint of acc bias to 0
    void set_R_gyro_bias(float val); // observation noise covariance matrix with respect to constraint of gyro bias to 0
private:
    class Impl;
    Impl* impl;
};