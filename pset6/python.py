#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

from cs50 import *
import sys


class Student():
    def __init__(self, name, age):
        self.name = name
        self.age = age


def main():
    if len(sys.argv) == 2:
        print(sys.argv[1])
    for s in sys.argv:
        print(s)
    print("Hello World")
    name = get_string("Name : ")
    age = get_string("Age : ")
    student = Student(name, age)
    print(f"{student.name} is {student.age} years old.")


if __name__ == "__main__":
    main()
