#include <bits/stdc++.h>
using namespace std;

class Difficulty {
public:
    string name;
    int maxNum;
    int maxGuesses;
    string flavour;
    Difficulty(string n, int m, int g, string f) {
        name = n;
        maxNum = m;
        maxGuesses = g;
        flavour = f;
    }
};

struct Record { 
    string level; 
    int guesses; 
    bool won; 
};

vector<Difficulty> LEVELS = {
    {"Easy",50,9,"Guess a number between 1 and 50."},
    {"Medium",100,7,"The range grows larger. Stay focused."},
    {"Hard",200,6,"Few chances remain. Choose wisely."},
    {"Very Hard",500,5,"Only the sharpest minds succeed here."}
};
vector<Record> session;

void divider(char ch = '-', int w = 52) {
    for(int i = 0; i < w; i++){
        cout << ch;
    }
    cout << "\n";
}

void boxLine(string text, int w) {
    cout << "| " << left << setw(w) << text << " |\n";
}

void banner() {
    divider('=',52);
    boxLine("     *  Welcome to the Number Guessing Game  *", 50);
    divider('=', 52);
    boxLine("  \"I hold a number in my mind. Seek it.\"", 50);
    divider('-', 52);
    cout << "\n";
}

string hotCold(int diff, int range) {
    double pct = (double)diff / range;

    if (pct <= 0.02) return "[BLAZING HOT] You are almost there!";
    else if (pct <= 0.05) return "[VERY HOT] The answer is extremely close.";
    else if (pct <= 0.10) return "[HOT] You are getting very close.";
    else if (pct <= 0.20) return "[WARM] You are moving in the right direction.";
    else if (pct <= 0.35) return "[COOL] The number is still some distance away.";
    else if (pct <= 0.50) return "[COLD] You are far from the answer.";
    else return "[FREEZING] You are nowhere near it.";
}

string guessBar(int remaining, int total) {
    string bar = "[";

    for(int i = 0; i < total; i++) {
        if(i < remaining) bar += "#";
        else bar += "-";
    }

    bar += "]";
    return bar;
}

void showScoreboard() {
    if (session.empty()) {
        cout << "No rounds played yet.\n";
        return;
    }
    
    divider('=');
    cout << "|" << setw(14) << "Level" << " |" << setw(8)  << "Result" << " |" << setw(10) << "Guesses"  << " |\n";
    divider('-');
    
    for (auto r : session) {
        cout << "| " << left << setw(13) << r.level << "| " << setw(7)  << (r.won ? "WIN" : "LOSS") << "| " << setw(9)  << r.guesses << "|\n";
    }

    divider('=', 52);
}

void playRound(Difficulty &d) {

    int secret = rand() % d.maxNum + 1;
    int guessesLeft = d.maxGuesses;
    int totalGuesses = 0;

    bool won = false;

    vector<int> history;

    cout << "\n" << d.flavour << "\n\n";

    divider('-');
    cout << "Range      : 1 - " << d.maxNum << "\n";
    cout << "Chances    : " << d.maxGuesses << "\n";
    divider('-');

    while(guessesLeft > 0) {

        if(!history.empty()) {
            cout << "\nPrevious guesses: ";
            for(int x : history) cout << x << " ";
            cout << "\n";
        }

        cout << "\nGuesses left : " << guessBar(guessesLeft, d.maxGuesses) << " " << guessesLeft << "\n";
        cout << "Your guess   : ";

        string line;
        getline(cin, line);

        bool valid = !line.empty();

        for(char c : line) {
            if(!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if(!valid){
            cout << "Enter a valid number.\n";
            continue;
        }

        int guess = stoi(line);
        if(guess < 1 || guess > d.maxNum){
            cout << "Enter a number between 1 and " << d.maxNum << ".\n";
            continue;
        }

        history.push_back(guess);
        totalGuesses++;
        guessesLeft--;

        if(guess == secret) {
            won = true;
            cout << "\n";
            divider('=');
            cout << "CONGRATULATIONS!\n";
            cout << "You guessed the number correctly.\n";
            cout << "Secret Number : " << secret << "\n";
            cout << "Attempts Used : " << totalGuesses << "\n";
            divider('=');
            break;
        }
        cout << "\n";

        if(guess < secret) cout << "--> Go HIGHER\n";
        else cout << "--> Go LOWER\n";

        cout << "--> " << hotCold(abs(secret - guess), d.maxNum) << "\n";
    }

    if(!won) {
        cout << "\n";
        divider('=');
        cout << "GAME OVER\n";
        cout << "You have used all attempts.\n";
        cout << "Secret Number : " << secret << "\n";
        divider('=');
    }

    divider('-');

    cout << "ROUND SUMMARY\n";
    cout << "Difficulty : " << d.name << "\n";
    cout << "Result     : " << (won ? "WIN" : "LOSS") << "\n";
    cout << "Attempts   : " << totalGuesses << "\n";
    divider('-');

    session.push_back({d.name, totalGuesses, won});
}

int chooseDifficulty() {
    divider('-');
    cout << "  Select difficulty:\n\n";
    for (int i = 0; i < (int)LEVELS.size(); ++i) {
        cout << "  [" << (i+1) << "] " << left << setw(12) << LEVELS[i].name << "  Range: 1-" << LEVELS[i].maxNum << "  Guesses: " << LEVELS[i].maxGuesses << "\n";
    }
    divider('-');
    
    while(true){
        cout << "Enter choice (1-" << LEVELS.size() << "): ";

        string in;
        getline(cin, in);

        bool valid = !in.empty();

        for(char c : in){
            if(!isdigit(c)){
                valid = false;
                break;
            }
        }

        if(valid){
            int choice = stoi(in);
            if(choice >= 1 && choice <= (int)LEVELS.size()) return choice - 1;
        }

        cout << "Invalid input. Try again.\n";
    }
}

int main() {
    srand(time(0));
    banner();

    while (true) {
        cout << "\n  [P] Play   [S] Scores   [Q] Quit\n  > ";
        string cmd;
        if (!getline(cin, cmd) || cmd.empty()) continue;
        
        char ch = tolower(cmd[0]);

        if(ch == 'q'){
            cout << "\nFinal Scoreboard\n";
            showScoreboard();

            cout << "\nExiting Number Guessing Game...\n";
            break;
        }
        else if (ch == 's') {
            showScoreboard();
        }
        else if (ch == 'p') {
            int idx = chooseDifficulty();
            playRound(LEVELS[idx]);
        }
        else {
            cout << " Unknown command. Try P, S, or Q.\n";
        }
    }
    return 0;
}