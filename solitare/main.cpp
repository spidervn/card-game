#include <stdlib.h>
#include <stdio.h>
#include "solitare.h"

int main()
{
	Solitare s;
	s.printCard();
	s.shuffle();
	s.printCard();
	s.shuffle();
	s.printCard();
	return ;
}