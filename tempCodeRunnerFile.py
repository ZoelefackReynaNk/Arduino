arduino = serial.Serial('COM11', 200, timeout=.1)
data = bytes('hands', 'utf-8')

arduino.write(data)