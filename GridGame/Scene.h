#pragma once
#include "Grid.h"
#include "ObjCreator.h"

namespace ProfEmanuel {
	class Scene {
	private:
		Grid grid;
		ObjCreator objCreator;

	public:
		void CreateObject(GridObjectType objType) {
			objCreator.CreateObj(objType);
		}

		GridObject* GetObject(GridObjectType targetType) {
			return objCreator.GetObj(targetType);
		}

		Vec2 GetGridSize() {
			return grid.GetSize();
		}

		char GetSymbol(int x, int y) {
			return objCreator.GetSym(x, y);
		}

		Scene() {
			std::cout << "Creating scene!" << std::endl;
			grid.SetSize(12, 12);
		}

		~Scene() {
			std::cout << std::endl;
			std::cout << "Destroying scene!" << std::endl;
		}
	};

}