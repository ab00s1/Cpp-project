#include "game.h"
using namespace std;



int main() {

	Game game;
	game.welcome();
	cout << "\nPress <Enter> to continue";
	game.pause();
	game.showAllP();
	game.selectPlayers();
	game.showTeamP();
	game.pause();
	game.Toss();
	game.statFirstInn();

	cout << "\nPress <Enter> to start 2nd Inning !";
	game.pause();
	game.statSecondInn();
	cout << "\n........Result of Match........\n";
	usleep(3000000);
	game.matchResult();
	game.matchSummary();

	return 0;
}
