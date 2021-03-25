//
//  main.cpp
//  Random Num Possibilities Template
//
//  Created by Avishai Rostamian on 3/23/21.
//  Copyright © 2021 Avishai Rostamian. All rights reserved.
//

#include <iostream>
using namespace std;

int x = 0, y = 0, total = 0,n;
int* ranarray = new int[x];
int pair1,pair2;

int sizeofarr;



template <typename T>

int fillarray(T x){                     //Fill array with random integers
    for (int i = 0; i < x;i++){                 //For loop to iterate through array
        *(ranarray + i) = rand() % 10 + 1;        //Fills in array with random numbers 1-10
    }
    return *ranarray;
}

template <typename T>
void printpair(T x, T y){                   //Prints the pair to console
    cout << "(" << x << "," << y << ")";
    total++;
}

template <typename T>
int pairs(T* x, T y){
    
    for (int i = 0; i < sizeofarr; i++){        //iterates through the array via the size of the pointer array / size of an integer
        for (int w = 0; w < i; w++){                        //set second loop to iterate through every pair
            if (*(ranarray + i) + *(ranarray + w) == y){     //checks if i position in array plus w position adds up to the desired number (checks for pair)
                pair1 =*(ranarray +i);                      //stores the paired number
                pair2 =*(ranarray + w);
                printpair(pair2, pair1);        //Runs through print function to print confirmed pair to console
                
            }
        }
    }
    return y;
}
    

int main() {
    srand (time(NULL));     //Ensure random numbers everytime program is run

    while(x <= 0){
    cout << "Enter size of array: ";            //Prompt user to input size of array and integer in a loop until a valid number is inputted
    cin >> x;
    }
    
    while(y <= 0){
    cout << "Enter an integer: ";
    cin >> y;
    }
    
    sizeofarr = x;
    fillarray<int>(x);              //Call function to fill in array of size n with random numbers
    
    for (int i = 0; i < x; i++){
        cout << *(ranarray +i) << " ";          //Print out array
    }
    
        cout << "\n~~~~~~\n";
    
    pairs(ranarray, y);             //Call function to find all pairs adding up to users integer
    
    cout << "\nNumber of pairs found: " << total << endl;
    

    cout << endl;
    delete[] ranarray;          //Delete array preventing memory leak

    return 0;
}


