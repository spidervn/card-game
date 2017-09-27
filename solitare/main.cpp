#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "solitare.h"

int main()
{
	srand(time(NULL));
	
	Solitare s;
	s.printCard();
	s.shufflev2();
	s.printCard();
	s.shufflev2();
	s.printCard();
	return ;
}