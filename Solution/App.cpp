#include "App.h"

# include "Library.h"
# include "DailyMix.h"
#include "Search.h"
# include "Podcast.h"
#include "PlayLists.h"

App::App()
{

	//Folders
	f_All* f_all = new f_All;						app_folders.push_back(f_all);
	f_Favorite* f_favorite = new f_Favorite;		app_folders.push_back(f_favorite);
	f_Recent* f_recent = new f_Recent;				app_folders.push_back(f_recent);
	f_Daily_Mix* f_daily_mix = new f_Daily_Mix;		app_folders.push_back(f_daily_mix);
	f_Mostplayed* f_mostplayed = new f_Mostplayed;	app_folders.push_back(f_mostplayed);
	f_Deleted* f_deleted = new f_Deleted;			app_folders.push_back(f_deleted);

	//Options
	o_Daily_Mix* o_daily_mix = new o_Daily_Mix;		app_options.push_back(o_daily_mix);
	o_Search* o_search = new o_Search;				app_options.push_back(o_search);
	o_Podcast* o_podcast = new o_Podcast;			app_options.push_back(o_podcast);
	o_Library* o_library = new o_Library;			app_options.push_back(o_library);
	o_Playlists* o_playlists = new o_Playlists;		app_options.push_back(o_playlists);



	vector <Song> songs1, songs_MostPlayed, songs_Favorites, songs_Recent, songs_DailyMix, songs_Deleted;

	songs1 = read_records("MUSIC3.txt");
	for (Song song : songs1)	app_folders[f_ALL]->GetSongsVector()->push_back(song);

	songs_Recent = read_records("Recent.txt");
	for (Song song : songs_Recent) app_folders[f_RECENT]->GetSongsVector()->push_back(song);

	songs_Recent = read_records("fav.txt");
	for (Song song : songs_Recent) app_folders[f_FAVORITE]->GetSongsVector()->push_back(song);

	songs_Recent = read_records("Daily.txt");
	for (Song song : songs_Recent) app_folders[f_DAILYMIX]->GetSongsVector()->push_back(song);

	songs_Recent = read_records("MostPlayed.txt");
	for (Song song : songs_Recent) app_folders[f_MOSTPLAYED]->GetSongsVector()->push_back(song);

	songs_Recent = read_records("Deleted.txt");
	for (Song song : songs_Recent) app_folders[f_DELETED]->GetSongsVector()->push_back(song);




	/*
	for (int i = 0; i < app_folders[f_ALL]->GetSongsVector()->size(); i++) {
		cout << app_folders[f_ALL]->GetSongsVector()->at(i) << endl;
	}
	cout << "*******************" << endl;
	cout << "*******************" << endl;
	for (int i = 0; i < app_folders[f_RECENT]->GetSongsVector()->size(); i++) {
		cout << app_folders[f_RECENT]->GetSongsVector()->at(i) << endl;
	}
	cout << "*******************" << endl;*/

	located_in = app_folders[f_ALL];
};

App::~App()
{
	for (unsigned i = 0; i < app_folders.size(); i++)	delete app_folders[i];

	for (unsigned j = 0; j < app_options.size(); j++)	delete app_options[j];
}


void App::RunProgram()
{
	srand(time(NULL));
	bool flag_exit = false;
	string ans;
	int ans_regex;

	while (!flag_exit)
	{
		app_options[PRINT]->PrintOptions(f_ALL);
		cin >> ans;
		ans_regex = RegexCheck(ans);
		if (ans_regex == EXIT)  flag_exit = true;
		else if (ans_regex == HELP)  app_options[PRINT]->PrintOptions(f_ALL);

		else ActionToDo(ans_regex, ans);
	}
}

int App::RegexCheck(string& str2check)
{
	cout << " App::RegexCheck" << endl;

	if (str2check.compare("Daily_Mix") == 0)
		return 0;
	else if (str2check.compare("Search") == 0)
		return 1;
	else if (str2check.compare("Podcast") == 0)
		return 2;
	else if (str2check.compare("Library") == 0)
	{
		app_options[PRINT]->PrintSongs(app_folders[f_ALL], false);
		return 3;
	}
	else if (str2check.compare("Play_Lists") == 0)
		return 4;
	else if (str2check.compare("Exit") == 0)
		return EXIT;
	else if (str2check.compare("Help") == 0)
		return HELP;
	else

		cout << "No appropriate command." << endl; return -1;
}


void App::ActionToDo(const int& num, const string& input)
{
	if (num >= 0)
		app_options.at(num)->OptionAction(app_folders, input);
}