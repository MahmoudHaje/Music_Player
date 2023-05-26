# ifndef SONG_H
# define SONG_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <iterator>
# include <list>
# include <vector>
# include <regex>


using namespace std;
class Song
{
public:
	Song();
	Song(string Song_full_path, string Song_name, string Singer, string Album, string Genre, string Duration);
	~Song() {};

	//Get
	string GetSong_full_path() const;
	string GetSong_name() const;
	string GetSinger()const;
	string GetAlbum() const;
	string GetGenre() const;
	string GetDuration() const;   
	string GetID() const;
	
	//Set
	void SetSong_full_path(const string& Song_full_path);
	void SetSong_name(const string& Song_name);
	void SetSinger(const string& Singer);
	void SetAlbum(const string& Album);
	void SetGenre(const string& Genre);
	void SetDuration(const string& Duration);
	void SetID(const string& id);

	// Operator overloads
	Song& operator=(const Song& other);
	friend ostream& operator<<(ostream& os, const Song& mail);

	void Show() const;


private:
	string m_Song_full_path; 
	string m_Song_name;
	string m_Singer; 
	string m_Album; 
	string m_Genre; 
	string m_Duration; 
	string m_id;
	static unsigned uniqe_id; 
};


vector<Song> read_records(string FilePath);


# endif // SONG_H