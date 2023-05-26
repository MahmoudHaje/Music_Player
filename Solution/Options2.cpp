# include "Options2.h"
# include "App.h"
#include <algorithm>
#include <fstream>
#include <string>

unsigned Options::print_indx = 0;

using namespace std;

//Class Options start

// Print 10 songs, then Print the 10th after...
void Options::PrintSongs(Folders* folder, const bool flag) const
{
	unsigned size = 0, i = 0, location = 0;
	vector <Song>::iterator start, end;

	if (flag)   // Add 10, to print the next 10 songs.
	{
		start = folder->GetSongsVector()->begin() + print_indx;
		print_indx += DefaultSizeShow;  // Add 10
	}
	else
		start = folder->GetSongsVector()->begin();

	end = folder->GetSongsVector()->end();
	size = end - start;

	for (; i < DefaultSizeShow && i < size; i++)
	{
		if (flag)
		{
			location = i + DefaultSizeShow * (print_indx / DefaultSizeShow - 1);
			cout << folder->GetSongsVector()->at(location) << endl;
		}
		else	cout << i + 1 << ". " << folder->GetSongsVector()->at(i) << endl;
	}
	if (i < DefaultSizeShow - 1) //No more Songs to show
	{
		if (flag)	print_indx = 0; // Printing all songs, index =0 , to print it again (new loop)
		cout << "\n No more Songs to show." << endl;
	}
}

//Print the first 10 songs in ABC order
void Options::PrintFirstTenSongs_ABC(Folders* folder) const
{
	vector<Song>* songs = folder->GetSongsVector();
	const size_t num_songs = songs->size();
	const size_t num_to_print = std::min(num_songs, static_cast<size_t>(DefaultSizeShow));

	// Sort the songs by title
	std::sort(songs->begin(), songs->end(), [](const Song& s1, const Song& s2) {
		return s1.GetSong_name() < s2.GetSong_name();
		});

	// Print the first num_to_print songs
	cout << "Songs sorted by title:" << endl;
	for (size_t i = 0; i < num_to_print; ++i)
	{
		cout << (*songs)[i] << endl;
	}

	// If there are no more songs to show, print a message
	if (num_to_print == 0) {
		cout << "\nNo songs to show." << endl;
	}
	else if (num_to_print == songs->size()) {
		cout << "\nNo more songs to show." << endl;
	}

}

////Find song Id
std::pair<Folders*, unsigned> Options::FindSongId(const vector <Folders*> folders, const string id2find, int choise) const
{
	unsigned size;
	pair<Folders*, unsigned> located_song;
	string id;
	bool found_flag = false;

	// OutLoop folders
	for (unsigned i = 0; i < folders.size(); i++)
	{
		size = folders.at(i)->GetSongsVector()->size();
		if (size)
			// InLoop folders to find the song.
			for (unsigned j = 0; j < size; j++)
			{
				if (choise == 1) id = folders.at(i)->GetSongsVector()->at(j).GetID();	//Search by id
				else if (choise == 2) id = folders.at(i)->GetSongsVector()->at(j).GetSong_name();//Search by name
				if (id.compare(id2find) == 0)
				{
					//cout << "id is foundddddddd :" << id << endl;
					located_song.first = folders.at(i);
					located_song.second = j;
					found_flag = true;
					break;
				}
			}
		if (found_flag) break;
	}
	if (!found_flag) // Id not found;
	{
		cout << "Id not found !" << endl;
		located_song.first = NULL;
		located_song.second = -1;
		return located_song;
	}
	return located_song;
}

// Prin the options
void Options::PrintOptions(const int num)
{
	cout << "\nWrite a command according to the list below:" << endl;
	switch (num)
	{
	case 0: //Main
	{
		string options[] = OPTIONS_ARRAY;
		for (int i = 0; i < TOTAL_OPTIONS; i++)
			cout << i + 1 << "." << "\t" << options[i] << endl;
		break;
	}
	case 1: //_LIBRARY
	{
		string options[] = OPTIONS_LIBRARY;
		for (int i = 0; i < LIBRARY_TOTAL_OPTIONS; i++)
			cout << i + 1 << "." << "\t" << options[i] << endl;
		break;
	}
	case 2: //_PlayList
	{
		string options[] = OPTIONS_PLAYLISTS;
		for (int i = 0; i < PLAYLISTS_TOTAL_OPTIONS; i++)
			cout << i + 1 << "." << "\t" << options[i] << endl;
		break;
	}

	}

}
//Class Options end



