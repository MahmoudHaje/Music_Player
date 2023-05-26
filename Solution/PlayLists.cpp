#include "PlayLists.h"






void o_Playlists::OptionAction(vector <Folders*>& folders, const string& input)
{
	// show option

	//RemoveSpaceSTR(input, input_arr);
	cout << "o_Playlists::OptionAction" << endl;

	//Remove* remove = new Remove; // todo: maybe this object can be created in the constructor o_Library::o_Library() 
	//remove->RemoveSong(folders, input);

	PlaylistsList* playlistslist = new PlaylistsList();


	int index_folder = f_ALL;
	bool flag_back = false;
	string temp_input;

	while (!flag_back)
	{
		PrintOptions(2);
		cout << "\n\nC:\\" << folders.at(index_folder)->GetName() << "> ";
		getline(cin, temp_input);
		int ans = RegexCheck(temp_input);
		if (ans >= 0)
		{

			// Using the erase, remove_if, and ::isspace functions.
			temp_input.erase(std::remove_if(temp_input.begin(), temp_input.end(), ::isspace), temp_input.end());
			cout << " == == == == == == == temp_input == == == == == == == " << temp_input << endl;

			if (temp_input.find("Add<") != string::npos) {
				string s = "Add<";
				string::size_type i = temp_input.find(s);
				if (i != string::npos) {
					temp_input.erase(i, s.length()); // remove "Add<"
					temp_input.erase(temp_input.length() - 1, temp_input.length()); // remove ">"
				}

				cout << "temp_input ==++== ==++== ==++== ==++== ==++== ==++== " << temp_input << endl;
			}
			else if (temp_input.find("Delete<") != string::npos) {

				string s = "Delete<";
				string::size_type i = temp_input.find(s);
				if (i != string::npos) {
					temp_input.erase(i, s.length()); // remove "Remove<"
					temp_input.erase(temp_input.length() - 1, temp_input.length()); // remove ">"
				}
				cout << "temp_input ==++== ==++== ==++== ==++== ==++== ==++== " << temp_input << endl;

			}
			cout << "temp_input ==++== ==++== ==++== ==++== ==++== ==++== " << temp_input << endl;

			playlistslist->sub_options_playlists_list.at(ans)->SubOptionAction(folders, temp_input, 0);
		}
		else {
			cout << "commands not found " << endl;
		}
	}
}


int o_Playlists::RegexCheck(const string& input)
{


	string temp_input = input;
	// Using the erase, remove_if, and ::isspace functions.
	temp_input.erase(std::remove_if(temp_input.begin(), temp_input.end(), ::isspace), temp_input.end());


	//if (input.compare("Add") == 0)

	string suffix = ">";

	// check if string start with "Add<" and ends with ">"
	if ((temp_input.rfind("Add<", 0) == 0) && (temp_input.rfind(suffix) == temp_input.size() - suffix.size())) {
		// s starts with prefix
		return 0;
	}
	else if ((temp_input.rfind("Delete<", 0) == 0) && (temp_input.rfind(suffix) == temp_input.size() - suffix.size())) {
		return 1;
	}
	else
		cout << "No appropriate command." << endl; return -1;
}

void o_Playlists::SubOptionAction(vector <Folders*>& folders, const string& input, int choice)
{
	cout << "o_Playlists::SubOptionAction" << endl;
}


PlaylistsList::PlaylistsList() : Options("PlaylistsList")
{
	cout << "PlaylistsList::PlaylistsList() : Options(PlaylistsList)" << endl;

	AddPlayList* sub_add = new AddPlayList;
	sub_options_playlists_list.push_back(sub_add);

	Delete* sub_delete = new Delete;
	sub_options_playlists_list.push_back(sub_delete);

}

PlaylistsList::~PlaylistsList()
{
	cout << "PlaylistsList::PlaylistsList()" << endl;

	//for (unsigned i = 0; i < sub_options_library_list.size();i++)
	//	delete sub_options_rlist.at(i);
}