# ifndef APP_H
# define APP_H

# include <iostream>
# include <fstream>
# include <regex>
# include <string.h>
# include <string>
# include <list>
# include <vector>
# include <iterator>

# include "Song.h"
# include "Options2.h"



class Folders;
class Options;


class o_Daily_Mix;
class o_Library;
/*
class o_Daily_Mix;
class o_Library;
*/
class Remove;

using namespace std;

class App
{
public:
	App();
	~App();

	void RunProgram();
	int RegexCheck(string& str2check);
	void ActionToDo(const int& num, const string& input);



private:
	vector <Folders*> app_folders;
	Folders* located_in;
	vector <Options*> app_options;

};

# endif 



