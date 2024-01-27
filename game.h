#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <limits>
#include "team.h"



class Game {

public:
	Game();
	int playersPerTeam;
	int maxBall;
	int totalPlayer;
	std::string Players[11];
	bool isFirstInning;
	bool isSecondInning;
	Team teamA,teamB;
	Team *battingTeam , *bowlingTeam;
	Player *batsman , *bowler;

	void welcome();
	void showAllP();
	void pause();
	int takeIntegerInput();
	void selectPlayers();
	bool validateSelPyr(int);
	void showTeamP();
	void Toss();
	void TossChoice(Team);
	void statFirstInn();
	void statSecondInn();
	void swapInning();
	void initializePlayers();
	void playInn();
	void bat();
	bool validateInnScore();
	void showGameScorecard();
	void matchResult();
	void matchSummary();

};
