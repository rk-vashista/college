import random, sys

wins, lose, tie =0 , 0 , 0
print("Enter (r)ock , (p)aper , (s)cissior or (q)uit")

turn ='p'


while turn != 'q':
    print(f"WINS: {wins}, Looses:{lose}, Tie:{tie}")
    print("Enter your choice")
    turn =input()

    if turn=='q':
        print("thank you for playing")
        sys.exit()
    elif turn == 'r':
        print("Rock verus....")
    elif turn == 'p':
        print("Paper verus....")
    else:
        print("Scissor verus....")
    

    comp_choice= random.randint(1,3)
    # 1- Rock 2- Paper 3- Scissors
    if comp_choice == 1:
        print('ROCK')
        #Tie
        if turn =='r':
            print('Tie')
            tie= tie+1
        #lose
        elif turn =='p':
            print('You Win!')
            wins =wins +1
        #win
        else:
            print('You Lose :(')
            lose=lose+1

    elif comp_choice == 2:
        print('PAPER')
         #Tie
        if turn =='p':
            print('Tie')
            tie= tie+1
        #lose
        elif turn =='s':
            print('You Win!')
            wins =wins +1
        #win
        else:
            print('You Lose :(')
            lose=lose+1

    elif comp_choice == 3:
        print('Scissor')
         #Tie
        if turn =='s':
            print('Tie')
            tie= tie+1
        #lose
        elif turn =='r':
            print('You Win!')
            wins =wins +1
        #win
        else:
            print('You Lose :(')
            lose=lose+1

        

