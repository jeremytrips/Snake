#include "Game.h"
#include <iostream>

Game::Game(): m_window("Chapter 2", sf::Vector2u(800, 600)),
m_world(sf::Vector2u(800, 600)),
m_snake(m_world.GetBlockSize())
{
    //m_window.GetRenderWindow()->setFramerateLimit(60);
}

Game::~Game() 
{
}

void Game::HandleInput()
{
    std::string dir;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
        && m_snake.GetDirection() != Direction::Down)
    {
        dir = "UP";
        m_snake.SetDirection(Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
        && m_snake.GetDirection() != Direction::Up)
    {
        dir = "DOWN";
        m_snake.SetDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        && m_snake.GetDirection() != Direction::Right)
    {
        dir = "LEFT";
        m_snake.SetDirection(Direction::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        && m_snake.GetDirection() != Direction::Left)
    {
        dir = "Right";
        m_snake.SetDirection(Direction::Right);
    }
}

void Game::Render() {
    m_window.BeginDraw();
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}

Window* Game::GetWindow()
{
    return &m_window;
}

sf::Time Game::GetElapsed()
{
    return m_elapsed;
}

void Game::RestartClock()
{
    m_elapsed += m_clock.restart();
}

void Game::Update() {
    float timestep = 1.0f / m_snake.GetSpeed();
    m_window.Update();
    if (m_elapsed.asSeconds() >= timestep) {
        std::cout << "bui" << std::endl;
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsed -= sf::seconds(timestep);
        if (m_snake.HasLost()) {
            m_snake.Reset();
        }
    }
}