def checkio(game_result):
    # check rows
    for row in game_result:
        if row == 'XXX':
            return 'X'
        elif row == 'OOO':
            return 'O'

    # check columns (using traverse)
    t_game_result = zip(*game_result)
    for row in t_game_result:
        r = ''.join(row)
        if r == 'XXX':
            return 'X'
        elif r == 'OOO':
            return 'O'

    # check diagonals
    main_diag = ''.join(game_result[i][i] for i in range(3))
    sec_diag = ''.join(game_result[2-i][i] for i in range(2, -1,-1))

    if main_diag == 'XXX' or sec_diag == 'XXX':
        return 'X'
    elif main_diag == 'OOO' or sec_diag == 'OOO':
        return 'O'

    # case none of the above, return 'D'
    return 'D'
