#include "Grid.h"

Grid::Grid():m_lin(20),m_col(20)
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

Grid::~Grid() {};

void Grid::AddCell(int pos_x, int pos_y)
{
	m_frame[pos_y][pos_x] = true;
}

void Grid::DelCell(int pos_x, int pos_y)
{
	m_frame[pos_y][pos_x] = false;
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

int Grid::CountNeighbours(int pos_x, int pos_y)
{
	int neighbours = 0;
	int y=0, x=0;
	for(int i=pos_y-1;i<=pos_y;i++)
		for (int j = pos_x - 1; j <= pos_x + 1; j++)
		{   //  warp space  ( miscare pacman)
			if (!(i == pos_y && j == pos_x))
			{
				y = i; x = j;
				if (y < 0)   y += m_lin;  // sus => jos
				if (y == m_lin) y = 0;    // jos => sus   
				if (x < 0)   x += m_col; // stanga => dreapta
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


			if (!m_frame[i][j])
			{
				if (CountNeighbours(j, i) == 3)  m_next_frame[i][j] = true;
			}
			else
			{
				if (CountNeighbours(j, i) > 3  || CountNeighbours(j, i) < 2)  m_next_frame[i][j] =false;
			}
			

		}
	std::swap(m_frame, m_next_frame);
	
		
}



void Grid::PrintGrid()
{
	for (int i = 0; i < m_lin; i++)
	{
		for (int j = 0; j < m_col; j++)
			if (m_frame[i][j])
				cout << "[*]";
			else
				cout << "[_]";
		cout << "\n";
	}
		
}