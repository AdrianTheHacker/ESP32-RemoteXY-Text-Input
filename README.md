# Phone-to-ESP32-Text-Display
Transfers text input from computer or phone over WIFI to ESP32. Text is displayed on LCD.
This uses RemoteXY to assist in data transfer between my phone and the ESP32.

## Parts List
Part | Quantity
---- | --------
ESP-WROOM-32 | 1
16x2 LCD | 1
10kΩ Potentiometer | 1
220Ω Resistor | 1

## Additional Parts for Battery Usage
Part | Quantity
---- | --------
Breadboard Power Supply Module | 1
9V to Barrel Jack Adapter | 1
9V Battery | 1

## Building Instructions
1. Construct the circuit.
2. Using The [Arduino IDE](https://www.arduino.cc/en/software) or equivalent, upload the code to the ESP32 board.
    - Note that the Arduino IDE will require additional libraries downloaded for ESP32 support.
    - A tutorial for this can be found [here](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/).
3. Download the RemoteXY software onto a mobile device (Chromebook, Iphone, Android, ect.).

## Usage Instructions
1. Provide power to the circuit.
2. Connect to the ESP32's WIFI.
3. Open the RemoteXY app on your mobile device and follow the instructions on the app to add a new device.
4. Once device has been added a GUI for interacting with the ESP32 will be present. Simply type whatever you want into the text box and click the submit button to display it on the LCD Screen.
