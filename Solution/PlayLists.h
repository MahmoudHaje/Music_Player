# include "Options2.h"

class PlaylistsList : public Options
{
public:
	PlaylistsList();
	~PlaylistsList();

	vector<Options*> sub_options_playlists_list;

private:
	int RegexCheck(const string& input);
};

