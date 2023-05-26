# include "Song.h"

unsigned Song::uniqe_id = 0;

/* ----------------------------- Constructors & Destructor ----------------------------- */



Song::Song()
{
  

    m_Song_full_path = "no Song path";
    m_Song_name = " no Song name";
    m_Singer = "no singer name";
    m_Album = "no album name";
    m_Genre = "no genre name";
    m_Duration = "no duration name";
    uniqe_id++;
    m_id = to_string(uniqe_id);
   
    //cout << "DUMY CONSTRUCTOR START END" << endl;

}

Song::Song(string Song_full_path, string Song_name, string Singer, string Album, string Genre, string Duration)
{

    //cout << "********* Song::Song *********" << endl;

    m_Song_full_path = Song_full_path;
    m_Song_name = Song_name;
    m_Singer = Singer;
    m_Album = Album;
    m_Genre = Genre;
    m_Duration = Duration;
    uniqe_id++;
    m_id = to_string(uniqe_id);


}



// Get
string Song::GetSong_full_path() const { return m_Song_full_path; };
string Song::GetSong_name() const { return m_Song_name; };
string Song::GetSinger()const { return m_Singer; };
string Song::GetAlbum() const { return m_Album; };
string Song::GetGenre() const { return m_Genre; };
string Song::GetDuration() const { return m_Duration; };
string Song::GetID() const { return m_id; };

//Set
void Song::SetSong_full_path(const string& Song_full_path) { m_Song_full_path = Song_full_path; };
void Song::SetSong_name(const string& Song_name) { m_Song_name = Song_name; };
void Song::SetSinger(const string& Singer) { m_Singer = Singer; };
void Song::SetAlbum(const string& Album) { m_Album = Album; };
void Song::SetGenre(const string& Genre) { m_Genre = Genre; };
void Song::SetDuration(const string& Duration) { m_Duration = Duration; };
void Song::SetID(const string& id) { m_id = id; };


void Song::Show() const
{
    cout << "\n" << m_id << "." << m_Song_full_path << "\t\t" << m_Song_name << "\t\t" << m_Singer << "\t\t";
    cout << m_Album << "\t\t" << m_Genre  << "\t\t" << m_Duration;
}
void displaySongs(vector<Song>& songs) {

    for (auto song : songs) {
        song.Show();
    }
}

vector<Song> read_records(string FilePath)
{
    ifstream inputFile;
    inputFile.open(FilePath);
    string line = "";
    //StudentId, Last Name, FirstName, Age, Phone Number, GPA
    string m_Song_full_path;
    string m_Song_name;
    string m_Singer;
    string m_Album;
    string m_Genre;
    string m_Year;
    string m_Duration;
    //  string uniqe_id;
    vector<Song> songs;
    while (getline(inputFile, line)) {
        stringstream inputString(line);
        //   getline(inputString, (uniqe_id), '\t');
        getline(inputString, m_Song_full_path, '\t');
        getline(inputString, m_Song_name, '\t');
        getline(inputString, m_Singer, '\t');
        getline(inputString, m_Album, '\t');
        getline(inputString, m_Genre, '\t');
        getline(inputString, m_Duration, '\t');
        Song song(m_Song_full_path, m_Song_name, m_Singer, m_Album, m_Genre, m_Duration);
        
        songs.push_back(song);
        line = "";
    }
    return songs;
}


//Operator overloads 
ostream& operator<<(ostream& os, const Song& song)
{

    os << "\n" << song.m_id << "." << song.m_Song_full_path << "\t\t" << song.m_Song_name << "\t\t" << song.m_Singer << "\t\t";
    os << song.m_Album << "\t\t" << song.m_Genre  << "\t\t" << song.m_Duration;
    return os;
}

Song& Song::operator=(const Song& other)
{
    m_Song_full_path = other.m_Song_full_path;
    m_Song_name = other.m_Song_name;
    m_Singer = other.m_Singer;
    // m_date = other.m_date;
    m_Album = other.m_Album;
    m_Genre = other.m_Genre;

    m_Duration = other.m_Duration;
    m_id = other.m_id;
    return *this;
}







