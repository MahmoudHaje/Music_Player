# include "DailyMix.h"

o_Daily_Mix::o_Daily_Mix() : Options("o_Daily_Mix") {};

o_Daily_Mix::~o_Daily_Mix() {};


void o_Daily_Mix::OptionAction(vector <Folders*>& folders, const string& input)
{
	unsigned size = folders.at(f_ALL)->GetSongsVector()->size();
	cout << endl;
	vector <Song> dm;
	for (int i = 0; i < DefaultSizeShow; i++)
	{
		int x = rand() % size;
		dm.push_back(folders.at(f_ALL)->GetSongsVector()->at(x));
	}
	PrintFirstTenSongs_ABC(folders.at(f_ALL));
	while (true)
	{
		string input;
		cout << "please choose one of the options :\n1. Play\n2. Random\n3. Back" << endl;
		cin >> input;

		if (input == "Play")
		{
			//play
		}
		else if (input == "Random")
		{
			for (int i = 0; i < DefaultSizeShow; i++)
			{
				int x = rand() % DefaultSizeShow;
			}
			//play
		}
		else if (input == "Back")
		{
			break;
		}
		else
		{
			cout << "Invalid option, try again" << endl;
		}
	}
}

