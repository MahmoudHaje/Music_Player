# ifndef FOLDERS2_H
# define FOLDERS2_H

# include <vector>


#include "App.h"
#include "Song.h"

# define f_ALL 0
# define f_FAVORITE 1
# define f_RECENT 2
# define f_DAILYMIX 3
# define f_MOSTPLAYED 4
# define f_DELETED 5


# define DefaultSizeShow 10 // show always 10 songs at once


class Options;
class Song;


class Folders
{
public:
	Folders();
	Folders(const string& name);
	~Folders();

	const string GetName() const;
	const unsigned GetFoldersSize() const;
	vector<Song>* GetSongsVector();

	void SetName(const string& name);

	Folders& operator=(const Folders& other);

protected:
	static unsigned cnt_folders;
	vector <Song> songs;
	string folder_name;
};

class f_All : public Folders
{
public:
	f_All() : Folders("f_All") {};
};

class f_Favorite : public Folders
{
public:
	f_Favorite() : Folders("Favorite") {};
};

class f_Recent : public Folders
{
public:
	f_Recent() : Folders("Recent") {};
};


class f_Daily_Mix : public Folders
{
public:
	f_Daily_Mix() : Folders("Daily_mix") {};
};

class f_Mostplayed : public Folders
{
public:
	f_Mostplayed() : Folders("Mostplayed") {};
};


class f_Deleted : public Folders
{
public:
	f_Deleted() : Folders("Deleted") {};
};

class f_PlayLists : public Folders
{
public:
	f_PlayLists() : Folders("f_PlayLists") {};
};




# endif // FOLDERS_H