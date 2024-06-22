# Virtual Cricket Game Application

This project is a virtual cricket game application built using C++ classes to demonstrate the concept of Object-Oriented Programming (OOP).

## Project Overview

The virtual cricket game application simulates a cricket match where players from two different team can bat, bowl, score runs, and take wickets.
The project is structured using different header files for game , players and teams to initialize runs and track game statistics.

## Project Structure

- **Player.h**: Contains the declaration of the Player class with attributes like player name, runs scored, wickets taken, etc.
- **Team.h**: Contains the declaration of the Team class which includes a collection of Player objects, team name, total runs scored, total wickets down, etc.
- **game.h**: Contains declaration of different attributes and methods to play the game.
- **cricket.cpp**: Implements the game logic for simulating a cricket match, including batting, bowling, scoring runs, and taking wickets. Contains definitions of                     all important methods.

## Getting Started

To run the virtual cricket game application, follow these steps:

1. Compile the source code using a C++ compiler.
2. Execute the compiled executable to start the virtual cricket game.
3. Follow the on-screen instructions to play the game and simulate a cricket match.

## Concepts Demonstrated

This project demonstrates the following Object-Oriented Programming (OOP) concepts in C++:

- Encapsulation: Classes like Player and Team encapsulate data and behaviors into objects.
- Inheritance: The Team class may inherit properties or methods from a parent class.
- Polymorphism: Players and Teams can exhibit different behaviors based on their roles in the game.
- Abstraction: The implementation hides complex details, allowing users to interact with simpler interfaces.
