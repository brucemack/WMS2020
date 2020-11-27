Arduino Light Controller
========================
This is an Arduino sketch for controling a holiday light display based on an 74HC595 shift 
register and some solid state relays.

There are three important control pins on the Arduino:

* SER (pin 9) the serial data output
* SRCLK (pin 8) for clocking the shift register to the right
* RCLK (pin 7) for latching the state of the shift register into the solid state relays

The write() function goes through a complete write cycle for 16 channel display.

Here's what the sketch looks like in action: https://www.youtube.com/watch?v=BPyLeSQ0ga8
