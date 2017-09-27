#ifndef _SOLITARE_H_
#define _SOLITARE_H_

#define CARD_NO 52
#define DECK_COUNT 13
#define DECK_COLOR 4

class Solitare 
{
private:
	void init();

	int card[CARD_NO];
	char color[CARD_NO];

	int row[7][CARD_NO];			// Playing board
	int reserve_card[24];			// Card for substitution
	int yield_card[4][DECK_COUNT];	// 
	
public:
	Solitare();

	void shuffle();
	
	void shufflev2();

	void printCard();

	void initSolitare();
};

#endif 
