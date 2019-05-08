# LWIP-Modbus-TCP-to-Modbus-RTU-converter
in this project use form LWIP stack for ethernet and support http socket (port 80) and (modbus tcp socket (port 502)

you can sent and recive modbus/rtu packet  by modbus/tcp and http web page by ethernet

default  ip address is 192.168.1.10
![alt text](https://github.com/ARoozitalab/LWIP-Modbus-TCP-to-Modbus-RTU-converter/blob/master/Untitled1.jpg "login menu")

user :admin

pass :admin

![alt text](https://github.com/ARoozitalab/LWIP-Modbus-TCP-to-Modbus-RTU-converter/blob/master/Untitled2.jpg "login menu")


after this you can set serial port (modbus/rtu) baud rate , parity and stop bit from rs485 config tab
 ![alt text](https://github.com/ARoozitalab/LWIP-Modbus-TCP-to-Modbus-RTU-converter/blob/master/rs485_tab.jpg "login menu")
 
 
you can send a modbus/rtu packet through http from modbus rtu tab
  ![alt text](https://github.com/ARoozitalab/LWIP-Modbus-TCP-to-Modbus-RTU-converter/blob/master/modbus_tab.jpg "login menu")

with modbus software like modbus poll for modbus/tcp  connection just set ip and port to 502 to use board as a converter
  ![alt text](https://github.com/ARoozitalab/LWIP-Modbus-TCP-to-Modbus-RTU-converter/blob/master/modbus.jpg "login menu")
  
  
  you can use this eval board to run this example :
  
  https://github.com/ARoozitalab/STM32F4-Eval-board
