#ifndef HEADER
#define HEADER

// Интерфейсный класс unit
class unit {
public:
    virtual void show_stats() = 0;
    virtual void take_damage(double damage) = 0;
    virtual void attack_unit(unit &unit) = 0;
};

// Абстрактный класс enemy
// Наследование от интерфейса unit
class enemy : public unit {
protected:
    double health;
    double attack_strength;
    double defence;

public:
    void show_stats();
    double get_health();
    virtual void take_damage(double damage) = 0;
    virtual void attack_unit(unit &target) = 0;
};

// Наследование от интерфейса unit
// Singleton class
class player : public unit {
private:
    static player *p_instance;
    double health;
    double mana;
    double attack_strength;
    double skill_strength;
    double defence;
    player();
    player(const player &);
    player &operator=(player &);

public:
    static player *getInstance();
    void show_stats();
    double get_health();
    virtual void take_damage(double damage);
    virtual void attack_unit(unit &target);
};

// ========================================================================= //

// Наследование от абстрактного класса enemy
class warrior : public enemy {
public:
    warrior();
    ~warrior();
    void take_damage(double damage);
    void attack_unit(unit &target);
};

// Наследование от абстрактного класса enemy
class mage : public enemy {
public:
    mage();
    ~mage();
    void take_damage(double damage);
    void attack_unit(unit &target);
};

#endif
