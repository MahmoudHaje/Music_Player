# include "Library.h"


// add song to vector and to file
void o_Library::AddFunction(Folders* folder, string a, string b, string c, string d, string e, string f, int a_file)
{
	vector<Song>* songs = folder->GetSongsVector();
	Song s1;
	s1.SetSong_full_path(a);
	s1.SetSong_name(b);
	s1.SetSinger(c);
	s1.SetAlbum(d);
	s1.SetGenre(e);
	s1.SetDuration(f);
	songs->push_back(s1);

	if (a_file == f_FAVORITE)
	{
		std::ofstream file("fav.txt", std::ios::app);
		file << s1.GetSong_full_path() << '\t' << s1.GetSong_name() << '\t' << s1.GetSinger() << '\t' << '\t' << s1.GetAlbum() << '\t' << s1.GetGenre() << '\t' << s1.GetDuration() << std::endl;
	}

	else if (a_file == f_DAILYMIX)
	{
		std::ofstream file("Daily.txt", std::ios::app);
		file << s1.GetSong_full_path() << '\t' << s1.GetSong_name() << '\t' << s1.GetSinger() << '\t' << '\t' << s1.GetAlbum() << '\t' << s1.GetGenre() << '\t' << s1.GetDuration() << std::endl;
	}
	else if (a_file == f_MOSTPLAYED)
	{
		std::ofstream file("MostPlayed.txt", std::ios::app);
		file << s1.GetSong_full_path() << '\t' << s1.GetSong_name() << '\t' << s1.GetSinger() << '\t' << '\t' << s1.GetAlbum() << '\t' << s1.GetGenre() << '\t' << s1.GetDuration() << std::endl;
	}
	else if (a_file == f_DELETED)
	{
		std::ofstream file("Deleted.txt", std::ios::app);
		file << s1.GetSong_full_path() << '\t' << s1.GetSong_name() << '\t' << s1.GetSinger() << '\t' << '\t' << s1.GetAlbum() << '\t' << s1.GetGenre() << '\t' << s1.GetDuration() << std::endl;
	}
	else if (a_file == f_ALL)
	{
		std::ofstream file("MUSIC3.txt", std::ios::app);
		file << s1.GetSong_full_path() << '\t' << s1.GetSong_name() << '\t' << s1.GetSinger() << '\t' << '\t' << s1.GetAlbum() << '\t' << s1.GetGenre() << '\t' << s1.GetDuration() << std::endl;
	}

}

