# cool-light-drums
An awesome responsive light system for drums.

Bill of Materials:

* Very cool drums. Better if it are DIY with upciclyng materials.
* Arduino Nano (or any other fiiting arduino)
* 1 USB cable fitting your arduino connector.
* 2  1 Mega Ohm resistors
* 2 Piezo discs
* 2 potentiometes
* Strips of WS2812B Leds (or anny other smart addressable leds, changes in code needed).
* 1 Momentry switch
* A power bank or any other source of portble power source. Other componets needed depending of the power source.

Requirements

* Arduino IDE (I use 1.8.1)
* FastLed 3.1
* Button, by Michael Adams

Conections:

Piezo 1:
* Black to common ground
* Red to Arduino A0

Piezo 2:
* Black to common ground
* Red to Arduino A1

Resistors:
* In parallel with Piezo 1 and piezo 2

Potentiometers
* Lead A to +5V
* Lead B to commond ground
* Cursor to Arduino A3 (pot 1) and Arduino A4 (pot 2)

Button 
* Side A to commond ground
* Side B to Arduino D3

Led Strips
* GND to common ground
* DIN to Arduino D6 (Strip 1) and Arduino D7 (Strip 2)
* VIN to Arduino +5v


Note that depending of the numbers of LEDs and power drawn by leds can be a bad idea power them directly from the Arduino.


Let's Play.
