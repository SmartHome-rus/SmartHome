#!/usr/bin/python

# Import modules for CGI handling
import cgi, cgitb
import serial
import time

# Create instance of FieldStorage to get values from html form
form = cgi.FieldStorage()

# Get data from fields
if form.getvalue('subject'):
   value = form.getvalue('subject')
# If no data chosen - error message
else:
   value = "Error"
ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)
ser.write('1')
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