# Description :

  This project is the implementation of a PID regulation on a custom Atmega32U4 microcontroller.
  
  * erreur.c measure the error between the output and the command
  * PID.c calculate the three component Kp, Ki & Kd
  * USB.c send data to the computer through USB

# Needed :

  * Lufa library for virtual serial communication. It is available at the [following repository](https://github.com/jmfriedt/l3ep/tree/master/LUFA_light)
  * Atmega library for the use of the Atmega32U4. 

# Installation :

  1. Clone the repository ```git clone https://github.com/J-A371/PID.m```
  2. Change makefile's paths REP & REPEEA
  3. ```make``` to compile
  4. ```make install``` to push it on the custom hardware