// Delete n-th line from given file
void delete_line(const string& Song_full_pathx)
{
	ifstream inputFile;
	inputFile.open("MUSIC3.txt");
	int line_counter = 0;
	string line;
	int line_number = -1;
	string Song_full_path;
	string Song_name;
	string Singer;
	string Album;
	string Genre;
	string Year;
	string Duration;
	while (getline(inputFile, line))
	{
		line_counter++;
		stringstream inputString(line);


		getline(inputString, Song_full_path, '\t');
		getline(inputString, Song_name, '\t');
		getline(inputString, Singer, '\t');
		getline(inputString, Album, '\t');
		getline(inputString, Genre, '\t');
		getline(inputString, Year, '\t');
		getline(inputString, Duration, '\t');


		if (Song_full_path.compare(Song_full_pathx) == 0) {
			line_number = line_counter;
		}
	}
	inputFile.close();
	if (line_number == -1) {
		cout << "This m_id is not found !" << endl;

	}
	else {
		fstream inputFile;
		inputFile.open("MUSIC3.txt");

		vector<string> lines;
		string line;

		// loop getting single characters
		while (getline(inputFile, line))
		{
			lines.push_back(line);
		}

		inputFile.close();

		// open file in write mode or out mode /////////// print the file
		ofstream write_file;
		write_file.open("MUSIC3.txt");
		line_number--;
		for (int i = 0; i < lines.size(); i++)
		{
			if (i != line_number) {
				write_file << lines[i] << endl;
				cout << lines[i] << endl;
			}
		}

		// closing output file
		write_file.close();
	}
}


Remove::Remove() : Options("Remove") {};

Remove::~Remove() {};



void Remove::RemoveSong(vector <Folders*>& folders, const string& input, int choise)
{
	std::pair<Folders*, unsigned> located_song = FindSongId(folders, input, choise);
	if (located_song.first != NULL) {
		Folders* app_folder = located_song.first;
		unsigned song_index = located_song.second;

		folders.at(f_DELETED)->GetSongsVector()->push_back(app_folder->GetSongsVector()->at(song_index));
		delete_line(app_folder->GetSongsVector()->at(song_index).GetSong_full_path());
		app_folder->GetSongsVector()->erase(app_folder->GetSongsVector()->begin() + song_index);
		for (int i = 0; i < folders.at(f_ALL)->GetSongsVector()->size(); i++) {
			cout << "i = " << folders.at(f_ALL)->GetSongsVector()->at(i) << endl;
		}

		for (int i = 0; i < folders.at(f_DELETED)->GetSongsVector()->size(); i++) {
			cout << "i = " << folders.at(f_DELETED)->GetSongsVector()->at(i) << endl;
		}


	}
	else
		cout << "\n There is no song found - can not remove" << endl;
}


void Remove::SubOptionAction(vector <Folders*>& folders, const string& input, int choise)
{
	RemoveSong(folders, input, choise);
}

o_Playlists::o_Playlists() : Options("o_Playlists") {};

o_Playlists::~o_Playlists() {};



AddPlayList::AddPlayList() : Options("AddPlayList") {};

AddPlayList::~AddPlayList() {};

void AddPlayList::Add_PlayList(vector <Folders*>& folders, const string& input) // todo: change input to m_ID
{
	f_PlayLists* f_playlists = new f_PlayLists;
	// add name of the folder
	f_playlists->SetName(input);
	folders.push_back(f_playlists);


	cout << "*******************" << endl;
	for (int i = 0; i < folders.size(); i++) {
		string f_name = folders[i]->GetName();
		cout << "folders.f_name()" << f_name << endl;
	}
	cout << "*******************" << endl;


}

void AddPlayList::SubOptionAction(vector <Folders*>& folders, const string& input, int choice)
{
	Add_PlayList(folders, input);
}



Delete::Delete() : Options("Delete") {};

Delete::~Delete() {};


void Delete::Delete_PlayList(vector <Folders*>& folders, const string& input) // todo: change input to m_ID
{
	cout << "Delete::Delete_PlayList()" << endl;

	if (input.compare("f_All") != 0 && input.compare("Favorite") != 0 && \
		input.compare("Recent") != 0 && input.compare("Daily_mix") != 0 && \
		input.compare("Mostplayed") != 0 && input.compare("Deleted") != 0) {

		// find Playlist based on name
		int elem = -1;
		for (int i = 0; i < folders.size(); i++) {
			string f_name = folders[i]->GetName();
			cout << "folders.f_name()" << f_name << endl;
			if (f_name.compare(input) == 0) {
				elem = i;
				break;
			}
		}
		//cout << "elem" << elem << endl;


		if (elem != -1) {
			folders.erase(folders.begin() + elem);
		}
		else {
			cout << "\nThere is no PlayLists found - can not remove" << endl;
		}

	}
	else {
		cout << "\nThe following folders cannot be deleted: [ Favorite, Recent, Daily_mix, Mostplayed, Deleted]" << endl;

	}

	cout << "*******************" << endl;
	for (int i = 0; i < folders.size(); i++) {
		string f_name = folders[i]->GetName();
		cout << "folders name: " << f_name << endl;
	}
	cout << "*******************" << endl;

}

void Delete::SubOptionAction(vector <Folders*>& folders, const string& input, int choice)
{
	Delete_PlayList(folders, input);
}






/* ----------------------------------------------------------------------- */
/* ---------------------------- Class Daily_Mix -------------------------- */
/* ----------------------------------------------------------------------- */



/* ----------------------------------------------------------------------- */
/* ------------------------------ Class Search --------------------------- */
/* ----------------------------------------------------------------------- */






/* ----------------------------------------------------------------------- */
/* ------------------------------ Class Podcast -------------------------- */
/* ----------------------------------------------------------------------- */


