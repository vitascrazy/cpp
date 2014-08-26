// Game version 2

#include <iostream>
#include <ncurses.h>

struct Player {
	int health, maxHealth, x, y;
	Player(int h, int mh) : health(h), maxHealth(mh), x(-1), y(-1) {}
	void heal(int hp) {
		health += hp;
		if (health>maxHealth) { health = maxHealth; }
	}
};

const char SYMBOL_EMPTY = ' ';
const char SYMBOL_PLAYER = '@';
const char SYMBOL_WALL = '#';
const char SYMBOL_HP_BOOST_5 = '+';
const int MapDy = 10;
const int MapDx = 20;
char Map[10][21] = {
	"###################\0",
	"#                 #\0",
	"#   +             #\0",
	"#                 #\0",
	"#    +      +     #\0",
	"#                 #\0",
	"#    +            #\0",
	"#                 #\0",
	"###################\0"
};

bool isValidPos(int y, int x) { return (x>=0 && x<MapDx && y>=0 && y<MapDy); }

bool movePlayer(Player &player, int y, int x) {
	if (!isValidPos(y, x)) { return false; }

	char ch = Map[y][x];

	if (ch == SYMBOL_HP_BOOST_5) {
		player.heal(5);
	} else if (ch != SYMBOL_EMPTY) {
		return false;
	}

	if (isValidPos(player.y, player.x)) {
		Map[player.y][player.x] = SYMBOL_EMPTY;
	}
	player.y = y;
	player.x = x;
	Map[player.y][player.x] = SYMBOL_PLAYER;
	return true;
}

void showMap() {
	for (int y=0; y<MapDy; y++) {
		printw("%s\n", Map[y]);
	}
	refresh();
}

void showPlayer(Player &player) {
	printw("\nPlayerX: %i\n", player.x);
	printw("PlayerY: %i\n", player.y);
	printw("PlayerHP: %i / %i\n", player.health, player.maxHealth);
}

void gameLoop() {
	Player player(50, 100);
	movePlayer(player, 2, 2);

	while (true) {
		clear();
		showMap();
		showPlayer(player);
		refresh();

		int ch = getch();
		bool updateDisplay = false;
		if (ch == KEY_UP) {
			updateDisplay = movePlayer(player, player.y-1, player.x);
		} else if (ch == KEY_DOWN) {
			updateDisplay = movePlayer(player, player.y+1, player.x);
		} else if (ch == KEY_LEFT) {
			updateDisplay = movePlayer(player, player.y, player.x-1);
		} else if (ch == KEY_RIGHT) {
			updateDisplay = movePlayer(player, player.y, player.x+1);
		} else if (ch == 27) {
			break;
		}
	}
}

int main()
{
	keypad(initscr(), 1);
	curs_set(0);
	gameLoop();
	endwin();

	return 0;
}

