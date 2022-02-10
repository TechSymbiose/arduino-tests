# **Motor Fan Control**

Code written by Adrien Louvrier, 08/01/2021

*Objective* : control a DC motor with a button

Card used : Arduino Uno

# Electronic circuit

## **List of the components**

Component | Quantity 
----------|----------
Arduino Uno | 1
motor | 1
diode | 1
transistor | 1
220 Ohms resistor | 1
button | 1
10kOhms resistor | 1

*input* : 
 - A button connected to 5V and pin 3 with a 10kOhms resistor in parallel connected to 5V and grd

*output* : 
- DC motor in parallel with a diode, transistor and 220 Ohms resistor connected to pin 5, 5V and grd