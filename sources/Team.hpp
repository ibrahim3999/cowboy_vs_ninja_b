#pragma once
#include<vector>
#include<iostream>
#include"Point.hpp"
#include"OldNinja.hpp"
#include"Ninja.hpp"
#include"Character.hpp"
#include"Cowboy.hpp"
#include"YoungNinja.hpp"
#include"TrainedNinja.hpp"

using namespace std;
namespace ariel{
    class Team{
        protected:
            vector<Character*> members;
            Character* captain;
            vector<Character*> captains;
            
        public:
            Team (Character*);
            ~Team();
            vector<Character*> & getTeam();//getter
            void add(Character*);//add characterin the team
            void remove(Character*);//add characterin the team
            virtual void attack(Team*);//attack other team 
            int stillAlive();//return number of charatersis alive in the team
            void print();
            int getTeamSize();
            // Check if the given character is already assigned as a captain in another team
            Character* getCaptain();
            void setCaptain(Character *);
            
            

        private:
            void isCaptainAlreadyAssigned(Character* captain) const;
            int attackRange;
            int teamSize;
            int teamMaxSize;


    };
}

