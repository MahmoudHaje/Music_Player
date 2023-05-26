//#include "player.h"
//#include "library.h"
//#include "Enter_The_Program2.h"
#include "App.h"
#include "Song.h"



int main() {

    //vector <StudentRecord> records;
    //records = read_records();

    App a;
    a.RunProgram();
    cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;
    return 0;
}



/*
  Player player;

    // Initialize the library
    Library library;

    while (true) {
        string input;
        cout << "Enter command: ";
        cin >> input;

        if (input == "library") {
            // Start library mode
            library.startLibraryMode();
        }
        else if (input == "play") {
            // Play a song
            string songName;
            cout << "Enter song name: ";
            cin >> songName;
            player.play(songName);
        }
        else if (input == "stop") {
            // Stop playing
            player.stop();
            break;
        }
        else {
            cout << "Invalid command, try again" << endl;
        }
    }

*/