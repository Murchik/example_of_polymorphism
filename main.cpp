#include <ctime>
#include <iostream>
#include <vector>

#include "header.hpp"

#define NUMBER_OF_ENEMIES 5

int main() {
    int rng;
    int the_number_of_the_current_enemy;
    player* Hero = player::getInstance();

    std::cout << "I'm a hero! Here are my stats:" << std::endl;
    Hero->show_stats();
    std::cout << std::endl;

    std::vector<enemy*> enemies = {};
    srand(time(0));
    std::cout << "We are your enemies! Here are our stats:" << std::endl;
    for (int i = 0; i < NUMBER_OF_ENEMIES; ++i) {
        rng = rand() % 2;
        if (rng) {
            std::cout << "I'm a warrior!" << std::endl;
            enemies.push_back(new warrior());
            enemies[i]->show_stats();
        } else {
            std::cout << "I'm a mage!" << std::endl;
            enemies.push_back(new mage());
            enemies[i]->show_stats();
        }
    }

    std::cout << "Let's fight!!!" << std::endl;
    for (int turn = 0; enemies.size() > 0 && Hero->get_health() > 0; ++turn) {
        std::cout << "// ====== Turn " << turn << "! ====== //" << std::endl;
        the_number_of_the_current_enemy = turn % enemies.size();
        // Герой атакует очередного противника
        Hero->attack_unit(*enemies[the_number_of_the_current_enemy]);
        // Очередной противник атакует героя
        enemies[the_number_of_the_current_enemy]->attack_unit(*Hero);
        // Если у противника кончилось здоровье то убираем его
        if (enemies[the_number_of_the_current_enemy]->get_health() <= 0) {
            std::cout << "The hero killed one of the enemies!" << std::endl;
            enemies.erase(enemies.begin() + the_number_of_the_current_enemy);
        }
        // Выводим результаты боя
        std::cout << "Hero's stats:" << std::endl;
        Hero->show_stats();
        std::cout << "Enemies' stats:" << std::endl;
        for (int i = 0; i < enemies.size(); ++i) {
            enemies[i]->show_stats();
        }
        std::cout << std::endl;
    }

    if (enemies.size() == 0 && Hero->get_health() > 0) {
        std::cout << "The hero wins the battle! Congratulations!!!"
                  << std::endl;
    } else if (Hero->get_health() <= 0) {
        std::cout << "The hero lost the battle!!!" << std::endl;
    } else {
        std::cout << "strange, the battle wasn't supposed to go like this ..."
                  << std::endl;
    }

    return 0;
}
