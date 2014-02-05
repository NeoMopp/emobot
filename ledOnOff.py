import serial;

ser = serial.Serial('/dev/ttyACM0', 9600)

while True:
	t = input('Light on or off, 1 for on 0 for off')

	if t == 1:
		//turn led on
		ser.write('c1')

	else if t == 0:
		//turn led off
		ser.write('c0')

	else:
		print('invalid command')
	