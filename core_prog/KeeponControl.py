import serial;
import sys;
import time
#Arrays to hold the commands we want to send.
#SOUND PLATY 23, MOVE PON DOWN
soundPlay = []
soundRepeat =[]
movePan = []
moveTilt = []

#Add things to our lists, faster than doing it manually, much code wow
for x in xrange(64):
	soundPlay.append('SOUND PLAY ' +str(x) + ';')
	soundRepeat.append('SOUND REPEAT ' +str(x)+ ';')

for x in xrange(-100, 101):
	movePan.append('MOVE PAN '+str(x)+';')
	moveTilt.append('MOVE TILT '+str(x)+';') 
		

#define a variable for the serial port.
#try catch to prevent errors.
try:
	brain = serial.Serial(sys.argv[1],sys.argv[2])
except:
	print  "Failed to connect with device."




for sound in  soundPlay:
#try catch for sending commands to the serial port
	try:
		brain.write(sound)
		time.sleep(5)
	except:
		print "Failed to send command"

