#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Grid
{
public:
	Grid();
	Grid(int, int);
	~Grid();
	void AddCell(int,int);
	void DelCell(int,int);
	int CountNeighbours(int, int);
	void InitRandom();
	void NextFrame();
	void PrintGrid();
private:
	int m_lin;
	int m_col;
	vector<vector<bool>>m_frame;
	vector<vector<bool>>m_next_frame;

};