//check if numbers or lettes
bool o_Library::isNumber(const string& s)
{
	for (char const& ch : s) {
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}


// Update Song by name or id
void o_Library::Update_name_id(vector <Folders*>& folders, string temp_input, int answer)
{
	vector<string> tokens;
	string delimiter = " ";
	size_t pos = 0;
	while ((pos = temp_input.find(delimiter)) != string::npos) {
		string token = temp_input.substr(0, pos);
		tokens.push_back(token);
		temp_input.erase(0, pos + delimiter.length());
	}
	tokens.push_back(temp_input);

	string singer, album, genre, duration, song_name, songID;
	string command = tokens[0].substr(0, 2); // extract the first three characters of the first token as the command
	if (!isNumber(tokens[1]))
	{
		song_name = tokens[1];
		for (int i = 2; i < tokens.size(); i++) {
			string token = tokens[i];
			if (token.substr(0, 7) == "singer=") {
				singer = token.substr(7);
			}
			else if (token.substr(0, 6) == "album=") {
				album = token.substr(6);
			}
			else if (token.substr(0, 6) == "genre=") {
				genre = token.substr(6);
			}
			else if (token.substr(0, 9) == "duration=") {
				duration = token.substr(9);
			}
		}
		Update_in_file(folders, song_name, singer, album, genre, duration);
	}
	else
	{
		songID = tokens[1];
		for (int i = 2; i < tokens.size(); i++) {
			string token = tokens[i];
			if (token.substr(0, 5) == "name=") {
				song_name = token.substr(7);
			}
			if (token.substr(0, 7) == "singer=") {
				singer = token.substr(7);
			}
			else if (token.substr(0, 6) == "album=") {
				album = token.substr(6);
			}
			else if (token.substr(0, 6) == "genre=") {
				genre = token.substr(6);
			}
			else if (token.substr(0, 9) == "duration=") {
				duration = token.substr(9);
			}
		}
		Update_in_file(folders, song_name, singer, album, genre, duration, songID);
	}
}

// Update the file 
void o_Library::update_file(Folders* folder, int Line, int choise, string replace)
{
	string line;
	fstream inputFile;
	inputFile.open("MUSIC3.txt");
	for (int i = 0; i < Line; i++)  getline(inputFile, line);
	size_t start = line.find('\t') + choise;
	size_t end = line.find('\t', start);
	line.replace(start, end - start, replace);
	inputFile.seekp(inputFile.tellg()); // Move the put pointer to the current get position
}

//Print the Song (name/id) that exits in folder (name) 
void o_Library::Print_song(vector <Folders*>& folders, string token, int place)
{
	unsigned size;
	string id;
	bool found_flag = false;
	int flag_repet = 0;
	for (int i = 1; i < folders.size(); i++)
	{
		size = folders.at(i)->GetSongsVector()->size();
		if (size)
			/* Running over the mails each folder */
			for (int j = 0; j < size; j++)
			{
				if (place == 1) id = folders.at(i)->GetSongsVector()->at(j).GetID();
				else if (place == 2) id = folders.at(i)->GetSongsVector()->at(j).GetSong_name();
				if (id.compare(token) == 0)
				{
					if (flag_repet == 0)
					{
						cout << "Song id: " << folders.at(i)->GetSongsVector()->at(j).GetID() << endl;
						cout << "Song full path: " << folders.at(i)->GetSongsVector()->at(j).GetSong_full_path() << endl;
						cout << "Song name: " << folders.at(i)->GetSongsVector()->at(j).GetSong_name() << endl;
						cout << "Song singer: " << folders.at(i)->GetSongsVector()->at(j).GetSinger() << endl;
						cout << "Song album: " << folders.at(i)->GetSongsVector()->at(j).GetAlbum() << endl;
						cout << "Song year: " << folders.at(i)->GetSongsVector()->at(j).GetGenre() << endl;
						cout << "Song duration" << folders.at(i)->GetSongsVector()->at(j).GetDuration() << endl;
					}
					flag_repet = 1;
					cout << "This song are in the list: " << folders.at(i)->GetName() << endl;
					found_flag = true;
				}
			}
	}
	if (!found_flag) 		cout << "Song: " << token << "does not exit in any list not found in any list \n " << endl;		// id not found;
}

//Update the song in the other files that it beleongs to
void o_Library::Update_in_file(vector <Folders*>& folders, string song_name, string singer, string album, string genre, string duration, string ID_X)
{
	unsigned size;
	string id;
	bool found_flag = false;
	for (int i = 0; i < folders.size(); i++)
	{
		size = folders.at(i)->GetSongsVector()->size();
		if (size)
			for (int j = 0; j < size; j++)
			{
				id = folders.at(i)->GetSongsVector()->at(j).GetSong_name();
				if (id.compare(song_name) == 0)
				{
					if (song_name != "")
					{
						folders.at(i)->GetSongsVector()->at(j).SetSinger(song_name);
						//	update_file(folders.at(i), j, 1, singer);
					}
					if (singer != "")
					{
						folders.at(i)->GetSongsVector()->at(j).SetSinger(singer);
						//	update_file(folders.at(i), j, 1, singer);
					}
					if (album != "")
					{
						folders.at(i)->GetSongsVector()->at(j).SetAlbum(album);
						//	update_file(folders.at(i), j, 2, album);
					}
					if (genre != "")
					{
						folders.at(i)->GetSongsVector()->at(j).SetGenre(genre);
						//	update_file(folders.at(i), j, 3, genre);
					}
					if (duration != "")
					{
						folders.at(i)->GetSongsVector()->at(j).SetDuration(duration);
						//update_file(folders.at(i), j, 4, duration);
					}

					found_flag = true;
					break;
				}
			}

		if (found_flag)
			break;
	}
	if (!found_flag) 		cout << "m_id not found !" << endl;		// id not found;
}

void o_Library::Update_in_file(vector <Folders*>& folders, string song_name, string singer, string album, string genre, string duration)
{
	unsigned size;
	string id;
	bool found_flag = false;
	for (int i = 0; i < folders.size(); i++)
	{
		size = folders.at(i)->GetSongsVector()->size();
		if (size)
			for (int j = 0; j < size; j++)
			{
				id = folders.at(i)->GetSongsVector()->at(j).GetSong_name();
				cout << "id id id id :" << id << endl;
				/* Condition to find mail by unique id */
				if (id.compare(song_name) == 0)
				{
					cout << singer << "." << album << "." << genre << "." << duration;
					if (singer != "")
					{
						folders.at(i)->GetSongsVector()->at(j).SetSinger(singer);
						//	update_file(folders.at(i), j, 1, singer);
					}
					if (album != "")
					{
						folders.at(i)->GetSongsVector()->at(j).SetAlbum(album);
						//	update_file(folders.at(i), j, 2, album);
					}
					if (genre != "")
					{
						folders.at(i)->GetSongsVector()->at(j).SetGenre(genre);
						//	update_file(folders.at(i), j, 3, genre);
					}
					if (duration != "")
					{
						folders.at(i)->GetSongsVector()->at(j).SetDuration(duration);
						//update_file(folders.at(i), j, 4, duration);
					}
					found_flag = true;
					break;
				}
			}

		if (found_flag)
			break;
	}
	if (!found_flag) 		cout << "m_id not found !" << endl;		// id not found;

}

//Add song to playlist, search by name
void o_Library::ADDFromPl(vector <Folders*>& folders, const string& input1, int input2)
{
	unsigned size;
	string id;
	bool found_flag = false;
	size = folders.at(f_ALL)->GetSongsVector()->size();
	string ID, songPath, name, singer, album, genre, duration;
	for (unsigned j = 0; j < size; j++)
	{
		id = folders.at(f_ALL)->GetSongsVector()->at(j).GetSong_name();
		if (id.compare(input1) == 0)
		{
			ID = folders.at(f_ALL)->GetSongsVector()->at(j).GetID();
			songPath = folders.at(f_ALL)->GetSongsVector()->at(j).GetSong_full_path();
			name = folders.at(f_ALL)->GetSongsVector()->at(j).GetSong_name();
			singer = folders.at(f_ALL)->GetSongsVector()->at(j).GetSinger();
			album = folders.at(f_ALL)->GetSongsVector()->at(j).GetAlbum();
			genre = folders.at(f_ALL)->GetSongsVector()->at(j).GetGenre();
			duration = folders.at(f_ALL)->GetSongsVector()->at(j).GetDuration();
			if (input2 == f_RECENT) 	AddSongs_toFile(folders, songPath, name, singer, album, genre, duration);
			else
				AddFunction(folders.at(input2), songPath, name, singer, album, genre, duration, input2);
			folders.at(input2)->GetSongsVector()->erase(folders.at(input2)->GetSongsVector()->begin() + j);
			found_flag = true;
			break;
		}
	}
	if (!found_flag)	cout << "m_id not found !" << endl;
}

//Remove song from playlist , searh by name or id 
void o_Library::RemoveFromPl(vector <Folders*>& folders, const string& input1, int input2, int choise)
{
	unsigned size;
	string id;
	bool found_flag = false;
	size = folders.at(input2)->GetSongsVector()->size();
	for (unsigned j = 0; j < size; j++)
	{
		if (choise == 1) id = folders.at(input2)->GetSongsVector()->at(j).GetID();
		else if (choise == 2) id = folders.at(input2)->GetSongsVector()->at(j).GetSong_name();

		if (id.compare(input1) == 0)
		{
			folders.at(input2)->GetSongsVector()->erase(folders.at(input2)->GetSongsVector()->begin() + j);

			//	update_file(folders.at(i), j, 1, singer);// make new function
			found_flag = true;
			break;
		}
	}
	if (!found_flag)	cout << "m_id not found !" << endl;

}

//ADD song to the Recent.txt file, if lines >10 must delete and add new line
void o_Library::AddSongs_toFile(vector <Folders*>& folders, string a, string b, string c, string d, string e, string f)
{
	string filename = "Recent.txt";
	ifstream infile(filename);
	string line;
	vector<string> lines;

	// Read the lines from the file
	while (getline(infile, line))
	{
		lines.push_back(line);
	}
	// Check if the file has less than 10 lines
	if (lines.size() < 10)
	{
		ofstream outfile(filename, ios::app);
		outfile << a << '\t' << b << '\t' << c << '\t' << '\t' << d << '\t' << e << '\t' << f << std::endl;
		outfile.close();

		//folders.at(f_RECENT)->GetSongsVector()->push_back(s1);
	}
	else
	{
		// Delete the first line
		lines.erase(lines.begin());
		// Add the new line to the end of the vector
		lines.push_back(a + '\t' + b + '\t' + c + '\t' + '\t' + d + '\t' + e + '\t' + f);
		// Write the lines back to the file
		ofstream outfile(filename);
		for (auto& line : lines)
		{
			outfile << line << endl;
		}
		outfile.close();
		//folders.at(f_RECENT)->GetSongsVector()->push_back(s1);
	}
	vector <Song> songs1;
	songs1 = read_records("Recent.txt");
	folders.at(f_RECENT)->GetSongsVector()->clear();
	for (Song song : songs1) folders.at(f_RECENT)->GetSongsVector()->push_back(song);

}

// play song by name or id
void o_Library::Play_song_by_name_id(vector <Folders*>& folders, const string& input, int choise)
{
	unsigned size;
	string id;
	bool found_flag = false;
	size = folders.at(f_ALL)->GetSongsVector()->size();
	for (unsigned j = 0; j < size; j++)
	{
		if (choise == 1) id = folders.at(f_ALL)->GetSongsVector()->at(j).GetID();
		else if (choise == 2) id = folders.at(f_ALL)->GetSongsVector()->at(j).GetSong_name();
		if (id.compare(input) == 0)
		{
			cout << folders.at(f_ALL)->GetSongsVector()->at(j).GetSong_full_path() << endl;

			AddSongs_toFile(folders, folders.at(f_ALL)->GetSongsVector()->at(j).GetSong_full_path(), \
				folders.at(f_ALL)->GetSongsVector()->at(j).GetSong_name(), \
				folders.at(f_ALL)->GetSongsVector()->at(j).GetSinger(), \
				folders.at(f_ALL)->GetSongsVector()->at(j).GetAlbum(), \
				folders.at(f_ALL)->GetSongsVector()->at(j).GetGenre(), \
				folders.at(f_ALL)->GetSongsVector()->at(j).GetDuration());

			//player.play(folders.at(f_ALL)->GetSongsVector()->at(j).GetSong_full_path());
			found_flag = true;
			break;
		}
	}
	if (!found_flag)	cout << "Song not found !" << endl; // song not found;
}

// play sorted songs 
void o_Library::SortSongs_Play(Folders* folder)
{
	vector<Song>* songs = folder->GetSongsVector();
	unsigned size = folder->GetSongsVector()->size();

	// Sort the songs by title
	std::sort(songs->begin(), songs->end(), [](const Song& s1, const Song& s2) {
		return s1.GetSong_name() < s2.GetSong_name();
		});
	// Print the  songs
	cout << "Songs sorted by title:" << endl;
	for (int i = 0; i < size; ++i)
	{
		//player.playList(folder->GetSongsVector())
		cout << folder->GetSongsVector()->at(i).GetSong_full_path() << endl;
	}

	// If there are no more songs to show, print a message
	if (size == 0) {
		cout << "\nNo songs to show." << endl;
	}
	else if (size == songs->size()) {
		cout << "\nNo more songs to show." << endl;
	}
}

//// play random songs 
void o_Library::RandomSongs_Play(Folders* folder)
{
	vector<Song>* songs = folder->GetSongsVector();
	unsigned size = songs->size();

	// Shuffle the songs randomly
	std::random_device rd;
	std::mt19937 g(rd()); //generator based on the Mersenne Twister algorithm
	std::shuffle(songs->begin(), songs->end(), g);

	// Print the shuffled songs
	cout << "Songs in random order:" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << songs->at(i).GetSong_full_path() << endl;
	}
	// If there are no more songs to show, print a message
	if (size == 0) {
		cout << "\nNo songs to show." << endl;
	}
	else if (size == songs->size()) {
		cout << "\nNo more songs to show." << endl;
	}
}

