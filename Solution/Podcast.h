# include "Options2.h"


class o_Podcast : public Options
{
public:
	o_Podcast();
	~o_Podcast();
	void OptionAction(vector <Folders*>& folders, const string& input);

private:

};