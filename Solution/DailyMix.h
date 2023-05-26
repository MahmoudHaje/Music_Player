# include "Options2.h"



class o_Daily_Mix : public Options
{
public:
	o_Daily_Mix();
	~o_Daily_Mix();
	void OptionAction(vector <Folders*>& folders, const string& input);

	//void SubOptionActionCD(vector <Folders*>& folders, string input[], unsigned folder_indx) override;

private:
};

