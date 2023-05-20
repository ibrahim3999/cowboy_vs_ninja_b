#pragma once
#include"Team.hpp"

namespace ariel{

    class Team2 :public Team{


        public:
            Team2(Character*);
            void attack(Team* enemyTeam)override;


    };
}