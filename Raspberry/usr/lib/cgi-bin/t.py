#!/usr/bin/env python
#-*- coding: UTF-8 -*-
 
#enable debugging
import cgitb
cgitb.enable()
import cgi
import  serial
import  time
 
form = cgi.FieldStorage()
if form.getvalue('submit'):
   value = form.getvalue('Zal3')
else:
   value = "Error"
ser = serial.Serial('/dev/ttyACM0', 9600)

time.sleep(2)

if "141142" in form:
   string = '141142'
elif "143144" in form:
   string = '143144'
elif "141" in form:
   string = '141'
elif "142" in form:
   string = '142'
elif "143" in form:
   string = '143'
elif "144" in form:
   string = '144'
elif "199" in form:
   string = '199'
elif "121131" in form:
   string = '121131'

elif "190" in form:
   string = '190'
elif "VentON" in form:
   string = '111'
elif "VentOFF" in form:
   string = '110'
elif "WorkZone" in form:
   string = '123'
elif "TV-TV" in form:
   string = '841843843843843843844'
elif "TV-Comp" in form:
   string = '841843844'
elif "845" in form:
   string = '845'
elif "846" in form:
   string = '846'
elif "847" in form:
   string = '847'
elif "848" in form:
   string = '848'
elif "849" in form:
   string = '849'
elif "850" in form:
   string = '850'
elif "851" in form:
   string = '851'
elif "852" in form:
   string = '852'
elif "125126" in form:
   string = '125126'
elif "124" in form:
   string = '124'
elif "120" in form:
   string = '120'
elif "134" in form:
   string = '134'
elif "130" in form:
   string = '130'
elif "770" in form:
   string = '770'
elif "771" in form:
   string = '771'

elif "WorkZone" in form:
   string = '123'

else:
   string = '126'

ser.write(string)

print "Content-type:text/html\n\n"
print "<html>"
print "<head>"
print "<h1>Hello!</h1>"
print "<title>Prototype v0.1</title>"
print "</head>"
print "<body>"
#  print "<form action="cgi-bin/t.py" method="get">"
#  print "<input type="submit" value="OK" />"
#  print "</form>"
print "<h2> You have chosen %s</h2>" % value
print "</body>"
print "</html>"
