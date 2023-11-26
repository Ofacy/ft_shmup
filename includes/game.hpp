#pragma once

#include <ncurses.h>
#include <iostream>
#include "game_object.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include <vector>
#include "collision_box.hpp"
#include "world.hpp"
#include "home.hpp"

#define	SCORE_MULTIPLIER 1
#define MAIN_WIN_COLOR 2

#define B_RED		"\033[1;31m"

int		get_key();

class Game
{
private:
	World			*world;
	Home			*home;

	CollisionBox	bounding_box;
	Position		offset;
	Position		dims;
	int				score = 0;
	int				tick = 0;
	std::string		exit_message;

	std::chrono::steady_clock::time_point	begin;

	Player					*player = nullptr;
	std::vector<GameObject*> objects;
	std::vector<GameObject*> objects_to_add;

	void	Update();
	void	Draw();

public:
	Game(CollisionBox bounding_box, Position pos, Position dims);
	~Game();

	void	Tick();
	bool	exit = false;
	int		lastScore = 0;

	std::vector<GameObject*>&	getObjects();

	Enemy*	getRandomEnemy();
	void	spawnEnemies();

	void	addObject(GameObject *obj);
	void	addScore(int score);

	CollisionBox&	getBounds();
	Position&		getOffset();
	Player*			getPlayer() const;
	Home*			getHome() const;
	void	printExit();
	void	setExitMessage(std::string message);
	void	startGame();
	void	stopGame();
	bool	checkDims(Position ndims);
};
