# **LCD Screen Clock**

Code written by Adrien Louvrier

*Objective* : display the date and time on the serial monitor and on a lcd screen

Card used : Arduino Mega 2560

# Electronic circuit

## **List of the components**

Component | Quantity 
----------|----------
Arduino Mega 2560 | 1
RTC clock module | 1
lcd screen | 1

*input* : 
 - RTC clock module (SCL pin -> pin 21, SDA pin -> pin 20, VCC pin -> pin 5V, grd pin -> grd pin)

*output* : 
- lcd screen (rs pin -> pin 32, en pin -> pin 30, d4 pin -> pin 28, d5 pin -> pin 26, d6 pin -> pin 24, d7 pin -> pin 22, Vcc pin -> 5V pin, grd pin -> grd pin)