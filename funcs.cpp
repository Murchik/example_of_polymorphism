#include <iostream>

#include "header.hpp"

// ============================== CLASS ENEMY ============================== //

void enemy::show_stats() {
    std::cout << "Health: "  << this->health          << "\t"
              << "Defence: " << this->defence         << "\t"
              << "Attack: "  << this->attack_strength << "\t"
              << std::endl;
}

double enemy::get_health() { return health; }

// ========================== END OF CLASS ENEMY =========================== //

// ============================= CLASS PLAYER ============================== //

player::player() {
    this->health = 370;
    this->mana = 100;
    this->defence = 75;
    this->attack_strength = 100;
    this->skill_strength = 150;
}

player *player::p_instance = 0;

player *player::getInstance() {
    if (!p_instance) p_instance = new player();
    return p_instance;
}

void player::show_stats() {
    std::cout << "Health: "          << this->health          << "\t"
              << "Mana: "            << this->mana            << "\t"
              << "Defence: "         << this->defence         << "\t"
              << "Attack strength: " << this->attack_strength << "\t"
              << "Skill strength: "  << this->skill_strength  << "\t"
              << std::endl;
}

double player::get_health() { return this->health; }

void player::take_damage(double damage) { this->health -= damage; }

void player::attack_unit(unit &target) {
    target.take_damage(this->attack_strength);
}
// ========================== END OF CLASS PLAYER ========================== //

// ============================= CLASS WARRIOR ============================= //

warrior::warrior() {
    this->health = 100;
    this->defence = 50;
    this->attack_strength = 30;
}

void warrior::take_damage(double damage) { this->health -= (damage - this->defence); }

void warrior::attack_unit(unit &target) {
    target.take_damage(this->attack_strength);
}
// ========================= END OF CLASS WARRIOR ========================== //

// ============================== CLASS MAGE =============================== //

mage::mage() {
    this->health = 50;
    this->defence = 30;
    this->attack_strength = 70;
}

void mage::take_damage(double damage) { this->health -= (damage - 0.5 * this->defence); }

void mage::attack_unit(unit &target) {
    target.take_damage(this->attack_strength * 1.5);
}
// ========================== END OF CLASS MAGE ============================ //
