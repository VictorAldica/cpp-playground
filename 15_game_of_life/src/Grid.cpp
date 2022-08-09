#include "Grid.h"

Grid::Grid() :m_lin(20), m_col(20)
{
	m_frame.resize(m_lin);
	m_next_frame.resize(m_lin);
	for (int i = 0; i < m_col; i++)
	{
		m_frame[i].resize(m_col);
		m_next_frame[i].resize(m_col);

	}
	for (int i = 0; i < m_lin; i++)
		for (int j = 0; j < m_col; j++)
		{
			m_frame[i][j] = 0;
			m_next_frame[i][j] = 0;
		}
}


Grid::Grid(int lin, int col) :m_lin(lin), m_col(col)
{
	if (m_lin < 20) m_lin = 20;
	if (m_col < 20) m_col = 20;
	m_frame.resize(m_lin);
	m_next_frame.resize(m_lin);
	for (int i = 0; i < m_col; i++)
	{
		m_frame[i].resize(m_col);
		m_next_frame[i].resize(m_col);

	}
	for (int i = 0; i < m_lin; i++)
		for (int j = 0; j < m_col; j++)
		{
			m_frame[i][j] = 0;
			m_next_frame[i][j] = 0;
		}
}

Grid::~Grid()
{
	for (int i = 0; i < m_lin; i++)
		for (int j = 0; j < m_col; j++)
		{
			m_frame[i][j] = 0;
			m_next_frame[i][j] = 0;
		}
};


bool Grid::ViablePosition(int x, int y)
{
	return ((x >= 0 && y >= 0) && (x < m_col && y < m_lin));
}




void Grid::AddCell(int pos_x, int pos_y)
{
	if (ViablePosition(pos_x, pos_y)) m_frame[pos_y][pos_x] = true;
}

void Grid::DelCell(int pos_x, int pos_y)
{
	if (ViablePosition(pos_x, pos_y)) m_frame[pos_y][pos_x] = false;
}
void Grid::InitRandom()
{
	srand(time(NULL));

	for (int i = 0; i < m_lin; i++)
		for (int j = 0; j < m_col; j++)
		{

			m_frame[i][j] = rand() % 2;


		}
}

void Grid::DrawShape(Shape shape, int x, int y)
{

	switch (shape)
	{
	case BLOCK:
	{AddCell(x, y);
	AddCell(x + 1, y);
	AddCell(x, y + 1);
	AddCell(x + 1, y + 1);
	break; }

	case BOAT:
	{AddCell(x, y);
	AddCell(x + 1, y);
	AddCell(x, y + 1);
	AddCell(x + 1, y + 2);
	AddCell(x + 2, y + 1);
	break; }

	case BLINKER:
	{AddCell(x, y);
	AddCell(x + 1, y);
	AddCell(x + 2, y);
	break; }

	case BEACON:
	{AddCell(x, y);
	AddCell(x + 1, y);
	AddCell(x, y + 1);
	AddCell(x + 2, y + 3);
	AddCell(x + 3, y + 3);
	AddCell(x + 3, y + 2);
	break; }

	case GLIDER:
	{AddCell(x, y);
	AddCell(x + 1, y);
	AddCell(x + 2, y);
	AddCell(x + 1, y - 2);
	AddCell(x + 2, y - 1);
	break; }
	default: cout << "NOT A VIABLE BLOCK\n"; break;
	}
}


int Grid::CountNeighbours(int pos_x, int pos_y)
{
	int neighbours = 0;
	int y = 0, x = 0;
	for (int i = pos_y - 1; i <= pos_y + 1; i++)
		for (int j = pos_x - 1; j <= pos_x + 1; j++)
		{   //  warp space  ( miscare pacman)
			if (!(i == pos_y && j == pos_x))
			{
				y = i; x = j;
				if (y < 0)   y += m_lin;  // sus => jos
				if (y == m_lin) y = 0;    // jos => sus   
				if (x < 0)   x += m_col;  // stanga => dreapta
				if (x == m_col) x = 0;    // dreapta => stanga

				neighbours += m_frame[y][x];
			}
		}
	return neighbours;


}

void Grid::NextFrame()
{
	for (int i = 0; i < m_lin; i++)
		for (int j = 0; j < m_col; j++)
		{

			m_next_frame[i][j] = m_frame[i][j];
			
		
		
				if (CountNeighbours(j, i) == 3)  m_next_frame[i][j] = true;
			
				if (CountNeighbours(j, i) > 3)   m_next_frame[i][j] = false;
			
				if (CountNeighbours(j, i) < 2)   m_next_frame[i][j] = false;
			


		}
	std::swap(m_frame, m_next_frame);


}



void Grid::PrintGrid()
{
	for (int i = 0; i < m_lin; i++)
	{
		for (int j = 0; j < m_col; j++)
			if (m_frame[i][j])
				cout << "{*}";
			else
				cout << "[ ]";
		cout << "\n";
	}

}