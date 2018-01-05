import serial


ser = serial.Serial('/dev/ttyACM0',9600)  # open serial port
print(ser.name) # print serial port name
ser.write(b"UP \n") # write to arduino that is UP to read
data=ser.read(35) # read
print(data)      # print the data
ser.write(b"ACK\n") # write ACK
ser.write(b"EXI\n") # close connection
ser.close()             # close port
