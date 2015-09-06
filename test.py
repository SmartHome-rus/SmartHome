
#!/usr/bin/env python
import serial
ser = serial.Serial('/dev/ttyACM0', 9600)
x = "test"
y = 0
for (y<3, y++) {
	x=ser.readline()
	print(x)
	delay(1000)
}
ser.write('5')