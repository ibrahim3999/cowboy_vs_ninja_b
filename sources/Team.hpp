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

        public:
            Team();
            Team (Character*);
            ~Team();
            vector<Character*> & getTeam();//getter
            void add(Character*);//add characterin the team
            void remove(Character*);//add characterin the team
            void attack(Team*);//attack other team 
            int stillAlive();//return number of charatersis alive in the team
            void print();
            int getTeamSize();

        private:
            vector<Character*> members;
            int teamSize;
            int teamMaxSize;

    };
}

