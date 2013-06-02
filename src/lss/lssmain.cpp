#include <iostream>
#include "info.h"
#include "lssmanager.h"

void title()
{
	std::cout << lssmenuL << "\n" << lssmenuS << "\n" << lssmenu3 << "\n" << lssmenu4 << "\n";
	std::cout << lssmenu5 << "\n" << lssmenu6 << "\n" << lssmenu7 << "\n" << lssmenu8 << "\n";
	std::cout << lssmenu9 << "\n" << lssmenuS << "\n" << lssmenuL << "\n";
}

int main(int argc, char **argv)
{
	LssManager* diskManager = new LssManager(4);
	
	title();	
	
	while (true)
	{
		int clave = 0;
		std::cin >> clave;
		
		if (clave == 1)
		{
			int fileSize;
			std::cout << SIZE1;
			std::cin >> fileSize;		
			diskManager->createDisk(fileSize);		
		}
		 
		else if (clave == 2)
		{
			short fileName;
			std::cout << NAME;
			std::cin >> fileName;
			diskManager->eraseDisk(fileName);
		}
		
		else if (clave == 3)
		{
			diskManager->showDisks();
		}
				
		else if (clave == 4)
		{
			//diskManager->saveDisks();
		}
		
		else if (clave == 5)
		{
			char * fileName;
			std::cout << NAME2;
			std::cin >> fileName;
			//diskManager->loadDisks();
		}
		
		else if (clave == 6)
		{
			break;
		}
		
	}
	
	return 0;
	
	
}
