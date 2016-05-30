abstract class Game {
 
    protected int playersCount;
 
    abstract void initializeGame();
 
    abstract void makePlay(int player);
 
    abstract boolean endOfGame();
 
    abstract void printWinner();
 
    /* A template method : */
    final void playOneGame(int playersCount) {
        this.playersCount = playersCount;
        initializeGame();
        int j = 0;
        while (!endOfGame()) {
            makePlay(j);
            j = (j + 1) % playersCount;
        }
        printWinner();
    }
}
 
//Now we can extend this class in order to implement actual games:
 
class Monopoly extends Game {
 
    /* Implementation of necessary concrete methods */
 
    void initializeGame() {
        // Initialize money
    }
 
    void makePlay(int player) {
        // Process one turn of player
    }
 
    boolean endOfGame() {
        // Return true of game is over according to Monopoly rules
    }
 
    void printWinner() {
        // Display who won
    }
 
    /* Specific declarations for the Monopoly game. */
 
    // ...
 
}
 
class Chess extends Game {
 
    /* Implementation of necessary concrete methods */
 
    void initializeGame() {
        // Put the pieces on the board
    }
 
    void makePlay(int player) {
        // Process a turn for the player
    }
 
    boolean endOfGame() {
        // Return true if in Checkmate or Stalemate has been reached
    }
 
    void printWinner() {
        // Display the winning player
    }
 
    /* Specific declarations for the chess game. */
 
    // ...
 
}

class X extends Game
{
}


class GameExample
{
	public static void main()
	{
		Game currentGame = new Chess();
		currentGame = new Monopoly();
		
		currentGame.playOneGame(numberofplayers);

		
	}

}