// simple betting game.
// Jack queen king are three choices where computer shuffles and asks player to predict the position.
// now player has to predict the position of queen
// if he wins , takes 3*bet , else looses bet amount , initially player has $100 of virtual cash
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include<string.h>
#include<math.h>
#include<time.h>
using namespace std;
int cash =100;
void play(int bet){
	char c[3] = {'J','Q','K'};
	cout << "shuffling ...............\n";
	srand(time(NULL));
	int i;
	for(i=0;i<5;i++){
		int x = rand()%3;
		int y = rand()%3;
		int temp=c[x] ;c[x]=c[y];c[y]=temp;
	}
	int playerguess;
	cout << "what's the queen position 1 or 2 or 3\n";
	cin >> playerguess;
	if(c[playerguess-1]=='Q'){
		cash +=3*bet;
		cout << "won the game\n" << "\npositions:" <<  c[0] << " " <<  c[1] << " " << c[2] << "\ncash after bet:" << cash << "\n";
	}
	else{
		cash -=bet;
		cout << "lost the game:" << c[0] << " " << c[1] << " " << c[2] << " " << cash << endl;
	}
}

int main(){
	int bet;
	while(cash>0){
		cout << "what's your bet ?" ;
		cin >> bet;
		if(bet == 0) break;
		else if(bet > cash){
			cout << "please enter valid bet amount as it should be less than or equal to cash available\n" << "what's your bet ?";
			cin >> bet;
		}
		play(bet);
	}
	cout << " ************************* end ***********************\n"; 
	return 0;
}

