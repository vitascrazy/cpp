#include <ncurses.h>

class Player
{
private:
	int health;
	int max;
	int PlayerX;
	int PlayerY;
public:
	Player(int, int);
	void setHealth(int);
	void setPlayerX(int);
	void setPlayerY(int);
	void setPlayerHpMax(int);
	int getHealth();
	int getPlayerX();
	int getPlayerY();
	int getPlayerHpMax();
};

char Map[10][20] =
{
	"###################",
	"#@                #",
	"#   +             #",
	"#                 #",
	"#    +      +     #",
	"#                 #",
	"#    +            #",
	"#                 #",
	"###################"
};

int main()
{
	initscr();
	Player* player = new Player(50, 100);
	while (true)
	{
		if (player->getHealth() > player->getPlayerHpMax())
		{
			player->setHealth(player->getPlayerHpMax());
		}

		clear();
		refresh();

		for (int y=0; y<10; y++)
		{
			printw("%s\n", Map[y]);
		}

		refresh();

		printw("\nPlayerX: %i\n", player->getPlayerX());
		printw("PlayerY: %i\n", player->getPlayerY());
		printw("PlayerHP: %i / %i\n", player->getHealth(), player->getPlayerHpMax());

		for (int y=0; y<10; y++)
		{
			for (int x=0; x<20; x++)
			{
				switch (Map[y][x])
				{
					case '@':
					{
						if (getch() == KEY_UP)
						{
							int y2 = (y - 1);
							switch (Map[y2][x])
							{
								case ' ':
								{
									Map[y][x] = ' ';
									y--;
									Map[y2][x] = '@';
									break;
								}
								case '+':
								{
									Map[y][x] = ' ';
									y--;
									Map[y2][x] = '@';
									player->setHealth(player->getHealth());
									break;
								}
							}
						}
						else if (getch() == KEY_DOWN)
						{
							int y2 = (y + 1);
							switch (Map[y2][x])
							{
								case ' ':
								{
									Map[y][x] = ' ';
									y++;
									Map[y2][x] = '@';
									break;
								}
								case '+':
								{
									Map[y][x] = ' ';
									y++;
									Map[y2][x] = '@';
									player->setHealth(player->getHealth());
									break;
								}
							}
						}
						else if (getch() == KEY_LEFT)
						{
							int x2 = (x - 1);
							switch (Map[y][x2])
							{
								case ' ':
								{
									Map[y][x] = ' ';
									x--;
									Map[y][x2] = '@';
									break;
								}
								case '+':
								{
									Map[y][x] = ' ';
									x--;
									Map[y][x2] = '@';
									player->setHealth(player->getHealth());
									break;
								}
							}
						}
						else if (getch() == KEY_RIGHT)
						{
							int x2 = (x + 1);
							switch (Map[y][x2])
							{
								case ' ':
								{
									Map[y][x] = ' ';
									x++;
									Map[y][x2] = '@';
									break;
								}
								case '+':
								{
									Map[y][x] = ' ';
									x++;
									Map[y][x2] = '@';
									player->setHealth(player->getHealth());
									break;
								}
							}
						}
					}
					player->setPlayerX(x);
					player->setPlayerY(y);
					break;
				}
			}
		}
	}
	endwin();
	return 0;
}

Player::Player(int health, int max)
{
	this->health = health;
	this->max = max;
}

void Player::setHealth(int health)
{
	this->health = health;
}

void Player::setPlayerX(int x)
{
	this->PlayerX = x;
}

void Player::setPlayerY(int y)
{
	this->PlayerY = y;
}

void Player::setPlayerHpMax(int maxx)
{
	this->max = max;
}

int Player::getHealth()
{
	return this->health;
}

int Player::getPlayerX()
{
	return this->PlayerX;
}

int Player::getPlayerY()
{
	return this->PlayerY;
}

int Player::getPlayerHpMax()
{
	return this->max;
}

