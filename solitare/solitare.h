#ifndef _SOLITARE_H_
#define _SOLITARE_H_

#define CARD_NO 52
#define DECK_COUNT 13
#define DECK_COLOR 4

#define TYPECARD int

#define SOLITARE_BOARD_ROW 7 

#include <vector> 

typedef struct structCardAddress
{
	int addressType;	// Type = Board Game; Yielded; Reserve
	TYPECARD cardValue;
	int address01;		//	Address 01 (row; index; or deck_type) depends on what addressType is 
	int address02;	

} CARD_ADDRESS;

typedef struct structSolitareSingleMove
{
	CARD_ADDRESS from;
	CARD_ADDRESS to;
} SOLITARE_SINGLE_MOVE;

typedef struct structSolitareMove 
{
	std::vector<SOLITARE_SINGLE_MOVE> move;
} SOLITARE_MOVE:

class Solitare 
{
private:
	void init();

	TYPECARD makeCard(int cardDeck, char& cardColor);
	void parseCard(TYPECARD cardType, int& cardDeck, char& cardColor);

	int card[CARD_NO];
	char color[CARD_NO];

	TYPECARD row[SOLITARE_BOARD_ROW][CARD_NO];			// Playing board
	TYPECARD reserve_card[24];							// Card for substitution
	TYPECARD yield_card[DECK_COLOR][DECK_COUNT];		// Card for success
	
	int row_len[SOLITARE_BOARD_ROW];					// Store the top of array
	int row_open_pos[SOLITARE_BOARD_ROW];				// 
	int reserve_len;									
	int yield_len[DECK_COLOR];							

public:
	Solitare();

	void shuffle();
	
	void shufflev2();

	void printCard();

	void drawBoard();

	void initSolitare();

	void play();

	bool validMove(TYPECARD card1, TYPECARD card2);
};

#endif 
