"""
WAR v0.3

A CLI mini game based on mini game "WAR" from the J2ME game "Wolfenstein RPG".
"""

import random
import time

player1_name = 'B.J. Blazkowicz'
player2_name = 'Gunther'

player1_money = 100
player2_money = 100

player1_bet = 0
player2_bet = 0

player1_card = 0
player2_card = 0

while True:
    print('Your money: ' + str(player1_money))
    print(player2_name + '\'s money: ' + str(player2_money))
    print('Make a bet!')
    player1_bet = int(input('-> '))

    if (player1_bet >= 10) and (player1_bet % 10 == 0) and (player1_bet <= player1_money) and (player1_bet <= player2_money):
        player2_bet = player1_bet

        player1_money = player1_money - player1_bet
        player2_money = player2_money - player2_bet

        print('Picking a card...')
        time.sleep(2)
        player1_card = random.randint(1, 20)
        print('Your card: ' + str(player1_card))

        print(player2_name + '\'s turn.')
        time.sleep(2)
        player2_card = random.randint(1, 20)
        print(player2_name + '\'s card: ' + str(player2_card))

        if player1_card > player2_card:
            print('You won the hand!\n')

            player1_money = player1_money + (player1_bet + player2_bet)
        elif player1_card < player2_card:
            print('You lost the hand.\n')

            player2_money = player2_money + (player1_bet + player2_bet)
        elif player1_card == player2_card:
            print('Cards are equal.')
            print('Go to WAR!\n')
            print('You\'re at WAR!')
            time.sleep(3)

            while True:
                player1_card = random.randint(1, 20)
                player2_card = random.randint(1, 20)

                if player1_card != player2_card:
                    print('Your card: ' + str(player1_card))
                    print(player2_name + '\'s card: ' + str(player2_card))

                    if player1_card > player2_card:
                        print('You won the hand!\n')

                        player1_money = player1_money + (player1_bet + player2_bet)

                        break
                    elif player1_card < player2_card:
                        print('You lost the hand.\n')

                        player2_money = player2_money + (player1_bet + player2_bet)

                        break

        if player2_money <= 0:
            print('You\'ve won all of your opponent\'s loot.')

            break
        elif player1_money <= 0:
            print('You don\'t have enough loot to play again.')

            break
