/*
 * LED_Functions.c
 *
 *  Created on: 22 feb. 2019
 *      Author: mikev
 */
#include "main.h"
#include "stm32f4xx_hal.h"

#include "LED_Functions.h"

void FillLEDarray( uint8_t *Array, uint32_t AmountOfBytes, uint8_t Intensity, uint8_t Red, uint8_t Green, uint8_t Blue )
{
	uint32_t ByteCounter = 0;

	/*STARTFRAME*/
	while(ByteCounter <= 3)
	{
		printf("%lu: Startframe\r\n", ByteCounter);
		Array[ ByteCounter ] = 0x00;
		ByteCounter++;
	}

	/*DATA for each LED*/
	while(ByteCounter < AmountOfBytes )
	{
		printf("%lu: Data\r\n", ByteCounter);
		Array[ ByteCounter ] = ( Intensity | 0b11100000 );
		ByteCounter++;

		printf("%lu: Data\r\n", ByteCounter);
		Array[ ByteCounter ] = Blue;
		ByteCounter++;

		printf("%lu: Data\r\n", ByteCounter);
		Array[ ByteCounter ] = Green;
		ByteCounter++;

		printf("%lu: Data M\r\n", ByteCounter);
		Array[ ByteCounter ] = Red;
		ByteCounter++;
	}

	return;
}

void RGB444toARGB32(uint8_t *rgb444)
{
	uint8_t arraycounter = 0;
	uint8_t RGBcounter = 0;
	uint8_t arraylength = 0;

	for(arraycounter = 0; arraycounter < arraylength; arraycounter++)
	{
		switch(RGBcounter)
		{
			case (uint8_t) 0:
				//RGextract();
				break;

			case (uint8_t) 1:
				//BRextract();
				break;

			case (uint8_t) 2:
				//GBextract();
				break;

			default:
				break;
		}

		RGBcounter++;

		if(RGBcounter > 2)
		{
			RGBcounter = 0;
		}
	}
}
/*
void RGextract()
{
	uint8_t Red = MSnibble();
	uint8_t Green = LSnibble();
}

void MSnibble()
{

}

void LSnibble()
{

}
*/




















