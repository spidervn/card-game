#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "solitare.h"
#include "util.h"

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

TYPECARD Solitare::makeCard(int cardDeck, char& cardColor)
{
	TYPECARD type = 0;
	int intColor = cardColorl
	type = (cardDeck & 0xFF00) | (intColor << 16) ;

	return type;
}

void Solitare::parseCard(TYPECARD cardType, int& cardDeck, char& cardColor)
{
	int intColor;
	cardDeck = cardType & 0xFF00;
	intColor = (cardType & 0x00FF) >> 16;
	cardColor = intColor;
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

void Solitare::initSolitare()
{
	for (int i=0;i<10;i++) {
		shuffle();
	}

	int rowNum = SOLITARE_BOARD_ROW;
	int cardPos = 0;

	for (int i=0;i<rowNum;i++) {
		row_len[i] = (i+1);
		row_open_pos[i] = i;	// Open a card at the top of stack 

		for (int j=0;j<=i;j++) {
			row[i][j] = makeCard(card[cardPos], color[cardPos++]);
		}
	}

	reserve_len = 0;
	while (cardPos < CARD_NO) {
		reserve_card[reserve_len++] = makeCard(card[cardPos],color[cardPos++]);
	}

	for (int i=0;i<DECK_COLOR;i++) {
		yield_len[i] = 0;	//Nothing yielded yet
	}
}

void Solitare::play()
{
	// Find a Valid solutions that OK
	//
	//	Valid solution = 
	//		=> Open A new card
	//		=> Yield a new card 

	// Find how to open a new card 
	// Find a path
	//	=> 
	//		=> Path 
	//			Build a graph that 
	//			G(V,E)
	//				e=(v1,v2) <=> v1 = one_state 
	//								v2 = another state
	//	Find the shortest path ?
	//	
	//	Data structure ?
	//		v1 -> v2 -> v3 -> v4 -> v5
	//		v6 -> v7 -> v8 -> v9 -> v10
	//		
	//	
	//	

	//	M1 => Each row => Find the next move 
	//			Can move to another part ? 
	//	
	//	M => Each row => Finding the next move
	// 
	//	M => Each row => Finding the next move ? 
	//	
	//			=> Easiest move => Open the top of card => Move to the next 
	//				=> Opening the top of the card => Move to the next ???
	//				
	//				Finding a path ? 
	//				


}

// Is valid move from card1 to card2
bool Solitare::validMove(TYPECARD card1, TYPECARD card2)
{
	int deck1, deck2;
	char color1, color2;

	parseCard(card1, deck1, color1);
	parseCard(card2, deck2, color2);

	/*  
	 *	color1 && color2 
	 * 		color1 && color2 trai dau <=> color1 == [0,1] && color2==[2,3]
	 *		(color1-1.5) * (color2-1.5) < 0
	 */
	return (card2 == card1+1) && (sign(color1 - 1.5) != sign(color2-1.5));
}
