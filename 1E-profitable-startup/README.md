# 1E Прибыльный стартап

k
 друзей организовали стартап по производству укулеле для кошек. На сегодняшний день прибыль составила 
n
 рублей. Вы, как главный бухгалтер компании, хотите в каждый из ближайших 
d
 дней приписывать по одной цифре в конец числа, выражающего прибыль. При этом в каждый из дней прибыль должна делиться на 
k
.

В единственной строке входных данных через пробел записаны три числа: 
n
,
k
,
d
 — изначальная прибыль, количество учредителей компании и количество дней, которое вы собираетесь следить за прибылью 
(
1
≤
n
,
k
≤
1
0
9
,
1
≤
d
≤
1
0
5
)
. НЕ гарантируется, что 
n
 делится на 
k
.

Выведите одно целое число 
x
 — прибыль компании через 
d
 дней. Первые цифры числа 
x
 должны совпадать с числом 
n
. Все префиксы числа 
x
, которые длиннее числа 
n
 на 
1
,
2
,
…
,
d
 цифр, должны делиться на 
k
. Если возможных ответов несколько, выведите любой из них. Если ответа не существует, выведите 
−
1
.

## Пример 1

### Ввод

21 108 1

### Вывод

216

## Пример 2

### Ввод

5 12 4

### Вывод

-1