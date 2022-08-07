#include "Grid.h"

int main()
{

	Grid G;
	G.InitRandom();
	G.AddCell(4, 5);
	for (int i = 0; i < 20; i++)
	{
			
			G.PrintGrid();
			cout << "\n\n";
			G.NextFrame();
			
	}
	
	return 0;
}
