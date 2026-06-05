# Number Guessing Game

## Overview

Number Guessing Game is a console-based C++ application where players attempt to guess a randomly generated number within a limited number of attempts. The game provides multiple difficulty levels, hot/cold hints, guess history tracking, and a session scoreboard to enhance the gameplay experience.

---

## Features

### Multiple Difficulty Levels

The game offers four difficulty modes:

| Difficulty | Number Range | Attempts |
| ---------- | ------------ | -------- |
| Easy       | 1 - 50       | 9        |
| Medium     | 1 - 100      | 7        |
| Hard       | 1 - 200      | 6        |
| Very Hard  | 1 - 500      | 5        |

---

### Random Number Generation

A secret number is generated randomly at the start of every round using the C++ random number facilities.

---

### Input Validation

The game validates user input and handles:

* Empty input
* Non-numeric input
* Out-of-range values

This prevents crashes and ensures smooth gameplay.

---

### Hot and Cold Hint System

After every incorrect guess, the game provides proximity hints:

* BLAZING HOT
* VERY HOT
* HOT
* WARM
* COOL
* COLD
* FREEZING

These hints help players estimate how close they are to the secret number.

---

### Higher / Lower Guidance

The game also tells the player whether the secret number is:

* Higher than the current guess
* Lower than the current guess

This helps narrow the search range.

---

### Guess History

All previous guesses made during a round are displayed to the player, allowing better decision making.

Example:

Previous guesses:
25 38 42

---

### Remaining Attempts Bar

A visual progress bar shows the number of remaining attempts.

Example:

[######---]

---

### Session Scoreboard

The scoreboard stores results from all rounds played during the current session.

Information displayed:

* Difficulty Level
* Result (WIN / LOSS)
* Number of Guesses Used

---

### Round Summary

At the end of every round, a summary is displayed showing:

* Difficulty
* Result
* Attempts Used

---

## Concepts Used

This project demonstrates the use of:

* Classes
* Structures
* Vectors
* Functions
* Loops
* Conditional Statements
* String Handling
* Input Validation
* Random Number Generation
* Modular Programming
* Object-Oriented Programming Basics

---

## Project Structure

### Class: Difficulty

Stores information about each difficulty level.

Members:

* name
* maxNum
* maxGuesses
* flavour

---

### Structure: Record

Stores the result of a completed game.

Members:

* level
* guesses
* won

---

### Main Functions

#### banner()

Displays the game title and welcome message.

#### divider()

Prints decorative separator lines.

#### hotCold()

Generates hot/cold hints based on proximity to the secret number.

#### guessBar()

Displays remaining attempts using a progress bar.

#### showScoreboard()

Displays results from all completed rounds.

#### chooseDifficulty()

Allows the player to select a difficulty level.

#### playRound()

Contains the core game logic.

---


## Sample Gameplay

```text
====================================================
|      Welcome to the Number Guessing Game         |
====================================================

[P] Play   [S] Scores   [Q] Quit

Enter choice (1-4): 2

Range      : 1 - 100
Chances    : 7

Your guess : 50

--> Go HIGHER
--> [WARM] You are moving in the right direction.

Your guess : 75

--> Go LOWER
--> [VERY HOT] The answer is extremely close.
```

---

## Future Enhancements

Possible improvements:

* Score System
* Win Streak Tracking
* Save Scoreboard to File
* Multiplayer Mode
* Timed Challenge Mode
* Graphical User Interface (GUI)
* Difficulty Statistics

---

