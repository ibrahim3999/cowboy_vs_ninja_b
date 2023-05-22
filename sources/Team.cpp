#include "Team.hpp"
#include <limits>
#include <algorithm>
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
    Team::Team(Character* captain) : teamMaxSize(10), teamSize(0), captain(captain) {
        if (captain == nullptr) {
            throw std::invalid_argument("NULL POINTER");
        }
        else if( captain->getJoinedTeam()){
            throw runtime_error(" Error Captian is Already in Ateam");
        }

        add(captain);
      
    }

    std::vector<Character*> Team::getTeam() {
        return members;
    }

    bool Team::getMember() {
        return isMember;
    }

    void Team::add(Character* character) {
        if (character == nullptr) {
            throw std::runtime_error("NULL POINTER");
        }
        if (teamSize >= 10) {
            throw std::runtime_error("ERROR: YOUR TEAM HAS REACHED THE MAXIMUM CHARACTER LIMIT");
        }else if( character->getJoinedTeam()){
            throw runtime_error(" Error Captian is Already in Ateam");
        }
        members.push_back(character);
        teamSize++;
        character->setJoinedteam(); 
        sortCowboysFirst(members);
        
    }
    void Team::sortCowboysFirst(vector<Character*>& characters) {
        sort(characters.begin(), characters.end(), [](Character* character1, Character* character2) {
            Cowboy* cowboy1 = dynamic_cast<Cowboy*>(character1);
            Cowboy* cowboy2 = dynamic_cast<Cowboy*>(character2);
            Ninja* ninja1 = dynamic_cast<Ninja*>(character1);
            Ninja* ninja2 = dynamic_cast<Ninja*>(character2);

            // Sort Cowboys before Ninjas
            if (cowboy1 && !cowboy2) {
                return true;
            } else if (!cowboy1 && cowboy2) {
                return false;
            } else {
                return false;
            }
        });
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

        if (enemyTeam == nullptr) {
            throw std::invalid_argument("Null pointer to enemy team");
        }else if(this==enemyTeam){
            throw runtime_error("cant attack yourself ");
        }
        else if (stillAlive()==0) {
            throw std::runtime_error("The team is dead.");
        }
        else if (enemyTeam->stillAlive() == 0) {
            throw std::runtime_error("The attacking team has been defeated.");
        }
        
        Character* closestEnemy = nullptr;

        if(!this->captain->isAlive()){

            // Find the closest alive teammate and appoint them as the new captain
            double minTeammateDistance = std::numeric_limits<double>::max();
            Character* closestTeammate = nullptr;
            for (Character* teammate : members) {
                if (teammate != captain && teammate->isAlive()) {
                    double distance = captain->distance(teammate->getLocation());
                    if (distance < minTeammateDistance) {
                        minTeammateDistance = distance;
                        closestTeammate = teammate;
                    }
                }
            }
            if (closestTeammate != nullptr) {
                enemyTeam->setCaptain(closestTeammate);
            }else{
                return;
            }
        }
        
        if(closestEnemy==nullptr || !closestEnemy->isAlive())
        {
            // Find the closest alive enemy to the attacking captian
            double minDistance = std::numeric_limits<double>::max();
            for (Character* enemy : enemyTeam->getTeam()) {
                if (enemy->isAlive()) {
                    double distance = this->captain->distance(enemy->getLocation());
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestEnemy = enemy;
                    }
                }
            }

        }
        // If there are no alive enemies or no alive members in the attacking team, the attack ends
        if (closestEnemy == nullptr ) {
        //throw std::invalid_argument("Null pointer to enemy team");
        return;
        }

        // Attack the closest alive enemy
        for (Character* attacker : members) {
            if (attacker->isAlive() && closestEnemy->isAlive() ){

                if ( Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)) {
                    
                    if (cowboy->hasboolets()) {
                            // Shoot the enemy
                            cowboy->shoot(closestEnemy);
                    } else if( !cowboy->hasboolets() ){
                        // Reload weapon
                        cowboy->reload();
                    }    
                }
                if( Ninja *ninja = dynamic_cast<Ninja*>(attacker)){
                
                    if(ninja->distance(closestEnemy->getLocation())<1 && closestEnemy->isAlive()){
                        ninja->slash(closestEnemy);
                        }else{
                            ninja->move(closestEnemy);
                        }
                } 
                
            }
            if(closestEnemy!=nullptr && !enemyTeam->getCaptain()->isAlive()){
                Character* closest = nullptr;
                double minDistance = std::numeric_limits<double>::max();
                for (Character* enemy : enemyTeam->getTeam()) {
                    if ( closestEnemy != enemy && enemy->isAlive()) {
                        double distance = closestEnemy->distance(enemy->getLocation());
                        if (distance < minDistance) {
                            minDistance = distance;
                            closest = enemy;

                            enemyTeam->setCaptain(closest); 
                        }
                    }
                }
            }
            if((!this->getCaptain()->isAlive())){
            
                Character* closest = nullptr;
                double minDistance = std::numeric_limits<double>::max();
                for (Character* member : members){
                    if(member!=captain){
                        double distance = captain->distance(member);
                        if (distance < minDistance) {
                            minDistance = distance;
                            closest = member;
                            this->setCaptain(closest); 
                        }
                    }
                }
            }
            
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

void Team::setCaptain(Character * capt){
   captain=capt;
}

Character * Team::getCaptain(){
   return captain;
}
   


} // namespace ariel
