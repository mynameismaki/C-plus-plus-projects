#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int choice1, trials = 3;
char choice, choice2, guess;
string name1, name2, yesno, fsl, hint, language;
bool guessTF = false;
    
/* Knowledge of the program */
string englishwordsguide56[10] = {"Queue, ","Class, ","Piano, ","Admin, ", "Advice, ","Review, ","Object, ","Linked, ","Stacks, ", "Friend"};
string tagalogwordsguide56[10] = {"Wakas, ","Damhin, ", "Alpas, ","Labis, ","Sambat, ","Sukgisan, ","Madali, ","Magaan, ","Ulayaw, ", "Bodega"};
string englishwordsguide78[10] = {"Priority, ","Bracket, ","Default, ","Program, ","Absolute, ","Property, ","Warranty, ","Function, ","Language","Academic"};
string tagalogwordsguide78[10] = {"Sintaks, ", "Sagisag, ", "Pintura, ","Rosaryo, ","Kulambo, ","Pandikit, ","Mapanuri, ","Kaalaman,","Lingwahe,","Pangalan"};
string englishwordsguide910[10] = {"Selection, ","Parameter, ","Statement, ","Identical, ","Reference, ","Friendship, ","Programmer, ","Specifiers, ","Repetition, ","Destructor"};
string tagalogwordsguide910[10] = {"Kondisyon, ","Halimbawa, ","Inhinyero, ","Kompyuter, ","Paandarin, ","Pagmamarka, ","Palaisipan, ","Makinabang, ","Pamamaraan, ","Ekspresyon"};

void Play();
void Exit();
void Instructions1();
void Instructions2();
void Instructions3();
void HangmanDraw();
void Hangman();

class Guide {
    public:

        void fivesixguideE(string fivesixguideEpassed[]) {
            cout << "\n5 to 6 letters english words:\n\n    ";
            for (int i = 0; i<9; i++)
                cout << fivesixguideEpassed[i];
            cout << endl;
            while (fsl.length() != 5 && fsl.length() != 6) {
                cout << "Please make sure " << name2 << " that the word you create is legible and 5-6 letters, it can be Tagalog or English word: ";
                cin >> fsl;
            }
            for (int space = 0; space < 50; space++)
                cout << endl;
            cout << "Ok then, proceeding to the game!";
            cout << endl << endl;
        }
        void fivesixguideT(string fivesixguideTpassed[]) {
            cout << "\n5 to 6 letters tagalog words:\n\n    ";
            for (int i = 0; i<9; i++) 
                cout << fivesixguideTpassed[i];
            cout << endl;
            while (fsl.length() != 5 && fsl.length() != 6) {
                cout << "Please make sure " << name2 << " that the word you create is legible and 5-6 letters, it can be Tagalog or English word: ";
                cin >> fsl;
            }
            for (int space = 0; space < 50; space++)
                cout << endl;
            cout << "Ok then, proceeding to the game!";
            cout << endl << endl;
        }
        void seveneightguideE(string seveneightguideEpassed[]) {
            cout << "\n7 to 8 letters tagalog words:\n\n    ";
            for (int i = 0; i<9; i++) 
                cout << seveneightguideEpassed[i];
            cout << endl;
            while (fsl.length() != 7 && fsl.length() != 8) {
                cout << "\n\nPlease make sure " << name2 << " that the word you create is legible and 7-8 letters, it can be Tagalog or English word: ";
                cin >> fsl;
            }
            for (int space = 0; space < 50; space++)
                cout << endl;
            cout << "Ok then, proceeding to the game!";
            cout << endl << endl;
        }
        void seveneightguideT(string seveneightguideTpassed[]) {
            cout << "\n7 to 8 letters tagalog words:\n\n    ";
            for (int i = 0; i<9; i++) 
                cout << seveneightguideTpassed[i];
            cout << endl;
            while (fsl.length() != 7 && fsl.length() != 8) {
                cout << "\n\nPlease make sure " << name2 << " that the word you create is legible and 7-8 letters, it can be Tagalog or English word: ";
                cin >> fsl;
            }
            for (int space = 0; space < 50; space++)
                cout << endl;
            cout << "Ok then, proceeding to the game!";
            cout << endl << endl;
        }
        void ninetenguideE(string ninetenEpassed[]) {
            cout << "\n9 to 10 letters tagalog words:\n\n    ";
            for (int i = 0; i<9; i++) 
            cout << ninetenEpassed[i];
            cout << endl;
            while (fsl.length() != 9 && fsl.length() != 10) {
                cout << "\n\nPlease make sure " << name2 << " that the word you create is legible and 9-10 letters, it can be Tagalog or English word: ";
                cin >> fsl;
            }
            for (int space = 0; space < 50; space++)
                cout << endl;
            cout << "Ok then, proceeding to the game!";
            cout << endl << endl;
        }
        void ninetenguideT(string ninetenTpassed[]) {
            cout << "\n9 to 10 letters tagalog words:\n\n    ";
            for (int i = 0; i<9; i++) 
                cout << ninetenTpassed[i];
            cout << endl;
            while (fsl.length() != 9 && fsl.length() != 10) {
                cout << "\n\nPlease make sure " << name2 << " that the word you create is legible and 9-10 letters, it can be Tagalog or English word: ";
                cin >> fsl;
            }
            for (int space = 0; space < 50; space++)
                cout << endl;
            cout << "Ok then, proceeding to the game!";
            cout << endl << endl;
        }
};

