#include "Grid.h"

int main()
{

	Grid G;
	G.DrawShape(BEACON,4, 5);
	G.DrawShape(BLOCK,19, 19);
	G.DrawShape(BLINKER,15, 15);
	G.DrawShape(GLIDER,8, 9);
	G.AddCell(0, 0);
	G.DelCell(0, 0);
	cout << "Shape test, will reset into random layout after 5 steps\nPress enter to continue the iterations\n";
	cin.get();
	for (int i = 0; i < 5; i++)
	{
		G.PrintGrid();
		G.NextFrame();
		cout << "\n\n";
		cin.get();
		

	}
	cout << "Reseting >>> \n";
	G.InitRandom();
	for (int i = 0; i < 20; i++)
	{
			
			G.PrintGrid();
			G.NextFrame();
			cout << "\n\n";
			cin.get();
			
			
	}
	
	
	return 0;
}
