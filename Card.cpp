#include "Card.h"

Card::Card(CardType type, const CardStats &stats) : m_effect(type), 
m_stats(stats.force, stats.hpLossOnDefeat, stats.cost, stats.heal, stats.buff, stats.loot)
{
}

static void handleBattleType(Player &player, int force, int loot, int hpLossOnDefeat){
if (player.getAttackStrength() >= force)
        {
            if (loot >= 0)
            {
                player.addCoins(loot);
            }
            player.levelUp();
            printBattleResult(true);
        }
        else
        {
            if (hpLossOnDefeat > 0)
            {
                player.damage(hpLossOnDefeat);
            }
            printBattleResult(false);
        }
}

void Card::applyEncounter(Player &player) const
{
    if (m_effect == CardType::Battle)
    {
        handleBattleType(player, m_stats.force, m_stats.loot, m_stats.hpLossOnDefeat);
    }
    else if (m_effect == CardType::Treasure)
    {
        if (m_stats.loot >= 0)
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