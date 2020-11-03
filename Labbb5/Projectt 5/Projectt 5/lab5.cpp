/*
Sharon Omenda
C++ Fall 2020
Due Nov 2 2020 11:59pm
Lab 5 Number Guessing Game
Description: Design a number guessing game in which the computeer selects a random number in the range of 0-100 and user gets 20 attempts.
*/

#include <iostream>
#include <stdio.h>
#include <iomanip>


using namespace std;

// Selects which question to ask
string askmessage[10] = { "You have to try better than that!\n",
                         "What would you like?\n",
                         "What now?\n",
                         "Try another number?\n",
                         "Geuss another number?\n",
                         "Next number please\n",
                         "What do you want?\n",
                         "Try another?\n",
                         "Type in a different digit\n",
                         "No, another number please\n" };


// This is the message array to select which win message to show
string winmessage[10] = { "Yes, you won\n",
                     "A great win for a great player\n",
                     "What a beautiful win\n",
                     "You are a winner\n",
                     "You won\n",
                     "Hip hip Horray\n",
                     "You are amazing at this game\n",
                     "Wow!Accurate geuss\n",
                     "Geussing master!\n",
                     "You are a super star!\n" };

// This is the message array to select which loss message to show
string lossmessage[10] = { "Better luck next time\n",
                     "You lost\n",
                     "Try again\n",
                     "Try harder\n",
                     "Luck is not on your side\n",
                     "What a loss\n",
                     "Oh no! Geuss again\n",
                     "Sorry, use different numbers\n",
                     "Incorrect geuss\n",
                     "Wrong number\n" };


int totalwins = 0;
int totallosses = 0;
int reply = -1;
int generatednumber;
int guessednumber = -1;
int win = 0;

//Welcome text
void printwelcome()
{
    cout << "Welcome to Sharix Guess Game" << endl;
    cout << "A random number has been generated from the range or 0 - 100" << endl;
    cout << "You have a maximum of 20 attempts, Goodluck!" << endl;
}


void askQuestions()
{
    do {
        generatednumber = 0 + rand() % 101; // chooses random number between 1 and 100
        for (int i = 0; i < 20; i++) // makes sure there are maximum of 20 attempts
        {
            guessednumber = -1;
            try
            {
                cout << "Kindly guess number? " << endl; // Asks user to guess a number
                cin >> guessednumber;
                if (cin.fail()) {
                    throw 1;
                }

                if (generatednumber == guessednumber) // Informs user if guessed number is correct
                {
                    totalwins++;
                    win = 1;
                    cout << "Right Answer" << endl; 
                    break;
                }
                else   // Informs user if guessed number is incorrect
                {
                    win = 0;
                    cout << "Wrong Answer" << endl;
                    continue;
                }
            }
            catch (int ex)
            {
                cout << "Wrong entry" << endl;
                break;

            }

        }

        int messagenumber;
        switch (win) // Switch statement 

            // allows the user to play the game again and input message whether it is a win or loss
        {
        case 1:
            messagenumber = 0 + rand() % 10;
            cout << winmessage[messagenumber] << " \n" << askmessage[messagenumber] << "1. play again\n2. quit" << endl;
            cin >> reply;
            break;
        case 0:
            messagenumber = 0 + rand() % 10;
            totallosses++;
            cout << lossmessage[messagenumber] << " \n" << askmessage[messagenumber] << "1. play again\n2. quit" << endl;
            cin >> reply;
            break;
        default:
            messagenumber = 0 + rand() % 10;
            totallosses++;
            cout << lossmessage[messagenumber] << " \n" << askmessage[messagenumber] << "1. play again\n2. quit" << endl;
            cin >> reply;
        }


    } while (reply == 1); // do while loop
}

// Outputs results of game
void printStats()
{

    cout << "game stats" << endl;
    cout << "total wins: " << totalwins << endl;
    cout << "total losses: " << totallosses << endl;
}

// 
int main()
{

    printwelcome();
    askQuestions();
    printStats();

    return 0;

}