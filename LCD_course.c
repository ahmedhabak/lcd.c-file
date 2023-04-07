
#include "LCD_course.h"

#if LCD_Mode==_8_BIT

void LCD_WriteOrder(u8 command){
	
		DIO_WritePin(RS,LOW);// this is a command
		DIO_WritePort(LCD_Port,command);  //write this to the port data ,this is a configuration look in the data sheet
		//make a pulse so the micro controller of the lcd will know that there is a chunck of data coming.
		DIO_WritePin(EN,HIGH);
		_delay_ms(1);
		DIO_WritePin(EN,LOW);
		_delay_ms(1);
}
  void LCD_WriteData(u8 data){// this will be used weither i am sending data to store of to write on the screen.
	DIO_WritePin(RS,HIGH);// this is a data
	DIO_WritePort(LCD_Port,data);  //write this to the port data ,this is a configuration look in the data sheet
	//make a pulse so the micro controller of the lcd will know that there is a chunck of data coming.
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void){
	_delay_ms(50);
	LCD_WriteOrder(0x38);// make the lcd two line ,and make the pixels 5*7
	LCD_WriteOrder(0x0c); // shape of the cursor
	LCD_WriteOrder(0x01); // clear the screen
	_delay_ms(1);
	LCD_WriteOrder(0x06);// increase the ddram address automatically ,don't use  shift.
}
#elif LCD_Mode==_4_BIT

void LCD_Init(void){
	_delay_ms(50);
	LCD_WriteOrder(0x02);

	LCD_WriteOrder(0x28);// make the lcd two line ,and make the pixels 5*7
	LCD_WriteOrder(0x0c); // shape of the cursor
	LCD_WriteOrder(0x01); // clear the screen
	_delay_ms(1);
	LCD_WriteOrder(0x06);// increase the ddram address automatically ,don't use  shift.
}

  void LCD_WriteOrder(u8 command){
	
	DIO_WritePin(RS,LOW);// this is a command
     DIO_WritePin(D7,READ_BIT(command,7)); 
	 DIO_WritePin(D6,READ_BIT(command,6)); 
	 DIO_WritePin(D5,READ_BIT(command,5)); 
	 DIO_WritePin(D4,READ_BIT(command,4)); 
	//make a pulse so the micro controller of the lcd will know that there is a chunck of data coming.
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	     DIO_WritePin(D7,READ_BIT(command,3));
	     DIO_WritePin(D6,READ_BIT(command,2));
	     DIO_WritePin(D5,READ_BIT(command,1));
	     DIO_WritePin(D4,READ_BIT(command,0));
	     //make a pulse so the micro controller of the lcd will know that there is a chunck of data coming.
	     DIO_WritePin(EN,HIGH);
	     _delay_ms(1);
	     DIO_WritePin(EN,LOW);
	     _delay_ms(1);
}
  void LCD_WriteData(u8 data){// this will be used weither i am sending data to store of to write on the screen.
	
	DIO_WritePin(RS,HIGH);// this is a data
	//make a pulse so the micro controller of the lcd will know that there is a chunck of data coming.
     DIO_WritePin(D7,READ_BIT(data,7));
     DIO_WritePin(D6,READ_BIT(data,6));
     DIO_WritePin(D5,READ_BIT(data,5));
     DIO_WritePin(D4,READ_BIT(data,4));
     //make a pulse so the micro controller of the lcd will know that there is a chunck of data coming.
     DIO_WritePin(EN,HIGH);
     _delay_ms(1);
     DIO_WritePin(EN,LOW);
     _delay_ms(1);
     
     DIO_WritePin(D7,READ_BIT(data,3));
     DIO_WritePin(D6,READ_BIT(data,2));
     DIO_WritePin(D5,READ_BIT(data,1));
     DIO_WritePin(D4,READ_BIT(data,0));
     //make a pulse so the micro controller of the lcd will know that there is a chunck of data coming.
     DIO_WritePin(EN,HIGH);
     _delay_ms(1);
     DIO_WritePin(EN,LOW);
     _delay_ms(1);
}
#endif 
void LCD_WriteChar(u8 ch){// this will be used when i want to write data on the lcd only
	 LCD_WriteData(ch);
}

void LCD_Clear(){// this will be used when i want to write data on the lcd only
	LCD_WriteOrder(0x01);
}

void LCD_WriteHex(u32 num) {
	u8 str[20];
	u8 rem, i = 0;
	if (num == 0) {
		LCD_WriteChar('0');
		return;
	}
	while (num > 0) {
		rem = num % 16;
		if (rem < 10) {
			str[i] = rem + '0';
			} else {
			str[i] = rem - 10 + 'A';
		}
		num = num / 16;
		i++;
	}
	for (s8 j = i - 1; j >= 0; j--) {
		LCD_WriteChar(str[j]);
	}
}