// Delete song from play list by name or id
void o_Library::Delete_Song_from_list(vector <Folders*>& folders, const string& input, int choise)
{
	unsigned size;
	string id;
	bool found_flag = false;
	for (unsigned i = 1; i < folders.size(); i++)
	{
		size = folders.at(i)->GetSongsVector()->size();
		if (size)
			/* Running over the mails each folder */
			for (unsigned j = 0; j < size; j++)
			{
				if (choise == 1) id = folders.at(i)->GetSongsVector()->at(j).GetID();
				else if (choise == 2) id = folders.at(i)->GetSongsVector()->at(j).GetSong_name();

				if (id.compare(input) == 0)
				{
					folders.at(i)->GetSongsVector()->erase(folders.at(i)->GetSongsVector()->begin() + j);
					//	update_file(folders.at(i), j, 1, singer); // make new function
					found_flag = true;
					break;
				}
			}

		if (found_flag)
			break;
	}
	if (!found_flag)	cout << "m_id not found !" << endl;
}

// seperate the input that contain Add
void o_Library::seprate_Add(vector <Folders*>& folders, string temp_input)
{
	vector<string> tokens;
	string delimiter = " ";
	size_t pos = 0;
	while ((pos = temp_input.find(delimiter)) != string::npos) {
		string token = temp_input.substr(0, pos);
		tokens.push_back(token);
		temp_input.erase(0, pos + delimiter.length());
	}
	tokens.push_back(temp_input);

	string command = tokens[0].substr(0, 3); // extract the first three characters of the first token as the command
	string file_path = tokens[1];
	string song_name = tokens[2];

	string singer, album, genre, duration;
	for (int i = 3; i < tokens.size(); i++) {
		string token = tokens[i];
		if (token.substr(0, 7) == "singer=") {
			singer = token.substr(7);
		}
		else if (token.substr(0, 6) == "album=") {
			album = token.substr(6);
		}
		else if (token.substr(0, 6) == "genre=") {
			genre = token.substr(6);
		}
		else if (token.substr(0, 9) == "duration=") {
			duration = token.substr(9);
		}
	}
	AddFunction(folders.at(f_ALL), file_path, song_name, singer, album, genre, duration, f_ALL);
}


