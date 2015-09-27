#!/usr/bin/python
#import CGI library
import cgi,cgitb
#serial #import library to work with Arduino via Serial Port
import serial
#import time/delay library
import time
#Create instance of FieldStorage to get values from html
form_data = cgi.FieldStorage()
# Get data from fields
if form_data.getvalue('subject'):
   value = form_data.getvalue('subject')
# If no data chosen - error message
else:
   value = "Error"
ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)
ser.write('value')
print "Content-type:text/html\r\n\r\n"
print "<html>"
print "<head>"
print "<h1>Hello!</h1>"
print "<title>This is a program to switch lights</title>"
print "</head>"
print "<body>"
print "<h2> You have chosen %s</h2>" % value
print "</body>"
print "</html>"