#include "Mtmchkin.h"

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

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards)
{

    m_player = *(new Player(playerName, 100, 5));
    for (int i = 0; i < numOfCards; i++)
    {
        m_cards[i] = *(new Card(cardsArray[i]));
    }
    m_gameStatus = GameStatus::MidGame;
    cardsCounter = 0;
    totalCards = numOfCards;
}

// methods
void Mtmchkin::playNextCard()
{
    m_cards[cardsCounter].applyEncounter(m_player);
    if (cardsCounter == totalCards - 1)
        cardsCounter = 0;
    else
        cardsCounter++;
}

bool Mtmchkin::isOver()
{
    if (m_gameStatus == GameStatus::MidGame)
    {
        return false;
    }
    else
        return true;
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
        if (m_player.getLevel() == 10)
            m_gameStatus = GameStatus::Win;
        if (m_player.isKnockedOut())
        {
            m_gameStatus = GameStatus::Loss;
        }
        m_player.printInfo();
    }
    if (GameStatus() == GameStatus::Win)
    {
        std::cout << "The player defeated all monsters and achieved eternal glory!";
    }
}