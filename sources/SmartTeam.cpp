#include"SmartTeam.hpp"

namespace ariel{
    SmartTeam::SmartTeam(Character * leader):Team(leader){

    }
   void SmartTeam::attack(Team * enemyTeam) {
    // Sort the members of the team based on their abilities
    std::sort(members.begin(), members.end(), [](Character* a, Character* b) {
        // Compare the abilities of the characters
        if (a->getAbility() < b->getAbility()) {
            return true;
        } else if (a->getAbility() > b->getAbility()) {
            return false;
        }
        // If abilities are equal, sort based on their names
        return a->getName() < b->getName();
    });

    Team::attack(enemyTeam);

    
   }
}

