#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;


void setWesternEuropeanCodePage() {
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
}

int main() {
    setWesternEuropeanCodePage();

    string filnamn;
    cout << "Ange filnamn: ";
    cin >> filnamn;

    ifstream fil(filnamn);

    if (!fil){
        cout << "kunde inte öppna filen";
        return 1;
    }

    string rad;
    vector<string> paragrafer;
    string paragraf;

    while (getline(fil, rad)) {
        if (rad.empty()) {
            
            paragrafer.push_back(paragraf);
            paragraf.clear();

        }
        else {
            paragraf += rad + " ";
        }

    }
    if (!paragraf.empty()) {
        paragrafer.push_back(paragraf);
    }

    cout << "Stycken\t Antal ord\n";
    cout << "-------------------\n";

    for (int i = 0; i < paragrafer.size(); i++) {

        string parag = paragrafer[i];

        int ord = 0;
        for (int j = 0; j < parag.length(); j++) {
            
            if (parag[j] == ' ') {
                ord++;
            }
        }

        cout << i + 1 << "\t" << ord << endl;

    }

}