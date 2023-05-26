# include "Podcast.h"



o_Podcast::o_Podcast() : Options("o_Podcast") {};

o_Podcast::~o_Podcast() {};

void o_Podcast::OptionAction(vector <Folders*>& folders, const string& input)
{
	cout << endl;
	string del, play;
	while (true)
	{
		int input;
		cout << "please choose one of the options number:\n1. Delete a Podcast\n2. Play a Podcast\n3. Back" << endl;
		cin >> input;

		if (input == 1)
		{
			cout << "enter Podcast name to delete: ";
			cin >> del;
		}
		else if (input == 2)
		{
			cout << "enter Podcast name to play: ";
			cin >> play;
		}
		else if (input == 3)
		{
			break;
		}
		else
		{
			cout << "Invalid option, try again" << endl;
		}
	}
}



