# A Fabian and Rocco Production
**Just your typical keyboard-controlled RC car**

A project by Fabian Yiu and Rocco Jiang.

## Instructions
1. The computer should be connected via Bluetooth to the HC-05 or HC-06 module (by default, the password is `1234`).
2. Find the Bluetooth serial port name via the Arduino IDE.
   
   Alternatively, you can list out all serial ports in a terminal window with the command:
   ```
   ls /dev/{tty,cu}.*
   ```
3. Load the Processing sketch in `input/input.pde`, replacing the `port_name` string if needed.
4. Run the sketch and use arrow keys to control the car.

## Schematic
![Schematic](schematic/schematic_img.png)