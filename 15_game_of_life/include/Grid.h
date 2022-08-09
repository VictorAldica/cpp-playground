#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::string;

enum Shape{BLOCK,BOAT,BLINKER,BEACON,GLIDER};

class Grid
{
public:
	Grid();
	Grid(int, int);
	~Grid();
	void AddCell(int,int);
	void DelCell(int,int);
	void InitRandom();
	int CountNeighbours(int, int);
	void NextFrame();
	void PrintGrid();
	void DrawShape(enum Shape, int, int);
	bool ViablePosition(int, int);
private:
	int m_lin;
	int m_col;
	vector<vector<bool>>m_frame;
	vector<vector<bool>>m_next_frame;

};
