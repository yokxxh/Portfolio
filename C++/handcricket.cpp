#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <limits>

std::mt19937 mt {std::random_device{}()};
std::uniform_int_distribution coin(0,1);
std::uniform_int_distribution play(0,6);

// variables 
std::string name{};
std::string tossc{};
std::string playc{};
std::string replay{};
int choice{};
int run{0};
int bowl{};
int bat{};
int opp_run{0};
int opp_bowl{};
int opp_bat{};
bool isUser{};
bool isuserchasing{};


//functions
void art(){
    std::cout << "--------------------------------------------------------------------------\n";
    std::cout << "@                               _                                  ,,\n";
    std::cout << " \\\\   _   @'                    ( )_                       .      _  \\\\\n";
    std::cout << "  \\\\_( )_//                    / Y |                   .      /--( )_//\n";
    std::cout << "    | Y/--                    /\\   /               .        '//  \\~ \\\n";
    std::cout << "    |_/       _ / o\"         ( _\\ /            .                   - \\\n";
    std::cout << "  _ //\\      | | |    .       \\_\\\\\\        .                     //  \\\\--,\n";
    std::cout << " /_// /      | | |      .    / \\ \\\\\\ .                           \\\\\n";
    std::cout << "/ // /_______|_|_|__________/_/_\\ \\_______________________________\\\\______\n";
} // art courtesy to https://ascii.co.uk/art/cricket //

void printScoreBox(std::string& name, int run, int opp_run) {
    std::string playerLine = name + "'s total score: " + std::to_string(run);
    std::string compLine = "Computer's total score: " + std::to_string(opp_run);

    size_t width = std::max(playerLine.length(), compLine.length()) + 4;

    std::cout << "\n" << std::string(width, '*') << "\n";
    std::cout << "* " << std::left << std::setw(width - 3) << playerLine << "*\n";
    std::cout << "* " << std::left << std::setw(width - 3) << compLine << "*\n";
    std::cout << std::string(width, '*') << "\n";
}

bool toss(int choice)
{
    int temptoss = coin(mt);
    if(temptoss) std::cout << "\nToss result: Tails\n";
    else std::cout << "\nToss result: Heads\n";
    if(temptoss == choice) return true;
    else return false;
}

int getch()
{
    int temp{};
    while(true)
    {
    std::cout << "\nEnter your choice(0 to 6): ";
    std::cin >> temp;

    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nInvalid input. Please enter a number from 0 to 6.";
        continue;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(temp >= 0 && temp <=6)
    {
        return temp;
        break;
    }
    else
    {
        std::cout << "\nInvalid Input, Please enter 0 to 6. ";
    }
    }
}

