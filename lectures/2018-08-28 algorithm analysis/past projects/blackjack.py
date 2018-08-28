def play():
    global my_player
    global the_bet
    global first_card
    global second_card
    global d_first_card
    global d_second_card
    bj_p = False
    bj_d = False
    the_vals = []
    d_the_vals = []
    the_sum =0
    d_the_sum = 0
    hit = 'y'
    counter = 0
    d_counter = 0
    if first_card.is_ace():
        if second_card.is_face() or second_card.value_of_card == 10:
            print("Black jack by player")
            bj_p = True
    if second_card.is_ace():
        if first_card.is_face() or second_card.value_of_card == 10:
            print("Black jack by player")
            bj_p = True    
    if d_first_card.is_ace():
        if d_second_card.is_face() or d_second_card.value_of_card == 10:
            print("The dealer reveals his first card, as {}".format(d_first_card.name_of_card))
            print("Black jack by Dealer")
            bj_d = True
    if d_second_card.is_ace():
        if d_first_card.is_face() or d_second_card.value_of_card == 10:
            print("The dealer reveals his first card, as {}".format(d_first_card.name_of_card))
            print("Black jack by Dealer")
            bj_d = True      
    while bj_p and not bj_d:
        the_bet = str(int(the_bet) * 3)
        print("{} has won {} chips.".format(my_player.players_name, the_bet))
        my_player.chips += int(the_bet)
        return
    while bj_d and not bj_p:
        print("{} has lost {} chips.".format(my_player.players_name, the_bet))
        return
    while bj_p and bj_d:
        print("{} has tied and is refunded {} chips.".format(my_player.players_name, the_bet))
        my_player.chips += int(the_bet)
        return
    first_card.is_ace()
    first_card.is_face()
    second_card.is_ace()
    second_card.is_face()
    the_vals.append(first_card.value_of_card)
    the_vals.append(second_card.value_of_card)
    the_sum = first_card.value_of_card + second_card.value_of_card
    while hit == 'y':
        print("you have: {}".format(the_sum))
        print("Would you like another card? y for yes. all other key entries will pass turn to the dealer.")
        h = ''
        hit = input(h)
        hit = hit.lower()
        if hit != 'y':
            continue
        rand_num = randint(0, 51)
        next_card = the_deck[rand_num]
        print("You are given {}".format(next_card.name_of_card))
        next_card.is_ace()
        next_card.is_face()
        the_vals.append(next_card.value_of_card)
        the_sum += next_card.value_of_card
        if the_sum > 21:
            for x in the_vals:
                if x == 11:
                    the_vals[counter] = 1
                    the_sum -= 10
                counter += 1
        elif the_sum == 21:
            break    
        # Figure out a way to continue if the sum is over 21 and theres no 11 to change to one
        if the_sum > 21:
            print("you have busted, and lost your bet of {}".format(the_bet))
            return
    if the_sum <= 21:
        print("The dealer flips their card over revealing {}".format(d_first_card.name_of_card))
        d_first_card.is_ace()
        d_first_card.is_face()
        d_second_card.is_ace()
        d_second_card.is_face()
        d_the_vals.append(d_first_card.value_of_card)
        d_the_vals.append(d_second_card.value_of_card)
        d_the_sum = d_first_card.value_of_card + d_second_card.value_of_card
        while d_the_sum < 17:
            print("Dealer has: {}".format(d_the_sum))
            rand_num = randint(0, 51)
            next_card = the_deck[rand_num]
            print("Dealer is given {}".format(next_card.name_of_card))
            next_card.is_ace()
            next_card.is_face()
            d_the_vals.append(next_card.value_of_card)
            d_the_sum += next_card.value_of_card
            if d_the_sum > 21:
                for x in d_the_vals:
                    if x == 11:
                        d_the_vals[d_counter] = 1
                        d_the_sum -= 10
                    d_counter += 1     
            elif d_the_sum == 21:
                break    
            if d_the_sum > 21:
                print("Dealer has busted, and you win the bet")
                my_player.chips += int(the_bet) * 2
                return
    if the_sum > d_the_sum:
        print("Your value of {} beat the dealers value of {}, you win.".format(the_sum, d_the_sum))
        my_player.chips += int(the_bet) *2
        return
    elif the_sum < d_the_sum:
        print("The dealers value of {} beat your value of {}, the house wins.".format(d_the_sum, the_sum))
        return
    elif the_sum == d_the_sum:
        print("You both have the same value, you regain your chips.")
        my_player.chips += int(the_bet)
        return
    else:
        print("This should never show")
            