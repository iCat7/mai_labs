# Обработка последовательной файловой структуры на языке Си
6 курсовой проект

## Задание:
Вывести все классы, в которых количество мальчиков больше количества девочек.

## Входные данные:
На вход программе подается массив данных, в котором построчно содержится информация о каждом выпускнике школы.

##### Информация об ученике:
1. Фамилия
2. Инициалы
3. Пол
4. Год выпуска
5. Буква класса
6. Университет

###### Пример:
```
Pupkin VI M 2003 Z Sharaga
Botanov MA M 2009 A MSU
Ivanov II M 1984 H MFTI
Sorokina YA F 2015 B MGMSU
etc.
```

## Компиляция
Для компиляции необходимо перейти в корневаю папку программу и выполнить команду `make`. В результате компиляции создастся 3 исполняемых файла:
1. test
2. gen
3. exe

## Работа с программой

1. Для генерации случайного теста выполните `./test` в терминале (`./test > <file>` для вывода теста в файл), команда принимает на вход лишь количество учеников.
2. Программа обрабатывает данные в бинарном виде, поэтому из текстового формата необходимо их сначали перевести в бинарный. Для этого выполните `./gen <file1> <file2>`, где `<file1>` - файл с текстовыми исходными данными, а `<file2>` - файл в который будут записаны данные в бинарном представлении.
3. Для исполнения самой программы выполните `./exe <file>`, где `file` - исходные данные в бинарном виде.

## Пример работы (входные данные, как на примере выше):
```
desoo@ubuntu:~/Desktop/git/mai_labs/CP6/workstation$ ./gen example bin
desoo@ubuntu:~/Desktop/git/mai_labs/CP6/workstation$ ./exe bin
Date   Letter     Male    Female
2003      Z        1        0
1984      H        1        0
2009      A        1        0
```

## Пример работы для случайно сгенерированных классов:
```
desoo@ubuntu:~/Desktop/git/mai_labs/CP6/workstation$ ./test > tetst
500
desoo@ubuntu:~/Desktop/git/mai_labs/CP6/workstation$ ./gen tetst f1
desoo@ubuntu:~/Desktop/git/mai_labs/CP6/workstation$ ./exe f1
Date   Letter     Male    Female
2011      A        13        9
2011      D        10        2
2011      B        10        9
2010      E        14        4
2014      A        11        7
2014      C        8        7
2014      E        10        6
2014      D        11        7
2013      C        8        7
2013      E        7        6
2012      E        10        9
2012      B        9        8
2012      A        7        6
2015      A        13        3
2015      C        9        8
2015      B        11        7
```
