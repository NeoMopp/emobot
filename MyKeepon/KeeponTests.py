import serial ;
import sys;

#Make the needed data structures.
soundPlay = []
soundRepeat =[]
i = -1

#Add things to our lists, faster than doing it manually, much code wow
for x in xrange(64):
	soundPlay.append('SOUND PLAY ' +str(x) + ';')
	soundRepeat.append('SOUND REPEAT ' +str(x)+ ';')

try:
	ser = serial.Serial(sys.argv[1], 115200)
except:
	print'Failed to connect to device'

while True:
	t = input('Play next sound?: ')
	if t == 1:
		i+=1
		try:
			ser.write(soundPlay[i])
			print(soundPlay[i])
		except:
			print'Failed to play sound'
	elif t == 2:
		try:
			ser.write(soundPlay[i])
			print(soundPlay[i])
		except:
			print'Failed to play sound'
	elif t == 3:
		break	
	else:
		print('Invalid command')
