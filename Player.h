class Player{
char * name;
int level;
int force;
int maxHp;
int curHp;
int coins;

public:
//constractors
Player()=delete;
Player(const char *playerName,const int maxHp=100,const int force=5);
Player::Player(const Player *player);

//distractor
Player::~Player();

//oprators
Player &Player::operator=(const Player &player);

//methods
void Player::printInfo();
void Player::levelUp();
int Player::getLevel();
void Player::buff(const int buffSize);
};