bool isAlphabetic(std::string& str) { 
    for (char c : str) {
        if (!std::isalpha(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

int main(){

    do
    {
    art();
    std::cout << "\n\nWelcome to Hand Cricket!";

    while (true) {
        std::cout << "\nEnter your name, player (letters only): ";
        std::getline(std::cin, name);

        if (isAlphabetic(name)) {
            break; // Exit loop if input is valid
        } else {
            std::cout << "Invalid input. Please enter letters only (A-Z or a-z).\n";
        }
    }


    std::cout << "\nTOSS TIME\n";
    while (true)
    {
        std::cout << '\n' << name << ", Enter your choice(Head or Tail): "; // problem here auto entering in first attempt// 
        std::getline(std::cin, tossc);

        if(tossc == "Head" || tossc == "head" || tossc == "Tail" || tossc == "tail" || tossc == "Heads" || tossc == "heads" || tossc == "Tails" || tossc == "tails" || tossc == "HEAD" || tossc == "TAIL" || tossc == "HEADS" || tossc == "TAILS")
        {
            if(tossc == "Head" || tossc == "head" || tossc == "Heads" || tossc == "heads" || tossc == "HEAD" || tossc == "HEADS") choice = 0;
            else choice = 1; 
            break;
        }
        else
        {
            std::cout << "\n\nInvalid Input, Please enter 'Head' or 'Tail' :";
        }
    }

    if(toss(choice))
    {
        std::cout << "\nYou won the toss!\n";
        isUser = true;
        while (true)
        {
            std::cout << "\nYou choose to Bat or Bowl : ";
            std::getline(std::cin, playc);
    
            if(playc == "Bat" || playc == "bat" || playc == "BAT" || playc == "Bowl" || playc == "BOWL" || playc == "bowl")
            {
                if(playc == "bat" || playc == "Bat" || playc == "BAT")
                {
                    choice = 0;
                }
                else
                {
                    isuserchasing = true;
                    choice = 1;
                }
                break;
            }
            else
            {
                std::cout << "\nPlease Enter 'Bat' or 'Bowl'. ";
            }
        }

    }
    else{
        std::cout << "\nYou lost the toss!\n";
        choice = coin(mt);
        isUser = false;
        if (!choice)
        {
             std::cout << "\nComputer chose to bowl first.\n";
        }
        else
        {
            std::cout << "\nComputer chose to bat first.\n";
            isuserchasing = true;
        } 
    }
    
    
    if(choice)
    {

        std::cout << '\n' << name << ", you are bowling.\n";
        std::cout << "\nComputer is batting.\n";
        std::cout << "\nBowling starts now...";
        for (int i = 1; i; ++i)
        {
            bowl = getch();
            opp_bat = play(mt);
            std::cout << "\nYour choice: " << bowl;
            std::cout << "\nComputer's choice: " << opp_bat << '\n';
            if(bowl == opp_bat)
            {
            std::cout << "\nWell bowled, " << name << ". \nComputer is out!.";
            std::cout << "\nComputer's total score: " << opp_run;
            std::cout << "\n\nYour target is " << opp_run + 1 << '\n';
            break;
            }
            else if(opp_bat == 0)
            {
                opp_run += bowl;
            }
            else
            {
                opp_run += opp_bat;
            }
            std::cout << "\nComputer's current score: " << opp_run << '\n';
        }

        std::cout << '\n' << name << ", you are batting.\n";
        std::cout << "\nComputer is bowling.\n";
        std::cout << "\nBatting starts now...";
        for (int i = 1; i; ++i)
        {
            bat = getch();
            opp_bowl = play(mt);
            std::cout << "\nYour choice: " << bat;
            std::cout << "\nComputer choice: " << opp_bowl << '\n';
            if(opp_bowl == bat)
            {
                std::cout << "welp, you got bowled " << name << "!\n";
                std::cout << "\nYour total score: " << run << '\n';
                break;
            }
            else if(bat == 0)
            {
                run += opp_bowl;
            }
            else
            {
                run += bat;
            }
            std::cout << '\n' << name << "'s current score: " << run << '\n';
            if (run < opp_run) std::cout << opp_run + 1 - run << " runs is needed for win.\n";
            if( run > opp_run)
            {
                break;
            }
        }        
    }
    else
    {

        std::cout << '\n' << name << ", you are batting.\n";
        std::cout << "\nComputer is bowling.\n";
        std::cout << "\nBatting starts now...";
        for (int i = 1; i; ++i)
        {
            bat = getch();
            opp_bowl = play(mt);
            std::cout << "\nYour choice: " << bat;
            std::cout << "\nComputer choice: " << opp_bowl << '\n';
            if(opp_bowl == bat)
            {
                std::cout << "welp, you got bowled " << name << "!";
                std::cout << "\nYour total score: " << run;
                std::cout << "\n\nComputer's target is " << run + 1 << '\n';
                break;
            }
            else if(bat == 0)
            {
                run += opp_bowl;
            }
            else
            {
                run += bat;
            }
            std::cout << '\n' << name << "'s current score: " << run << '\n';
        }        
        
        std::cout << '\n' << name << ", you are bowling.\n";
        std::cout << "\nComputer is batting.\n";
        std::cout << "\nBowling starts now...";
        for (int i = 1; i; ++i)
        {
            bowl = getch();
            opp_bat = play(mt);
            std::cout << "\nYour choice: " << bowl;
            std::cout << "\nComputer's choice: " << opp_bat << '\n';
            if(bowl == opp_bat)
            {
                std::cout << "\nWell bowled, " << name << ". \nComputer is out!.\n";
                std::cout << "\nComputer's total score: " << opp_run<< '\n';
                break;
            }
            else if(opp_bat == 0)
            {
                opp_run += bowl;
            }
            else
            {
                opp_run += opp_bat;
            }
            std::cout << "\nComputer's current score: " << opp_run << '\n';
            if(opp_run < run) std::cout << '\n' << run + 1 - opp_run << " runs need for win.\n";
            if(opp_run > run)
            {
                break;
            }
        }
    }

    printScoreBox(name, run, opp_run);

    if(run > opp_run)
    {
        if(isuserchasing)
        {
            std::cout << name << ", you won! \n You have chased " << ((run > opp_run + 1) ? run :opp_run + 1 ) << " runs.\n";
        }
        else
        {
            std::cout << '\n' << name << ", you won by " << run - opp_run << " runs!\n";
        }
    }
    else if (run == opp_run)
    {
        std::cout << "\nIt is a draw.\n";
    }
    else
    {
        if(isuserchasing)
        {
            std::cout << "\nComputer wins by " << opp_run - run << " runs!\n";
        }
        else
        {
            std::cout <<  "\n Computer wins by chasing " << ((opp_run > run + 1) ? opp_run : run + 1) << " runs!\n";
        }
    }
    

    while(true)
    {
        std::cout << "\n \nDo you want to play again, " << name << "? (Yes or No): ";
        std::getline(std::cin, replay);

        if( replay == "yes" || replay == "no" || replay == "Yes" || replay == "No" || replay == "Yes" || replay == "NO")
        {
            if(replay == "yes" || replay == "YES" || replay == "Yes") choice = 1;
            else choice = 0;
            break;
        }
        else
        {
            std::cout << "Invalid Input, " << name << ". Please Enter only 'Yes' or 'No'. \n"; 
        }
    }
    }while(choice);

    std::cout << "\n\nThanks for playing, " << name << ", Press any key to quit";
    std::cin.get();

    return 0;
}