void HangmanDraw() {
    cout << "            H A N G M A N\n";
    cout << "|-----------------------------------|\n";
    cout << "|                |                  |\n";
    cout << "|               ◯                   |\n"; 
    cout << "|                |                  |\n";
    cout << "|             /  |  ""\\""               |\n";
    cout << "|            /   |   ""\\""              |\n";
    cout << "|               / ""\\""                 |\n";
    cout << "|              /   ""\\""                |\n";
    cout << "|                                   |\n";
    cout << "|-----------------------------------|\n";
}

void Hangmanintro() {
    cout << "|-----------------------------------|\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n"; 
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|-----------------------------------|\n";
}

void HangmanDraw3() {
    cout << "|-----------------------------------|\n";
    cout << "|                |                  |\n";
    cout << "|               ◯                   |\n"; 
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|-----------------------------------|\n";
}

void HangmanDraw2() {
    cout << "|-----------------------------------|\n";
    cout << "|                |                  |\n";
    cout << "|               ◯                   |\n"; 
    cout << "|                |                  |\n";
    cout << "|             /  |  ""\\""               |\n";
    cout << "|            /   |   ""\\""              |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|-----------------------------------|\n";
}

void HangmanDrawLOSER() {
    cout << "|-----------------------------------|\n";
    cout << "|                |                  |\n";
    cout << "|               ◯                   |\n"; 
    cout << "|                |                  |\n";
    cout << "|             /  |  ""\\""               |\n";
    cout << "|            /   |   ""\\""              |\n";
    cout << "|               / ""\\""                 |\n";
    cout << "|              /   ""\\""                |\n";
    cout << "|                                   |\n";
    cout << "|-----------------------------------|\n";
    cout << "|         L   O   S   E   R         |\n";
    cout << "|-----------------------------------|\n";
}

void Play() {
    cin.clear();
    cout << "\nHow many letters would you " << name2 << ", like to create?\n\n";
    while (choice2 != 'a' && choice2 != 'b' && choice2 != 'c') {
        cout << "a. 5-6 Letters\nb. 7-8 Letters\nc. 9-10 Letters\n";
        cin >> choice2;
    switch (choice2) {
        case 'a':
            Instructions1();
            Hangman();
            break;

        case 'b':
            Instructions2();
            Hangman();
            break;
        case 'c':
            Instructions3();
            Hangman();
            break;

        default:
            cout <<"\nInvalid choice, please put only small letters a to c.\n";
    }
    }
    
}

void Instructions1()
{
    Guide obj1;
    cout <<"\nPlease do not look at the screen " << name1 << ", until " << name2 <<" create his/her word for you ;)\n\n\n";
    while (yesno != "YES" && yesno != "yes" && yesno != "NO" && yesno != "no") {
        cout << name2 << ", create a word with five letters to six, do you need help? yes or no: ";
        cin >> yesno;
    }
    
    if (yesno == "NO" || yesno == "no") {
        while (fsl.length() != 5 && fsl.length() != 6) {
            cout << "Please make sure " << name2 << " that the word you create is legible and 5-6 letters, it can be Tagalog or English word: ";
            cin >> fsl;
    } 
        for (int space = 0; space < 50; space++)
            cout << endl;
            cout << "\n\nOk then, proceeding to the game!\n\n";
    } else if (yesno == "YES" || yesno == "yes") {
        while (language != "English" && language != "english" && language != "Tagalog" && language != "tagalog") {
            cout <<"Trouble in English word or Tagalog? ";
            cin >> language;
                if (language == "English" || language == "english") {
                    obj1.fivesixguideE(englishwordsguide56);
                } else if (language == "Tagalog" || language == "tagalog") {
                    obj1.fivesixguideT(tagalogwordsguide56);
                } 
        }
    } 
}

void Instructions2()
{
    Guide obj2;
    cout <<"\nPlease do not look at the screen " << name1 << ", until " << name2 <<" create his/her word for you ;)\n\n\n";
    while (yesno != "YES" && yesno != "yes" && yesno != "NO" && yesno != "no") {
        cout << name2 << ", create a word with seven letters to eight, do you need help? yes or no: ";
        cin >> yesno;
    }
    
    if (yesno == "NO" || yesno == "no") {
        while (fsl.length() != 7 && fsl.length() != 8) {
            cout << "Please make sure " << name2 << " that the word you create is legible and 7-8 letters, it can be Tagalog or English word: ";
            cin >> fsl;
    } 
        for (int space = 0; space < 50; space++)
            cout << endl;
            cout << "\n\nOk then, proceeding to the game!\n\n";
    } else if (yesno == "YES" || yesno == "yes") {
        while (language != "English" && language != "english" && language != "Tagalog" && language != "tagalog") {
            cout <<"Trouble in English word or Tagalog? ";
            cin >> language;
                if (language == "English" || language == "english") {
                    obj2.seveneightguideE(englishwordsguide78);
                } else if (language == "Tagalog" || language == "tagalog") {
                    obj2.seveneightguideT(tagalogwordsguide78);
                } 
        }
    } 
}

