def get_winner(n, m):
    moves = min(n, m)
    if moves % 2 == 0:
        return "Malvika"
    else:
        return "Akshat"

if __name__ == "__main__":
    n, m = tuple(map(int, input().strip().split()))
    print(get_winner(n, m))
