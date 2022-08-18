# BattleShipTaskQt
Была дана задача, по поводу корректности поля в игре под названием морской бой. Надо указать свой путь к файлу к чтению файла в программе.
Для выполнения задания, был выбран двумерный вектор, так как после использования вектора освобождается память, тем самым не нагружает программу.
Двумерный ввектор специально задан больше чем само поле. Для того чтобы контролировать преждевременный выход за вектор. 
При чтение файла символы перезаписываются в массив заменяя *->1 0->0, если имеются посторонние символы программа оповещает пользователя о том что ввод не верный.
Далее когда ввод текста верный программа ищет по массивы 1 если имеется то программа ищет следующий элемент по вертикали и горизонтали. Если 1 имеется то продолжается поиск в заданной плоскости. И перезаписывает 1->2. Эти элемены были посещенны.
Далее программа берет столбец выше и по строке -1 , тем самым идет проверка в части массива. 
Сам корабль дальше складывается с общим числом кораблей и если это число соотвествует то программа выводит результат.
Пример:
0*0    010   020
0*0    010   020             Длинна 4 тип корабля 4-х палубный.
0*0    010   020 
0*0 -> 010 ->020 Правильно! 

Ложный пример:
 0*0    010    020
* *0    110    120
 0*0    010    020
 0*0 -> 010 -> 020 Вокруг корабля есть 1 это ошибка. 
