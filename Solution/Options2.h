# ifndef OPTIONS2_H
# define OPTIONS2_H

# include <iostream>
# include <regex>
# include <map>
#include <algorithm>
#include <random>

# include "Folders2.h"
//# include "Player.h"
//Player player;

class Folders;

# define OPTIONS_ARRAY { "Daily_Mix", "Search", "Podcast", "Library", "Play_Lists" ,"Help","Exit"};

# define o_DAILYMIX			(0)
# define o_SEARCH			(1)
# define o_PODCAST			(2)
# define o_LIBRARY			(3)
# define o_PLAYLISTS		(4)
# define HELP				(5)
# define EXIT				(6)

# define TOTAL_OPTIONS		(7)


# define OPTIONS_DISPLAY { "Print <unique_id>", "Exit", "Help"};
# define PRINT				    (0)
//# define EXIT				    (1)


# define OPTIONS_LIBRARY {"Add <file path> <song name> singer=<singer> album=<album> genre=<genre> duration =<duration>",\
							"Remove <unique_id>","Remove <song_name>",\
							"Update song_name  singer=<singer> album=<album> genre=<genre> duration =<duration>",\
							"Update file_ID name=<song name> singer=<singer> album=<album> genre=<genre> duration =<duration>",\
							"Delete <unique_id>","Delete <song_name>","RemoveFromPL <song_name> <playlist_name>",\
							"PrintPL" ,"PrintSong <unique_id>","PrintSong <song_name>","More","List","Play <song_name>",\
							 "Play <song_id>","PlayAll","PlayRandom","Add2PL<song_name> <playlist_name>","Back"};

# define LIBRARY_ADD				(0)
# define LIBRARY_REMOVE_ID			(1)
# define LIBRARY_REMOVE_songName	(2)
# define LIBRARY_UPDATE_SONG_NAME	(3)
# define LIBRARY_UPDATE_ID			(4)
# define LIBRARY_DELETE_ID			(5)
# define LIBRARY_DELETE_songName	(6)
# define LIBRARY_REMOVE_FROM_PL 	(7)
# define LIBRARY_PRINTPL		 	(8)
# define LIBRARY_PRINT_SONG_ID	 	(9)
# define LIBRARY_PRINT_SONG_NAME	(10)
# define LIBRARY_MORE				(11)
# define LIBRARY_LIST				(12)
# define LIBRARY_PLAY_SONG_NAME		(13)
# define LIBRARY_PLAY_SONG_NAME		(14)
# define LIBRARY_PLAY_ABC			(15)
# define LIBRARY_PLAY_RANDOM		(16)
# define LIBRARY_Add_2PL			(17)
# define LIBRARY_BACK				(18)
# define LIBRARY_TOTAL_OPTIONS		(19)
# define MAX_SIZE_COMMAND   (3)

# define OPTIONS_PLAYLISTS { "Add <playlist_name>", "Delete <playlist_name>"};

# define PLAYLISTS_ADD				(0)
# define PLAYLISTS_DELETE			(1)
# define PLAYLISTS_TOTAL_OPTIONS	(2)

using namespace std;

class Options
{
public:
	Options(string name) : option_type(name) {};
	virtual ~Options() {};

	void PrintSongs(Folders* folder, const bool flag) const; // Print 10 songs, then Print the 10th after...
	void PrintFirstTenSongs_ABC(Folders* folder) const; //Print the first 10 songs in ABC order
	std::pair <Folders*, unsigned> FindSongId(const vector <Folders*> folders, const string id2find, int choise) const; //Find song Id
	static void PrintOptions(const int num); // Prin the main options
	virtual void OptionAction(vector <Folders*>& folders, const string& input) {};
	virtual void SubOptionAction(vector <Folders*>& folders, const string& input, int choise) {};


protected:
	string input_arr[MAX_SIZE_COMMAND];
	string option_type;
	static unsigned print_indx;
};






class o_Playlists : public Options
{
public:
	o_Playlists();
	~o_Playlists();
	void OptionAction(vector <Folders*>& folders, const string& input) override;
	void SubOptionAction(vector <Folders*>& folders, const string& input, int choise) override;
	int RegexCheck(const string& input);

	//private:

};





class Remove : public Options
{
public:
	Remove();
	~Remove();

	void RemoveSong(vector <Folders*>& folders, const string& input, int choise);
	void SubOptionAction(vector <Folders*>& folders, const string& input, int choise) override;


private:
};

class AddPlayList : public Options
{
public:
	AddPlayList();
	~AddPlayList();

	void Add_PlayList(vector <Folders*>& folders, const string& input);
	void SubOptionAction(vector <Folders*>& folders, const string& input, int choise) override;

	//void SubOptionActionRlist(vector <Folders*>& folders, string input[], unsigned folder_indx, map<string, list<Contacts>>& rlist) override;

private:
	//void create_new_librarylist(map<string, list<Contacts>>& rlist, const string& input);
};

class Delete : public Options
{
public:
	Delete();
	~Delete();

	void Delete_PlayList(vector <Folders*>& folders, const string& input);
	void SubOptionAction(vector <Folders*>& folders, const string& input, int choise) override;

	//void OptionAction(vector <Folders*>& folders, const string& input, list <Contacts>& contact_list, map<string, list<Contacts>>& rlist) override;

	//void DeletePlayLists(vector <Folders*>& folders, const string& input);
	//void SubOptionAction(vector <Folders*>& folders, const string& input) override;

private:
};

# endif // OPTIONS_H