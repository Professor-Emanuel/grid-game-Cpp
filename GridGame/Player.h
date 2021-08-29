#pragma once
#include "GridObject.h"

namespace ProfEmanuel {
	class Player :public GridObject {
	public:
		Player() {
			std::cout << "Player created! " << std::endl;
			objectType = GridObjectType::PLAYER;
			symbol = 'p';
		}
	};
}