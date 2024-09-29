#include<stdint.h>
#include "Keyboard.h"

#define SIZE_X 4
#define SIZE_Y 3
const uint8_t portmapX[] = {2, 3, 4, 5};
const uint8_t portmapY[] = {6, 7, 8};

const char keymap [4] [3] ={
	{'#', '0', '*'}, 
	{'7', '8', '9'},
  {'4', '5', '6'}, 
	{ '1', '2', '3'}}; 

void writePinX(uint8_t pin){
	for(uint8_t i=0; i < SIZE_X; i++)
		{
			if(i == pin)
				{
					pinMode(portmapX[i], OUTPUT);
					digitalWrite(portmapX[i], LOW);
				}
			else
				{
					pinMode(portmapX[i], INPUT_PULLUP);
				}
		}
}

char scanKeys()
{
	static uint8_t xPos = 0;
	static uint8_t yPos = 0;

	for(xPos = 0; xPos < SIZE_X; xPos++)
		{
			writePinX(xPos);
			for(yPos = 0; yPos < SIZE_Y; yPos++)
				{
					if(digitalRead(portmapY[yPos]) == LOW)
						{
							Keyboard.write(keymap[xPos][yPos]);
              _delay_ms(100);
              while(digitalRead(portmapY[yPos]) == LOW);
						}
				}
		}
}


void setup()
{
  static uint8_t yPos = 0; 
  for(yPos = 0; yPos < SIZE_Y; yPos++)
    {
      pinMode(portmapY[yPos], INPUT_PULLUP);
    }
}

void loop()
{
  char key;
  key = scanKeys();
}
