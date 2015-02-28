#!/usr/bin/python3

def chunk(A, k):
    """Yield chunks from A of size k"""
    for i in range(len(A)):
        chunk = A[i:i+k]
        if len(chunk) == k:
            yield chunk
        else:
            break

def unfairness(A, k):
    # sort list
    A.sort()

    # create chunk generator
    chunks = chunk(A, k)

    # calculate all the unfairness
    min_unfair = 2 ** 32 #freaking high number :)
    for c in chunks:
        # since values already sorted, the min and max is trivial
        unfairness = c[-1] - c[0] # last(max) - first(min)
        if min_unfair > unfairness:
            min_unfair = unfairness
    # return minimal unfair found
    return min_unfair


if __name__ == '__main__':
    N = int(input())
    K = int(input())
    A = []
    for i in range(N):
        A.append(int(input()))
    print(unfairness(A, K))
