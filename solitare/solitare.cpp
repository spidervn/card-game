#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "solitare.h"

using namespace std;

Solitare::Solitare()
{
	// Color: 
	// 	1: Bich; 2:Tep; 3: Ro; 4: Co
	init();
}

void Solitare::init()
{
	for (int i=0;i<DECK_COUNT;i++) 
	{
		for (int j=0;j<DECK_COLOR;j++) 
		{
			card[j*DECK_COUNT + i] = (i+1);	// Zero index
			color[j*DECK_COUNT + i] = (j+1);
		}
	}
}

void Solitare::shuffle()
{
	int type = rand() * 10;

	if (type < 2)	// Shuffle from the bottom to the top
	{
		int shuffPos = rand()*(CARD_NO * 2/3);	// Zero index

		// Move from [0,shuffPos) to the top	<=> Switching
		std::copy(&card[0],&card[shuffPos], &tempMem[0]);
		std::copy(&card[shuffPos], &card[CARD_NO], &card[0]);
		std::copy(&tempMem[0],&tempMem[shuffPos], &card[shuffPos]);

		std::copy(&color[0],&color[shuffPos], &tempChar[0]);
		std::copy(&color[shuffPos], &color[CARD_NO], &color[0]);
		std::copy(&tempChar[0],&tempChar[shuffPos], &color[shuffPos]);

	}
	else 		// Shuffle from middle to the top 
	{
		int shuffFrom = rand()*(CARD_NO * 2/3);
		int shuffTo = rand() * (CARD_NO - shuffFrom) + shuffFrom;

		// Swapping [shuffPos,shuffTop) with the top 
		std::copy(&card[shuffFrom], &card[shuffTo], &tempMem[0]);
		std::copy(&card[shuffTo], &card[CARD_NO], &card[shuffFrom]);	
		std::copy(&tempMem[0], &tempMem[shuffTo-shuffFrom], &card[shuffTo]);
	}
}

void Solitare::shufflev2()
{
	/* 
	 * Firstly; divide the 
	 * 		- Mix [0,dividePos) with [dividePos,end)
	 * 		- How to mix method
	 */

	int dividePos = CARD_NO/2 + rand()*5;
	int tempInt[CARD_NO];
	char tempChar[CARD_NO];
	
	while (true)
	{
		int index = 0;
		for (int i=0;i<CARD_NO;i++) {
			if (i >= dividePos && (dividePos+i) >= CARD_NO) {
				break;
			}

			if (i < dividePos) {
				tempInt[index] = card[i];
				tempChar[index++] = color[i];	// Increase index after insert
			}

			if (dividePos + i <CARD_NO) {
				tempInt[index] = card[dividePos+i];
				tempChar[index++] = color[dividePos+i]; // Increase index after insert
			}
		}
	}	
}

void Solitare::printCard()
{
	printf("New card: ");
	for (int i=0;i<CARD_NO;i++) {
		printf(" %d", card[i]);
		switch (color[i]) 
		{
			case 1:
				printf("BICH;");
			break;
			case 2:
				printf("TEP;");
			break;
			case 3:
				printf("RO;");
			break;
			case 4:
				printf("CO;");
			break;
			default:
				printf("INVALID;");
			break;
		}
	}
}