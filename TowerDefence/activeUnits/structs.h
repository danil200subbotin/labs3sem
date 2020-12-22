//
// Created by Данил Морозов on 06/12/2020.
//

#ifndef TOWERDEFENCE_STRUCTS_H
#define TOWERDEFENCE_STRUCTS_H

/*!
\file
\brief Файл со структурами, используемыми несколькими классами
*/


/*!
	\brief Таблица эффектов магической башни и ловушки
*/

struct Effect {
    int slow;

    int illness;

    int time;
};

/*!
	\brief Таблица эффектов цветов
*/

struct colourInd {
    int red;
    int blue;
    int green;
};

#endif //TOWERDEFENCE_STRUCTS_H
