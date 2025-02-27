# MAX7219CNG 7-Segment LED Controller with Raspberry Pi

This project demonstrates how to interface a Raspberry Pi with a MAX7219CNG to control a 7-segment LED display.

## Requirements

- **BCM2835 Library**: This library is essential for GPIO operations on the Raspberry Pi. Follow the installation instructions provided [here](https://www.airspayce.com/mikem/bcm2835/).

## Wiring Connections

Ensure the following connections between the MAX7219CNG and the Raspberry Pi Zero:

| MAX7219CNG Pin | Function | Raspberry Pi Pin | GPIO Pin Name |
|----------------|----------|------------------|---------------|
| 19 (V+)        | VCC      | 2                | 5V            |
| 18 (ISET)      | GND      | 6                | GND           |
| 1 (DIN)        | Data In  | 19               | MOSI          |
| 13 (CLK)       | Clock    | 23               | SCLK          |
| 12 (LOAD)      | Load     | 24               | CE0           |
| 18 (ISET)      | Resistor | -                | -             |

- **Note**: Connect pin 18 (ISET) to 5V through a 10kΩ resistor.

For the 7-segment LED to MAX7219CNG connections:

| 7-Segment LED Pin | Function | MAX7219CNG Pin |
|-------------------|----------|----------------|
| G                 | Segment G| 17             |
| F                 | Segment F| 15             |
| A                 | Segment A| 14             |
| B                 | Segment B| 16             |
| E                 | Segment E| 21             |
| D                 | Segment D| 23             |
| C                 | Segment C| 20             |
| COM               | Common   | 2 (DIG0)       |

## Breadboard Diagram

![alt text](https://github.com/NikTsiop/max7219cng-basic-operation-using-raspberrypi/blob/main/max7219SegLed_breadboard.png)

## Installation and Usage

1. **Install the BCM2835 Library:**
   ```sh
   wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.71.tar.gz
   tar zxvf bcm2835-1.71.tar.gz
   cd bcm2835-1.71
   ./configure
   make
   sudo make install
   ```

2. **Clone the Repository:**
   ```sh
   git clone https://github.com/NikTsiop/max7219cng-basic-operation-using-raspberrypi.git
   cd max7219cng-basic-operation-using-raspberrypi
   ```

3. **Compile and Run the Code:**
   ```sh
   gcc max7219.c -o max7219 -lbcm2835
   sudo ./max7219
   ```

## Features

- Controls a 7-segment LED display using a Raspberry Pi.
- Implements SPI communication with MAX7219CNG.
- Supports multiple digit display configurations.

## Troubleshooting

- Ensure the **BCM2835 library** is properly installed.
- Verify SPI is enabled using:
  ```sh
  sudo raspi-config
  ```
  Navigate to **Interfacing Options > SPI > Enable**.
- Check wiring connections with reference to the table above.

## License
This project is licensed under the **MIT License**.

## Author
Developed by NikTsiop


