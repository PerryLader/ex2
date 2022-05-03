

#include "Player.h"
#include <string.h>
// char * name;
// int level;
// int force;
// int maxHp;
// int curHp;
// int coins;
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
Player::Player(const Player *player)
{
    int nameSize = strlen(player->name);
    name = new char[nameSize + 1];
    for (int i = 0; i < nameSize; i++)
    {
        name[i] = player->name[i];
    }
    name[nameSize] = '\0';
    this->level = player->level;
    this->force = player->force;
    this->maxHp = player->maxHp;
    this->curHp = this->maxHp;
    this->coins = player->coins;
}
Player &Player::operator=(const Player &player)
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
