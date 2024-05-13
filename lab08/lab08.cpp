#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype> 

using namespace std;

class Compare {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second == b.second)
            return a.first > b.first;
        else
            return a.second < b.second;
    }
};

int main() {
    ifstream file("Text.txt");
    if (!file) {
        cout << "Failed to open input file." << endl;
        return 1;
    }
    string phrase;
    getline(file, phrase);
    file.close();

    map<string, int> words;
    string word;
    for (size_t i = 0; i < phrase.size(); ++i) {
        if (isalnum(phrase[i])) {
            word += tolower(phrase[i]);
        }
        else {
            if (!word.empty())
                words[word]++;
            word.clear();
        }
    }
    if (!word.empty())
        words[word]++;

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> wordQueue;
    for (const auto& entry : words)
        wordQueue.push(entry);

    while (!wordQueue.empty()) {
        auto entry = wordQueue.top();
        cout << entry.first << " => " << entry.second << '\n';
        wordQueue.pop();
    }
    return 0;
}
