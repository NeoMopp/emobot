#!/usr/bin/env python
import sys
import time
import serial
from twython import Twython, TwythonStreamer

global arduino

class MyStreamer(TwythonStreamer):
	def on_success(self, data):
		if 'text' in data:
			t = data['text'].encode('utf-8')
			if "happy" in t:
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE PON UP;")
				arduino.write("MOVE PON DOWN;")
				print t
				print ' Happy!'
			elif "sad" in t:
				arduino.write("SOUND PLAY 23;")
				arduino.write("MOVE TILT 100;")
				arduino.write("MOVE PAN 25;")
				arduino.write("MOVE PAN -25;")
				arduino.write("MOVE PAN 0;")
				arduino.write("MOVE PON UP;")
				arduino.write("MOVE PON DOWN;")
				print t
				print ' Sad!'
			elif "fear" in t:
				arduino.write("MOVE TILT 0;")
				arduino.write("SOUND PLAY 44;")
				arduino.write("SOUND PLAY 44;")
				arduino.write("MOVE TILT 100;")
				print t
				print 'Fear!'
			elif "anger" in t:
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE TILT 100;")
				arduino.write("MOVE TILT -100;")
				arduino.write("MOVE TILT 100;")
				arduino.write("MOVE TILT -100;")
				print t
				print 'Suprise!'
			elif "suprise" in t:
				arduino.write("SOUND PLAY 49;")
				arduino.write("MOVE PON 100;")
				print t
			elif "disgust" in t:
				arduino.write("MOVE PAN 25;")
				arduino.write("MOVE PAN -25;")
				arduino.write("SOUND PLAY 41;")
				print t
				print 'Disgust!'
			elif "dance" in t:
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE PON UP;")
				arduino.write("MOVE PON DOWN;")
				arduino.write("MOVE PON UP;")
				arduino.write("MOVE PON DOWN;")
				arduino.write("MOVE PAN 50;")
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE PON UP;")
				arduino.write("MOVE PON DOWN;")
				arduino.write("MOVE PON UP;")
				arduino.write("MOVE PON DOWN;")
				arduino.write("MOVE PAN -50;")
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE SIDE LEFT;")
				arduino.write("MOVE SIDE RIGHT;")
				arduino.write("MOVE PON UP;")
				arduino.write("MOVE PON DOWN;")
				arduino.write("MOVE PON UP;")
				arduino.write("MOVE PON DOWN;")
				arduino.write("MOVE PAN 0;")
				print t
				print 'Lets Dance!'
			else:
				print t					
				
	def on_error(self, status_code, data):
		print status_code

CONSUMER_KEY = ''
CONSUMER_SECRET = ''
ACCESS_KEY = ''
ACCESS_SECRET = ''

#api = Twython(CONSUMER_KEY,CONSUMER_SECRET,ACCESS_KEY,ACCESS_SECRET) 

#api.update_status(status=sys.argv[1])

try:
	arduino = serial.Serial("/dev/ttyACM0", 115200)
except:
	print 'Failed to connect to device'

while True:
	t = raw_input('Please Connect Device. Is Device Connected?(Y/N): ' )
	if t == 'Y':
		print 'Testing..'
		arduino.write("MOVE PON UP;")
		t2 = raw_input('Was test successful?')
		if t2 == 'Y':
			print 'Program Starting...'
			break
		else:
			'Resetting'

stream = MyStreamer(CONSUMER_KEY,CONSUMER_SECRET,ACCESS_KEY,ACCESS_SECRET)
stream.user()
