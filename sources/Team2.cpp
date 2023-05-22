#include "Team2.hpp"
#include<limits>

namespace ariel{
  
 
  Team2::Team2(Character* leader): Team(leader){
    
  }
  void Team2::add(Character* character) {
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
        
    }
}
