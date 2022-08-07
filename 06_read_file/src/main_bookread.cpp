#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/**
	Define a simple book.
*/
class Book
{
public:
	std::string name;
	std::string authors;

	void print()
	{
		std::cout << this->name << std::endl;
		std::cout << "\t(by " << this->authors << ")" << std::endl;
	}
};

/**
	Reads a vector of books from a text file.
	Note: the text file shall contain lines of text in pairs for the book name and authors
	E.g.
		BOOK 1
		AUTHOR 1
		BOOK 2
		AUTHOR 2
		BOOK 3
		AUTHOR 1, AUTHOR 2, AUTHOR 3
	@param file_name The name of the file to read from (must include path).
	@return Vector of books.
*/
std::vector<Book> readBooksFromTextFile(const std::string& file_name)
{
	std::vector<Book> results;

	std::string name;
	std::string authors;
	std::ifstream file_input(file_name);

	
	if (file_input.is_open())
	{
		while (!file_input.eof())
		{
			Book b;
			std::getline(file_input, name);
			b.name = name;
			std::getline(file_input, authors);
			b.authors = authors;

			results.push_back(b);
		}
		file_input.close();
	}
	else
			std::cout << "Error at opening and parsing file\n";
	return results;
}

int main()
{

	//Modificat path-ul pentru a putea rula din bin
	
	// Read the data
	std::string input_data("../data/ermahgerd_berks.txt");
	std::cout << "Reading the data from " << input_data << std::endl;
	std::vector<Book> books_from_file = readBooksFromTextFile(input_data);

	// Print the data
	std::cout << "Here are all the books found in the data file..." << std::endl;
	for (auto book : books_from_file)
	{
		book.print();
	}

	return 0;
}