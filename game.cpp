#include "game.h"
using namespace std;



Game::Game() {

	playersPerTeam = 4;
	maxBall = 6;
	totalPlayer = 11;

	Players[0] = "Rohit";
	Players[1] = "Shubman";
	Players[2] = "Ishan";
	Players[3] = "Virat";
	Players[4] = "Surya";
	Players[5] = "Dhoni";
	Players[6] = "Hardik";
	Players[7] = "Jadeja";
	Players[8] = "Kuldeep";
	Players[9] = "Chahal";
	Players[10] = "Bumrah";

	isFirstInning = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

}

void Game::welcome() {

    cout << " _______________________________<CRICKET>_______________________________ " << endl;
    cout << "|                                                                       |" << endl;
    cout << "|==================Welcome to the Virtual Cricket Game==================|" << endl;
    cout << "|_______________________________________________________________________|" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << " _______________________________________________________________________ " << endl;
    cout << "|                                                                       |" << endl;
    cout << "|=============================INSTRUCTIONS==============================|" << endl;
    cout << "|_______________________________________________________________________|" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|1. Create 2 teams , Team A and Team B , of 4 players in each from given|" << endl;
    cout << "|   pool of 11 players.                                                 |" << endl;
    cout << "|2. Lead the Toss and choose Bat or Bowl for Toss winner.               |" << endl;
    cout << "|3. There will be 2 innings , each of 6 balls.                          |" << endl;
    cout << "|_______________________________________________________________________|" << endl;

}

void Game::showAllP() {
    cout << endl;
    cout << " _______________________________________________________________________ " << endl;
    cout << "|                                                                       |" << endl;
    cout << "|----------------------------Pool of Players----------------------------|" << endl;
    cout << "|_______________________________________________________________________|" << endl;
    cout << endl;
    for (int i=0;i<11;i++) {
        cout << "\t\t\t[" << i << "] " << Players[i] << endl;
    }
}

