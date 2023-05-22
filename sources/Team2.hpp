#pragma once
#include"Team.hpp"

namespace ariel{

    class Team2 :public Team{


        public:
            Team2(Character*);
            void add(Character*)override;


    };
}
