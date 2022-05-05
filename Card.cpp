#include "Card.h"

Card::Card(CardType type, const CardStats &stats)
{
    m_effect = type;

    m_stats.force = stats.force;
    m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
    m_stats.loot = stats.loot;
    m_stats.cost = stats.cost;
    m_stats.heal = stats.heal;
    m_stats.buff = stats.buff;
}

void Card::applyEncounter(Player &player) const
{
    if (m_effect == CardType::Battle)
    {
        if (player.getAttackStrength() >= m_stats.force)
        {
            player.addCoins(m_stats.loot);
            printBattleResult(true);
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }
        printBattleResult(true);
    }
    else if (m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }
    else if (m_effect == CardType::Heal)
    {
        if (player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
    }
    else if (m_effect == CardType::Buff)
    {
        if (player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
    }
}

void Card::printInfo() const
{
    if (m_effect == CardType::Battle)
    {
        printBattleCardInfo(m_stats);
    }
    else if (m_effect == CardType::Heal)
    {
        printHealCardInfo(m_stats);
    }
    else if (m_effect == CardType::Buff)
    {
        printBuffCardInfo(m_stats);
    }
    else if (m_effect == CardType::Treasure)
    {
        printTreasureCardInfo(m_stats);
    }
}