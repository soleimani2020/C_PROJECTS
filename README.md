
Here's a detailed description of what this code does:
This code implements a Tic-Tac-Toe game for two players. The game allows players to alternately place their marks (X or O) on a 3x3 board until one player wins or the game ends in a draw. It includes functionalities for initializing the game board, displaying the board state, making moves, switching turns, checking for a winner, and determining a draw. 

Main Functions:
1. InitializeBoard: Initializes the 3x3 board by setting all positions to empty (EMPTY, represented as ' ').
3. DisplayBoard: Displays the current state of the game board in a formatted 3x3 grid with visual separators (| for columns and --+--+-- for rows).
4. Player_Switch: Switches the current player between 'X' and 'O'.
5. CheckWinningMoves: Checks if the current player has met one of the winning conditions (3 in a row, column, or diagonal).
6. CheckDraw: Determines if the game is a draw by checking if all cells are filled without any player meeting the winning condition.
7. PlayGame: Implements the main game loop where players alternately make moves until the game ends with a win or a draw.

