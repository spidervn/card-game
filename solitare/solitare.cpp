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
	printf("INit \r\n");
	for (int i=0;i<DECK_COUNT;i++) 
	{
		for (int j=0;j<DECK_COLOR;j++) 
		{
			card[j*DECK_COUNT + i] = (i+1);	// Zero index
			color[j*DECK_COUNT + i] = (j+1);
		}
	}
	printf("Finish INit \r\n");
}

void Solitare::shuffle()
{
	printf("Shuffle \r\n");
	
	int type = rand() * 10;
	int tempMem[CARD_NO];
	char tempChar[CARD_NO];	

	if (type < 2)	// Shuffle from the bottom to the top
	{	
		int shuffPos = rand() % (CARD_NO * 2/3) + 1;	// Zero index

		printf("Begin\r\n");
		// Move from [0,shuffPos) to the top	<=> Switching
		std::copy(&card[0],&card[shuffPos], &tempMem[CARD_NO - shuffPos]);
		std::copy(&card[shuffPos], &card[CARD_NO], &tempMem[0]);
		std::copy(&tempMem[0],&tempMem[CARD_NO], &card[0]);

		std::copy(&color[0],&color[shuffPos], &tempChar[CARD_NO - shuffPos]);
		std::copy(&color[shuffPos], &color[CARD_NO], &tempChar[0]);
		std::copy(&tempChar[0],&tempChar[CARD_NO], &color[0]);

	}
	else 		// Shuffle from middle to the top 
	{
		int shuffFrom = rand() % (CARD_NO * 2/3);
		int shuffTo = rand() % (CARD_NO - shuffFrom) + 1 + shuffFrom;

		// Swapping [shuffPos,shuffTop) with the top 
		std::copy(&card[shuffFrom], &card[shuffTo], &tempMem[CARD_NO - shuffTo + shuffFrom]);
		std::copy(&card[shuffTo], &card[CARD_NO], &tempMem[shuffFrom]);	
		std::copy(&tempMem[shuffFrom], &tempMem[CARD_NO], &card[shuffFrom]);

		std::copy(&color[shuffFrom], &color[shuffTo], &tempChar[CARD_NO - shuffTo + shuffFrom]);
		std::copy(&color[shuffTo], &color[CARD_NO], &tempChar[shuffFrom]);	
		std::copy(&tempChar[shuffFrom], &tempChar[CARD_NO], &color[shuffFrom]);
	}

	printf("Finish Shuffle \r\n");
}

void Solitare::shufflev2()
{
	/* 
	 * Firstly; divide the 
	 * 		- Mix [0,dividePos) with [dividePos,end)
	 * 		- How to mix method
	 */

	int dividePos = CARD_NO/2 + rand()%5;
	int tempInt[CARD_NO];
	char tempChar[CARD_NO];
	
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

	for (int i=0;i<CARD_NO;i++) {
		card[i] = tempInt[i];
		color[i] = tempChar[i];
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