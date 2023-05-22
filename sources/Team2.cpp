#include "Team2.hpp"
#include<limits>

namespace ariel{
  
 
  Team2::Team2(Character* leader): Team(leader){
  }
  void Team2::attack(Team* enemyTeam) {
    if(enemyTeam == nullptr){
      throw invalid_argument("null ptr enemy Team");
    }
    Character* attackingLeader = nullptr;
    Character* closestAliveEnemy = nullptr;

    // Find the attacking team's leader
    for (Character* character : members) {
        if (character->isAlive()) {
            attackingLeader = character;
            break;
        }
    }

    // If the attacking team has no living leader, the attack ends
    if (attackingLeader == nullptr) {
        std::cout << "The attacking team has no living leader. Attack failed." << std::endl;
        return;
    }

    // Find the closest alive enemy to the attacking leader
    double minDistance = std::numeric_limits<double>::max();
    for (Character* enemy : enemyTeam->getTeam()) {
        if (enemy->isAlive()) {
            double distance = attackingLeader->distance(enemy->getLocation());
            if (distance < minDistance) {
                minDistance = distance;
                closestAliveEnemy = enemy;
            }
        }
    }

    // If there are no alive enemies, or no alive members in the attacking team, the attack ends
    if (closestAliveEnemy == nullptr || stillAlive() == 0) {
        std::cout << "The attack cannot be executed. No alive enemies or attacking team members." << std::endl;
        return;
    }

    // Attack the closest alive enemy
    for (Character* attacker : members) {
        if (attacker->isAlive()) {
            if (dynamic_cast<Cowboy*>(attacker)) {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker);
                if (cowboy) {
                    if (cowboy->hasboolets()) {
                        // Shoot the enemy
                        cowboy->shoot(closestAliveEnemy);
                    } else {
                        // Reload weapon
                        cowboy->reload();
                    }
                } else {
                    std::cout << "Attacker is not a Cowboy. Cannot perform shooting action." << std::endl;
                }
               }
            }
            if (dynamic_cast<Ninja*>(attacker)) {
                Ninja* ninja = dynamic_cast<Ninja*>(attacker);
                if (ninja) {
                    if (attacker->distance(closestAliveEnemy->getLocation()) <= 1) {
                        // Perform a melee attack
                        ninja->slash(closestAliveEnemy);
                    } else {
                        // Move towards the enemy
                        ninja->move(closestAliveEnemy);
                    }
                } else {
                    std::cout << "Attacker is not a Ninja. Cannot perform attack action." << std::endl;
                }
            }
    }
    // Check if the closest enemy is defeated
    if (!closestAliveEnemy->isAlive()) {
        std::cout << "The closest enemy has been defeated." << std::endl;
    } else {
        std::cout << "The attack has been executed." << std::endl;
    }
}

  
  
}