void o_Library::OptionAction(vector <Folders*>& folders, const string& input)
{
	LibraryList* librarylist = new LibraryList();
	int index_folder = f_ALL;
	bool flag_back = false;
	string temp_input;

	while (!flag_back)
	{
		PrintOptions(1);
		//cout << "\n\nC:\\" << folders.at(index_folder)->GetName() << "> ";
		getline(cin, temp_input);
		int ans = RegexCheck(temp_input);
		int place;
		if (ans >= 0)
		{
			string token;
			if (ans == 0) //add
			{
				if (temp_input.find("Add2PL") != string::npos)
				{
					string token1, token2;
					size_t pos1 = temp_input.find("<");
					size_t pos2 = temp_input.find(">");
					size_t pos3 = temp_input.find("<", pos2 + 1);
					size_t pos4 = temp_input.find(">", pos3 + 1);
					token1 = temp_input.substr(pos1 + 1, pos2 - pos1 - 1);
					token2 = temp_input.substr(pos3 + 1, pos4 - pos3 - 1);
					cout << "token1: " << token1 << "   token2:" << token2 << endl;
					if (token2 == "Favorite") ADDFromPl(folders, token1, f_FAVORITE);
					else if (token2 == "Recent") ADDFromPl(folders, token1, f_RECENT);
					else if (token2 == "Daily_mix") ADDFromPl(folders, token1, f_DAILYMIX);
					else if (token2 == "Mostplayed") ADDFromPl(folders, token1, f_MOSTPLAYED);
					else if (token2 == "Deleted") ADDFromPl(folders, token1, f_DELETED);
					else cout << " there is no folder in the name: " << token2 << endl;
				}
				else
				{
					seprate_Add(folders, temp_input);
				}
			}

			else if (ans == 1) //remove
			{
				if (temp_input.find("RemoveFromPL") != string::npos)
				{
					string token1, token2;
					size_t pos1 = temp_input.find("<");
					size_t pos2 = temp_input.find(">");
					size_t pos3 = temp_input.find("<", pos2 + 1);
					size_t pos4 = temp_input.find(">", pos3 + 1);
					token1 = temp_input.substr(pos1 + 1, pos2 - pos1 - 1);
					token2 = temp_input.substr(pos3 + 1, pos4 - pos3 - 1);
					cout << "token1: " << token1 << "   token2:" << token2 << endl;
					if (token2 == "Favorite") RemoveFromPl(folders, token1, f_FAVORITE, 2);
					else if (token2 == "Recent") RemoveFromPl(folders, token1, f_RECENT, 2);
					else if (token2 == "Daily_mix") RemoveFromPl(folders, token1, f_DAILYMIX, 2);
					else if (token2 == "Mostplayed") RemoveFromPl(folders, token1, f_MOSTPLAYED, 2);
					else if (token2 == "Deleted") RemoveFromPl(folders, token1, f_DELETED, 2);
					else cout << " there is no folder in the name: " << token2 << endl;

				}
				else
				{
					token = temp_input.substr(temp_input.find("<") + 1, temp_input.find(">") - temp_input.find("<") - 1);
					cout << "token in remove == " << token << endl;
					if (isNumber(token)) place = 1;
					else place = 2;
					librarylist->sub_options_library_list.at(ans - 1)->SubOptionAction(folders, token, place);
				}

			}
			else if (ans == 3)//update
			{
				Update_name_id(folders, temp_input, 3);
			}
			else if (ans == 4) //Delete
			{
				token = temp_input.substr(temp_input.find("<") + 1, temp_input.find(">") - temp_input.find("<") - 1);
				cout << "token in Delete == " << token << endl;
				if (isNumber(token)) place = 1;
				else place = 2;
				cout << "place == " << place << endl;
				Delete_Song_from_list(folders, token, place);
			}
			else if (ans == 9)//printsong
			{
				token = temp_input.substr(temp_input.find("<") + 1, temp_input.find(">") - temp_input.find("<") - 1);
				cout << "printsong in printsong == " << token << endl;
				if (isNumber(token)) place = 1;
				else place = 2;
				cout << "place == " << place << endl;
				Print_song(folders, token, place);
			}

			else if (ans == LIBRARY_PRINTPL)
			{
				int size = folders.size();
				for (int i = 0; i < size; i++) {
					cout << "FOLDER NAME: " << folders.at(i)->GetName() << endl;
				}

			}
			else if (ans == LIBRARY_MORE) // more 
			{
				PrintSongs(folders.at(f_ALL), true);
			}
			else if (ans == LIBRARY_LIST) // List 
			{
				PrintFirstTenSongs_ABC(folders.at(f_ALL));
			}

			else if (ans == 13) // Play songs 
			{
				if (temp_input.find("PlayAll") != string::npos)
				{
					SortSongs_Play(folders.at(f_ALL));

				}
				else if (temp_input.find("PlayRandom") != string::npos)
				{
					RandomSongs_Play(folders.at(f_ALL));
				}
				else
				{
					token = temp_input.substr(temp_input.find("<") + 1, temp_input.find(">") - temp_input.find("<") - 1);
					cout << "token in play == " << token << endl;
					if (isNumber(token)) place = 1;
					else place = 2;
					cout << "plcae: " << place;
					Play_song_by_name_id(folders, token, place);
				}

			}
			/* Back */
			else if (ans == LIBRARY_BACK) {
				cout << "flag back is truexxxxxxxxx " << input << endl;
				flag_back = true;
			}
		}
		else {
			cout << "m_index not found " << endl;

		}
	}
}


int o_Library::RegexCheck(const string& input)
{
	if (input.find("Add") != string::npos) return 0;
	else if (input.find("Remove") != string::npos) return 1;
	else if (input.find("Update") != string::npos) return 3;
	else if (input.find("Delete") != string::npos) return 4;
	else if (input.find("PrintSong") != string::npos) return 9;
	else if (input == "PrintPL") return LIBRARY_PRINTPL;
	else if (input == "More") return LIBRARY_MORE;
	else if (input == "List") return LIBRARY_LIST;
	else if (input.find("Play") != string::npos) return 13;
	else if ("Back" == input) return LIBRARY_BACK;
	else
		cout << "No appropriate command." << endl; return -1;
}


void o_Library::SubOptionAction(vector <Folders*>& folders, const string& input, int choise)
{
	cout << "Options::SubOptionAction" << endl;
}



LibraryList::LibraryList() : Options("LibraryList")
{
	Remove* sub_remove = new Remove;
	sub_options_library_list.push_back(sub_remove);
}

LibraryList::~LibraryList()
{
	for (unsigned i = 0; i < sub_options_library_list.size(); i++)
		delete sub_options_library_list.at(i);
}



o_Library::o_Library() : Options("o_Library") {};

o_Library::~o_Library() {};
