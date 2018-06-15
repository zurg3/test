# Casino v0.6.4 by zurg3
# текстовая игра / text game

import random
import time

# начальные суммы денег и джекпота
money = 1000
jackpot = 10000

# приветствие
print('Добро пожаловать в казино!')
print('Ваши текущие деньги: 1000')
print('Узнать правила игры можно, если ввести "rules"')

# основная часть
while True:
    print('\n###############')
    print('# Ваши деньги:', money)
    print('# Джекпот:', jackpot)
    print('# Ваша ставка')
    bet = str(input('# -> '))

    # проверки на корректность ввода
    if bet == '':
        print('\nВы ничего не поставили!')
        continue
    elif bet == 'rules':
        print('\nПРАВИЛА ИГРЫ')
        print('Если выпало 2 одинаковых рядом стоящих числа (например, 544 или 337),\n'
              'то вы выиграете вашу ставку * 0.[цифра, которая выпала]. Например, для 774 будет ваща ставка * 0.7\n'
              'Если выпало 2 рядом стоящих 0, то ваша ставка * 1.5\n')
        print('Если выпало 3 одниковых числа (например, 777 или 222,\n'
              'то вы выиграете вашу ставку * [цифра, которая выпала]. Например, для 555 будет ваша ставка * 5\n')
        print('Если у вас выпало 000, то вы выиграете джекпот!\n')
        checked = str(input('Если вы прочитали правила, нажимте Enter'))
        continue
    elif (bet != 'rules') and (bet != ''):
        try:
            bet = float(bet)
        except ValueError:
            print('\nВы ввели неправильное значение!')
            continue
    else:
        bet = float(bet)

    # защиты
    if bet > money:
        print('\nУ вас недостаточно денег!')
        continue
    elif bet == 0:
        print('\nНельзя ничего не ставить!')
        continue
    elif bet < 0:
        print('\nВы поставили отрицательную сумму, так делать нельзя!')
        continue

    # вычитание ставки из текущих денег
    money = money - bet

    # случайная генерация чисел
    num1 = str(random.randint(0, 9))
    num2 = str(random.randint(0, 9))
    num3 = str(random.randint(0, 9))

    # получение общего числа
    result = str(num1 + num2 + num3)

    # вывод результата партии
    print('#')
    print('# #######\n'
          '# # ' + result + ' #\n'
          '# #######')
    print('#')

    # определение выигрыша
    if (num1 == '1') and (num1 == num2 == num3):
        win_money = bet * 1
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif (num1 == '2') and (num1 == num2 == num3):
        win_money = bet * 2
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif (num1 == '3') and (num1 == num2 == num3):
        win_money = bet * 3
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif (num1 == '4') and (num1 == num2 == num3):
        win_money = bet * 4
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif (num1 == '5') and (num1 == num2 == num3):
        win_money = bet * 5
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif (num1 == '6') and (num1 == num2 == num3):
        win_money = bet * 6
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif (num1 == '7') and (num1 == num2 == num3):
        win_money = bet * 7
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif (num1 == '8') and (num1 == num2 == num3):
        win_money = bet * 8
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif (num1 == '9') and (num1 == num2 == num3):
        win_money = bet * 9
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif (num1 == '0') and (num1 == num2 == num3):
        win_money = jackpot + bet
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли джекпот!:', win_money)
    elif ((num1 == '1') and (num1 == num2)) or ((num3 == '1') and (num2 == num3)):
        win_money = bet * 0.1
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif ((num1 == '2') and (num1 == num2)) or ((num3 == '2') and (num2 == num3)):
        win_money = bet * 0.2
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif ((num1 == '3') and (num1 == num2)) or ((num3 == '3') and (num2 == num3)):
        win_money = bet * 0.3
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif ((num1 == '4') and (num1 == num2)) or ((num3 == '4') and (num2 == num3)):
        win_money = bet * 0.4
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif ((num1 == '5') and (num1 == num2)) or ((num3 == '5') and (num2 == num3)):
        win_money = bet * 0.5
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif ((num1 == '6') and (num1 == num2)) or ((num3 == '6') and (num2 == num3)):
        win_money = bet * 0.6
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif ((num1 == '7') and (num1 == num2)) or ((num3 == '7') and (num2 == num3)):
        win_money = bet * 0.7
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif ((num1 == '8') and (num1 == num2)) or ((num3 == '8') and (num2 == num3)):
        win_money = bet * 0.8
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif ((num1 == '9') and (num1 == num2)) or ((num3 == '9') and (num2 == num3)):
        win_money = bet * 0.9
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    elif ((num1 == '0') and (num1 == num2)) or ((num3 == '0') and (num2 == num3)):
        win_money = bet * 1.5
        jackpot = jackpot - win_money
        money = money + win_money
        print('# Вы выиграли:', win_money)
    else:
        print('# Вы проиграли')
        jackpot = jackpot + bet

    print('###############\n')

    # условия для завершения игры
    if money <= 0:
        print('\nУ вас не осталось денег, вы полностью проиграли!')
        retry = str(input('Начать игру заново? [yes/no] '))
        if (retry == 'yes') or (retry == 'Yes') or (retry == 'YES') or (retry == 'y') or (retry == 'Y'):
            money = money + 1000
            print('Игра начнётся заново через 1 минуту')
            time.sleep(60)
            continue
        elif (retry == 'no') or (retry == 'No') or (retry == 'NO') or (retry == 'n') or (retry == 'N'):
            print('Game Over!')
            break
        else:
            break
    elif jackpot <= 0:
        print('\nВ автомате закочились деньги, подождите 3 минуты')
        time.sleep(180)
        jackpot = jackpot + 5000