void Instructions3()
{
    Guide obj3;
    cout <<"\nPlease do not look at the screen " << name1 << ", until " << name2 <<" create his/her word for you ;)\n\n\n";
    while (yesno != "YES" && yesno != "yes" && yesno != "NO" && yesno != "no") {
        cout << name2 << ", create a word with nine letters to ten, do you need help? yes or no: ";
        cin >> yesno;
    }
    
    if (yesno == "NO" || yesno == "no") {
        while (fsl.length() != 9 && fsl.length() != 10) {
            cout << "Please make sure " << name2 << " that the word you create is legible and 9-10 letters, it can be Tagalog or English word: ";
            cin >> fsl;
    } 
        for (int space = 0; space < 50; space++)
            cout << endl;
            cout << "\n\nOk then, proceeding to the game!\n\n";
    } else if (yesno == "YES" || yesno == "yes") {
        while (language != "English" && language != "english" && language != "Tagalog" && language != "tagalog") {
            cout <<"Trouble in English word or Tagalog? ";
            cin >> language;
                if (language == "English" || language == "english") {
                    obj3.ninetenguideE(englishwordsguide910);
                } else if (language == "Tagalog" || language == "tagalog") {
                    obj3.ninetenguideT(tagalogwordsguide910);
                } 
        }
    } 
}

void Exit()
{
    return;
}

void Hangman() {
    transform(fsl.begin(), fsl.end(), fsl.begin(), ::tolower);
    HangmanDraw();
    string unknown(fsl.length(), '*');
    cout << "Goodluck! " << name1 << ", guess the word!\n";
    cout << "There are " << unknown.length() << " letters present to the mystery word\n\n";
    
    while (trials >= 0) {
        guessTF = false;
        cout << endl << unknown;
        cout << endl << unknown.length() << " letters, " << trials << " guesses left.\n";
        cout << "Guess the letter: ";
        cin >> guess;
        cout << endl << endl;
        for (int j=0; j<unknown.length(); j++) {
            if (fsl[j] == guess) {
                unknown[j] = guess;
                guessTF = true;
            }
        }
        
        if (fsl == unknown) {
            cout << "Congratulations! " << name1 << " you guessed the word from " << name2 << " !!\n";
            cout << "The word is: " << unknown;
            break;
        }
        
        if (guessTF == false) {
            trials--;
        }
        switch (trials) {
            case 3:
                Hangmanintro();
                break;
            case 2:
                HangmanDraw3();
                break;
            case 1:
                HangmanDraw2();
                break;
            case 0:
                HangmanDrawLOSER();
                trials = -1;
        }
    }
}

int main()
{
    
    cout << "Player one is the guesser and player two will be the creator.\n\n";
    cout << "Hello! What is your name player one?: ";
    cin >> name1;
    cout << "How about you player two?: ";
    cin >> name2;
    cout << "\n\n" << name1 << " and " << name2 << " Let's play some Hangman!\n\n";
    HangmanDraw();
    cout << "\n--INSTRUCTIONS: This is how the players will play.--" << endl;
    cout << name1 << " will be the GUESSER and " << name2 << " will be the CREATOR of the word!\n\n";
    while (cout << "Do you wanna swap positions? y/n: " && !(cin >> choice) || (choice != 'y') && (choice != 'n')) {
        cout << "Input characters y or on only.\n";
    }
    if (choice == 'y') {
        swap (name1,name2);
        cout << "\nOK! I swapped your positions, " << name1 << " will be the GUESSER and " << name2 << " will be the CREATOR of the word!\n\n";
    }
    
    cout << "\nThe guesser will be given only 3 trials to guess what letter correspond to the word created!\n";
    cout << "The game continues until the word/phrase (all letters are revealed) -- WINNER!\n";
    cout << "                         all parts of the hangman are displayed -- LOSER!\n";
    
    while (cout << "\n1. Play\n2. Exit\n" && !(cin >> choice1) || (choice1 != 1) && (choice1 != 2)) {
        cout << "\nPlease put only digits 1 and 2.";
        if (cin.fail()) {
            cout << " You did not put an integer type.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    switch (choice1) {
        case 1:
            Play();
            break;
        case 2:
            Exit();
            break;
        default:
            cout <<"\nInvalid choice, please put only digits 1 and 2.\n";
    }
    return 0;
}