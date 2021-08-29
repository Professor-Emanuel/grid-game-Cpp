#pragma once
#include<vector>
#include "Player.h"
#include "Item.h"
#include "Enemy.h"

namespace ProfEmanuel {
	class ObjCreator {
	private:
		std::vector<GridObject*> ObjPtrs;

		void DeleteAll() {
			for (GridObject* obj : ObjPtrs) {
				delete obj;
			}
		}

	public:
		void CreateObj(GridObjectType objType) {
			for (GridObject* obj : ObjPtrs) {
				if (obj->GetType() == objType) {
					throw "Object type already exists!";
				}
			}

			if (objType == GridObjectType::PLAYER) {
				Player* player = new Player();
				ObjPtrs.push_back(player);
			}
			else if (objType == GridObjectType::ENEMY) {
				Enemy* enemy = new Enemy();
				ObjPtrs.push_back(enemy);
			}
			else if (objType == GridObjectType::ITEM) {
				Item* item = new Item();
				ObjPtrs.push_back(item);
			}
		}

		GridObject* GetObj(GridObjectType targetType) {
			for (GridObject* obj : ObjPtrs) {
				if (obj->GetType() == targetType) {
					return obj;
				}
			}
			throw "Object type not found";
		}

		char GetSym(int x, int y) {
			for (GridObject* obj: ObjPtrs) {
				Vec2 pos = obj->GetPosition();
				if (pos.x == x && pos.y == y) {
					return obj->GetSymbol();
				}
			}

			//return default grid symbol if nothing matches
			return '.';
		}

		~ObjCreator()
		{
			std::cout << "Destroying objcreator!" << std::endl;
			DeleteAll();
		}

	};
}