# MAX7219CNG 7SegLed Controller using Raspberry Pi

## Requirments
BCM2835 Library, for the installation check here: https://www.airspayce.com/mikem/bcm2835/

## Connections
|MAX7219CNG| Raspberry Pi Zero|
| :-- | :- |
| PIN19(V+)| 5v |
| PIN18(ISET)| GND |
| PIN1(DIN) | PIN19(MOSI) |
| PIN13(CLK) | PIN23(SCLK)|
| PIN12(LOAD)| PIN24(CEO)|

|7-SEG LED| MAX7219CNG|
| :- | :- |
| PIN-G| PIN17(SEG G) |
| PIN-F| PIN15(SEG F) |
| PIN-A| PIN14(SEG A) |
| PIN-B| PIN16(SEG B) |
| PIN-E| PIN21(SEG E) |
| PIN-D| PIN23(SEG D) |
| PIN-C| PIN20(SEG C) |
| PIN-COM| PIN2(DIG0) |

## Breadboard
![alt text](https://github.com/NikTsiop/max7219cng-basic-operation-using-raspberrypi/blob/main/max7219SegLed_breadboard.png)

## Compile
`c++ -o max7219cng_run max7219cng_7seg_led.c -lbcm2835`

## Run
`sudo ./max7219cng_run`
