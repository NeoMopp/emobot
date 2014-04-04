#!/usr/bin/env python
import sys
import time
import serial
from twython import Twython, TwythonStreamer

class MyStreamer(TwythonStreamer):
	def on_success(self, data):
		if 'text' in data:
			t = data['text'].encode('utf-8')
			if t.find("happy") == 1:
				arduino.write("MOVE SIDE LEFT;")
				time.sleep(2)
				arduino.write("MOVE SIDE RIGHT;")
				time.sleep(2)
				arduino.write("MOVE SIDE LEFT;")
				time.sleep(2)
				arduino.write("MOVE SIDE RIGHT;")
				time.sleep(2)
				arduino.write("MOVE PON UP;")
				time.sleep(2)
				arduino.write("MOVE PON DOWN;")
				time.sleep(2)
				print t
				print ' Happy!'
			elif t.find("sad") == 1:
				arduino.write("SOUND PLAY 23;")
				time.sleep(2)
				arduino.write("MOVE TILT 100;")
				time.sleep(2)
				arduino.write("MOVE PAN 25;")
				time.sleep(2)
				arduino.write("MOVE PAN -25;")
				time.sleep(2)
				arduino.write("MOVE PAN 0;")
				time.sleep(2)
				arduino.write("MOVE PON UP;")
				time.sleep(2)
				arduino.write("MOVE PON DOWN;")
				time.sleep(2)
				print t
				print ' Sad !'
			elif t.find("fear") == 1:
				arduino.write("MOVE TILT 0;")
				time.sleep(2)
				arduino.write("SOUND PLAY 44;")
				time.sleep(2)
				arduino.write("SOUND PLAY 44;")
				time.sleep(2)
				arduino.write("MOVE TILT 100;")
				time.sleep(2)
				print t
				print 'Fear'
			elif t.find("anger") == 1:
				arduino.write("MOVE SIDE LEFT;")
				time.sleep(2)
				arduino.write("MOVE SIDE RIGHT;")
				time.sleep(2)
				arduino.write("MOVE SIDE LEFT;")
				time.sleep(2)
				arduino.write("MOVE SIDE RIGHT;")
				time.sleep(2)
				arduino.write("MOVE TILT 100;")
				time.sleep(2)
				arduino.write("MOVE TILT -100;")
				time.sleep(2)
				arduino.write("MOVE TILT 100;")
				time.sleep(2)
				arduino.write("MOVE TILT -100;")
				time.sleep(2)
				print t
			elif t.find("suprise") == 1:
				arduino.write("SOUND PLAY 49;")
				time.sleep(2)
				arduino.write("MOVE PON 100;")
				time.sleep(2)
				print t
			elif t.find("disgust") == 1:
				arduino.write("MOVE PAN 25;")
				time.sleep(2)
				arduino.write("MOVE PAN -25;")
				time.sleep(2)
				arduino.write("SOUND PLAY 41;")
				time.sleep(2)
				print t
				print 'Disgust'
			elif t.find("dance") == 1:
				#do something
				print t
			else:
				print t					
				
	def on_error(self, status_code, data):
		print status_code

CONSUMER_KEY = 'xUfEkO7tRfU8AP2nhgSv5Q'
CONSUMER_SECRET = 'DNM6HU9Ea65stWXwzFKefMqhwJ1wgtmwjHwm4XzftrA'
ACCESS_KEY = '231817345-lUr55qZRkUs4GCRKTNlBzRuzDH6KoePf0uByh1RR'
ACCESS_SECRET = 'mz7OT8g5xAsP1Nt9nyUiwmXKrtMJicuLoDjWGTvy7XKfa'

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
