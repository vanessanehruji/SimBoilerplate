//
// Created by Vanessa Nehruji on 09/04/2017.
//

#include "Simulation.h"

const sf::Time Simulation::TimePerFrame = sf::seconds(1.f/60.f);

Simulation::Simulation() : settings(0, 0, 8, 1, 1, sf::ContextSettings::Attribute::Default, false),
                           mWindow(sf::VideoMode(800, 600), "Physics Engine"),
                           timeSinceStart(0.0)
{

}

Simulation::~Simulation() {

}

void Simulation::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        render();
    }
}

void Simulation::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch(event.type){
            case sf::Event::KeyPressed:
                handleInput(event.key.code, event);
                break;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Simulation::handleInput(sf::Keyboard::Key key, sf::Event event) {

}

void Simulation::update(sf::Time elapsedTime) {
    //update here
    timeSinceStart += elapsedTime.asSeconds();
}

void Simulation::render() {
    mWindow.clear();
    //render here
    mWindow.display();
}