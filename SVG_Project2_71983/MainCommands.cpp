#include "MainCommands.h"
#pragma warning (disable:4996)
int MainCommands::StringToInt(const char* str)
{
	return stoi(str);
}
int MainCommands::FirstIndexSymbol(char symbol, const char* str)
{
	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] == symbol)
		{
			return i;
		}
	}
	return -1;
}
int MainCommands::LastIndexSymbol(char symbol, const char* str)
{
	for (size_t i = strlen(str); i >= 0; i--)
	{
		if (str[i] == symbol)
		{
			return i;
		}
	}
	return -1;
}
char* MainCommands::Substr(const char* str, int firstIndex, int secondIndex)
{
	char newStr[64];
	for (size_t i = firstIndex; i < secondIndex; i++)
	{
		newStr[i] = str[i];
	}
	newStr[strlen(newStr)] = '\0';
	return newStr;
}
int CountSymbols(const char * text, char symbol)
{
	int counter = 0;
	for (size_t i = 0; text[i]; i++)
	{
		if (text[i] == symbol)
		{
			counter++;
		}
	}
	return counter;
}

Vector<char*> MainCommands::Split(char* txt) // got help from Veselin Todorov
{
	Vector <char* > words;

	while (CountSymbols(txt, ' '))
	{
		words.pushBack(Substr(txt, 0, FirstIndexSymbol(' ', txt)));
		txt = Substr(txt, FirstIndexSymbol(' ', txt) + 1, strlen(txt));
	}
	words.pushBack(txt);
	return words;
}
Vector<Figure*> MainCommands::Open(const char * file)// got help from Veselin Todorov
{
	 Vector<Figure*> f;
	 ifstream input;
	 char arr[64];
	 input.open(file);
	 while (!input.eof())
	 {
		 input.getline(arr, 64);
		 Vector <char*> row = Split(arr);
		 if (strcmp(file, "") == 0)
		 {
			 break;
		 }
		 if (strcmp(row[0],"rect") == 0)
		 {
			 Rect * r;
			 for (size_t i = 1; i <= 4; i++)
			 {
				 row[i] = Substr(row[i], FirstIndexSymbol('\"', row[i]) + 1, LastIndexSymbol('\"', row[i]));
			 }
			 f.pushBack(new Rect(StringToInt(row[1]), StringToInt(row[2]), StringToInt(row[3]), StringToInt(row[4]), row[5]));
		 }
		 if (strcmp(row[0], "circle") == 0)
		 {
			 for (size_t i = 1; i <= 4; i++)
			 {
				 row[i] = Substr(row[i], FirstIndexSymbol('\"', row[i]) + 1, LastIndexSymbol('\"', row[i]));
			 }
			 f.pushBack(new Circle(StringToInt(row[1]), StringToInt(row[2]), StringToInt(row[3]), row[4]));
		 }
		 if (strcmp(row[0], "line") == 0)
		 {
			 for (size_t i = 1; i <= 4; i++)
			 {
				 row[i] = Substr(row[i], FirstIndexSymbol('\"', row[i]) + 1, LastIndexSymbol('\"', row[i]));
			 }
			 f.pushBack(new Line(StringToInt(row[1]), StringToInt(row[2]), StringToInt(row[3]), StringToInt(row[4])));
		 }
	 }
	 return f;
}
void MainCommands::Help()
{
	cout << "The program provides the following options:  " << endl;
	cout << "--------------------------------------------------------------- "<< endl;
	cout << "Print ->                 will print all the figures in the list." << endl;
	cout << "Open <file> ->           opens file <file>." << endl;
	cout << "Close ->                 closes currently opened file." << endl;
	cout << "Save ->                  saves the currently opened file." << endl;
	cout << "Saveas <file> ->         saves the currently opened file as <file>." << endl;
	cout << "Help ->                  shows the functionality of the program." << endl;
	cout << "Exit ->                  exits the currently opened program." << endl;
	cout << "Erase <n> ->             delete figure number n." << endl;
	cout << "Create <figure> ->       creates figure of type <figure>." << endl;
	cout << "Translate                vertical=<n> horizontal=<p> -> translates figure with the given parameters." << endl;
	cout << "Within <option> ->       find figures within some given by the user space" << endl;
}

void MainCommands::Print(Vector<Figure*>& figures)
{
	for (size_t i = 0; i < figures.GetSize(); i++)
	{
		figures[i]->GetInfo();
	}
}

void MainCommands::Save(Vector<Figure*>& figures, const char * file)
{
	ofstream output;
	output.open(file);
	//displays the default xml code
	output << "< ? xml version = \"1.0\" standalone = \"no\" ? >" << std::endl
		<< "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"" << std::endl
		<< "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl
		<< "<svg>" << std::endl;
	//writing the info of the figure 
	for (size_t i = 0; i < figures.GetSize(); i++)
	{
		figures[i]->GenerateInfo(output);
	}
	output.close();
}

void MainCommands::SaveAs(Vector<Figure*>& figures,const char* file)
{
	ofstream output;
	ifstream input;
	output << "Please insert where you want to save the file: " << endl;
	char* newfile = new char[strlen(file) + 1];
	strcpy(newfile, file);
	input.getline(newfile, 54);
	output.open(newfile);
	//displays the default xml code
	output << "< ? xml version = \"1.0\" standalone = \"no\" ? >" << std::endl
		<< "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"" << std::endl
		<< "  \"vishttp://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl
		<< "<svg>" << std::endl;
	//writing the info of the figure 
	for (size_t i = 0; i < figures.GetSize(); i++)
	{
		figures[i]->GenerateInfo(output);
	}
	output.close();
}

void MainCommands::Erase(Vector<Figure*>& figures, int index)
{
	figures.RemoveElem(index);
}

