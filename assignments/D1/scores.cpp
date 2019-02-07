#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/**
 * Devoir 1 CSI 2772[A] Robert Laganière
 * scores.cpp
 * Écrire un programme qui accepte comme input les résultats de matchs de sport et qui calcule quelques statistiques.
 * 
 * @author Maxime Côté-Gagné(8851539)
 * 
 */ 


int main ()
{   
    //init array
    int yourScore[100];
    int thereScore[100];
    string name[100];

    int j(0);//see how many score are enter or the numbers of game played

    string str1, str2, str3;//init the 3 string use as tmp var
    
    //bool cancel(false);
    cout << "Enter scores with this format ->   yourScores:thereScores thereName" << endl;
    while(true){

        getline (cin,str1);

        //cancel if "-" is in the line-> negative
        size_t found = str1.find ("-");
        if(found != string::npos){
            break;
        }

        //isolated yourScores
        size_t you;
        int me = stoi (str1, &you); //me -> you
        string str2 = str1.substr (you, str1.length());//created a new string named str2


        //cout << str2 << endl;
        //cout << "yourScores: " << me << endl;


        //remove the ":" char from the string
        str2.erase(remove(str2.begin(), str2.end(), ':'), str2.end());//remove ':' char from the str2( a string)
        //cout << str2 <<endl;
        

        //isolated thereScores
        size_t there;
        int them = stoi (str2 , &there); //them -> there
        string str3  = str2.substr(there, str2.length());


        //cout << str3 << endl;
        //cout << "thereScores: "<< them << endl;


        //isolated name while removing the space
        str3.erase(0,1);//remove the ' ' or space char from the string(str3).
        //cout << "name: " << str3 << endl;

        
        
        
        //TEST
        //cout << "Saved in array: ";

        yourScore[j] = me;
        //cout << yourScore[j]; //for testing only

        thereScore[j] = them;
        //cout << thereScore[j]; //for testing only

        name[j] = str3;
        //cout << name[j];//for testing only

        //cout << yourScore[j] << ":" << thereScore[j] << " " << name[j];


        j++;//counter to see how many scores are enter or the total number of gamePlayed
    }


    //STATS
    cout << "\nStats :\n";

    int i(0); 
    
    //Your total goals
    int sumYourTotal(0);
    double averageYourGoal(0);
      
    //There total goals
    int sumThereTotal(0);
    double averageThereGoal(0);

    //wins/draws/loses
    int wins(0);
    int draws(0);
    int loses(0);

    //int min = yourScore[0];
    int lossLow(0);//if not init lowest loss will not load
    int lossHigh(0);
    //int diff(0);
    //int max = yourScore[0];
    int winHigh(0);// same has minTEMP
    int winLow(0);
    int lowMin(1000);
    int lowMax(0);
    int highMax(0);
    int highMin(1000);
    int youMax;
    int youMin;

    //STATS LOOP
    for(i = 0; i<j; i++){
        //sum of yourScore
        sumYourTotal += yourScore[i]; 
        //sum of thereScore
        sumThereTotal += thereScore[i];
        //wins
        if(yourScore[i]>thereScore[i]){
            wins++;
            //diff = (yourScore[i] - thereScore[i]);
            youMax = yourScore[i];
            if(youMax > highMax){
                highMax = youMax;
                if(wins == 0){//init winLow
                    winLow = i;
                }
                winHigh = i;
            } else if(youMax < highMin) {
                highMin = youMax;
                winLow = i ;
            }   
        }
        //loses
        else if(yourScore[i]<thereScore[i]){
            loses++;
            //diff = (thereScore[i] - yourScore[i]);
            //Highest Loss
            youMin = yourScore[i];
            if(youMin > lowMax){
                lowMax = youMin;
                if(loses == 1){//init lossLow
                    lossLow = i;
                }
                lossHigh = i;
            } else if(youMin < lowMin) {
                lowMin = youMin;
                lossLow = i;
            }
        }
        //draws
        else{
            draws++;
        }
    }
    averageYourGoal = ((double)sumYourTotal / (double)j);
    averageThereGoal = ((double)sumThereTotal / (double)j);


    //show the STATS
    cout << "Wins/Draws/Loses: " << wins << ":" << draws << ":" << loses << endl;
    cout << "Goals: " << sumYourTotal << ":" << sumThereTotal << endl;
    cout << "Average number of goals scored: " << averageYourGoal << ":" << averageThereGoal << endl;
    
    //if no wins or no loses highest win or largest loss will not show up
    if(wins == 0){
        cout << "Highest win: " << "No game was win"<<endl;
    }else{
        cout << "Highest win: "<< yourScore[winHigh] << ":" << thereScore[winHigh] <<" " << name[winHigh] <<endl;
    }
    if(wins == 0){
        cout << "Lowest win: "<< "No game was win" <<endl;
    }else{
        cout << "Lowest win: "<< yourScore[winLow] << ":" << thereScore[winLow] <<" " << name[winLow] <<endl;
    }


    if(loses == 0){
        cout << "Highest loss: "<< "No game was lose" <<endl;
    }else{
        cout << "Highest loss: "<< yourScore[lossHigh] << ":" << thereScore[lossHigh] <<" " << name[lossHigh] <<endl;
    }

    if(loses == 0){
        cout << "Lowest loss: "<< "No game was lose" <<endl;
    }else{
        cout << "Lowest loss: "<< yourScore[lossLow] << ":" << thereScore[lossLow] <<" " << name[lossLow] <<endl;
    }



    
    
    


    //Show all the game with the format: "me:them name";
    cout << "\nGames:\n";
    i = 0;
    while(i != j){
        cout << yourScore[i] << ":" << thereScore[i] << " " << name[i] << "\n";
        i++;
    }
    return 0;
}
