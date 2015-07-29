/* 
 * File:   main.cpp
 * Author: Valeria Alatorre
 * GAME ARCADE 
 * Created on July 27, 2015, 1:09 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Global Constants
//Function Prototypes

void display_board();
void player_turn();
bool gameover();

char turn;
bool draw = false;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};


int hard(int&sum) {
    int sum1 = sum - 10;
    return sum1;

}

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();

//Execution begins here
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1: problem1();break;
        case 2: problem2();break;
            default:;
        };
    }while(inN<7);
    return 0;
}

//Menu Function
void Menu(){
    cout<<"--------GAME ARCADE--------"<<endl;
    cout<<"Type 1 to play BLACKJACK"<<endl;
    cout<<"Type 2 to play TIC TAC TOE"<<endl;
    cout<<"Type 7 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
    int inN;
    cin>>inN;
    return inN;
}

//Solution to problem 1
void problem1(){
    cout<<"BLACKJACK: "<<endl<<endl;
    //Declare variables
    srand(time(NULL));
    int choice;
    int chips;
    string name;
    chips = 100;
    int bet;
    int sum1;
    int sum2;
    int randomcard;
    int sum;

//Do loop to begin game
    do {



        cout << "PRESS 1 TO START" << endl;

        cout << endl;

        cin >> choice;


        if (choice == 3) {
            cout << "Thanks for playing.";
        } else if (choice < 1 || choice > 2) {
            cout << "Please enter a correct choice! ";
            cin >> choice;

        }

//switch loop to choose between blackjack or leave the table
        switch (choice) {
            case 1:
                cout << "Welcome to Blackjack, " << name << "!" << endl;
                cout << "Are you ready to play?" << endl;
                cout << "y or n : ";
                string response;
                cin >> response;
                if (response == "y") {
                    int gobackchoice;
                    do {
                        cout << "How many chips would you like to bet? " << endl;
                        cin>>bet;

                        while (chips < bet) {
                            cout << "Sorry " << name << ", but you cannot bet more "
                                    "than you have!" << endl;
                            cout << "Enter your bet: ";
                            cin >> bet;
                        }

                        randomcard = rand() % 11 + 1;
                        int randomcard1 = rand() % 11 + 1;




                        int softorhard;
                        int newsum;
                        int dealersum;
                        int newdealersum;

                        sum = randomcard1 + randomcard;
                        int randomcard3 = rand() % 11 + 1;
                        int randomcard4 = rand() % 11 + 1;
                        dealersum = randomcard3 + randomcard4;




                        cout << "Your first card was : " << randomcard << endl;
                        cout << "Your second card was : " << randomcard1 << endl;
                        cout << "You have: " << sum << endl;
                        cout << "______________________" << endl;
                        cout << "Dealers' first card was : " << randomcard3 << endl;
                        cout << "Dealers' second card was : " << randomcard4 << endl;
                        cout << "Dealer has: " << dealersum << endl;

                        if (sum == 21) {
                            cout << "Blackjack!" << endl;
                            cout << "You won!" << endl;
                            chips = chips + bet;
                            cout << "You have " << chips << "chips" << endl;
                            cout << "Please enter 1 to play again" << endl;
                            cout << "Please enter 2 to go back to the menu"
                                    << endl;
                            cin >> gobackchoice;
                        } else if (dealersum == 21) {
                            cout << "Dealer Blackjack!" << endl;
                            cout << "You lost!" << endl;
                            chips = chips - bet;
                            cout << "You have " << chips << "chips" << endl;
                            cout << "Please enter 1 to play again" << endl;
                            cout << "Please enter 2 to go back to the menu"
                                    << endl;
                            cin >> gobackchoice;
                        }
                        else if (dealersum == 21 && sum == 21) {
                            cout << "A Tie!" << endl;
                            cout << "You have " << chips << "chips" << endl;
                            cout << "Please enter 1 to play again" << endl;
                            cout << "Please enter 2 to go back to the menu"
                                    << endl;
                            cin >> gobackchoice;


                        }
                        else if (randomcard == 11 || randomcard1 == 11) {
                            cout << "You got an ace, do you want it soft or hard?"
                                    << endl << "[1 for hard/2 for soft] ";
                            cin >> softorhard;

                            if (softorhard == 1) {
                                sum = sum - 10;
                                cout << "You now have: " << sum << endl;
                            } else {
                                cout << "You have: " << sum << endl;
                            }
                        }
                        int hitschoice;
                        do {

                            int newcard = rand() % 11 + 1;


                            //                            if (sum>21){
                            //                                cout<<"You Busted!"<< endl;
                            //                            cout << "Please enter 2 and then 1 to play again" << endl;
                            //                            cout << "Please enter 2 to go back to the menu"
                            //                                    << endl;
                            //                            cin >> hitschoice;
                            //                            cin >> gobackchoice;
                            //                           
                            //                            }

                            //                           
                            cout << "Please enter 1 to hit" << endl;
                            cout << "Please enter 2 to stay"
                                    << endl;
                            cout << "If you bust over 21 press 2" << endl;
                            cin >> hitschoice;
                            sum = sum + newcard;
                            if (hitschoice == 1) {

                                cout << "You now have: " << sum << endl;
                            }
                        } while (hitschoice == 1);

                        cout << "Dealer has: " << dealersum << endl;


                        if (randomcard3 == 11 || randomcard4 == 11 && dealersum == 17) {
                            cout << "Dealer has soft 17,and must hit!" << endl;

                            int dealerhit = rand() % 11 + 1;
                            dealersum += dealerhit;
                            cout << "Dealer  now has: " << dealersum << endl;
                        }
                        while (dealersum < 17) {
                            int dealerhit = rand() % 11 + 1;
                            dealersum = dealerhit + dealersum;
                        }
                        cout << "Dealer has: " << dealersum << endl;

                        if (dealersum == 21 || dealersum > sum || sum > 21) {
                            chips = chips - bet;
                            cout << "YOU LOST :(" << endl;
                            cout << "You have " << chips << " chips" << endl;
                            cout << "Please enter 1 to play again" << endl;
                            cout << "Please enter 2 to go back to the menu"
                                    << endl;
                            cin >> gobackchoice;
                        }
                        else if (sum == 21 || sum > dealersum || dealersum > 21) {
                            chips = chips + bet;
                            cout << "YOU WON!!!" << endl;
                            cout << "You have " << chips << " chips" << endl;
                            cout << "Please enter 1 to play again" << endl;
                            cout << "Please enter 2 to go back to the menu"
                                    << endl;
                            cin >> gobackchoice;
                        }

                        else if (dealersum == sum) {
                            chips = chips;
                            cout << "A Push/Tie" << endl;
                            cout << "You have " << chips << " chips" << endl;
                            cout << "Please enter 1 to play again" << endl;
                            cout << "Please enter 2 to go back to the menu"
                                    << endl;
                            cin >> gobackchoice;
                        }



                    } while (gobackchoice == 1);
                }
        }



    } while (choice != 3);
}

//Solution to problem 2
void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    //Declare variables
    
    cout << "Tic Tac Toe Game\n";
    cout << "Player 1 [X] --- Player 2 [O]\n";
    turn = 'X';
    
    while (!gameover())
    {
        display_board();
        player_turn();
        gameover();
    }
    
    if (turn == 'O' && !draw)
    {
        display_board();
        cout << endl << endl << "Player 1 [X] Wins! Game Over!\n";
    }
    else if (turn == 'X' && !draw)
    {
        display_board();
        cout << endl << endl << "Player 2 [O] Wins! Game Over!\n";
    }
    else
    {
        display_board();
        cout << endl << endl << "It's a draw! Game Over!\n";
    }
}



//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}


void board()
{

	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}

void display_board()
{
    cout << "---------------------" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
}

void player_turn()
{
    int choice;
    int row = 0, column = 0;
    
    if (turn == 'X')
    {
        cout << "Player 1 turn [X]: ";
    }
    else if (turn == 'O')
    {
        cout << "Player 2 turn [O]: ";
    }
    cin >> choice;
    
    switch (choice)
    {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "You didn't enter a correct number! Try again\n";
            player_turn();
    }
    
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "The cell you chose is used! Try again\n";
        player_turn();
    }

}

bool gameover()
{
    for (int i = 0; i < 3; i++)//Check for a win
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i]) || (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            return true;
        }
    }
    
    for (int i = 0; i < 3; i++)//Check for draw
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    draw = true;
    return true;
}
