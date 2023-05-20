#pragma once
#include "Team.hpp"

namespace ariel{

    class SmartTeam : public Team{
        public:
            SmartTeam(Character*);
            void attack(Team * enemyTeam)override;  

    };
}