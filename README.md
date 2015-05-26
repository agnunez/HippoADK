# HippoADK
HippoADK


Due to the lack of support by HippoADK group, I am forking this project to try to add all info that is missing
Any help from user community is welcome. Also from developers if they come back :-)

List of Issues (ToDo's)
  1. Missing stm32 windows driver for downloading sketchs from Arduino IDE
  2. No installing instruction
  3. No circuit diagrams, no pinouts (HippoADK, HippoLego). 

------------

1. Do not follow the instruction downloading arduino-1.5.5-master.zip, but clone this repository. There are few changes that are important. Install drivers of "Silicon Labs CP210x USB to UART bridge(COMx)". Delete all preivous registered drivers on your COM ports (hidden ones) and install arduino driver directory of this repository.

2. Connect HippoADK to microUSB right port (under power connector) and your PC. Start Arudino from repository (not other installation you may have). Select the COM port and type of platform "F405_25Mhz Boot0 Config (USB_to_Serial)" (HippoADK might appear grayed). Compile and download the Blink example program, changing LED by 40 or 41 (corresponds to red and green leds on HippoADK).

3. Have a look to my map of HippoADK pinout pdf on https://github.com/agnunez/HippoADK/hardware directory, and choos the digital pins functionality to program normally with arduino IDE.

Have Fun!
Agustin
