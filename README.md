# 2GIS_Task
Тестовое задание от 2GIS


Напишите (консольную) программу, принимающую на вход имя файла и набор параметров.

В зависимости от параметров программа должна работать в трёх режимах:

 1. test -f Test.tst -m words -v mother — печатает количество слов «mother» в файле «Test.tst»

 2. test -f Test.tst -m checksum — печатает 32-битную чексумму, рассчитанную по алгоритму checksum = word1 + word2 + ... + wordN (word1..wordN – 32-хбитные слова, представляющие содержимое файла)

 3. test -h — печатает информацию о программе и описание параметров.

При написании тестового задания мы ожидаем увидеть пример качественного production-кода на С++ (а не «чистом» С, несмотря на некоторую избыточность С++ для данной задачи),  в частности:

- соблюдение единого стиля кодирования

- разумное расходование памяти

- расчёт на производительность

- расчёт на расширяемость

- следование принципам ООП там, где это уместно

- использование modern C++ best practices

## Требования к сборке 
 - CMake 3.9
 - g++ 8.4.0
 - Boost::program_options
 - GTest
