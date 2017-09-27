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

	int tempMem[CARD_NO];
	char tempChar[CARD_NO];
public:
	Solitare();

	void shuffle();
	
	void shufflev2();
};

#endif 
