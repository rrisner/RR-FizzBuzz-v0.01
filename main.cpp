//FizzBuzz v0.01
//Written by Richard Risner in about 25 minutes on February 9, 2021

#include <iostream>
#include <conio.h>


int ExecuteFizz()
{
    std::cout<<"Fizz!\n";

    return 1;
}

int ExecuteBuzz()
{
    std::cout<<"Buzz!\n";

    return 1;
}

int ExecuteFizzAndBuzz()
{
    std::cout<<"FizzBuzz!\n";

    return 1;
}

int PlayFizzBuzz(int MaxNumber, int ValueAtFizz, int ValueAtBuzz)
{
    bool GameIsStillRunning = 1;
    int i = 1;
    int DefinedUpperBound = 100000;

    if (MaxNumber > DefinedUpperBound)
    {
        std::cout<<"Error when executing PlayFizzBuzz() process: number is too big!\n";
        return 5; // this is an arbitrary error code to allow the rest of the program to identify that there was a problem.
    }

    while (GameIsStillRunning) //the loop is iterated manually since a future implementation may change how the game works beyond what a simple for loop can accommodate.
    {
        if ((i % ValueAtFizz == 0) && (i % ValueAtBuzz == 0))
        {
            ExecuteFizzAndBuzz();
        }
        else if (i % ValueAtFizz == 0)
        {
            ExecuteFizz();
        }
        else if (i % ValueAtBuzz == 0)
        {
            ExecuteBuzz();
        }
        else
        {
            std::cout << i << std::endl;
        }

        if ((i == MaxNumber) || (i == DefinedUpperBound))
        {
            std::cout << "You won! Thanks for playing!\n";
            GameIsStillRunning = 0;
        }
        i++;
    } //end of game loop
    return 1;
}


int main()
{
    int FizzValue = 3;
    int BuzzValue = 5;
    int PlayUntilThisValue = 0; // this value is always set within the switch.
    char c = 0;

    std::cout<<"FizzBuzz v0.01\nWritten by Richard Risner on February 9, 2021\n";
    std::cout<<"\nPress 'n' to enter the final value for FizzBuzz. Press any other key to play until 100.\n:";

    c = getch();

    switch(c)
    {
    case 78:
    case 110:
        std::cout << "Please enter a numeric value less than 100,000.\n:";
        std::cin >> PlayUntilThisValue; //This will need more protection from the user later. Right now this will work for demonstration.
        break;
    default:
        PlayUntilThisValue = 100;
        break;
    }

    PlayFizzBuzz(PlayUntilThisValue, FizzValue, BuzzValue);

    return 0;
}
