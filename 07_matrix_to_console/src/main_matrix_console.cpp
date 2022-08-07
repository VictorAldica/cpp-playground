#include <iostream>
#include <string>
#include <vector>

/**
	Define a simple matrix.
*/
class Matrix
{
private:
	size_t column_count;
	size_t line_count;


	std::vector<std::string> m_matrix;
	// TODO: store the data
	// hints: you can use std::string, std::vectors + string, char**, vector<vector<char>>, etc
public:
	Matrix(size_t numColumnsX, size_t numLinesY):column_count(numColumnsX),line_count(numLinesY),m_matrix(numColumnsX*numLinesY)
		// TODO: add functionality
	{
		
		std::fill(m_matrix.begin(), m_matrix.end(), " ");
		// TODO: add functionality
	}

	// Set an entire line
	void setLine(size_t line_number, const std::string& data)
	{
		if(data.size()<=column_count)
		for (int i = 0; i < column_count; i++)
			m_matrix[i +(column_count*line_number)] = data[i];
	}

	//OPTIONAL
	char getCellXY(size_t x, size_t y, char& cell_content)
	{
		if (x <= column_count && y <= line_count && y >= 0 && x >= 0)
		{		cell_content = *m_matrix[y*column_count + x].c_str();
				return cell_content;
		}// TODO: add functionality
		return 0;
	}

	/**
		Sets the cell content for a specific cell identified by its coordinates (X and Y)
		@param x The horizontal coordinate of the cell to set. Index starts at zer0.
		@param y The vertical coordinate of the cell to set. Index starts at zer0.
		@param cell_content A cell char to set.

		E.g.
		 X axis: 0 -------- ... -------> Width
		 Y axis
		 0       0,0  1,0                W-1, 0
		 |       0,1  1,1                     
		 |       0,2                      
		 .                             
		 .                             
		 .                             
		 |       0, H-1     ...          W-1, H-1           
		 V

		 Height
	*/
	void setCellXY(size_t x, size_t y, char cell_content)
	{
		if(x<=column_count && y<=line_count && y>=0 && x>=0) 
		m_matrix[y*column_count+x] = cell_content;
	}

	void print()
	{
		for (int i = 0; i < line_count; i++)
		{	
			for (int j = 0; j < column_count; j++)
				std::cout << m_matrix[i*column_count+j];
			std::cout << "\n";
		}
	}
};

int main()
{
	// Create a matrix with the width of 20 and height of 10.
	Matrix matrix(20, 10);
	

	matrix.setLine(0, "X-----X----X-----XX-");
	matrix.setLine(1, "--X-----------------");
	matrix.setLine(2, "-----X--------------");
	matrix.setLine(3, "--------X-----------");
	matrix.setLine(4, "-----------X--------");
	matrix.setLine(5, "--------------X-----");
	matrix.setLine(6, "-----------------X--");
	matrix.setLine(7, "-------------------X");
	matrix.setLine(8, "------------------X-");
	matrix.setLine(9, "-----------------X--");
	
	
	
	char c=matrix.getCellXY(0, 0, c);
	std::cout <<c<< "\n\n";
	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--X-----------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/
	std::cout << "\n";
	matrix.setCellXY(2, 1, '-');
	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/
	std::cout << "\n";
	matrix.setCellXY(3, 7, 'O');
	matrix.print();
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
---O---------------X
------------------X-
-----------------X--
*/

	// This should silently fail (not trigger an error): cell Y=11 invalid due to limited height.
	matrix.setCellXY(3, 11, 'O');
	return 0;
}