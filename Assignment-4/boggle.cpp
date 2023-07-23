/*
n is the square width

Time spent:       40 minutes
Technique:        DFS with Sets as dictionary
Time complexity:  O(8^(n^2)) 
Space complexity: O(n^2)
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Boggle {
public:
    Boggle(const vector<vector<char>>& board, const unordered_set<string>& dictionary)
        : board(board), dictionary(dictionary) {}

    vector<string> findWords() {
        if (board.empty() || board[0].empty() || dictionary.empty()) {
            return {};
        }

        vector<string> foundWords;
        const int rows = board.size();
        const int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                string currentWord;
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                findWordsUtil(i, j, currentWord, visited, foundWords);
            }
        }

        return foundWords;
    }

private:
    const vector<vector<char>>& board;
    const unordered_set<string>& dictionary;

    void findWordsUtil(int row, int col, string& currentWord, vector<vector<bool>>& visited, vector<string>& foundWords) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col]) {
            return;
        }

        currentWord.push_back(board[row][col]);
        visited[row][col] = true;

        if (currentWord.length() >= 3 && dictionary.find(currentWord) != dictionary.end()) {
            foundWords.push_back(currentWord);
        }

        // Explore adjacent cells (including diagonals)
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                findWordsUtil(i, j, currentWord, visited, foundWords);
            }
        }

        // Backtrack
        currentWord.pop_back();
        visited[row][col] = false;
    }
};

int main() {
    vector<vector<char>> board = {
            {'A', 'D', 'E'},
            {'R', 'C', 'P'},
            {'L', 'A', 'Y'}
    };

    unordered_set<string> dictionary = {
          "ACE", "APE", "CAPE", "CLAP", "CLAY", "GAPE", "GRAPE",
                "LACE", "LAP", "LAY", "MACE", "MAP", "MAY", "PACE", "PAY",
                "RAP", "RAY", "TAP", "TAPE", "TRACE", "TRAP", "TRAY", "YAP"
    };

    Boggle boggle(board, dictionary);
    vector<string> validWords = boggle.findWords();

    // Print the valid words found on the board
    cout << "Valid Words on the Boggle Board:" << endl;
    for (const string& word : validWords) {
        cout << word << endl;
    }

    return 0;
}
