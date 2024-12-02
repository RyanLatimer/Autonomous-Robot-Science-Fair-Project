## Autonomous Path Navigation Robot Using Ultasonic Sensors

## Description

This project is to build an autonomous robot that usess Raspberry Pi Pico and HC-SRO4 ultrasonic sensor to navigate a course without prior knowledge of the shape of the course.
This robot will be capable of navigating turns in the path and has been optimized for the limited resources that are being used in the original project. 
Becuase this project only uses one motor controller, the turning mechanism will only rotate one direction. This is in an effor to keep the robot small and the power supply minimal. 
Those resoucres are listed below:

## Resources:

1x Raspberry Pi Pico 2 (any model will work)
3x HC-SRO4 Ultrasonic Distance Sensor
1x 3AA Batter Pack
1x H-Bridge Motor Controller Integrated Circuit

## Installation

1. Esnure that you have the latest version of MicroPython for your Raspberry Pi Pico accessible at https://www.raspberrypi.com/documentation/microcontrollers/micropython.html
2. Download the main.py file located in the [Programs](Programs) Folder and flash it onto the Pico - Add link to locations
3. Rebuild the circuitry according to the schematics and CAD files loacted in the Design Folder -Add link to loactions

## Usage
Utilize the program according to the instruction in the USAGE.md file. - Add link to location

## Liscense
This work is liscened under the GNU General Public Liscense GPLv3 - see the [LICENSE](LICENSE) file for details
