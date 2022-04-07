# cub3D_21school

3D бродилка на С, с использованием библиотеки MinilibX (подробнее про MinilibX: https://harm-smits.github.io/42docs/)

(командный проект @trurgot и @acristin)

## Mandatory part

Игрок может бегать по лабиринту, ходить сквозь стены, изменять цвета пола и потолка при нажатии пробела.

Направление движения игрока управляется кнопками ```W```, ```A```, ```S```, ```D```.

Поворот поля зрения - с помощью стрелочек ```<-```, ```->```.

При нажатии кнопки ```ESC``` игра завершается.

## Bonus part

К основному функционалу добавляется:
 - Игрок сталкивается со стенами, а не ходит сквозь них
 - Кнопка ```M``` включает миникарту в левом верхнем углу экрана
 - Поворот поля зрения можно осуществлять движением мыши

## Команды для сбоки игры

```make``` - компиляция библиотек libft и MinilibX, компиляция основной игры

```make bonus``` - компиляция библиотек libft и MinilibX, компиляция бонусной игры

```make clean``` - удаление объектных файлов

```./cub3d <map>.cub``` или ```./cub3d_bonus <map>.cub``` - запуск игры, в качестве аргумента передается карта с расширением ```.cub```

```make fclean``` - удаление всех скомпилированных файлов

## Критерии валидности карт

 - Файл с картой имеет расширение ```.cub```
 - Внутри файла с картой должна быть специальная информация о текстурах для стен:
   - ```NO ./path_to_the_north_texture``` - текстура северной стены
   - ```SO ./path_to_the_south_texture``` - текстура южной стены
   - ```WE ./path_to_the_west_texture``` - текстура западной стены
   - ```EA ./path_to_the_east_texture``` - текстура восточной стены
 - Внутри файла с картой должна быть специальная информация о цветах пола и потолка (R, G, B цвета в диапазоне [0, 255]):
   - ```F 220,100,0``` - цвет пола
   - ```C 220,100,0``` - цвет потолка
 - Карта находится строго после специальной информации
 - Карта состоит из 6 символов:
   - ```0``` - свободное поле
   - ```1``` - стена
   - ```N```, ```S```, ```W```, ```E``` - позиция игрока и его начальное направление поля зрения
 - Карта окружена стенами
 - Внутри карты не должно быть пустых строк

Примеры карт находятся в папке maps.