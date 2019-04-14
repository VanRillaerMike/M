/*
 * Flash_Functions.c
 *
 *  Created on: 20 feb. 2019
 *      Author: mikev
 */
#include "main.h"
#include "stm32f4xx_hal.h"

#include "Flash_Functions.h"

void Flash_write( uint32_t Adress, uint32_t Data )
{
	HAL_FLASH_Unlock();

	//FLASH_Erase_Sector( FLASH_SECTOR_5, VOLTAGE_RANGE_3 );		Is maar 1 keer nodig, daarna is je sector leeg en kun je er altijd in schrijven (tot deze vol zit)
	HAL_FLASH_Program( FLASH_TYPEPROGRAM_WORD, Adress, Data );

    HAL_FLASH_Lock();

	return;
}

uint32_t Flash_read( uint32_t Adress )
{
	uint32_t Data;
	Data = *( uint32_t * ) Adress;

	return ( uint32_t ) Data;
}
