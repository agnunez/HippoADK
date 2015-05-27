
              HM-12/13 dual mode bluetooth module Firmware Release Notes

                       Jinan Huamao Technology Co,. Ltd.

                                                                 www.jnhuamao.cn
                                                               www.huamaosoft.com

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
Version 309
2015-04-07

Notices:

-Add iBeacon support
-Add AT+IBEA command
-Add AT+IBE0 command
-Add AT+IBE1 command
-Add AT+IBE2 command
-Add AT+IBE3 command
-Add AT+MARJ command
-Add AT+MINO command
-Add AT+MEAS command


-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
Version 307
2015-02-01

Notices:

-redefine ATT protocol.
-Add internal 1024Bytes buffer.


-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
Version 305
2015-01-19

Notices:

-Modify L2CAP and HCI protocol.
-Fix some internal bugs.


-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
Version 304
2014-12-20

Notices:

-Add AT+STOPB command use to pause BLE mode.
-Add AT+STOPE command use to pause EDR mode.


-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 303
2014-12-10

Notices:

-Redefine RFCOMM protocol.


-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 302
2014-12-06

Notices:

-Redefine SDP protocol use 16bit UUID.


-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 301
2014-12-01

Notices:

-Add AT+IMMB command to switch BLE work mode.
-Add AT+IMME command to switch EDR work mode.
-Add AT+STARB command to let module goto work state.
-Add AT+STARE command to let module goto work state.
-Add serial upgrade function.

-Fix some internal bugs.

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------


Version 215
2014-10-11

Notices:

-Add AT+RSSB command to read BLE RSSI value.
-Add AT+RSSE command to read EDR RSSI value

-Fix some internal bugs.

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 213
2014-10-09

Notices:

-Add AT+NOTP command to switch notify mode.

-Fix some internal bugs.

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 212
2014-10-01

Notices:

-Support BLE master and slave role.
-Add balance mode and high speed mode.
-In high speed mode, data transmission speed increated 8 times.
-In balance mode, data transmission speed increated 4 times.

-Add AT+HIGH command to switch balance mode and high speed mode.
-Add AT+ROLB command to switch BLE master mode and slave mode.

-Fix some internal bugs.

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 211
2014-09-10

Notices:

-Add AT+FLOW command to support hardware flow control.
-Add AT+STOP command to setup UART stop bit.
-Add AT+PARI command to setup UART pari bit.
-Add AT+INIT command to notify if the module has loaded.
-Add AT+RADE command to query last connect EDR address.
-Add AT+RADB command to query last connect BLE address.
-Add AT+CLEAB command to clear last connect BLE address.
-Add AT+CLEAE command to clear last connect EDR address.

-Fix some internal bugs.
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 209
2014-08-03

Notices:

-Add AT+PIO commands to control PIO output states

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 208
2014-07-16

Notices:

- Add AT+DUAL command replace AT+MODE command.
- Change old AT+MODE command function to switch Datatrans mode or Remote control mode.
- Add KEY multi-function, use to disconnect or restore factory setup.

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 207
2014-07-05

Notices:

- Fix some bugs.
- Add AT+ATOB command
- Add AT+NOTI command
- Add AT+SCAN comamnd
- Add AT+AUTH command
  
Changes and Enhancements:

- Add connection check, if no any answer for 5 seconds, module will reset.

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 206
2014-07-01

Notices:

- Fix some bugs.
- Add AT+PIO1 command
  
Changes and Enhancements:

- Modify the work flow.

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------

Version 106
2014-06-05

Notices:

- Fix some bugs.
- Add AT+MODE command
  
Changes and Enhancements:

- V106 have an bugs: when you change BLE name, the EDR pin code will not work, please dont change BLE name, use AT+RENEW to fix it.
