# include "Options2.h"


class o_Library : public Options
{
public:
	o_Library();
	~o_Library();

	void AddFunction(Folders* folder, string a, string b, string c, string d, string e, string f, int file);//add song to vector and to file
	void Update_name_id(vector <Folders*>& folders, string temp_input, int answer);// Update Song by name or id
	void Update_in_file(vector <Folders*>& folders, string song_name, string singer, string album, string genre, string duration);
	void Update_in_file(vector <Folders*>& folders, string song_name, string singer, string album, string genre, string duration, string id);//Update the song in the other files that it beleongs to
	void update_file(Folders* folder, int Line, int choise, string replace);// Update the file
	void Delete_Song_from_list(vector <Folders*>& folders, const string& input, int choise);// Delete song from play list by name or id
	void Print_song(vector <Folders*>& folders, string song_name, int place);//Print the Song (name/id) that exits in folder (name) 
	void RemoveFromPl(vector <Folders*>& folders, const string& input1, int input2, int choise);//Remove song from playlist , searh by name or id 
	bool isNumber(const string& s);//check if numbers or lettes
	void Play_song_by_name_id(vector <Folders*>& folders, const string& input, int choise);// play song by name or id
	void SortSongs_Play(Folders* folder);// play sorted songs 
	void RandomSongs_Play(Folders* folder);
	void AddSongs_toFile(vector <Folders*>& folders, string a, string b, string c, string d, string e, string f);//ADD song to the Recent.txt file, if lines >10 must delete and add new line
	void ADDFromPl(vector <Folders*>& folders, const string& input1, int input2);//Add song to playlist, search by name
	void seprate_Add(vector <Folders*>& folders, string num); // seperate the input that contain Add

	void OptionAction(vector <Folders*>& folders, const string& input) override;
	void SubOptionAction(vector <Folders*>& folders, const string& input, int choise) override;

	int RegexCheck(const string& input);



	//private:

};



class LibraryList : public Options
{
public:
	LibraryList();
	~LibraryList();
	vector<Options*> sub_options_library_list;


private:
	const int help_print = 1;
};
