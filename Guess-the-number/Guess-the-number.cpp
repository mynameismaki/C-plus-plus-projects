#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void lottery5();
void lottery9();
void lottery15();

void menu() {
    int v = 0;
    cout << endl << "Please input the number you want only from 1-3." << endl;
    cout << "1. Generate 5 numbers to be guessed" << endl;
    cout << "2. Generate 9 numbers to be guessed" << endl;
    cout << "3. Generate 15 numbers to be guessed" << endl;
    cin >> v;
    cout << "" << endl;
    switch (v) {
        case 1:
        lottery5();
        break;
        case 2:
        lottery9();
        break;
        case 3:
        lottery15();
        break;
        default:
        menu();
        break;
    }
}

void win() {
    int width = 40;
    int leftp = (width - 25) / 2;
    int rightp = width - leftp - 25;
    cout << endl << setw(leftp) << "Congratulations you won!!" << setw(rightp) << endl;
}

void lost() {
    int width = 40;
    int leftp = (width - 25) / 2;
    int rightp = width - leftp - 25;
    cout << endl << setw(leftp) << "Sorry, you lost. Please try again." << setw(rightp) << endl;
}

void lottery5() {
    int n, m, guess;

    srand (time(NULL));
    n = rand()%5 + 1;
    cout << "You only have 1 trial, Good Luck!" << endl;
    
    for (int i=0; i<1; i++) {
    cout << "Guess the number (1 to 5): ";
    cin >> guess;
        if (n<guess) {
            cout << "The number is lower" << endl << endl;
    }   else if (n>guess) {
            cout << "The secret number is higher" << endl << endl;
    }   else if (n==guess) {
            win();
            break;
    }
    }
    if (n!=guess)
        lost();
    menu();
}

void lottery9() {
    int count = 0;
    int n, m, guess;

    srand (time(NULL));
    n = rand()%9 + 1;
    cout << "You only have 2 trials, Good Luck!" << endl;
    
    for (int i=0; i<2; i++) {
    cout << "Guess the number (1 to 9): ";
    cin >> guess;
        if (n<guess) {
            cout << "The number is lower" << endl << endl;
    }   else if (n>guess) {
            cout << "The secret number is higher" << endl << endl;
    }   else if (n==guess) {
            win();
            break;
    }
    }
    if (n!=guess)
        lost();
    menu();
}

void lottery15() {
    int count = 0;
    int n, m, guess;

    srand (time(NULL));
    n = rand()%15 + 1;
    cout << "You only have 3 trials, Good Luck!" << endl;
    
    for (int i=0; i<3; i++) {
    cout << "Guess the number (1 to 15): ";
    cin >> guess;
        if (n<guess) {
            cout << "The number is lower" << endl << endl;
    }   else if (n>guess) {
            cout << "The secret number is higher" << endl << endl;
    }   else if (n==guess) {
            win();
            break;
    }
    }
    if (n!=guess)
        lost();
    menu();
}

void login(string& c, string& d) {
    string username, password;
    while (username != c || password != d) {
    cout << endl << "***LOGIN***" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
        if (username == c && password == d) {
            cout << endl << "Welcome! " << username << endl << endl;
            break;
        }
    cout << "Incorrect username and password, please try again." << endl;
    }
}

void registration(string& c, string& d) {
    cout << "***REGISTRATION***" << endl;
    cout << "Enter your username: ";
    cin >> c;
    cout << "Enter your password: ";
    cin >> d;
}

int main()
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
    cout << "           **********GUESSING GAME**********" << endl;
    cout << "           presented by Mckinley L. Petalver" << endl;
    cout << "                                               " << asctime(localtm) << endl << endl;
    
    int q, v;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cin >> q;
    string username0, registername0, password0, registerpassword0, registername, registerpassword;
        switch (q) {
            case 1:
            cout << "Username: ";
            cin >> username0;
            cout << "Password: ";
            cin >> password0;
                if (username0 != registername0 && password0 != registerpassword0) {
                cout << "Incorrect username and password. If you are a new user, please register." << endl << endl;
            }
            case 2:
            registration(registername, registerpassword);
            login(registername, registerpassword);
            break;
            default:
            registration(registername, registerpassword);
            }
    menu();
    return 0;
}