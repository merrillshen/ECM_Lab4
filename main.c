// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG3L
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include <stdio.h>
#include "LCD.h"
#include "ADC.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

void main(void) {
    LCD_Init();
    LCD_setline(1);
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00100000,1); // " "
    
    LCD_setline(2);
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b00100000,1); // " "
    LCD_sendbyte(0b01011100,1); //"\"
    LCD_sendbyte(0b00101111,1); // "/"

    while (1) {
        LCD_scroll();
    }
}

