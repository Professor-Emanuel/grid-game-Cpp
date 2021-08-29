#pragma once
#include "Scene.h"
#include<iostream>
#include<vector>

namespace ProfEmanuel {
	class Renderer {
	public:
		void RenderObjectImage(Scene& scene) {
			Vec2 playerPosition = scene.GetObject(GridObjectType::PLAYER)->GetPosition();
			Vec2 itemPosition = scene.GetObject(GridObjectType::ITEM)->GetPosition();
			Vec2 enemyPosition = scene.GetObject(GridObjectType::ENEMY)->GetPosition();

			//player-item collision
			if (playerPosition == itemPosition) {
				//"R" makes the cout be as it is below
				std::cout << R"(
                           ___
                          ( ((
                           ) ))
  .::.                    / /(
 '  .-;-.-.-.-.-.-.-.-.-/| ((::::::::::::::::::::::::::::::::::::::::::::::.._
(  ( ( ( ( ( ( ( ( ( ( ( |  ))   -====================================-      _.>
 `  `-;-`-`-`-`-`-`-`-`-\| ((::::::::::::::::::::::::::::::::::::::::::::::''
  `::'                    \ \(
                           ) ))
                          (_((
)" << std::endl;
			}
			//player-enemy collision
			else if (playerPosition == enemyPosition) {
				std::cout << R"(
 __         __
/  \.-"""-./  \
\    -   -    /
 |   o   o   |
 \  .-'''-.  /
  '-\__Y__/-'
     `---`
)" << std::endl;
			}
		}

		void RenderScene(Scene& scene) {
			Vec2 gridSize = scene.GetGridSize();

			for (int col = 0; col < gridSize.y; col++) {
				for (int row = 0; row < gridSize.x; row++) {
					std::cout << scene.GetSymbol(row, col);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		void AddEmptyLines(int count) {
			for (int i = 0; i < count; i++) {
				std::cout << std::endl;
			}
		}
	};
}