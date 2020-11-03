#pragma once
// clang-format off

/*
    6_pack_stepstick_XYZ_v1.h

    Covers all V1 versions V1p0, V1p1, etc

    Part of Grbl_ESP32
    Pin assignments for the ESP32 I2S 6-axis board
    2018    - Bart Dring
    2020    - Mitch Bradley
    2020    - Michiyasu Odaki
    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/
#define MACHINE_NAME            "6 Pack Controller StepStick XYZ"

#define N_AXIS 3

// === Special Features

// I2S (steppers & other output-only pins)
#define USE_I2S_OUT
#define USE_I2S_STEPS
//#define DEFAULT_STEPPER ST_I2S_STATIC
// === Default settings
#define DEFAULT_STEP_PULSE_MICROSECONDS I2S_OUT_USEC_PER_PULSE

#define USE_STEPSTICK   // makes sure MS1,2,3 !reset and !sleep are set

#define I2S_OUT_BCK             "gpio.22"
#define I2S_OUT_WS              "gpio.17"
#define I2S_OUT_DATA            "gpio.21"


// Motor Socket #1
#define X_DISABLE_PIN           "i2so.0"
#define X_DIRECTION_PIN         "i2so.1"
#define X_STEP_PIN              "i2so.2"

// Motor Socket #2
#define Y_DIRECTION_PIN         "i2so.4"
#define Y_STEP_PIN              "i2so.5"
#define Y_DISABLE_PIN           "i2so.7"

// Motor Socket #3
#define Z_DISABLE_PIN           "i2so.8"
#define Z_DIRECTION_PIN         "i2so.9"
#define Z_STEP_PIN              "i2so.10"

/*
    Socket I/O reference
    The list of modules is here...
    https://github.com/bdring/6-Pack_CNC_Controller/wiki/CNC-I-O-Module-List
    Click on each module to get example for using the modules in the sockets


Socket #1
#1 "gpio.33" 
#2 "gpio.32"
#3 "gpio.35" (input only)
#4 "gpio.34" (input only)

Socket #2
#1 "gpio.2"
#2 "gpio.25"
#3 "gpio.39" (input only)
#4 "gpio.36" (input only)

Socket #3
#1 "gpio.26"
#2 "gpio.4"
#3 "gpio.16"
#4 "gpio.27"

Socket #4
#1 "gpio.14"
#2 "gpio.13"
#3 "gpio.15"
#4 "gpio.12"

Socket #5
#1 "i2so.24"  (output only)
#2 "i2so.25"  (output only)
#3 "i2so.26"  (output only)

*/


// 4x Input Module in Socket #1
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
#define X_LIMIT_PIN                 "gpio.33"
#define Y_LIMIT_PIN                 "gpio.32"
#define Z_LIMIT_PIN                 "gpio.35"


// // 4x Input Module in Socket #2
// // https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
// #define X_LIMIT_PIN                 "gpio.2"
// #define Y_LIMIT_PIN                 "gpio.25"
// #define Z_LIMIT_PIN                 "gpio.39"

// // 4x Input Module in Socket #3
// // https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
// #define CONTROL_CYCLE_START_PIN      "gpio.26"
// #define CONTROL_FEED_HOLD_PIN        "gpio.4"
// #define CONTROL_RESET_PIN            "gpio.16"
// #define CONTROL_SAFETY_DOOR_PIN      "gpio.27"
// //#define INVERT_CONTROL_PIN_MASK      B0000

// ================= Setting Defaults ==========================
#define DEFAULT_X_STEPS_PER_MM      800
#define DEFAULT_Y_STEPS_PER_MM      800
#define DEFAULT_Z_STEPS_PER_MM      800
