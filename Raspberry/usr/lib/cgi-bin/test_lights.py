#!/usr/bin/env python
import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600)
y = "hello"
x = 0
for letter in 'Python':
	y=ser.readline()
	print(y)
	time.sleep(5)
else:
	print(x)
ser.write('5')
