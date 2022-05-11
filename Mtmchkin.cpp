#include "Mtmchkin.h"
#include <iostream>
static int cardsCounter;
static int totalCards;

Mtmchkin &Mtmchkin::operator=(const Mtmchkin &game)
{
    if (this == &game)
        return *this;
    delete &m_player;
    delete[] m_cards;
    m_player = game.m_player;
    for (int i = 0; i < totalCards; i++)
    {
        m_cards[i] = *(new Card(game.m_cards[i]));
    }
    m_gameStatus = game.m_gameStatus;
    return *this;
}

// constractors

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) : m_player(playerName, 100, 5)
{
    m_cards = new Card[numOfCards]();

    for (int i = 0; i <= numOfCards - 1; i++)
    {

        m_cards[i] = cardsArray[i];
    }
    m_gameStatus = GameStatus::MidGame;
    cardsCounter = 0;
    totalCards = numOfCards;
}

// distractors
Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}

// methods
void Mtmchkin::playNextCard()
{
    //std::cout << "cardcounter (" << cardsCounter << ")." << std::endl;
     
    m_cards[cardsCounter].printInfo();
    m_cards[cardsCounter].applyEncounter(m_player);
    if (cardsCounter >= totalCards - 1)
        cardsCounter = 0;
    else
        cardsCounter++;
    if (m_player.getLevel() == 10)
        m_gameStatus = GameStatus::Win;
    if (m_player.isKnockedOut())
    {
        m_gameStatus = GameStatus::Loss;
    }

    m_player.printInfo();
}

bool Mtmchkin::isOver()
{
    if (m_gameStatus == GameStatus::MidGame)
    {
        return false;
    }
    else
    {
        return true;
        delete this;
    }
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}
void Mtmchkin::runGame()
{
    while (!isOver())
    {

        playNextCard();
    }
    if (GameStatus() == GameStatus::Win)
    {
        std::cout << "The player defeated all monsters and achieved eternal glory!";
    }
}