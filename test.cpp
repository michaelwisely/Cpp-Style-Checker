//Programmer: Josh Wilkerson       Date: 2011/09/18
//File: workDecider.cpp            Class: CS53
//Purpose: This program helps groundskeeper Willie select
//         the appropriate amount of work to do, given a
//         level of motivation

#include<iostream>
using namespace std;

const float LEV_A_RAIN_THRESH = 0.5;
const int LEV_A_LOW_GAS = 5;
const int LEV_A_HIGH_GAS = 10;
const float LEV_C_RAIN_THRESH = 1.5;
const float LEV_D_RAIN_THRESH = 0.0;

int main()
{
  char motivLev = 0, chalmersPresent = 0;
  string userName = "";
  float rainLev = 0;
  int gasLev = 0, numChildren = 0, numAdults = 0;

  //welcome and prompt the user for their name
  cout << "\nWelcome to the Work-Avoider 2000\n"
       << "--------------------------------\n"
       << "Please enter your name: ";
  cin >> userName;

  //put the riff-raff in their place
  //(NOTE: this is not part of the assignment, per se; but is obviously
  //a necesary addition)
  if(userName == "ClaytonPrice" || userName == "TommySzalapski")
  {
    cout << "\nOh come on, we both know you aren't going to do work regardless "
         << "of what I say.\n"
         << "Fine, we'll go through the motions anyway" << endl;
  }

  //prompt for the motivation level
  cout << "\nHow motivated are you today, " << userName << "?\n"
       << "  a) Amazingly motivated\n"
       << "  b) Basically a good worker\n"
       << "  c) Can't get good help no more\n"
       << "  d) Don't plan on work from me\n"
       << "  e) Elevated slothfullness\n\n"
       << "Enter the letter corresponding to your motivation level: ";
  cin >> motivLev;

  //determine what response to give, allowing the user to use upper or lower
  //case for their motivation level

  /////////////
  //motivation level A
  /////////////
  if(motivLev == 'a' || motivLev == 'A')
  {
    cout << "\nWell are't we a hard worker, very impressive.\n"
         << "Tell me, " << userName << ", how many inches did it rain last "
         << "night?\n";
    cin >> rainLev;
    cout << "Ok, and how many gallons of gas do you have on hand (to the "
         << "nearest gallon, please)?\n";
    cin >> gasLev;

    //if it rained more than the rain threshold for this level
    cout << endl << userName << ", you should ";
    if(rainLev >= LEV_A_RAIN_THRESH)
    {
      cout << (gasLev <= LEV_A_LOW_GAS ?
                 "burn some of those ridiculous text books from the 1940's"
               :
                 "go purify that bathroom with righteous flames of cleansing") << endl;
    }
    //if it rained less than the rain threshold for this level
    else
    {
      //if we don't have much gas
      if(gasLev < LEV_A_LOW_GAS)
        cout << "go get more gas, then ask me what to do again" << endl;
      //we have a moderate amount of gas
      else if(gasLev >= LEV_A_LOW_GAS && gasLev < LEV_A_HIGH_GAS)
        cout << "rev up the mower and take care of that overgrown yard" << endl;
      //we have a lot of gas
      else
      {
        cout << "fill up the biggest tractor you have and do some laps where\n"
             << "everyone can admire your impressive work ethic" << endl;
      }
    }
  }

  /////////////
  //motivation level B
  /////////////
  else if(motivLev == 'b' || motivLev == 'B')
  {
    cout << "\nOk, pretty mortivated then.\n"
         << "In that case, is Superintendent Chalmers where he can see you?\n"
         << "(y or n, please): ";
    cin >> chalmersPresent;

    //if chalmers is present then we clean the floor on hands and knees
    if(chalmersPresent == 'y' || chalmersPresent == 'Y')
    {
      cout << endl << userName << ", you should get on your hands and knees and"
           << " scrub that floor, an impressed boss is\n"
           << "a happy boss!" << endl;
    }
    //otherwise we see how many adults and children are present
    else
    {
      cout << "Ok, the boss isn't watching. How many adults are around, then?\n";
      cin >> numAdults;
      cout << "And how many children are around?\n";
      cin >> numChildren;

      //if there are more adults than children, clean on hands and knees, mop
      //otherwise
      cout << endl << userName << ", you should ";
      cout << (numAdults >= numChildren ?
                 "get some word of mouth spreading, scrub the floor on hands and knees"
               :
                 "just mop the floor")
           << endl;
    }
  }

  /////////////
  //motivation level C
  /////////////
  else if(motivLev == 'c' || motivLev == 'C')
  {
    cout << "\nOk, so you just want to look busy; fair enough.\n"
         << "How many inches did it rain last night?\n";
    cin >> rainLev;

    cout << endl << userName << ", you should ";
    //if it rained less than this level's rain threshold lean on a rake,
    //otherwise lean on a broom inside
    cout << (rainLev <= LEV_C_RAIN_THRESH ?
               "go get your rake and lean on it"
             :
               "go inside and lean on your broom")
         << ", looking as annoyed as possible\n"
         << "(makes you look busier)" << endl;
  }

  /////////////
  //motivation level D
  /////////////
  else if(motivLev == 'd' || motivLev == 'D')
  {
    cout << "\nOk, motivated enough to go to work, but not motivated enough to"
         << " deal with anyone.\n"
         << "How many inches did it rain last night?\n";
    cin >> rainLev;

    cout << endl << userName << ", you should go hide in ";
    //if it rained less than this level's rain threshold hide in a hedge,
    //otherwise hide in the toolshed
    cout << (rainLev <= LEV_D_RAIN_THRESH ?
               "a hedge"
             :
               "the toolshed")
         << endl;
  }

  /////////////
  //motivation level E
  /////////////
  else if(motivLev == 'e' || motivLev == 'E')
  {
    //NOTE: this output uses escape sequences (the \"'s), if you haven't learned about
    //these by the time you read this, you will soon
    cout << "\n\"I don't always stay in bed and skip work, but when I do it's because\n"
         << "a computer program told me to\"\n"
         << "  --The most unmotivated man in the world\n\n"
         << "Enjoy your \"sick day\", " << userName << endl;
  }

  /////////////
  //unknown motivation level
  /////////////
  else
  {
    cout << "ERROR 87328047:\n"
         << "UNRECOGNIZED MOTIVATION LEVEL\n"
         << "TERMINATING" << endl;
  }

  cout << "\n--------------------------------\n"
       << "Thank you for using the Work-Avoider 2000\n" << endl;

  return 0;
}
