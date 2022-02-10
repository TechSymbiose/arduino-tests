# **L293D Motor Driver**

Code written by Adrien Louvrier, 04/02/2021

*Objective* : motor control with a L293D motor driver

Card used : Arduino Uno

# Electronic circuit

## **List of the components**

Component | Quantity 
----------|----------
Arduino Uno | 1
DC motor | 1
L293D motor driver | 1
potentiometer | 1

*input* : 
- potentiometer (X axis pin -> pin A0, Vcc pin -> 5V pin, grd pin -> grd pin)

*output* :
- L293 motor driver (IN1 pin -> pin 9, IN2 pin -> pin 10, Vcc pin -> 5V pin, grd pin -> grd pin) with DC motor connected to A+ and A-
