# TicTacToe Engine (C++)

A modular console-based TicTacToe engine implemented in C++ using object-oriented design and strict separation of concerns.  
The system isolates board state management from gameplay control, enabling clear abstraction, testability, and extensibility.

This project demonstrates core software engineering principles including encapsulation, responsibility-driven class design, and deterministic game-state evaluation.

---

## System Architecture

The application is structured around two primary components with clearly defined responsibilities.

### Game Controller — `TicTacToeGame`
Manages gameplay flow and player interaction.

Responsibilities:
- Turn management
- Main game loop
- Player input handling
- Delegation of moves to board
- Game termination control
- User feedback

This class represents the **control layer** of the system.

---

### Board Engine — `TicTacToeBoard`
Encapsulates the full game state and rule logic.

Responsibilities:
- Board representation
- Move validation
- Mark placement
- Win detection
- Draw detection
- Board rendering

This class represents the **domain logic layer**.

All rule evaluation is contained here to ensure deterministic and testable behavior.

---

### Design Rationale

The system enforces separation between:

| Concern | Component |
|------|-----------|
| Game state representation | Board |
| Rule enforcement | Board |
| Turn sequencing | Game |
| User interaction | Game |

Benefits of this design:

- High cohesion within classes
- Low coupling between components
- Independent testing of game logic
- Reusable board engine
- Easy addition of AI players or GUI frontends
- Clear responsibility boundaries

This mirrors real-world game engine architecture where state and control layers are decoupled.

---

## Class Relationship
User Input
↓
TicTacToeGame (control flow)
↓
TicTacToeBoard (state + rules)
↓
Game Result


The game controller never directly manipulates board internals — it interacts through a defined interface.

---

## Testing Strategy

Game logic and gameplay control are tested independently.

Test modules validate:

- Legal and illegal move handling
- Win condition detection
- Draw state detection
- Turn sequencing correctness
- State transitions

Separating rule logic from control flow allows deterministic testing of board behavior without running full gameplay loops.

---

## Features

- Two-player turn-based gameplay
- Input validation with rejection of illegal moves
- Automatic win detection across rows, columns, and diagonals
- Draw detection
- Deterministic game-state evaluation
- Modular object-oriented architecture
- Independent logic testing

---

## Engineering Concepts Demonstrated

- Object-oriented design
- Encapsulation and abstraction
- Separation of concerns
- Responsibility-driven class design
- State machine reasoning
- Deterministic rule evaluation
- Modular architecture
- Testable system design

---

## Build and Run

### g++ (Linux / macOS / MinGW)

Compile:
```bash
g++ TicTacToeBoard.cpp TicTacToeGame.cpp main.cpp -o tictactoe
./tictactoe
```
Visual Studio (MSVC)

Open project solution

Build solution

Run executable
TicTacToe/
│
├── TicTacToeBoard.hpp      # Board interface
├── TicTacToeBoard.cpp      # Board implementation
├── TicTacToeGame.hpp       # Game controller interface
├── TicTacToeGame.cpp       # Game controller implementation
│
├── TestTicTacToeBoard.cpp  # Board logic tests
├── TestTicTacToeGame.cpp   # Gameplay flow tests
│
├── README.md
└── .gitignore

Example Gameplay
 X | O | X
-----------
 O | X |  
-----------
   |   | O
Extensibility Roadmap

The architecture supports straightforward expansion.

Planned enhancements:

Minimax AI opponent

Alpha-beta pruning optimization

Graphical interface (Qt / SDL / web frontend)

Persistent match history

Configurable board sizes

Network multiplayer

Unit test framework integration (GoogleTest)

CMake build system

Why This Project Exists

This project was developed to practice building a system that:

cleanly separates domain logic from control logic

remains testable at the component level

mirrors real software architecture patterns

scales without structural refactoring

Rather than focusing only on gameplay, the emphasis is on engineering structure and correctness.

Author

Yilan Ruan
GitHub: https://github.com/YilanRuan


