#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

bool findKeyWord(const std::string &str, const std::string &keyWord);
void readTextFromFile(const string& filename, map<string, vector<int>>& index);

int main(int argc, char** argv) {
    map<string, vector<int>> index;
    readTextFromFile("bible.txt", index);

    for (auto& it : index) {
        cout << it.first << " ";
        for(int i = 0; i < it.second.size() - 1; i++) {
            if(it.second[i] == it.second[i + 1] - 1) {
                cout << it.second[i] << "-";
            } else {
                cout << it.second[i] << ", ";
            }
        }
        cout << it.second[it.second.size() - 1];
        cout << endl;
    }
}

bool findKeyWord(const std::string &str, const std::string &keyWord)
{
    auto index = str.find(keyWord);
    if(index == std::string::npos) {
        return false;
    }

    auto not_part_of_word = [&](int index){
        if(index < 0 || index >= str.size()) {
            return true;
        }
        if(std::isspace(str[index]) || std::ispunct(str[index])) {
            return true;
        }
        return false;
    };
    return not_part_of_word(index - 1) && not_part_of_word(index + keyWord.size());
}

void readTextFromFile(const string& filename, map<string, vector<int>>& index) {
    fstream fin(filename);
    if(!fin) {
        exit(1);
    }

    string line;

    while(getline(fin, line) && !line.empty()) {
        vector<int> empty;
        std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c){
            return std::toupper(c);
        });
        index.insert({line, empty});
    }

    int counter = 1;
    while(getline(fin, line)) {
        std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c){
            return std::toupper(c);
        });

        for(auto& it : index) {
            if (findKeyWord(line, it.first)) {
                it.second.emplace_back(counter);
            }
        }
        counter++;
    }

    fin.close();
}
