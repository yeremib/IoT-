import serial
import time

serialcomm = serial.Serial('COM3', 9600)
serialcomm.Timeout = 1

while True:
  inputcomm = input('on or off: ').strip()
  if inputcomm == 'on':
    print('LED ON')
  elif inputcomm == 'off':
    print('LED OFF')
  else:
    print('invalid input')

  serialcomm.write(inputcomm.encode())
  time.sleep(0.5)

print(serialcomm.readLine().decode('ascii'))
serialcomm.close()
