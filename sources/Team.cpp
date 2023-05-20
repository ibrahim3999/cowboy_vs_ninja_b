#include "Team.hpp"
#include <limits>
using namespace std;
namespace ariel{

   // Destructor
   
   Team::~Team() {
      for (Character* character : members) {
         delete character;
      }
      members.clear();
   }
   
   // Constructor with an initial character

   Team::Team(Character* captain):teamMaxSize(10),teamSize(0){
      add(captain);
   }


    // Getter for the team
   std::vector<Character*> & Team::getTeam() {
        return members;
   }
   Character* Team::getCaptain(){
      return captain;

   }
   void Team::setCaptain(Character * Captain){

   }

   // Add a character to the team
   void Team::add(Character* character) {
      if(teamSize == 10){
         throw runtime_error("ERORR YOUR YOUHAVE MAX CHARACTER");
      }

      if (teamSize < teamMaxSize) {
         members.push_back(character);
         teamSize++;
      }
   }
  // Remove a character from the team
   void Team::remove(Character* character) {
        for (auto it = members.begin(); it != members.end(); ++it) {
            if (*it == character) {
                members.erase(it);
                teamSize--;
                break;
         }
      }
   }

   void Team::print() {
      for (Character* character : members) {
            character->print();
      }
   }


   void Team::attack(Team* enemyTeam) {

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

            if (dynamic_cast<Ninja*>(attacker)) {
                Ninja* ninja = dynamic_cast<Ninja*>(attacker);
                if (ninja) {
                    if (attacker->distance(closestAliveEnemy->getLocation()) <= 1) {
                        // Ninja attacks
                        ninja->slash(closestAliveEnemy);
                     } else {
                        // Ninja moves towards the enemy
                        ninja->move(closestAliveEnemy);
                     }
                } else {
                    std::cout << "Attacker is not a Ninja. Cannot perform attack action." << std::endl;
                }
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
  
    // Check if any team members are still alive
    int Team::stillAlive() {
        int aliveCount = 0;
        for (Character* character : members) {
            if (character->isAlive()) {
                aliveCount++;
            }
        }
        return aliveCount;
    }

} // namespace ariel