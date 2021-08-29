#pragma once
#include "Scene.h"
#include "PlayerInput.h"

namespace ProfEmanuel {
	class CharacterController {
	private:
		PlayerInput playerInput;
		char inputChar = '0';

	public:
		char GetInputCharacter() {
			return inputChar;
		}

		void MovePlayer(Scene& scene) {
			inputChar = playerInput.GetInput();

			if (inputChar == 'w') {
				scene.GetObject(GridObjectType::PLAYER)->MoveWest();
			}
			else if (inputChar == 'e') {
				scene.GetObject(GridObjectType::PLAYER)->MoveEast();
			}
			else if (inputChar == 'n') {
				scene.GetObject(GridObjectType::PLAYER)->MoveNorth();
			}
			else if (inputChar == 's') {
				scene.GetObject(GridObjectType::PLAYER)->MoveSouth();
			}
		}
	};
}
