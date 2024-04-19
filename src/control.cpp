#include "control.hpp"
// write control rule here.
// args:
// euler [in]: Euler angles [rad]. Roll, pitch, yaw.
// acc   [in]: acceleration [m/s^2]. x, y, z. x is forward, y is right, z is down.
// gyro  [in]: angle velocity [rad/s]. Roll, pitch, yaw.
// rc    [in]: rc command
// servo_output [out]: pwm signal to output．-1 ~ 1．
void control(const float euler[3], const float acc[3], const float gyro[3], const float mag[3], const float rc[16], std::vector<float>& servo_output) {
    // below is an example of control.
    servo_output[0] = rc[1]; // elevator
    servo_output[1] = rc[3]; // rudder
    servo_output[2] = rc[2]; // throttle

    // output to serial monitor
    Serial.print("euler [deg]: ");
    Serial.print(euler[0] * 180 / M_PI); Serial.print(" ");
    Serial.print(euler[1] * 180 / M_PI); Serial.print(" ");
    Serial.print(euler[2] * 180 / M_PI); Serial.print(" ");
    Serial.println("");

    digitalWriteFast(13, HIGH); // LED on
    delay(10);
}