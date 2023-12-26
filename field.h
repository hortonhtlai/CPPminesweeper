#include <vector>
#include <set>

using namespace std;

class Field {
    public:
        Field(int fieldWidth, int fieldHeight, int bombRate);
        void displayField();
    
    private:
        vector<vector<char>> gameArea;
        set<pair<int, int>> bombTiles;
};