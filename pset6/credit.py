from cs50 import *


def isLuhnAlgVerified(nb):
    c = list("3782822463100056")
    total = 0
    subtotal = 0
    i = 0
    x = 0
    l = len(nb)
    while i < l:
        if i % 2 != 0:
            tmp = ((int(nb[i]) - int('0')) * 2)
            if tmp > 9:
                c[x] = "1"
                x += 1
            tmp = tmp % 10
            c[x] = str(tmp)
            x += 1
        else:
            total = total + (int(nb[i]) - int('0'))
        i += 1
    c[x] = "\0"
    i = 0
    while c[i] != "\0":
        subtotal = subtotal + int(c[i])
        i += 1
    if (total + subtotal) % 10 == 0:
        return True
    return False


def isValid(nb):
    l = len(nb)
    if ((l == 15 or len == 16 or len == 13) and
            isLuhnAlgVerified(nb)):
        return True
    return False


def isMasterCard(nb):
    l = len(nb)
    if (l == 16 and nb[0] == '5' and
            (nb[1] == '1' or nb[1] == '2' or nb[1] == '3' or nb[1] == '4' or nb[1] == '5')):
        return True
    return False


def isVisa(nb):
    l = len(nb)
    if (l != 16 or l != 13) and nb[0] != '4':
        return False
    return True


def isAmex(nb):
    l = len(nb)
    if (l == 15 and nb[0] == '3' and
            (nb[1] == '4' or nb[1] == '7')):
        return True
    return False


def checkCard(nb):
    if isMasterCard(nb):
        print("MASTERCARD")
    elif isVisa(nb):
        print("VISA")
    elif isAmex(nb):
        print("AMEX")


def main():
    print("Number : ", end='')
    nb = get_string()

    if not isValid(nb):
        print("INVALID")
    else:
        checkCard(nb)


if __name__ == "__main__":
    main()
