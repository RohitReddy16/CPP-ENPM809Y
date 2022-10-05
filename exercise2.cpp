/**
 * @file exercise2.cpp
 * @author Rohit Reddy Pakhala (rpakhala@umd.edu) UID 119399125
 * @brief Program for filling the slots by different pegs using robotic arm
 * @version 0.1
 * @date 2022-10-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    /**
     * @brief char of choice to make the selection between yes and no
     * @brief string dotted is used to print the dotted lines when required
     */
    char choice;
    std::string dotted = "--------------------------------\n";
    do
    {
        /**
         * @brief pick slots: executes the loop from the start when the wrong input is given
         */
    pick_slots:
        std::cout << dotted;
        std::cout << "EXERCISE 2\n";
        std::cout << dotted;
        /**
         * @brief matrix with 3X3
         * prinitng the matrix
         */
        std::string arrslots[3][3] = {{"1", "2", "3"},
                                      {"4", "5", "6"},
                                      {"7", "8", "9"}};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << arrslots[i][j] << " ";
            }
            cout << endl;
        }
        /**
         * @brief declaring the vectors for storing the inputs given
         */
        string decision;
        string tryagain;
        bool boolean = false;
        vector<int> vect1={};
        string pick_slots;
        vector<string> vect_blue={};
        std::cout << dotted;
        /**
         * @brief red peg starts here asking the user to go ahead with red or not
         */
        do
        {
            std::cout << "Do you want to place red peg (y/n)? ";
            std::cin >> decision;
        } while (decision != "y" && decision != "n");
        //when the decision is yes and you this loop starts to fill the slot with red
        if (decision == "y")
        {
            //performing the do while loop to check the condition
            do
            {
                vect1.empty();
                string two_digits = "";
                std::cout << "Where to place red pegs (1-9)? ";
                getline(cin >> ws, pick_slots); //taking the user input for red to occupy
                two_digits = two_digits + ""; 
                pick_slots = pick_slots + " ";
                //for loop to iterate and sort the inputs with white spaces.
                for (int i = 0; i < pick_slots.size(); i++)
                {
                    if (pick_slots[i] != ' ')
                    {
                        two_digits.push_back(pick_slots[i]);
                    }
                    else
                    {
                        vect1.push_back(stoi(two_digits));
                        two_digits = "";
                    }
                }
                //checking the inputs is in the range of (0-9) or not
                for (int i = 0; i < vect1.size(); i++)
                {
                    if (vect1.at(i) > 9 || vect1.at(i) < 0) 
                    {
                        boolean = true; //when the input is greater than 9 or less than 0 then boolean is true and it continues the loop
                    }
                    else //else the boolean is false and exits the loop
                    {
                        boolean = false;
                    }
                }
            } while (boolean); //contidion for the loop to run//when boolean is true loop runs
        }
        std::cout<<dotted;
        //assigning the red pegs to the desired slots according to the input given
        for (int i = 0; i < 3; i++)
        { 
            for (int j = 0; j < 3; j++)
            {
                if (std::find(vect1.begin(), vect1.end(), stoi(arrslots[i][j])) != vect1.end()) // stoi string to int
                {
                    arrslots[i][j] = 'r';
                }
                cout << arrslots[i][j] << " ";
            }
            cout << "\n";
        }
        cout << '\n'
             << dotted;
        //getting the slots available after assigning the red pegs.
        string avslots;
        for (int i = 0; i < 3; i++)
        {
            for (int a = 0; a < 3; a++)
            { //checking the number of slots by getting the values of array in between 1-9
                if (arrslots[i][a] >= "1" && arrslots[i][a] <= "9")
                {
                    avslots += arrslots[i][a] + ", ";
                }
            }
        }
        //storing the available slots in a string
        string s = avslots.substr(0, avslots.size() - 2);
        if (s == "")
        {
            vect1.clear();
            std::cout << "Try again (y/n)? "; //if the entire slots are filled with red pegs, 
            std::cin >> choice;
            std::cout<<'\n';
            if (choice == 'y')
            {
                goto pick_slots; //goes to the starting of the loop if want to run again when the slots are filled with red pegs
            }
        }
        //logic for the green pegs starts here
        char decision_1;
        do
        {
            std::cout << "Do you want to place green peg (y/n)? ";
            std::cin >> decision_1; //taking the user input for green to occupy
        } while (decision_1 != 'y' && decision_1 != 'n');
        string pick_slots_1;
        green:
        vector<string> vect_green={};
        if (decision_1 == 'y')
        {
            do
            {
                string two_digits_1 = "";
                std::cout << "Where to place green pegs (" << s << ") ? "; //printing the available slots for the green peg
                getline(cin >> ws, pick_slots_1);
                two_digits_1 = two_digits_1 + "";
                pick_slots_1 = pick_slots_1 + " ";
                for (int i = 0; i < pick_slots_1.size(); i++)
                {
                    if (pick_slots_1[i] != ' ')
                    {
                        two_digits_1.push_back(pick_slots_1[i]); //sorting the spaces.
                    }
                    else
                    {
                        vect_green.push_back((two_digits_1));
                        two_digits_1 = ""; 
                    }
                }
                for (int i = 0; i < vect_green.size(); i++)
                {
                    if (stoi(vect_green.at(i)) > 9 || stoi(vect_green.at(i)) < 0) // stoi string to int
                    {
                        boolean = true;
                    }
                    else
                    {
                        boolean = false;
                    }
                }
            } while (boolean);
        }
        std::cout << dotted;
        //prinitng the matrix after the green pegs assigned
        // there are green and red pegs in this matrix
        for (int m = 0; m < 3; m++)
        {
            for (int n = 0; n < 3; n++)
            {
                if (std::find(vect_green.begin(), vect_green.end(), (arrslots[m][n])) != vect_green.end()) 
                {
                    arrslots[m][n] = 'g';
                }
                cout << arrslots[m][n] << " ";
            }
            cout << "\n";
        }
        cout << '\n'
             << dotted;
        // slots available after red and green pegs
        string avslots_blue;
        for (int c = 0; c < 3; c++)
        {
            for (int b = 0; b < 3; b++)
            {
                if (arrslots[c][b] >= "1" && arrslots[c][b] <= "9")
                {
                    avslots_blue += arrslots[c][b] + ", ";
                }
            }
        }
        string s_blue = avslots_blue.substr(0, avslots_blue.size() - 2);
        if (s_blue == "")
        {
            vect_green.clear();
            goto tryagain; //goes to try again label if slots are not empty
        }
        //logic for blue pegs starts here
        char decision_2;
        do
        {
            std::cout << "Do you want to place blue peg (y/n)? ";
            std::cin >> decision_2; //taking the user input for blue to occupy
        } while (decision_2 != 'y' && decision_2 != 'n');
        if (decision_2 == 'y')
        {
            string pick_slots_blue;
            do
            {
                string two_digits_2 = "";
                std::cout << "Where to place blue pegs (" << s_blue << ") ? ";
                getline(cin >> ws, pick_slots_blue);
                two_digits_2 = two_digits_2 + "";
                pick_slots_blue = pick_slots_blue + " ";
                for (int i = 0; i < pick_slots_blue.size(); i++) //sorting the inputs given
                {
                    if (pick_slots_blue[i] != ' ')
                    {
                        two_digits_2.push_back(pick_slots_blue[i]); //sorting the spaces
                    }
                    else
                    {

                        vect_blue.push_back((two_digits_2)); //adding the value to the vector.
                        two_digits_2 = "";
                    }
                }
                 std::cout << dotted;
                for (int i = 0; i < vect_blue.size(); i++)
                {
                    if ((stoi(vect_blue.at(i))) > 9 || stoi(vect_blue.at(i)) < 0)
                    {
                        boolean = true;
                    }
                    else
                    {
                        boolean = false;
                    }
                }
            } while (boolean);
        }
        //prinitng the matrix after assigning all the pegs
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (std::find(vect_blue.begin(), vect_blue.end(), (arrslots[i][j])) != vect_blue.end()) // stoi string to int
                {
                    arrslots[i][j] = 'b';
                }
                cout << arrslots[i][j] << " ";
            }
            cout << "\n";
        }
        cout << '\n';
    //tryagain label is given to iterate when every slot is filled or when all the conditions are met
    tryagain:
        do
        {
            std::cout << dotted;
            std::cout << "Try again (y/n)? ";
            std::cin >> choice;
            if (choice == 'y' || choice == 'n')
            {
                break;
            }
            cout<<'\n';
        } while (true);
    } while (choice != 'n');
}