//
// Damon Schafer
// 9/19/2020
// CS 481
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Point.h"

int main(int argc, char** argv)
{
	std::string filename;
	size_t dimension = 0;
	std::fstream fout;

	bool fileOpened = false;

	std::cout << "Enter dimension in meters" << std::endl;

	std::cin >> dimension;
	
	while (!fileOpened)
	{
		std::cout << "Enter filename for .csv file." << std::endl;

		std::cin >> filename;

		fout.open(filename);

		if (fout.is_open()) {
			fileOpened = true;
		}
		else {
			std::cout << "Failed to open file " + filename << std::endl;
		}
	}

	std::cout << "File opened successfully" << std::endl;
	
	std::pair<size_t, size_t> topLeftPosition;

	std::cout << "Enter the top left coordinate position (X Y)" << std::endl;

	std::cin >> topLeftPosition.first
		>> topLeftPosition.second;

	std::pair<size_t, size_t> currentPosition = topLeftPosition;
	
	// then read from the opened .csv file
	std::vector<std::vector<Point>> data;
	std::string line;
	size_t i = 0;
	
	while (std::getline(fout, line))
	{
		data.emplace_back(std::vector<Point>());

		std::string currentToken = "";
		currentPosition.first = topLeftPosition.first;
		for (char c : line)
		{
			if (c == '\n')
			{
				break;
			}
			if (c == ',')
			{
				float elevation = std::stof(currentToken);
				currentToken.clear();

				data[i].emplace_back(currentPosition.first, currentPosition.second, elevation);
				currentPosition.first += dimension;
				continue;
			}
			if (c <= 0)
			{
				continue;
			}
			currentToken += c;
		}
		currentPosition.second += dimension;
		i++;
	}

	fout.close();

	fout.open("Formatted.csv", std::fstream::out);

	if (fout.fail())
		return EXIT_FAILURE;

	for (std::vector<Point> line : data)
	{
		for (Point point : line)
		{
			fout << point.getX() << "," << point.getY() << "," << point.getElevation() << "\n";
		}
		std::cout << ".";
	}

	fout.close();

	std::cout << "Completed." << std::endl;
	
	return EXIT_SUCCESS;
}
