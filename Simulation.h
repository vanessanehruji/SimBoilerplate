//
// Created by Vanessa Nehruji on 09/04/2017.
//

#ifndef FLUID_SPH_SIMULATION_H
#define FLUID_SPH_SIMULATION_H

#include <SFML/Graphics.hpp>

class Simulation {

public:
    Simulation();
    ~Simulation();
    void run();

private:
    void processEvents();
    void handleInput(sf::Keyboard::Key key, sf::Event event);
    void update(sf::Time elapsedTime);
    void render();

private:
    static const sf::Time TimePerFrame;
    double timeSinceStart;
    sf::RenderWindow mWindow;
    sf::ContextSettings settings;
};


#endif //FLUID_SPH_SIMULATION_H
