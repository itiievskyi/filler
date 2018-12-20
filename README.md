# Filler (42 School Project)
A visual battle between two algorithms on the different maps

* In this game, two players fight each other. They play one after another.
* The goal is to collect as many points as possible by placing the highest number of pieces on the the game board.
* The board is defined by X columns and N lines, it will then become X*N cells.
* At the beginning of each turn, player receives the game piece.
* A game piece is defined by X columns and N lines, so it will be X*N cells. Inside each game piece, will be included a shape of one or many cells.
* To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory).
* The shape must not exceed the dimensions of the board.
* When the game starts, the board already contains one shape.
* The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.

![Filler](/images/1.png)

### How to use
* git clone https://github.com/itiievskyi/filler.git ~/filler/
* cd ~/filler/
* make
* Usage: ./resources/filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time] **[| ./visual/visual]**
  * -t  --time           set timeout in second
  * -q  --quiet          quiet mode
  * -i  --interactive    interactive mode(default)
  * -p1 --player1        use filler binary as a first player
  * -p2 --player2        use filler binary as a second player
  * -f  --file           use a map file (required)
  * -s  --seed           use the seed number (initialization random) (man srand)
  * Using | ./visual/visual enables the ASCII visualization in your shell.

### Enjoy!
