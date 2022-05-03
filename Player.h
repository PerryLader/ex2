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
    Player::Player() = delete;
    Player::Player(const char *playerName, const int maxHp = 100, const int force = 5);
    Player::Player(const Player &player);

    // distractor
    Player::~Player();

    // oprators
    Player &Player::operator=(const Player &player);

    // methods
    void Player::printInfo();
    void Player::levelUp();
    void Player::heal(const int healSize);
    void Player::dmg(const int dmgSize);
    int Player::getAttackStrength();
    int Player::getLevel();
    void Player::addCoins(const int coinsSize);
    void Player::buff(const int buffSize);
    bool Player::isKnockedOut();
    bool Player::pay(const int coinsSize);
};

#endif