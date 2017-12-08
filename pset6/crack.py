from cs50 import *
import sys
import crypt


MAXLEN = 1


def genString(tab, s, c, hashed):
    i = 0
    while i < 52:
        s[c] = tab[i]
        if (c + 1) < MAXLEN:
            genString(tab, s, (c + 1), hashed)
        else:
            s = s[0:MAXLEN]
            if hashed == crypt.crypt(''.join(s), "50"):
                print(''.join(s))
                sys.exit(0)
        i += 1


def main():
    if len(sys.argv) != 2:
        print("Usage: ./crack hash")
        return 2
    tab = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    tmp = list("abcd")
    global MAXLEN
    while MAXLEN <= 4:
        genString(tab, tmp, 0, sys.argv[1])
        MAXLEN += 1


if __name__ == "__main__":
    main()
