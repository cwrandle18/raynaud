# raynaud
Code for driving temperature sensor based tinker project

Developers: Wilson Randle and Tilden Chima

Raynaud's Disease is a condition that causes restricted blood flow in response to cold. 
It particularly affects extremeties such as the fingers, toes, or ears.
This results in a loss of feeling, or numbness in the affected areas.

Project Raynaud is a wearable device that aims to alleviate those affected with Raynaud's disease.

A glove is worn over the user's hand.
An Arduino LilyPad, along with a LilyPad Temperature Sensor and Songle SRD-05VDC-SL-C Relay are used in the control/logic setup.
A small heating pad is used to heat the interior of the glove.
An external power supply (18V DC - two 9V batteries) is used to power the heating pad.

The LilyPad Temperature Sensor is connected to the Arduino LilyPad via sewn in conducting steel thread.
The Arduino Lilypad itself is sewn into the glove. The supporting breadboard, relay, and circuit wiring components are mounted
in a small box mounted on the wrist portion of the glove.
When the temperature from the sensor is measured to be below a certain threshold defined by a simple variable "threshold",
the Arduino switches the relay on, which then turns on the heating pad via external 18V DC power supply.
When the temperature is above the threshold, the Arduino switches the relay off, and the heating pad is no longer turned on.

The .ino file contains the pin configurations we used, along with scaling the measured temperature and comparing that against
the threshold we set, and controlling the output pin to the relay as needed.
