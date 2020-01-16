#pragma once

using namespace std;
void mainLoop(int** currentGeneration, int** nowa, int size, int interval);
void display(int** currentGeneration, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (currentGeneration[i][j] == 0)cout  << char(177) << char(177);
			if (currentGeneration[i][j] == 1)cout << char(219) << char(219);
		}
		cout << endl;
	}
}
void recreatingFieldWithNewSize(int** a,int**b, int size,int interval) {
	a= new int* [size];
	for (int i = 0; i < size; ++i)
		a[i] = new int[size] {};
	b = new int* [size];
	for (int i = 0; i < size; ++i)
		b[i] = new int[size] {};
	mainLoop(a, b, size, interval);
}
void randomlyChoosingCellsForFirstGeneration(int** a, int size) {	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = rand() % 2;
		}
	}
}
void calculatingNextGeneration(int** currentGeneration, int** nowa, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int cellsAround{};
			int currentState = currentGeneration[i][j];
			if (j > 0) {
				if (currentGeneration[i][j - 1] > 0) {
					cellsAround++;
				}
			}
			if (j > 0&&i<(size-1)) {
				if (currentGeneration[i+1][j - 1] > 0) {
					cellsAround++;
				}
			}
			if (i < (size-1)) {
				if (currentGeneration[i+1][j] > 0) {
					cellsAround++;
				}
			}
			if (j < (size - 1)&& i < (size - 1)) {
				if (currentGeneration[i+1][j + 1] > 0) {
					cellsAround++;
				}
			}
			if (j < (size-1)) {
				if (currentGeneration[i][j + 1] > 0) {
					cellsAround++;
				}
			}
			if (i > 0 && j < (size - 1)) {
				if (currentGeneration[i - 1][j + 1] > 0) {
					cellsAround++;
				}
			}
			if (i >0) {
				if (currentGeneration[i -1][j] > 0) {
					cellsAround++;
				}
				if (j >0&& i >0) {
					if (currentGeneration[i - 1][j - 1] > 0) {
						cellsAround++;
					}
				}
				if (cellsAround == 3 || cellsAround == 2 && currentState > 0)nowa[i][j] = 1;
				else nowa[i][j] = 0;
			}
		}
	}
}
void copyingGeneration(int** currentGeneration, int** nowa, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			currentGeneration[i][j] = nowa[i][j];
			}
		}
	}
void startSimulation(int** currentGeneration, int** nowa, int size, int interval) {
	while (!_kbhit())
	{
		system("CLS");
		display(currentGeneration, size);
		calculatingNextGeneration(currentGeneration, nowa, size);
		copyingGeneration(currentGeneration, nowa, size);
		Sleep(interval);
	}
}
void changeInterval(int& interval) {
	cout << "Set new interval in ms: ";
	while (!(cin >> interval))
	{
		cout << "Error: enter a number: ";
		cin.clear();
		cin.ignore(123,'\n'); 
	}
	while (!(interval > 0)) {
		cout << "Error: enter a positive number: ";
		while (!(cin >> interval))
		{
			cout << "Error: enter a positive number:";
			cin.clear();
			cin.ignore(123, '\n');
		}
	}

}
void changeSizeOfField(int** currentGeneration, int** nowa, int& size,int interval) {
	cout << "Size of field: ";
	int x{};
	while (!(x > 0)) {
		cout << "Error: enter a positive number: ";
		while (!(cin >> x))
		{
			cout << "Error: enter a positive number: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
	}
	size = x;
	recreatingFieldWithNewSize(currentGeneration, nowa, x, interval);

	
}
void fillGenerationWithDeadCells(int** a, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = 0;
		}
	}

}
void chooseWhichCellsLive(int** currentGeneration, int size) {	
	for (int i = 0; i < size; i++) {
		system("CLS");
		bool error = true;
		display(currentGeneration, size);
		cout << "Line number "<< i + 1 << ":" << endl;
		string line;
		while (error){
			error = false;
			cin >> line;
		for (int i = 0; i < line.length(); i++) {
			if (((line[i] - 48) != 0) && ((line[i] - 48) != 1)) {
				error = true;
			}
			if (line.length() != size){
				error = true;
				
		}
	}
		
		if(error)cout << "Put correct number of 0's and 1's(" << size << "):" << endl;
	}
		for (int j = 0; j < size; j++)
		{
			currentGeneration[i][j] = (int)line[j] - 48;
		};
}}
void mainLoop(int** currentGeneration, int** nowa, int size, int interval) {
	
	system("CLS");
	
	int choice;
	cout << "1 - Start simulation" << endl;
	cout << "2 - Change interval(" << interval << "ms)" << endl;
	cout << "3 - Change size of the field("<<size<<"x"<<size<<")" << endl;
	cout << "4 - Choose which cells live in 1st generation"<<size<<"x"<<size << endl;
	cout << "5 - Randomly fill generation" << endl;
	cout << "6 - Exit" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "1st generation:" << endl;
	display(currentGeneration, size);
	cout << "Enter a number: ";
	while (!(cin >> choice) ){
		cout << "Enter a number: ";
		cin.clear();
		cin.ignore(123, '\n');
	};
	switch (choice) {
	case 1:
		startSimulation(currentGeneration, nowa, size, interval);
		exit(1);
		break;
	case 2:
		changeInterval(interval);
		mainLoop(currentGeneration, nowa, size, interval);
		break;
	case 3:
		changeSizeOfField(currentGeneration,nowa, size,interval);	
		recreatingFieldWithNewSize(currentGeneration,nowa, size,interval);
		mainLoop(currentGeneration, nowa, size, interval);
		break;
	case 4:
		fillGenerationWithDeadCells(currentGeneration, size);
		chooseWhichCellsLive(currentGeneration, size);
		mainLoop(currentGeneration, nowa, size, interval);
		break;
	case 5:
		randomlyChoosingCellsForFirstGeneration(currentGeneration, size);
		mainLoop(currentGeneration, nowa, size, interval);
		break;
	case 6:
		exit(1);
		break;
	
	}
		mainLoop(currentGeneration, nowa, size, interval);
	
}