void LCD_WriteString(u8*str){
	u8 i;
	for(i=0;str[i];i++){
		LCD_WriteChar(str[i]);

	}
}
void LCD_WriteNumber(u32 num){//2503
	
	u8 str[20]; //array to put the string in it
	u8 rem,i=0;
	if(num==0){
		LCD_WriteChar('0');
		return;
		
	}
	if(num<0){
		num=num*-1;
		LCD_WriteChar('-');
	}
	while(num>0){
		rem=num%10;//get the first number
		str[i]=rem+'0'; //store the reminder and add it with 0 so ascii respresintaion of the number will be stored
		num=num/10;// delete the most right digit
		i++;
	}
	//print the from the last because they are reversed.
	for(s8 j=i-1;j>=0;j--){
		LCD_WriteChar(str[j]);
	}
	
}
void LCD_WriteBinary(u8 num)
{
	s8 i,flag=0;
	for( i=7;i>=0;i--){
		if((num>>i)&1)
		{
			LCD_WriteChar('1');
			flag=1; //this flag will prevent the printing of dummy zeros
		}else{
			if(flag==1){
			LCD_WriteChar('0');	
			}
			
			
		}
	}
}

void LCD_GoTo(u8 line, u8 cell){
	if(line==0){
		LCD_WriteOrder(0x80+cell); 
		//i should send 1 in the 7th digit in a command to the screen that means i am setting 
		//address in the ddram so 0b10000000 will write in the address 0 in the first line of the lcd
		//becaues the address of the ddram start from 0 and  i send the place of the cell i want to write to 
	}else if(line ==1){
		LCD_WriteOrder(0x80+0x40+cell);
	}
}

void LCD_WriteNumber_4D(u16 num){
	LCD_WriteChar(num%10000/1000+'0');
	LCD_WriteChar(num%1000/100+'0');
	LCD_WriteChar(num%100/10+'0');
	LCD_WriteChar(num%10/1 +'0');
}


void LCD_Animate(void) {
	// Create custom characters
	LCD_CreateCustomCharacters();

	// Clear LCD and write standing man at first position
	LCD_Clear();
	LCD_GoTo(0, 0);
	LCD_WriteChar(0);
		LCD_GoTo(0, 13);
		LCD_WriteChar(0);

	// Write arrow animation
	for (u8 i = 2; i <= 12; i++) {
		LCD_GoTo(0, i);
		LCD_WriteChar('-');
		_delay_ms(200);
				LCD_GoTo(0, i);
				LCD_WriteChar(' ');
	}

	// Write standing man at last position


	// Wait for a moment
	_delay_ms(300);

	// Replace standing man with sleeping man
	LCD_GoTo(0, 13);
	LCD_WriteChar(1);
}

void LCD_CreateChar(u8 location, u8 *charmap) {
	// Ensure location is valid (0-7)
	location &= 0x07;

	// Send command to set CGRAM address
	LCD_WriteOrder(0x40 | (location << 3));

	// Write character data to CGRAM
	for (u8 i = 0; i < 8; i++) {
		LCD_WriteChar(charmap[i]);
	}

	// Set DDRAM address to return to previous position
	LCD_WriteOrder(0x80);
}

void LCD_CreateCustomCharacters(void) {
	u8 standingMan[8] = {0x0E, 0x04, 0x0A, 0x11, 0x1F, 0x04, 0x0A, 0x11};
	u8 sleepingMan[8] = {0x00, 0x00, 0x00, 0x00, 0x1F, 0x11, 0x15, 0x1B};
	LCD_CreateChar(0, standingMan);
	LCD_CreateChar(1, sleepingMan);
}



void LCD_AnimateString(char *str) {
	u8 len = strlen(str);
	for (u8 i = 0; i < len; i++) {
		// Write character to first line
		LCD_GoTo(0, 1);
		LCD_WriteChar(str[i]);

		// Move character to the right
		for (u8 j = 1; j <= 16; j++) {
			LCD_GoTo(0, j);
			LCD_WriteChar(str[i]);
			LCD_GoTo(0, j - 1);
			LCD_WriteChar(' ');
			_delay_ms(200);
		}

		// Move character to the second line
		LCD_GoTo(1, 16);
		LCD_WriteChar(str[i]);
		LCD_GoTo(0, 16);
		LCD_WriteChar(' ');

		// Move character to the left
		for (s8 j = 15; j >= 0; j--) {
			LCD_GoTo(1, j + 1);
			LCD_WriteChar(str[i]);
			LCD_GoTo(1, j + 2);
			LCD_WriteChar(' ');
			_delay_ms(200);
		}
	}
}

void LCD_ClearDigits(u8 line, u8 cell, u8 numDigits) {
	// Calculate the position of the first digit to clear
	u8 pos = (line == 1) ? (0x80 + cell) : (0xC0 + cell);
	
	// Write spaces to the specified number of digits starting at the specified position
	for (u8 i = 0; i < numDigits; i++) {
		LCD_GoTo(line, cell + i);
		LCD_WriteChar(' ');
	}
}