

#ifndef LCD_COURSE_H_
#define LCD_COURSE_H_



#define _4_BIT 1 
#define _8_BIT 2


#define LCD_Mode _4_BIT

#define RS PINA1 
#define EN PINA2




#define D4 PINA3
#define D5 PINA4
#define D6 PINA5
#define D7 PINA6 

#define LCD_Port PA 



/*******************End_Configuraions**********/


#include "DIO_Interface.h"
#define F_CPU 8000000
#include <util/delay.h>
  void LCD_WriteOrder(u8 command);

void LCD_Init(void);
void LCD_Clear(void);	
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8*string);
void LCD_WriteNumber(u32 num);
//void LCD_WriteNumber_4D(u16 num);// Not implemented
void LCD_WriteBinary(u8 num);
//void LCD_WriteHex(u8 num);//Not implemented
void LCD_GoTo(u8 line, u8 cell);
//void LCD_MovingName(char*name);//Not implemented
//void LCD_ShootPerson();//Not implemented

void LCD_WriteHex(u32 num);
void LCD_Animate(void) ;
void LCD_CreateChar(u8 location, u8 *charmap) ;
void LCD_CreateCustomCharacters(void) ;
void LCD_AnimateString(char *str) ;
void LCD_ClearDigits(u8 line, u8 cell, u8 numDigits) ;







#endif /* LCD_COURSE_H_ */