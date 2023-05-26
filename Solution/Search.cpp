#include "Search.h"



o_Search::o_Search() : Options("o_Search") {};

o_Search::~o_Search() {};



void o_Search::OptionAction(vector <Folders*>& folders, const string& input)
{
	unsigned size = folders.at(f_ALL)->GetSongsVector()->size();
	cout << endl;
	string name, singer, album, genre;

	while (true)
	{
		int input;
		cout << "please choose one of the options number:\n1. Search by name\n2. Search by singer\n3. Search by album\n4. Search by genre\n5. Back" << endl;
		cin >> input;

		if (input == 1)
		{
			cout << "enter song name: ";
			cin >> name;

			for (int i = 0; i < size; i++)
			{
				if (folders.at(f_ALL)->GetSongsVector()->at(i).GetSong_name() == name)
				{
					//PrintSongs(folders.at(f_ALL), i);
					cout << folders.at(f_ALL)->GetSongsVector()->at(i) << endl;;
				}
			}
		}
		else if (input == 2)
		{
			cout << "enter singer name: ";
			cin >> singer;
			for (int i = 0; i < size; i++)
			{
				if (folders.at(f_ALL)->GetSongsVector()->at(i).GetSinger() == singer)
				{
					cout << folders.at(f_ALL)->GetSongsVector()->at(i) << endl;;
				}
			}
		}
		else if (input == 3)
		{
			cout << "enter album name: ";
			cin >> album;
			for (int i = 0; i < size; i++)
			{
				if (folders.at(f_ALL)->GetSongsVector()->at(i).GetAlbum() == album)
				{
					cout << folders.at(f_ALL)->GetSongsVector()->at(i) << endl;;
				}
			}
		}
		else if (input == 4)
		{
			cout << "enter genre: ";
			cin >> genre;
			for (int i = 0; i < size; i++)
			{
				if (folders.at(f_ALL)->GetSongsVector()->at(i).GetGenre() == genre)
				{
					cout << folders.at(f_ALL)->GetSongsVector()->at(i) << endl;;
				}
			}
		}
		else if (input == 5)
		{
			break;
		}
		else
		{
			cout << "Invalid option, try again" << endl;
		}
	}
}