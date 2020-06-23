#pragma once

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

struct SnakeSegment
{
	SnakeSegment(int x, int y) :position(x, y) {}
	sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction{None, Up, Down, Left, Right};

class Snake
{
public:
	Snake(int l_blockSize);
	~Snake();

	void SetDirection(Direction l_dir);
	int GetSpeed();
	sf::Vector2i GetPosition();
	Direction GetDirection();
	int GetLives();
	int GetScore();
	int IncreaseScore();
	bool HasLost();

	void Lose();
	void ToggleLost();
	void Extend();
	void Reset();
	void Move();

	void Tick();
	void Cut(int l_segments);
	void Render(sf::RenderWindow& l_window);

private:
	void CheckCollision();
	SnakeContainer m_snakeBody;
	int m_size;
	Direction m_dir;
	int m_speed;
	int m_lives;
	int m_score;
	int m_lost;
	sf::RectangleShape m_bodyRect;
};

