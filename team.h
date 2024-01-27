#include <vector>
#include "player.h"



class Team {

public :
	Team();
	std::string name;
	int totalRun;
	int totalWicket;
	int ballsBowled;
	std::vector<Player> players;

};
