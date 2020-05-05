#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class memoryGame
{
private:
    int cards[4][4];
    char face[4][4];
    int pairs[16] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};


public:
    memoryGame()
    {
        // Initialization of array with through constructor
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cards[i][j] = 0;
                face[i][j] = '*';
            }
        }
    }

    // Function to play game
    void play()
    {
        shuffle();

        while(1)
        {
            // Game terminating after completing the game successfully
            if(win())
            {
                table();
                exit(1);
            }

            // Keep playing
            else
            {
                table();
                pick();
            }
        }

    }

    // For displaying shuffled cards (faced up and faced down)
    void table()
    {
        cout << endl;
        for(int i = 0; i < 4; i++)
        {
            cout << "   ";
            for(int j = 0; j < 4; j++)
            {
                cout << face[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function for random shuffle of cards
    void shuffle()
    {
        int x = -1;
        int y = -1;
        int z = 0;
        srand(time(0));

        // Run until all cards are shuffle
        while((cards[0][0] == 0) || (cards[0][1] == 0) || (cards[0][2] == 0) || (cards[0][3] == 0) ||
              (cards[1][0] == 0) || (cards[1][1] == 0) || (cards[1][2] == 0) || (cards[1][3] == 0) ||
              (cards[2][0] == 0) || (cards[2][1] == 0) || (cards[2][2] == 0) || (cards[2][3] == 0) ||
              (cards[3][0] == 0) || (cards[3][1] == 0) || (cards[3][2] == 0) || (cards[3][3] == 0))
        {
            // Random pick of array index
            x = (rand() % 4);
            y = (rand() % 4);

            // Checking if array index is empty or not
            if(cards[x][y] == 0)
            {
                cards[x][y] = pairs[z];
                z++;
            }
        }
    }

    // Function to let player pick cards through index position
    void pick()
    {
        bool picked1, picked2;
        int x1, x2, y1, y2;

        picked1 = picked2 = false;
        x1 = x2 = y1 = y2 = -1;

        while((picked1 == false) || (picked2 == false))
        {
            // First Pick
            if(picked1 == false)
            {
                cout << "\nEnter the row (1 to 4) and col (1 to 4) position of the pair: \n" ;
                cin >> x1 >> y1;

                // Changing input from 1-4 to 0-3 for array
                x1--;
                y1--;

                // Checking invalid position
                if( (x1 < 0 || x1 > 3) || (y1 < 0 || y1 > 3))
                {
                    cout << "\nInvalid position.\n";
                    continue;
                }

                // Checking if already face up or not
                else if (face[x1][y1] != '*')
                {
                    cout << "\nCard at this position already faced up. Select option again.\n";
                    continue;
                }
                // Turning picked card face up
                else
                {
                    face[x1][y1] = cards[x1][y1] + '0';
                    picked1 = true;
                    table();
                }
            }

            // Second Pick
            else
            {
                cout << "\nEnter the row (1 to 4) and col (1 to 4) position of the pair: \n" ;
                cin >> x2 >> y2;

                // Changing input from 1-4 to 0-3 for array
                x2--;
                y2--;

                // User input error
                if(x2 == -1 || y2 == -1)
                {
                    cout << "\nBoth number must be entered.\nPlease try again.\n";
                    continue;
                }

                // Checking invalid position
                else if( (x2 < 0 || x2 > 3) || (y2 < 0 || y2 > 3))
                {
                    cout << "\nInvalid position.\n";
                    continue;
                }

                // Checking if already face up or not
                else if (face[x2][y2] != '*')
                {
                    cout << "\nCard at this position already faced up. Select option again.\n";
                    continue;
                }
                // Turning picked card face up
                else
                {
                    face[x2][y2] = cards[x2][y2] + '0';
                    picked2 = true;
                    table();
                }
            }

        }

        // Checking either pair matched or not
        if(face[x1][y1] == face[x2][y2])
        {
            cout << "\nPair matched.\n";
        }
        else
        {
            cout << "\nPair do not match. Select again!\n";
            face[x1][y1] = face[x2][y2] = '*';
        }
    }

    // Checking either all cards are shuffled or not
    bool win()
    {
        if((face[0][0] == '*') || (face[0][1] == '*') || (face[0][2] == '*') || (face[0][3] == '*') ||
           (face[1][0] == '*') || (face[1][1] == '*') || (face[1][2] == '*') || (face[1][3] == '*') ||
           (face[2][0] == '*') || (face[2][1] == '*') || (face[2][2] == '*') || (face[2][3] == '*') ||
           (face[3][0] == '*') || (face[3][1] == '*') || (face[3][2] == '*') || (face[3][3] == '*'))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    memoryGame game;
    game.play();
    return 0;
}
