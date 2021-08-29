#pragma once
#include "GridObject.h"

namespace ProfEmanuel {
	class Item :public GridObject {
	public:
		Item() {
			std::cout << "Creating Item! " << std::endl;
			objectType = GridObjectType::ITEM;
			symbol = 'i';
		}
	};
}