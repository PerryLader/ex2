

#include "Player.h"
#include "utilities.h"
#include <cstring>

// char * name;
// int level;
// int force;
// int maxHp;
// int curHp;
// int coins;

// constractors
Player::Player(const char *playerName, const int maxHp, const int force)
{
    int nameSize = strlen(playerName);
    name = new char[nameSize + 1];
    for (int i = 0; i < nameSize; i++)
    {
        name[i] = playerName[i];
    }
    name[nameSize] = '\0';
    level = 1;
    this->force = force;
    this->maxHp = maxHp;
    curHp = maxHp;
    coins = 0;
}
Player::Player(const Player& player)
{
    int nameSize = strlen(player.name);
    name = new char[nameSize + 1];
    for (int i = 0; i < nameSize; i++)
    {
        name[i] = player.name[i];
    }
    name[nameSize] = '\0';
    this->level = player.level;
    this->force = player.force;
    this->maxHp = player.maxHp;
    this->curHp = player.curHp;
    this->coins = player.coins;
}
// distractor
Player::~Player()
{
    delete[] this->name;
}
// oprators
Player& Player::operator=(const Player &player)
{
    if (this == &player)
        return *this;
    delete[] name;
    int nameSize = strlen(player.name);
    name = new char[nameSize + 1];
    for (int i = 0; i < nameSize; i++)
    {
        name[i] = player.name[i];
    }
    name[nameSize] = '\0';
    this->level = player.level;
    this->force = player.force;
    this->maxHp = player.maxHp;
    this->curHp = this->maxHp;
    this->coins = player.coins;
    return *this;
}
// methods

void Player::printInfo()
{
    printPlayerInfo(name, level, force, curHp, coins);
}

void Player::levelUp()
{
    if (level <= 9)
    {
        level++;
    }
}
int Player::getLevel()
{
    return level;
}
int Player::getAttackStrength()
{
    int strength = level + force;
    return strength;
}
bool Player::isKnockedOut()
{
    return (curHp <= 0);
}
bool Player::pay(const int coinsSize)
{
    if (coins < coinsSize)
    {
        return false;
    }
    coins -= coinsSize;
    return true;
}
void Player::heal(const int healSize)
{
    curHp += healSize;
    if (curHp > maxHp)
    {
        curHp = maxHp;
    }
}
void Player::dmg(const int dmgSize)
{
    curHp = curHp - dmgSize;
}
void Player::addCoins(const int coinsSize)
{
    coins += coinsSize;
}
void Player::buff(const int buffSize)
{
    force += buffSize;
}
int main()
{
    Player *p1 = new Player("guy",300,2);
    p1->printInfo();
}
