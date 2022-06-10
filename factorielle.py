def factorielle (n):
    if n == 1:
        return(1)
    return(n*factorielle(n-1))

k = int(input())
print(factorielle(k))
