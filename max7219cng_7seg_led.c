#include <stdio.h>
#include <bcm2835.h>
#include <stdlib.h>
#include <unistd.h>

#define SHUTDOWN      0b0000110000000000
#define SCANLIMIT     0b0000101100000000
#define NORMAL_OP     0b0000110000000001
#define DISPLAY_TEST  0b0000111100000000
#define DECODE_MODE_B 0b0000100111111111
#define ZERO          0b00000000
#define ONE           0b00000001
#define TWO           0b00000010
#define THREE         0b00000011
#define FOUR          0b00000100
#define FIVE          0b00000101
#define SIX           0b00000110
#define SEVEN         0b00000111
#define EIGHT         0b00001000
#define NINE          0b00001001
#define DASH          0b00001010
#define E_LETTER      0b00001011
#define H_LETTER      0b00001100
#define L_LETTER      0b00001101
#define P_LETTER      0b00001110
#define BLANK         0b00001111

char spiOut[2];

//DIG0
unsigned short digits[]={
        0b00000001
};

unsigned short config[]={
        NORMAL_OP,
        SCANLIMIT,
        DISPLAY_TEST,
        DECODE_MODE_B
};

unsigned short data[]={
        ZERO,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        E_LETTER,
        H_LETTER,
        L_LETTER,
        P_LETTER,
        DASH,
        BLANK,
        SHUTDOWN
};

//Split the 16bit word in two parts of 8 bits
void makeWord(char eightBits[], unsigned short sixteenBits){
        eightBits[0] = sixteenBits >> 8;
        eightBits[1] = sixteenBits & 0x00FF;
}

void configCommand(unsigned short command){
        makeWord(spiOut, command);
        bcm2835_spi_transfern(spiOut, sizeof(spiOut));
}
void transfer_data_to_digits(unsigned short digit, unsigned short data){
        spiOut[0] = digit;
        spiOut[1] = data;
        bcm2835_spi_transfer(spiOut[0]);
        bcm2835_spi_transfer(spiOut[1]);
}

void loop_through_all_data(unsigned short digit){
        // Loop through the data 1-9,-,E,H,L,P
        for(int i = 0; i < (sizeof(data)/sizeof(data[0])); i++){
                if(data[i]==SHUTDOWN){
                        configCommand(data[i]);
                        break;
                }
                transfer_data_to_digits(digit, data[i]);
                sleep(1);
        }
}

int main(){

        if(!bcm2835_init()) return 1;
        bcm2835_spi_begin();
        bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
        bcm2835_spi_setDataMode(BCM2835_SPI_MODE2);
        bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_16);
        bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
        bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);

        for(int k = 0; k<sizeof(config); k++){
               configCommand(config[k]);
        }

        loop_through_all_data(digits[0]);

        return 0;
}