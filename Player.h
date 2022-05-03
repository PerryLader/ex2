#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

class Player
{
    char *name;
    int level;
    int force;
    int maxHp;
    int curHp;
    int coins;

public:
    // constractors
    Player() = delete;
    Player(const char *playerName, const int maxHp = 100, const int force = 5);
    Player(const Player &player);

    // distractor
    ~Player();

    // oprators
    Player& operator=(const Player &player);

    // methods
    void printInfo();
    void levelUp();
    void heal(const int healSize);
    void damage(const int dmgSize);
    int getAttackStrength();
    int getLevel();
    void addCoins(const int coinsSize);
    void buff(const int buffSize);
    bool isKnockedOut();
    bool pay(const int coinsSize);
};

#endif