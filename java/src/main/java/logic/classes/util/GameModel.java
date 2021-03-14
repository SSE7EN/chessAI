package logic.classes.util;

import logic.classes.board.Board;
import logic.classes.board.Spot;
import logic.enums.Color;
import ui.BoardPanel;
import ui.Square;

import java.util.Observable;

public class GameModel extends Observable {
    public static Board board;
    private BoardPanel boardPanel;

    private Player plays;

    private Player player1;
    private Player player2;

    public GameModel(String player1Name, String player2Name){
        this.player1 = new Player(player1Name, Color.WHITE);
        this.player2 = new Player(player2Name, Color.BLACK);
        this.plays = this.player1;
        this.player1.setPieces(Board.getPlayerPieces(player1));
        this.player1.recalculateAttackedSpots();
        this.player2.setPieces(Board.getPlayerPieces(player2));
        this.player2.recalculateAttackedSpots();

        this.boardPanel = new BoardPanel(this);
    }



    public void onMoveRequest(Square startSquare, Square endSquare){
        Spot startSpot = startSquare.getSpot();
        Spot endSpot = endSquare.getSpot();

        Move move = new Move(plays,startSpot, endSpot);

        if(startSpot.getPiece() != null && startSpot.getPiece().getColor() == plays.getColor()){
            if(MoveValidator.validateMoveBeforeMove(move)){
                executeMove(move);
            }
        }
    }

    private void executeMove(Move move){
        Board.executeMove(move);
        if(MoveValidator.validateMoveAfterMove(move,getSecondPlayer())){
            MoveHistory.moveHistory.add(move);
            boardPanel.executeMove(move);
            changePlayer();
        }
        else{
            Board.undoMove(move);
        }

    }

    private void changePlayer(){
        if(plays == player1) plays = player2;
        else  plays = player1;
    }


    public static Board getBoard() {
        return board;
    }

    public static void setBoard(Board board) {
        GameModel.board = board;
    }

    public Player getPlays() {
        return plays;
    }

    public void setPlays(Player plays) {
        this.plays = plays;
    }

    public Player getPlayer1() {
        return player1;
    }

    public void setPlayer1(Player player1) {
        this.player1 = player1;
    }

    public Player getPlayer2() {
        return player2;
    }

    public void setPlayer2(Player player2) {
        this.player2 = player2;
    }

    public Player getSecondPlayer(){
        Player player = null;

        if(plays == player1) player = player2;
        else  player = player1;

        return player;
    }

    public BoardPanel getBoardPanel() {
        return boardPanel;
    }

    public void setBoardPanel(BoardPanel boardPanel) {
        this.boardPanel = boardPanel;
    }
}
