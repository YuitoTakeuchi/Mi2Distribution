# Mi Controller for Distribution

This repository contains the Mi Controller for Distribution project, intended to be distributed in Flying Robot class.

## Table of Contents
- [Getting Started](#getting-started)
- [API](#api)
- [Contributing](#contributing)
- [License](#license)
- [Included Software](#included-software)

## Getting Started

## API
### Core
```c++
void setup();
```
This function sets up kalman filter and communication.
Call this function ONCE in void setup() in main.cpp.

```c++
void estimate(float euler[3], float acc[3], float gyro[3], float mag[3], float rc[16])
```
read sensor values, rc input, and estimate attitude.

args:
- euler: [out] euler angles [rad].
- acc  : [out] accelerometer output [m/s^2]
- gyro : [out] gyrometer output [rad/s]
- mag  : [out] magnetometer output.
- rc   : [out] rc input mapped to -1 to 1.

```c++
void control(const std::vector<float>& servo_output)
```
output pwm signal to specified pins.


### Kalman Filter
```c++
void get_position(float pos[3])
```

```c++
void get_velocity(float vel[3])
```

```c++
void get_acc_bias(float acc_bias[3])
```

```c++
void get_gyro_bias(float gyro_bias[3])
```

```c++
void set_P_position(float val)
```

```c++
void set_P_velocity(float val)
```

```c++
void set_P_attitude(float val)
```

```c++
void set_P_acc_bias(float val)
```

```c++
void set_P_gyro_bias(float val)
```

```c++
void set_Q_velocity(float val)
```

```c++
void set_Q_attitude(float val)
```

```c++
void set_Q_acc_bias(float val)
```

```c++
void set_Q_gyro_bias(float val)
```

```c++
void set_R_acc(float val)
```

```c++
void set_R_acc_dynamic(float val)
```

```c++
void set_R_mag(float val)
```

```c++
void set_R_acc_bias(float val)
```

```c++
void set_R_gyro_bias(float val)
```


### Hardware Configurations
You can use your own hardware configurations.
Change pins written in main.cpp.

By default, following code is set for ﾐ² avionics circuit board.
```c++
// main.cpp

// hardware configuration
HardwareSerial& sbus_serial = Serial2;
TwoWire& bmx055_wire = Wire;
const int N_servo = 3;
const std::vector<int> servo_pins = {2, 3, 4};
```

```c++
void set_sensor_alignment_matrix(float**)
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Included Softwares
This software contains [BasicLinearAlgebra](https://github.com/tomstewart89/BasicLinearAlgebra) and [sbus](https://github.com/bolderflight/sbus).
See the [licenses](licenses) folder.