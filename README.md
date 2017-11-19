# Harvard cs50 Computer Science Course
Harvard CS50 is a course on edX educational platform.  
https://www.edx.org/course/introduction-computer-science-harvardx-cs50x

#### Requirements
In order to make those program compile, you'll have to install the [libcs50](https://github.com/cs50/libcs50)

## pset1: C
water.c : a program to convert shower's length (in minutes) to equivalent water bottles
```javascript
$ ./water
minutes: 10
bottles: 120
```

mario.c : a program that recreates half-pyramid using hashes (#) for blocks.
```javascript
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```
credit.c : a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.
```javascript
$ ./credit
Number: 378282246310005
AMEX
```

## pset2: Crypto

vigenere.c : a program to vigenere cipher a text
```javascript
$ ./vigenere bacon
Meet me at the park at eleven am
Negh zf av huf pcfx bt gzrwep oz
```

crack.c : a program that cracks passwords, per the below.
```
$ ./crack 50fkUxYHbnXGw
rofl
```

## pset3: Game of Fifteen
find.c : a program that finds a number among numbers, per the below.
```
$ ./generate 1000 | ./find 42
Didn't find needle in haystack.
```

fifteen.c : a game of fifteen games
```javascript
$ ./fifteen 4

15 14 13 12

11 10  9  8

 7  6  5  4

 3  1  2  _
 
Tile to move:
```

## pset4: Forensics
whodunit.c : a program that intelligently analyze an image (clue.bmp) and turn it to a better image (verdict.bmp)
```javascript
$ ./whodunit clue.bmp verdict.bmp
```
Before running whodunit.c

![Image of clue](https://s30.postimg.org/gtxuk8y69/download.png)

After running whodunit.c

![Image of verdict](https://s30.postimg.org/p9eotmns1/download_1.png)

resize.c : a program that can enlarge an image to n size
```javascript
$ ./resize 4 small.bmp large.bmp
```

Before and after running resize.c

![Image of small](https://s24.postimg.org/u4la5vqyt/small.png)
![Image of large](https://s30.postimg.org/zevkxb49d/large.png)

recover.c : a program that recovers .jpeg images from card.raw
```javascript
$ ./recover
```
![Image of before and after](https://s29.postimg.org/whkiz0dlj/test.png)

## pset5: Spellchecker
```javascript
$ ./speller dictionaries/large endi.txt

MISSPELLED WORDS

nme
veri
persan
yo
bro
USConstitution
http
usconstitution
const
html

WORDS MISSPELLED:     10
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        722
TIME IN load:         0.10
TIME IN check:        0.00
TIME IN size:         0.00
TIME IN unload:       0.06
TIME IN TOTAL:        0.16
```


## pset6: Python
Requirements & Dependencies:
```javascript
cd ~/workspace/pset6/sentiments/
pip3 install --user -r requirements.txt
```

### Convert some of pset1 and 2 .c programs to .py
```javascript
$ python mario.py
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

```javascript
$ python credit.py
O hai! How much change is owed?
0.41
4
```

```javascript
$ python vigenere.py bacon
Meet me at the park at eleven am
Negh zf av huf pcfx bt gzrwep oz
```

### Sentiments

smile.py : a program that categorizes a word as positive or negative

[![smile.png](https://s28.postimg.org/jzsjsjkod/smile.png)](https://postimg.org/image/907cgxu95/)

tweets.py categorizes a user’s recent 100 tweets as positive or negative (uses Twitter API)

[![tweets.png](https://s23.postimg.org/xjn5x6qm3/tweets.png)](https://postimg.org/image/4u0a0jmlz/)

Implement a website that generates a pie chart categorizing a user’s tweets
[![sentiments.png](https://s23.postimg.org/ortjkn7vf/sentiments.png)](https://postimg.org/image/o2ar8a7br/)

#### Usage: 
```javascript
$ export API_KEY= <insert your API_KEY from Twitter here>
$ export API_SECRET= <insert your API_SECRET from Twitter here>
$ export FLASK_APP=application.py
$ export FLASK_DEBUG=1
$ flask run
```
