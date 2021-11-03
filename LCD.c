#include <xc.h>
#include "LCD.h"

/************************************
 * Function to toggle LCD enable bit on then off
 * when this function is called the LCD screen reads the data lines
************************************/
void LCD_E_TOG(void)
{
	LCD_E = 1;//turn the LCD enable bit on
	__delay_us(5); //wait a short delay
	LCD_E = 0;//turn the LCD enable bit off again
    __delay_us(5);
}

/************************************
 * Function to set the 4-bit data line levels for the LCD
************************************/
void LCD_sendnibble(unsigned char number)
{
    if (number & 0b0001){
        LCD_DB4 = 1;
    }
    else{
        LCD_DB4 = 0;
    }
    if (number & 0b0010){
        LCD_DB5 = 1;
    }
    else{
        LCD_DB5 = 0;
    }
    if (number & 0b0100){
        LCD_DB6 = 1;
    }
    else{
        LCD_DB6 = 0;
    }
    if (number & 0b01000){
        LCD_DB7 = 1;
    }
    else{
        LCD_DB7 = 0;
    }
	
    //set the data lines here (think back to LED array output)
    //LCD_RS = 0; //to be set at sendbyte/LCD_init itself
    
    LCD_E_TOG();			//toggle the enable bit to instruct the LCD to read the data lines
    __delay_us(5);      //Delay 5uS
}


/************************************
 * Function to send full 8-bit commands/data over the 4-bit interface
 * high nibble (4 most significant bits) are sent first, then low nibble sent
************************************/
void LCD_sendbyte(unsigned char Byte, char type)
{
    LCD_RS = type;// set RS pin whether it is a Command (0) or Data/Char (1) using type argument
    
    // send high bits of Byte using LCDout function
    unsigned char MSB = Byte & 0b11110000; //e.g. turns 10110000 to 1011
    LCD_sendnibble(MSB >> 4); //send 4 most significant bits first
    
    // send low bits of Byte using LCDout function
    unsigned char LSB = Byte & 0b00001111; // converts to least significant bits
    LCD_sendnibble(LSB);
    __delay_us(50);               //delay 50uS (minimum for command to execute)
}

/************************************
 * Function to initialise the LCD after power on
************************************/
void LCD_Init(void)
{
    /*
    LCD_setline(__ (MSB line));
    unsigned char sendData = 0b0011;
    LCD_sendnibble(sendData);
    delay(39us)
    LCD_sendnibble(second line)
    */        
    //Define LCD Pins as Outputs and
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC2 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB2 = 0;
    TRISEbits.TRISE3 = 0;
    TRISEbits.TRISE1 = 0;
    //set all pins low (might be random values on start up, fixes lots of issues)
    LCD_RS = 0;
    LCD_E = 0;
    LCD_DB4 = 0;
    LCD_DB5 = 0;
    LCD_DB6 = 0;
    LCD_DB7 = 0;

    //Initialisation sequence code
	// follow the sequence in the GitHub Readme picture for 4-bit interface.
	// first Function set should be sent with LCD_sendnibble (the LCD is in 8 bit mode at start up)
	// after this use LCD_sendbyte to operate in 4 bit mode
    ///LCD_setline();
    __delay_ms(50);
    LCD_sendnibble(0b0011);
    __delay_ms(5);
    LCD_sendbyte(0b00101000,0);
    __delay_us(50);
    LCD_sendbyte(0b00101000,0);
    __delay_us(50);
    LCD_sendbyte(0b00001000,0); //display on or off control
    __delay_us(50);
    LCD_sendbyte(0b00000001,0); //display clear
    __delay_ms(2);
    LCD_sendbyte(0b00000110,0); //entry mode
    __delay_ms(50);
    LCD_sendbyte(0b00001110,0);// turn on display
    __delay_ms(50);

  
	//remember to turn the LCD display back on at the end of the initialisation (not in the data sheet)
}

/************************************
 * Function to set the cursor to beginning of line 1 or 2
************************************/
void LCD_setline (char line)
{
    if (line==1){
        LCD_sendbyte(0x80,0);//Send 0x80 to set line to 1 (0x00 ddram address), 0x80 is 128
    }
    if (line==2){
        LCD_sendbyte(0x40,0);//Send 0xC0 to set line to 2 (0x40 ddram address), 0xC0 is 192
    }
}

/************************************
 * Function to send string to LCD screen
************************************/
void LCD_sendstring(char *string)
{
	//code here to send a string to LCD using pointers and LCD_sendbyte function
    while(*string != 0){ //While the data pointed to isn't a 0x00 do below (strings in C must end with a NULL byte) 
        LCD_sendbyte(*string++, 1); //Send out the current byte pointed to and increment the pointer
    }
}

/************************************
 * Function to send string to LCD screen
************************************/
void LCD_scroll(void)
{
	//code here to scroll the text on the LCD screen
}

/************************************
 * Function takes a ADC value and works out the voltage to 2 dp
 * the result is stored in buf as ascii text ready for display on LCD
 * Note result is stored in a buffer using pointers, it is not sent to the LCD
************************************/
void ADC2String(char *buf, unsigned int ADC_val){
	//code to calculate the inegeter and fractions part of a ADC value
	// and format as a string using sprintf (see GitHub readme)
}
