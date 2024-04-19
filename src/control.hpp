#pragma once
#include <Arduino.h>

void control(const float euler[3], const float acc[3], const float gyro[3], const float mag[3], const float rc[16], std::vector<float>& servo_output);