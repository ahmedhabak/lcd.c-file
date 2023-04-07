/*

#ifndef LCD_H_
#define LCD_H_

#include "DIO_Interface.h"


void LCD_Init(void);
void LCD_WriteData(u8 data);
void LCD_SendCommand(u8 command);
void LCD_WriteString(char *str);

void LCD_clear(void);

void LCD_WriteNumber_4d(u16 num);


void LCD_writeBinary(u8 num);

void LCD_GoTo(u8 line,u8 cell);
void LCD_WriteHex(u16 num);
void Create_character(u8 *Pattern,u8 Location);




#endif /* LCD_H_ */

