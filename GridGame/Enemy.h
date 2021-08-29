#pragma once
#include "GridObject.h"

namespace ProfEmanuel {
	class Enemy :public GridObject {
	public:
		Enemy() {
			std::cout << "Creating Enemy! " << std::endl;
			objectType = GridObjectType::ENEMY;
			symbol = 'e';
		}
	};
}