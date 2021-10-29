#include <xc.h>
#include "LCD.h"

/************************************
 * Function to toggle LCD enable bit on then off
 * when this function is called the LCD screen reads the data lines
************************************/
void LCD_E_TOG(void)
{
	//turn the LCD enable bit on
	__delay_us(2); //wait a short delay
	//turn the LCD enable bit off again
}

/************************************
 * Function to set the 4-bit data line levels for the LCD
************************************/
void LCD_sendnibble(unsigned char number)
{

	//set the data lines here (think back to LED array output)

    LCD_E_TOG();			//toggle the enable bit to instruct the LCD to read the data lines
    __delay_us(5);      //Delay 5uS
}


/************************************
 * Function to send full 8-bit commands/data over the 4-bit interface
 * high nibble (4 most significant bits) are sent first, then low nibble sent
************************************/
void LCD_sendbyte(unsigned char Byte, char type)
{
    // set RS pin whether it is a Command (0) or Data/Char (1) using type argument
    // send high bits of Byte using LCDout function
    // send low bits of Byte using LCDout function
	
    __delay_us(50);               //delay 50uS (minimum for command to execute)
}

/************************************
 * Function to initialise the LCD after power on
************************************/
void LCD_Init(void)
{

    //Define LCD Pins as Outputs and
    //set all pins low (might be random values on start up, fixes lots of issues)


    //Initialisation sequence code
	// follow the sequence in the GitHub Readme picture for 4-bit interface.
	// first Function set should be sent with LCD_sendnibble (the LCD is in 8 bit mode at start up)
	// after this use LCD_sendbyte to operate in 4 bit mode

	//remember to turn the LCD display back on at the end of the initialisation (not in the data sheet)
}

/************************************
 * Function to set the cursor to beginning of line 1 or 2
************************************/
void LCD_setline (char line)
{
    //Send 0x80 to set line to 1 (0x00 ddram address)
    //Send 0xC0 to set line to 2 (0x40 ddram address)
}

/************************************
 * Function to send string to LCD screen
************************************/
void LCD_sendstring(char *string)
{
	//code here to send a string to LCD using pointers and LCD_sendbyte function
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
