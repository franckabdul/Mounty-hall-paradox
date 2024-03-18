#include <iostream>
#include<time.h>
#include<chrono>
#include<windows.h>// included to use the sleep() function which will allow us to get different results
using namespace std;
/*
Suppose you're on a game show, and you're given the choice of three doors: Behind one door is a car; behind the others, goats. 
You pick a door, say No. 1, and the host, who knows what's behind the doors, opens another door, say No. 3, which has a goat. 
He then says to you, "Do you want to pick door No. 2?" Is it to your advantage to switch your choice?
****************************************************************************************************************
This program will try to see how many times you get it correctly by indeed switching. 
*/

bool mountyHall(int selectedDoor, char choice){
    //Was getting an error as the seed for the pseudonumber wasn't changing quick enough. The following lines solve that
    // Get current time with milliseconds
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    // Seed the random number generator with milliseconds
    srand(static_cast<unsigned int>(milliseconds));
  // Seed the random number generator with current time

  //generate random number
    int correctDoor=rand()%3+1;
    int revealedDoor=0;
    bool win;
    cout<<" For debug, the correct door is "<<correctDoor<<endl;
    cout<<"There are three doors. If you select the correct one you get a free car\n Which one do you select? Type a number 1-3: ";
    cout<<selectedDoor<<endl;
    for(int i=1;i<=3;i++){
        if(i!=correctDoor && i!=selectedDoor){
            revealedDoor=i;
            break;
        }
    }
    cout<<"The door "<<revealedDoor<<" is NOT the correct one. Do you maintain your choice(no means change)(y/n) ";
    cout<<choice<<endl;
   
    if(choice=='y'||choice=='Y'){
        if(selectedDoor==correctDoor){
            win=true;
        }
        else{
            win=false;
        }
    }
    else if(choice=='n'|| choice=='N'){
        for(int i=0;i<3;i++){
            if(i!=selectedDoor && i!=revealedDoor){
                selectedDoor=i;
            }
        }
         if(selectedDoor==correctDoor){
            win=true;
        }
        else{
            win=false;
        }      
    }
     cout<<"The correct door is "<<correctDoor<<endl;
        if(win==true){
            cout<<" You won";
        }
        else{
            cout<<"You lost";
        }
        cout<<endl<<endl<<endl;
    return win;
}
int notChanging(){
    srand(time(0));
    int selectedDoor=rand()% 3+1;
    bool result= mountyHall(selectedDoor,'y');
    return result;
}
int Changing(){
    srand(time(0));
    int selectedDoor=rand()% 3+1;
   bool result= mountyHall(selectedDoor,'n');
   return result;
}


int main(){
    int numberOfIterations=10;
    int changingWins=0, changingLosses=0, notChangingWins=0, notChangingLosses=0;
    double changingWinRate=0, notChangingWinRate=0;

    for(int i=0;i<numberOfIterations;i++){
        cout<<"Iteration "<<i<<endl;
        if(notChanging()==1){
            notChangingWins++; 
        }
        else{
            notChangingLosses++;
        }
        Sleep(3);
    }
    for(int i=0;i<numberOfIterations;i++){
        cout<<"Iteration "<<i<<endl;

        if(Changing()==1){
            changingWins++;
        }
        else{
            changingLosses++;
        }
       Sleep(3);
    }    
changingWinRate = static_cast<double>(changingWins) / numberOfIterations;
notChangingWinRate = static_cast<double>(notChangingWins) / numberOfIterations;

cout << "\nBy changing you won " << changingWins << " times out of " << numberOfIterations << " a win rate of " << changingWinRate * 100 << " percent";
cout << "\nBy not changing you won " << notChangingWins << " times out of " << numberOfIterations << " a win rate of " << notChangingWinRate * 100 << " percent";

   

    return 0;
}