void Game::pause(){
   cin.clear();
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Game::takeIntegerInput() {
	int n;

	while (!(cin>>n)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input ! , Enter Integer: ";
	}
	return n;
}

bool Game::validateSelPyr(int index) {
	vector<Player> players;
	players = teamA.players;
	for (int i=0;i<players.size();i++) {
		if (players[i].id == index) {
			return false;
		}
	}
	players = teamB.players;
	for (int i=0;i<players.size();i++) {
		if (players[i].id == index) {
			return false;
		}
	}
	return true;
}

void Game::selectPlayers() {
		cout << endl;
	    cout << " ______________________________________________ " << endl;
		cout << "|                                              |" << endl;
		cout << "|========== Create Team-A and Team-B ==========|" << endl;
		cout << "|______________________________________________|" << endl;

		for (int i=0;i<playersPerTeam;i++) {
			labelA:
				cout << endl << "Select Player " << i+1 << " of Team-A ";
				int playerInputA = takeIntegerInput();

				if (playerInputA<0 || playerInputA>10) {
					cout << endl << "Please select index of the given Players !" << endl;
					goto labelA;
				}
				else if (!validateSelPyr(playerInputA)) {
					cout << endl << "This Player has already been selected , Please select again" << endl;
					goto labelA;
				}
				else {
					Player teamAPlayer;
					teamAPlayer.id = playerInputA;
					teamAPlayer.name = Players[playerInputA];
					teamA.players.push_back(teamAPlayer);
				}

			 labelB:
				 cout << endl << "Select Player " << i+1 << " of Team-B ";
				 int playerInputB = takeIntegerInput();

				 if (playerInputB<0 || playerInputB>10) {
					 cout << endl << "Please select index of the given Players !" << endl;
					 goto labelB;
				 }
				 else if (!validateSelPyr(playerInputB)) {
					 cout << endl << "This Player has already been selected , Please select again" << endl;
					 goto labelB;
				 }
				 else {
					 Player teamBPlayer;
					 teamBPlayer.id = playerInputB;
					 teamBPlayer.name = Players[playerInputB];
					 teamB.players.push_back(teamBPlayer);
				 }
		}
}

void Game::showTeamP() {
	vector<Player> APlayers = teamA.players;
	vector<Player> BPlayers = teamB.players;

	cout << endl << endl;
	cout << " ______________________________  ________________________________ " << endl;
	cout << "|                              ||                                |" << endl;
	cout << "|==========  Team-A  ==========||============  Team-B  ==========|" << endl;
	cout << "|______________________________||________________________________|" << endl;

	for (int i=0;i<playersPerTeam;i++) {
		cout << "\t[" << APlayers[i].id << "] " << APlayers[i].name << "\t\t\t\t" << "[" << BPlayers[i].id << "] " << BPlayers[i].name << endl;
	}
}

void Game::Toss() {
	 	 	cout << endl << endl;
		    cout << " ______________________________________________ " << endl;
			cout << "|                                              |" << endl;
			cout << "|================ Let's Toss ! ================|" << endl;
			cout << "|______________________________________________|" << endl << endl;

			cout << "Tossing the coin..." << endl << endl;
			usleep(2000000);

			srand(time(NULL));
			int randomValue = rand() % 2;

			switch(randomValue) {
			case 0 : cout << "Team-A won the toss !" << endl << endl;
					 TossChoice(teamA);
					 break;
			case 1 : cout << "Team-B won the toss !" << endl << endl;
					 TossChoice(teamB);
					 break;
			}
}

void Game::TossChoice(Team x) {

	cout << "Enter \'1\' to \'Bat\' or \'2\' to \'Bowl\' first " << endl;
	int tossInput = takeIntegerInput();
	switch(tossInput) {
	case 1 : cout << endl << x.name << " won the toss and elected to Bat first" << endl << endl;
	  	     if(x.name.compare("Team-A") == 0) {
	  	    	 battingTeam = &teamA;
	  	    	 bowlingTeam = &teamB;
	  	     }
	  	     else {
	  	    	 battingTeam = &teamB;
	  	    	 bowlingTeam = &teamA;
	  	     }
	  	     break;
	case 2 : cout << endl << x.name << " won the toss and elected to Bowl first" << endl << endl;
	     	 if(x.name.compare("Team-A") == 0) {
	     		 battingTeam = &teamB;
	     		 bowlingTeam = &teamA;
	     	 }
	     	 else {
	     		 battingTeam = &teamA;
	     		 bowlingTeam = &teamB;
	     	 }
	     	 break;
	default : cout << endl << "Please enter either 1 or 2 only !" << endl <<endl;
			  TossChoice(x);
	}
}

void Game::statFirstInn() {

	cout << endl << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "\t\t ==> FIRST INNINGS STARTS <== " << endl;
	cout << "-----------------------------------------------------" << endl << endl;
	isFirstInning = true;
	isSecondInning = false;
	initializePlayers();
	playInn();
}

void Game::initializePlayers() {

	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}

void Game::playInn() {

	for (int i = 0; i < maxBall; i++) {

		cout << "Press Enter to bowl...";
		pause();
		cout << "Bowling..." << endl;
		usleep(2000000);
		bat();

	    if (!validateInnScore()) {
	    	break;
	    }
	}
}

void Game::bat() {

	srand(time(NULL));
	int runsScored = rand() % 7;

	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRun = battingTeam->totalRun + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->ballsBowled = bowlingTeam->ballsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

    if (runsScored != 0) {
    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
    	showGameScorecard();
    } else {
    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

    	battingTeam->totalWicket = battingTeam->totalWicket + 1;
    	bowler->wicketTaken = bowler->wicketTaken + 1;

    	showGameScorecard();

    	int nextPlayerIndex = battingTeam->totalWicket;
    	batsman = &battingTeam->players[nextPlayerIndex];
    }
}

bool Game::validateInnScore() {

	if (isFirstInning) {

		if (battingTeam->totalWicket == playersPerTeam || bowlingTeam->ballsBowled == maxBall) {

			cout << "-----------------------------------------------------" << endl;
			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl;
			cout << "-----------------------------------------------------" << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRun << " - "
					<< battingTeam->totalWicket << " (" << bowlingTeam->ballsBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRun + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}
    } else if (isSecondInning) {

    	if (battingTeam->totalWicket == playersPerTeam || bowlingTeam->ballsBowled == maxBall) {

    			cout << "-----------------------------------------------------" << endl;
    			cout << "\t\t ||| SECOND INNINGS ENDS ||| " << endl;
    			cout << "-----------------------------------------------------" << endl << endl;

    			cout << battingTeam->name << " " << battingTeam->totalRun << " - "
    					<< battingTeam->totalWicket << " (" << bowlingTeam->ballsBowled
    					<< ")" << endl;

    			return false;
    		}
    }

	return true;
}

void Game::swapInning() {
	Team *swap;
	swap = battingTeam;
	battingTeam = bowlingTeam;
	bowlingTeam = swap;
}

void Game::statSecondInn() {

	cout << endl << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "\t\t ==> SECOND INNINGS STARTS <== " << endl;
	cout << "-----------------------------------------------------" << endl << endl;
	isFirstInning = false;
	isSecondInning = true;

	swapInning();
	initializePlayers();
	playInn();
}

void Game::showGameScorecard() {

    cout << "--------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << "  " << battingTeam->totalRun << " - "
      << battingTeam->totalWicket << " (" << bowlingTeam->ballsBowled << ") | " << batsman->name
      << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
	  << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketTaken << "\t" << endl;

    cout << "--------------------------------------------------------------------------" << endl << endl;
}

void Game::matchResult() {
	if (teamA.totalRun > teamB.totalRun) {
		cout << endl;
		cout << " ________________________________________ " << endl;
		cout << "|                                        |" << endl;
		cout << "|------------Team-A is Winner------------|" << endl;
		cout << "|________________________________________|" << endl;
		cout << "\n\t ||| Match Ends |||" << endl;
	}
	else if (teamA.totalRun < teamB.totalRun) {
		cout << endl;
		cout << " ________________________________________ " << endl;
		cout << "|                                        |" << endl;
		cout << "|------------Team-B is Winner------------|" << endl;
		cout << "|________________________________________|" << endl;
		cout << "\n\t ||| Match Ends |||" << endl;
	}
	else {
		cout << endl << endl;
		cout << " ________________________________________ " << endl;
		cout << "|                                        |" << endl;
		cout << "|---------------Match-Draw---------------|" << endl;
		cout << "|________________________________________|" << endl;
		cout << "\n\t ||| Match Ends |||" << endl;
	}
}

void Game::matchSummary() {
	cout << endl;
	cout << teamA.name << " " << teamA.totalRun << "-" << teamA.totalWicket << " (" << teamB.ballsBowled << ")" << endl;
	cout << " ______________________________________________ " << endl;
	cout << "|  PLAYER     |     BATTING      |    BOWLING  |" << endl;
	cout << "|_____________|__________________|_____________|" << endl;
	for (int i=0;i<4;i++) {
	cout << "| " << teamA.players[i].name << "    \t    " << teamA.players[i].runsScored << "(" << teamA.players[i].ballsPlayed << ")" << "   \t   " << teamA.players[i].ballsBowled << "-" << teamA.players[i].runsGiven << "-" << teamA.players[i].wicketTaken << "  " << endl;
	cout << "|______________________________________________|" << endl;
	}

	cout << endl;
	cout << teamB.name << " " << teamB.totalRun << "-" << teamB.totalWicket << " (" << teamA.ballsBowled << ")" << endl;
	cout << " ______________________________________________ " << endl;
	cout << "|  PLAYER     |     BATTING      |    BOWLING  |" << endl;
	cout << "|_____________|__________________|_____________|" << endl;
	for (int i=0;i<4;i++) {
	cout << "| " << teamB.players[i].name << "    \t    " << teamB.players[i].runsScored << "(" << teamB.players[i].ballsPlayed << ")" << "     \t     " << teamB.players[i].ballsBowled << "-" << teamB.players[i].runsGiven << "-" << teamB.players[i].wicketTaken << "  " << endl;
	cout << "|______________________________________________|" << endl;
	}

}
