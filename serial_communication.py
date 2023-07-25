from codecs import utf_16_encode
import serial
arduino = serial.Serial('COM10', 200, timeout=.1)
data = bytes('hands', 'utf-8')

arduino.write(data)

while True:
    
    #the last bit gets rid of the new-line chars
    
   
    if arduino.write(data):
        print("worked perfectly")
        