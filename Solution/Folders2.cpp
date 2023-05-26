# include "Folders2.h"

unsigned Folders::cnt_folders = 0;


Folders::Folders() {}; //Constuctor
Folders::Folders(const string& name) : folder_name(name) { cnt_folders++; }; //Constuctor
Folders::~Folders() {}; //Destuctor

// Get
const string Folders::GetName() const { return folder_name; };
const unsigned Folders::GetFoldersSize() const { return cnt_folders; };

vector<Song>* Folders::GetSongsVector() { return &songs; };
void Folders::SetName(const string& name)
{
	folder_name = name;
	cout << "\nNew name saved successfully" << endl;
}

// Operator overloads
Folders& Folders::operator=(const Folders& other)
{
	folder_name = other.folder_name;

	return *this;
}




