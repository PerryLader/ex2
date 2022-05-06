

#include "Player.h"
#include "utilities.h"
#include <cstring>

Player::Player(const char *playerName, const int maxHp, const int force)
{
    int nameSize = strlen(playerName);
    m_name = new char[nameSize + 1];
    for (int i = 0; i < nameSize; i++)
    {
        m_name[i] = playerName[i];
    }
    m_name[nameSize] = '\0';
    m_level = 1;
    this->m_force = force;
    this->m_maxHp = maxHp;
    m_curHp = maxHp;
    m_coins = 0;
    
}
Player::Player(const Player &player)
{
    int nameSize = strlen(player.m_name);
    m_name = new char[nameSize + 1];
    for (int i = 0; i < nameSize; i++)
    {
        m_name[i] = player.m_name[i];
    }
    m_name[nameSize] = '\0';
    this->m_level = player.m_level;
    this->m_force = player.m_force;
    this->m_maxHp = player.m_maxHp;
    this->m_curHp = player.m_curHp;
    this->m_coins = player.m_coins;
}
// distractor
Player::~Player()
{
    delete[] this->m_name;
}
// oprators
Player &Player::operator=(const Player &player)
{
    if (this == &player)
        return *this;
    delete[] m_name;
    int nameSize = strlen(player.m_name);
    m_name = new char[nameSize + 1];
    for (int i = 0; i < nameSize; i++)
    {
        m_name[i] = player.m_name[i];
    }
    m_name[nameSize] = '\0';
    this->m_level = player.m_level;
    this->m_force = player.m_force;
    this->m_maxHp = player.m_maxHp;
    this->m_curHp = this->m_maxHp;
    this->m_coins = player.m_coins;
    return *this;
}
// methods

void Player::printInfo()
{
    printPlayerInfo(m_name, m_level, m_force, m_curHp, m_coins);
}

void Player::levelUp()
{
    if (m_level <= 9)
    {
        m_level++;
    }
}
int Player::getLevel()
{
    return m_level;
}
int Player::getAttackStrength()
{
    int strength = m_level + m_force;
    return strength;
}
bool Player::isKnockedOut()
{
    return (m_curHp <= 0);
}
bool Player::pay(const int coinsSize)
{
    if (m_coins < coinsSize)
    {
        return false;
    }
    if (coinsSize > 0)
    {
        m_coins -= coinsSize;
    }
    return true;
}
void Player::heal(const int healSize)
{
    if (healSize > 0)
    {
        m_curHp += healSize;
        if (m_curHp > m_maxHp)
        {
            m_curHp = m_maxHp;
        }
    }
}
void Player::damage(const int dmgSize)
{
    if (dmgSize > 0)
    {
        m_curHp = m_curHp - dmgSize;
    }
}
void Player::addCoins(const int coinsSize)
{
    if (coinsSize > 0)
    {
        m_coins += coinsSize;
    }
}
void Player::buff(const int buffSize)
{
    if (buffSize > 0)
    {
        m_force += buffSize;
    }
}
