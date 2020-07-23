 #pragma once
 #include "FootSoldier.hpp"
 
 namespace WarGame{
 	
 	void FootSoldier::fire(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override{
            std::pair<int,int> target = this->closest_target(source,board);
            if(target.first==-1 && target.second==-1) return;

            board[target.first][target.second]->hp-=board[source.first][source.second]->dmg;
            if(board[target.first][target.second]->hp<=0){
                delete(board[target.first][target.second]);
                board[target.first][target.second]=nullptr;
            }

	}
}	
