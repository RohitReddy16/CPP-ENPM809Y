/**
 * @file exercise1.cpp
 * @author Rohit Reddy Pakhala(rpakhala@umd.edu)(rohitpreddi@gmail.com)
 * @brief program for a robot arm to pick and place the parts using the specified grippers and placing them on the desired color table.
 * @version 0.1
 * @date 2022-10-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
int main()
{ 
    /**
     * @brief initializing the variables
     * 
     */
    char choice;
    std::string input_part;
    std::string input_gripper;
    std::string input_table;
    std::string dotted="----------------------------------------\n";
    
    do 
    {
        std::cout<<dotted;
        std::cout << "EXERCISE 1\n";
        std::cout<<dotted;
        //
        char pickup_part; //delaring a char for part
        do{
            std::cout <<"Which part to pick up (c,b,p)? ";
            std::cin >> pickup_part; //taking input for part
        //iterating the loop till the input is given correctly.
        }while(pickup_part!='c' && pickup_part!='b' && pickup_part!='p' );
        {
            switch(pickup_part) //using switch case to get the string for the symbolic representation 
                    {
                        case 'c':
                            input_part="cube"; //c as cube
                            break;
                        case 'b': 
                            input_part="ball";//b as ball
                            break;
                        case 'p': 
                            input_part="peg";//p as peg
                            break;
                        default: 
                            break;
                    }  
        char gripper_toUse; //delaring a char for gripper
        do
        {
            std::cout<<dotted;
            std::cout<<"Which gripper to use (s,f)? "; 
            std::cin>> gripper_toUse; // taking input for gripper
            }
        while(gripper_toUse!='s'&& gripper_toUse!='f');
        {
             switch(gripper_toUse) //using switch case to clasify the grippers
             {
                        case 's': 
                            input_gripper="suction gripper"; //s as suction gripper
                            break;
                        case 'f': 
                            input_gripper="finger gripper"; //f as finger gripper
                            break;
                        default:
                            break;
             }
        if(gripper_toUse=='s' && pickup_part=='b' || gripper_toUse=='f' && pickup_part== 'c' || gripper_toUse=='f' && pickup_part== 'b')
        //checking the conditions for part and gripper 
        {
            char table; //delaring a char for table
                do
                {
                    std::cout<<dotted;
                    std::cout<<"Which table to use (r,g,b)? ";
                    std::cin>>table; //taking input for table
                //condition for the loop to run when r,g,b are not the inputs, it asks for the input till the desired one.
                }while(table!='r'&& table!='g'&& table!='b');
                    switch(table) //using switch to clasify the tables
                    {
                        case 'r': 
                            input_table ="red table";//r for red table
                            break;
                        case 'g': 
                            input_table="green table";//g for green table
                            break;
                        case 'b': 
                            input_table="blue table";//b for blue table
                            break;
                        default: //breaking the loop if nothing from the above char is given
                            break;
                    }  
                //checking the conditions for the specified part to be placed on specified table
                if(table=='g' && pickup_part=='b'||table=='r' && pickup_part=='c'||table=='b' && pickup_part=='p')
                {
                    std::cout<<dotted; //sucess statement prints with the desired combitions
                    std::cout<<"Success: the "<<input_part<<" was placed on the "<<input_table<<'\n';
                }
                else
                {   //Failure statement for giving one or both inputs of part and table combination are incorrect
                    std::cout<<dotted;
                    std::cout<<"Failure: Cannot place the "<<input_part<<" on the "<<input_table<<'\n';
                }
        }
        else
        {   //Failure statement for giving one or both inputs of part and gripper combination are incorrect
            std::cout<<dotted;
            std::cout<<"Failure: Cannot pick up the "<<input_part<<" with the "<<input_gripper<<'\n';
        }
        }
        }
        std::cout<<dotted;
        std::cout<<"Try again (y/n)?"; //try again statement so it runs the entire code again
        std::cin>>choice;
    }
    while(choice !='n');
}
