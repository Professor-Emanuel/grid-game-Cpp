#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "CharacterController.h"

namespace ProfEmanuel {
	class GameProcessor {
	private:
		Scene scene;
		Renderer renderer;
		CharacterController characterController;

	public:
		void Run() {
			scene.CreateObject(GridObjectType::PLAYER);
			scene.CreateObject(GridObjectType::ENEMY);
			scene.CreateObject(GridObjectType::ITEM);

			scene.GetObject(GridObjectType::PLAYER)->SetPosition(1, 4);
			scene.GetObject(GridObjectType::ITEM)->SetPosition(2, 2);
			scene.GetObject(GridObjectType::ENEMY)->SetPosition(6, 7);

			while (characterController.GetInputCharacter() != 'q') {
				renderer.AddEmptyLines(20);
				renderer.RenderObjectImage(scene);
				renderer.RenderScene(scene);

				characterController.MovePlayer(scene);
			}
		}
	};
}