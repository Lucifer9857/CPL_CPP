//Write a Program to implement Contest Scoreboard Problem//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Contestant {
    int solved = 0;
    int penalty = 0;
    map<int, int> incorrectSubmissions;
    map<int, int> firstCorrectTime;
};

bool compare(const pair<int, Contestant>& a, const pair<int, Contestant>& b) {
    if (a.second.solved != b.second.solved) {
        return a.second.solved > b.second.solved;
    }
    if (a.second.penalty != b.second.penalty) {
        return a.second.penalty < b.second.penalty;
    }
    return a.first < b.first;
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;
    cin.ignore();

    bool firstCase = true;

    while (T--) {
        if (!firstCase) {
            cout << endl;
        }
        firstCase = false;

        map<int, Contestant> scoreboard;
        string line;

        cout << "Enter the submissions for the current test case (enter an empty line to finish):\n";

        while (getline(cin, line) && !line.empty()) {
            stringstream ss(line);
            int contestant, problem, time;
            char result;
            ss >> contestant >> problem >> time >> result;

            Contestant& c = scoreboard[contestant];

            if (result == 'C') {
                if (c.firstCorrectTime.find(problem) == c.firstCorrectTime.end()) {
                    c.firstCorrectTime[problem] = time;
                    c.solved++;
                    c.penalty += time + 20 * c.incorrectSubmissions[problem];
                }
            } else if (result == 'I') {
                if (c.firstCorrectTime.find(problem) == c.firstCorrectTime.end()) {
                    c.incorrectSubmissions[problem]++;
                }
            }
        }

        vector<pair<int, Contestant>> sortedContestants(scoreboard.begin(), scoreboard.end());
        sort(sortedContestants.begin(), sortedContestants.end(), compare);

        cout << "\nContestant Rankings:\n";
        for (const auto& entry : sortedContestants) {
            cout << "Contestant " << entry.first << ": "
                 << entry.second.solved << " problems solved, "
                 << entry.second.penalty << " minutes penalty\n";
        }
    }

    return 0;
}
