
#include <iostream>
#include <fstream>
using namespace std;
bool eq(char a[], char b[]);
void addp();
void viewp();
void searchp();
void updatep();
void deletep();
int main() {
    int c;
    do {
        cout << " PSL Management System\n";
        cout << "1. Add Player\n";
        cout << "2. View All Players\n";
        cout << "3. Search Player (by Name or Team)\n";
        cout << "4. Update Player Stats\n";
        cout << "5. Delete Player Record\n";
        cout << "0. Exit\n";
        cout << "enter your choice: ";
        cin >> c;
        switch (c) {
        case 1: addp(); break;
        case 2: viewp(); break;
        case 3: searchp(); break;
        case 4: updatep(); break;
        case 5: deletep(); break;
        case 0: cout << "Exit complete.\n"; break;
        default: cout << "choice not found;;;\n";
        }

    } while (c!= 0);

    return 0;
}
bool eq(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return false;
        i++;
    }
    return a[i]== '\0'&& b[i]== '\0';
}
void addp() {
    ofstream file("players.txt", ios::app);
    char name[50], team[30], role[20];
    int runs, wickets;

    cin.ignore();
    cout << "enter Player Name: ";
    cin.getline(name, 50);
    cout << "enter Team Name: ";
    cin.getline(team, 30);
    cout << "Enter Role (Batsman/Bowler/All-rounder): ";
    cin.getline(role, 20);
    cout << "enter Total Runs: ";
    cin >> runs;
    cout << "enter Total Wickets: ";
    cin >> wickets;

    file << name << "," << team << "," << role << "," << runs << "," << wickets << "\n";
    file.close();

    cout << "Player record added successfully!\n";
}
void viewp() {
    ifstream file("players.txt");
    char ch;

    cout << "\nName\tTeam\tRole\tRuns\tWickets\n";
    while (file.get(ch)) {
        if (ch == ',')
            cout << '\t';
        else if (ch == '\n')
            cout << endl;
        else
            cout << ch;
    }
    file.close();
}
void searchp() {
    ifstream file("players.txt");
    char name[50], team[30], role[20], search[50];
    int runs, wickets;
    bool found = false;

    cout << "enter player name or Team to search: ";
    cin.ignore();
    cin.getline(search, 50);

    while (file.getline(name, 50, ',') &&
        file.getline(team, 30, ',') &&
        file.getline(role, 20, ',') &&
        file >> runs &&
        file.get() && file >> wickets) {
        file.ignore();

        if (eq(name, search) || eq(team, search)) {
            cout << "\nPlayer Found:\n";
            cout << "Name: " << name << endl;
            cout << "Team: " << team << endl;
            cout << "Role: " << role << endl;
            cout << "Runs: " << runs << endl;
            cout << "Wickets: " << wickets << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No match player ,;;.\n";
    file.close();
}

void updatep() {
    ifstream f1("players.txt");
    ofstream f2("temp.txt");
    char name[50], team[30], role[20], updateName[50];
    int runs, wickets, newRuns, newWickets;
    bool updated = false;

    cout << "Enter Player Name to update: ";
    cin.ignore();
    cin.getline(updateName, 50);
    cout << "Enter new Total Runs: ";
    cin >> newRuns;
    cout << "Enter new Total Wickets: ";
    cin >> newWickets;
    while (f1.getline(name, 50, ',') &&
        f1.getline(team, 30, ',') &&
        f1.getline(role, 20, ',') &&
        f1 >> runs &&
        f1.get() && f1 >> wickets) {
        f1.ignore();
        if (eq(name, updateName)) {
            runs = newRuns;
            wickets = newWickets;
            updated = true;
        }
        f2 << name << "," << team << "," << role << "," << runs << "," << wickets << "\n";
    }
    f1.close();
    f2.close();

    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (updated)
        cout << "Player stats updated successfully!\n";
    else
        cout << "Player not found.\n";
}
void deletep() {
    ifstream f1("players.txt");
    ofstream f2("temp.txt");
    char name[50], team[30], role[20], deleteName[50];
    int runs, wickets;
    bool deleted = false;
    cout << "Enter Player Name to delete: ";
    cin.ignore();
    cin.getline(deleteName, 50);
    while (f1.getline(name, 50, ',') &&
        f1.getline(team, 30, ',') &&
        f1.getline(role, 20, ',') &&
        f1 >> runs &&
        f1.get() && f1 >> wickets) {
        f1.ignore();
        if (!eq(name, deleteName)) {
            f2 << name << "," << team << "," << role << "," << runs << "," << wickets << "\n";
        }
        else {
            deleted = true;
        }
    }
    f1.close();
    f2.close();
    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (deleted)
        cout << "Player deleted rightly!\n";
    else
        cout << "Player not found;;;.\n";
}

