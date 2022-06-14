#!/usr/bin/python3
# TODO: make prettier
# TODO: add help
# На unix-подобных системах не придётся писать python3 перед каждым вызовом
import sys
from functools import reduce


def main(args: list) -> None:
    
    # Изначально аргументы из командной строки - строки
    a, b = map(int, args)
    print(a * b)

if __name__ == "__main__":
    # Допустим это очень плохая программа
    # Тогда мы не нуждаемся в help или в других флагах!
    if len(sys.argv) != 3:
        # Выкинем ошибку, если неправильное кол-во аргументов
        raise TypeError("uncorrect arguments!")
    # Уберём из аргументов название скрипта
    sys.argv.pop(0)
    main(sys.argv)