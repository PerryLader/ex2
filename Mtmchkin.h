//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
 */
enum class GameStatus
{
    Win,
    Loss,
    MidGame
};

class Mtmchkin
{
public:
    Mtmchkin &operator=(const Mtmchkin &game);
    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
     */
    Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards);

    /*
     * defult constractor should not be allowed
     *
     */

    
    Mtmchkin() = delete;
    Mtmchkin(const Mtmchkin &game) = delete;

    
     /*
     * di'tor of the game:
     *
     * a diconstractor of Mtmchkin
     */
    ~Mtmchkin();

    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
     */
    void playNextCard();

    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver();

    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    void runGame();

private:
    Player m_player;
    Card *m_cards;
    GameStatus m_gameStatus;
};

#endif // EX2_GAME_H
