/*
WAR v0.2

A CLI mini game based on mini game "WAR" from the J2ME game "Wolfenstein RPG".
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  char player1_name[20] = "B.J. Blazkowicz";
  char player2_name[20] = "Gunther";
  
  int player1_money = 100;
  int player2_money = 100;
  
  int player1_bet = 0;
  int player2_bet = 0;
  
  int player1_card = 0;
  int player2_card = 0;
  
  while (true) {
    cout << "Your money: " << player1_money << endl;
    cout << player2_name << "'s money: " << player2_money << endl;
    cout << "Make a bet!" << endl;
    cout << "-> ";
    cin >> player1_bet;
    
    if ((player1_bet >= 10) && (player1_bet % 10 == 0) && (player1_bet <= player1_money) && (player1_bet <= player2_money)) {
      player2_bet = player1_bet;
    
        player1_money = player1_money - player1_bet;
        player2_money = player2_money - player2_bet;
        
        srand(time(NULL));
        
        cout << "Picking a card..." << endl;
        player1_card = 1 + rand() % 20;
        cout << "Your card: " << player1_card << endl;
        
        cout << player2_name << "'s turn." << endl;
        player2_card = 1 + rand() % 20;
        cout << player2_name << "'s card: " << player2_card << endl;
        
        if (player1_card > player2_card) {
          cout << "You won the hand!\n" << endl;
          
          player1_money = player1_money + (player1_bet + player2_bet);
        }
        else if (player1_card < player2_card) {
          cout << "You lost the hand.\n" << endl;
          
          player2_money = player2_money + (player1_bet + player2_bet);
        }
        else if (player1_card == player2_card) {
          cout << "Card are equal." << endl;
          cout << "Go to WAR!\n" << endl;
          cout << "You're at WAR!" << endl;
          
          while (true) {
            srand(time(NULL));
            
            player1_card = 1 + rand() % 20;
            player2_card = 1 + rand() % 20;
            
            if (player1_card != player2_card) {
              cout << "Your card: " << player1_card << endl;
              cout << player2_name << "'s card: " << player2_card << endl;
              
              if (player1_card > player2_card) {
                cout << "You won the hand!\n" << endl;
                
                player1_money = player1_money + (player1_bet + player2_bet);
                
                break;
              }
              else if (player1_card < player2_card) {
                cout << "You lost the hand.\n" << endl;
                
                player2_money = player2_money + (player1_bet + player2_bet);
                
                break;
              }
            }
          }
        }
        
        if (player2_money <= 0) {
          cout << "You've won all of your opponent's loot." << endl;
          
          break;
        }
        else if (player1_money <= 0) {
          cout << "You don't have enough loot to play again." << endl;
          
          break;
        }
      }
    }
  
  return 0;
}
