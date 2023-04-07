/*
#include "LCD.h"
#include "DIO_Interface.h"
#define F_CPU 8000000
#include <util/delay.h>

void LCD_SendCommand(u8 command)
{
	// Set RS to LOW to send a command
	DIO_WritePin(PINA1, LOW);

	// Send the high nibble of the command
	DIO_WritePin(PINA3, (command >> 4) & 0x01);
	DIO_WritePin(PINA4, (command >> 5) & 0x01);
	DIO_WritePin(PINA5, (command >> 6) & 0x01);
	DIO_WritePin(PINA6, (command >> 7) & 0x01);

	// Pulse the EN pin
	DIO_WritePin(PINA2, HIGH);
	_delay_ms(1);
	DIO_WritePin(PINA2, LOW);

	// Send the low nibble of the command
	DIO_WritePin(PINA3, command & 0x01);
	DIO_WritePin(PINA4, (command >> 1) & 0x01);
	DIO_WritePin(PINA5, (command >> 2) & 0x01);
	DIO_WritePin(PINA6, (command >> 3) & 0x01);

	// Pulse the EN pin again
	DIO_WritePin(PINA2, HIGH);
	_delay_ms(1);
	DIO_WritePin(PINA2, LOW);

	// Wait for the command to execute
	_delay_ms(2);
}

void LCD_Init(void)
{
	// Initialization sequence for LCD screen
	_delay_ms(50);
	LCD_SendCommand(0x33);
	_delay_ms(5);
	LCD_SendCommand(0x32);
	_delay_ms(1);
	LCD_SendCommand(0x28);
	_delay_ms(1);
	LCD_SendCommand(0x0E); // Turn on display and show cursor
	_delay_ms(1);
	LCD_SendCommand(0x01);
}

void LCD_WriteData(u8 data)
{
	// Set RS to HIGH to send data
	DIO_WritePin(PINA1, HIGH);

	// Send the high nibble of the data
	DIO_WritePin(PINA3, (data >> 4) & 0x01);
	DIO_WritePin(PINA4, (data >> 5) & 0x01);
	DIO_WritePin(PINA5, (data >> 6) & 0x01);
	DIO_WritePin(PINA6, (data >> 7) & 0x01);

	// Pulse the EN pin
	DIO_WritePin(PINA2, HIGH);
	_delay_ms(1);
	DIO_WritePin(PINA2, LOW);

	// Send the low nibble of the data
	DIO_WritePin(PINA3, data & 0x01);
	DIO_WritePin(PINA4, (data >> 1) & 0x01);
	DIO_WritePin(PINA5, (data >> 2) & 0x01);
	DIO_WritePin(PINA6, (data >> 3) & 0x01);

	// Pulse the EN pin again
	DIO_WritePin(PINA2, HIGH);
	_delay_ms(1);
	DIO_WritePin(PINA2, LOW);

	// Wait for the data to be written
	_delay_ms(2);
}

void LCD_WriteString(char *str)
{
	while(*str != '\0')
	{
		LCD_WriteData(*str);
		str++;
	}
}

void LCD_clear(void)
{
	// Send the "Clear Display" command to the LCD
	LCD_SendCommand(0x01);
}

void LCD_WriteNumber_4d(u16 num)
{
	// Convert the number to a string and write it to the LCD
	char buffer[5];
	itoa(num, buffer, 10);
	LCD_WriteString(buffer);
}

void LCD_writeBinary(u8 num)
{
	// Write the binary representation of the number to the LCD
	for (int i = 7; i >= 0; i--)
	{
		LCD_WriteData((num & (1 << i)) ? '1' : '0');
	}
}




void LCD_GoTo(u8 line, u8 cell)
{
	// Calculate the DDRAM address for the specified line and cell
	u8 address = (line == 0) ? cell : (0x40 + cell);

	// Send the "Set DDRAM Address" command to the LCD
	LCD_SendCommand(0x80 | address);
}

void LCD_WriteHex(u16 num)
{
	// Convert the number to a hexadecimal string and write it to the LCD
	char buffer[5];
	sprintf(buffer, "%04X", num);
	LCD_WriteString(buffer);
}

void Create_character(u8 *Pattern, u8 Location)
{
	// Send the "Set CGRAM Address" command to the LCD
	LCD_SendCommand(0x40 | (Location << 3));

	// Write the pattern data to the CGRAM
	for (u8 i = 0; i < 8; i++)
	{
		LCD_WriteData(Pattern[i]);
	}
}

*/