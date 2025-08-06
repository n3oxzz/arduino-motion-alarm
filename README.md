# Arduino Motion Alarm System
### Final Project — Physics 11

## Scope & Purpose
This project is a motion alarm system built on Arduino using the MPU-6050 sensor.  
The MPU-6050 includes a 3-axis gyroscope and accelerometer, allowing the system to calculate angular motion.  
A complementary filter is used to smooth out the sensor data, and when a threshold angle of 5° is detected, an active buzzer is triggered.

The system is designed to be mounted on a door (with a reference position of 0°). When the door opens and reaches 5°, the alarm is activated.

## Circuit Diagram
![Circuit](images/circuit-diagram(motion-alarm).png)

## Demo
[Watch Demo](https://www.youtube.com/shorts/lRnNpZ3W_hQ)

## Project Document
[Project Document (PDF)](Final-Project-Doc.pdf)

## License
[MIT]([https://opensource.org/license/mit/](https://mit-license.org/))
