# HippoADK
HippoADK


Due to the lack of support by HippoADK group, I am forking this project to try to add all info that is missing.
Any help from user community is welcome. Also from developers if they come back :-)

List of Issues 
  1. Missing stm32 windows driver for downloading sketchs from Arduino IDE (Done)
  2. No installing instruction (Done)
  3. No circuit diagrams, no pinouts (HippoADK, HippoLego). (Pinout Done. Almost)
  4. No info about Dual bluetooth module. No code examples (Done)


------------ 

1. Do not follow the instruction downloading arduino-1.5.5-master.zip, but clone this repository. There are few changes that are important. Install drivers of "Silicon Labs CP210x USB to UART bridge(COMx)". Delete all preivous registered drivers on your COM ports (hidden ones) and install arduino driver directory of this repository.

2. Connect HippoADK to microUSB right port (under power connector) and your PC. Start Arudino from repository (not other installation you may have). Select the COM port and type of platform "F405_25Mhz Boot0 Config (USB_to_Serial)" (HippoADK might appear grayed). Compile and download the Blink example program, changing LED by 40 or 41 (corresponds to red and green leds on HippoADK).

3. Have a look to my map of HippoADK pinout pdf on https://github.com/agnunez/HippoADK/hardware directory, and choos the digital pins functionality to program normally with arduino IDE.

4. An HM13 dual mode (BLE,SPP) bluetooth module is included in HippoADK. The original datasheet provided is in chinesse. HMSoft manufacturer info has been found and included in /hardware subdirectory. We did identified connections and guess that USART2 from STM32F405 pin is connected to pins 1(tx) & 2(rx) of HM13 bluetooth attached board. From Arduino IDE Serial1 object can be used by standard library to write or read from bluetooth. BT SSP and BLE are easily discovered by mobile phone as HMSoft and BLE protocols works and allow to read and write services. Some demos have been include in DemosAgnuca folder of HippoADK github. I suffer a lot to have them working until realise that Serial1 has to be open at 115200 bps, not 9600!!!

Have Fun!
Agustin
