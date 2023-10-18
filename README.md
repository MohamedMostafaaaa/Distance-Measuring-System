# Fan-Speed-Controller
Developing a system that controls the speed of a fan based on the temperature value
# Hardware Used:
* ATmega32 Microcontroller
* DC Motor
* H Bridge
* LM35 Temprature Sensor
* LCD
# Project on Proteus:
![image](https://github.com/MohamedMostafaaaa/Fan-Speed-Controller/assets/134022125/394c5414-1c59-405b-9626-3add20d740bd)
# Drivers Used:
* GPIO
* LCD
* PWM
* ADC
* DC Motor
* LM35-Sensor
# Project Functionalities
we are changing the Temprature using the Sensor LM35 and based on it fan speed changes as follows:
* If the temperature is less than 30C turn off the fan.
* If the temperature is greater than or equal 30C turn on the fan with 25% of its 
maximum speed
* If the temperature is greater than or equal 60C turn on the fan with 50% of its 
maximum speed
* If the temperature is greater than or equal 90C turn on the fan with 75% of its 
maximum speed.
* If the temperature is greater than or equal 120C turn on the fan with 100% of its 
maximum speed.
