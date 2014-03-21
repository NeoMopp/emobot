#!/usr/bin/env python
import sys
from twython import Twython, TwythonStreamer

class MyStreamer(TwythonStreamer):
	def on_success(self, data):
		if 'text' in data:
			t = data['text'].encode('utf-8')
			if t.find("happy") == 1:
				#do something
				print t
			elif t.find("sad") == 1:
				#do something
				print t
			elif t.find("fear") == 1:
				#do something
				print t
			elif t.find("anger") == 1:
				#do something
				print t
			elif t.find("suprise") == 1:
				#do something
				print t
			elif t.find("disgust") == 1:
				#do something
				print t
			elif t.find("dance") == 1:
				#do something
				print t
			else:
				print t					
				print "Hello Friend"
				
	def on_error(self, status_code, data):
		print status_code

CONSUMER_KEY = 'xUfEkO7tRfU8AP2nhgSv5Q'
CONSUMER_SECRET = 'DNM6HU9Ea65stWXwzFKefMqhwJ1wgtmwjHwm4XzftrA'
ACCESS_KEY = '231817345-lUr55qZRkUs4GCRKTNlBzRuzDH6KoePf0uByh1RR'
ACCESS_SECRET = 'mz7OT8g5xAsP1Nt9nyUiwmXKrtMJicuLoDjWGTvy7XKfa'

#api = Twython(CONSUMER_KEY,CONSUMER_SECRET,ACCESS_KEY,ACCESS_SECRET) 

#api.update_status(status=sys.argv[1])

stream = MyStreamer(CONSUMER_KEY,CONSUMER_SECRET,ACCESS_KEY,ACCESS_SECRET)
stream.user()
