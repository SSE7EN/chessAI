package ui;

import logic.classes.board.Board;
import logic.classes.util.GameModel;
import logic.classes.util.Move;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.Observable;
import java.util.Observer;
import java.util.List;

public class BoardPanel extends JPanel implements MouseListener, Observer {

    private Square[][] board;
    private Square startSquare = null;
    private Square endSquare = null;
    private static GameModel gameModel;


    public BoardPanel(GameModel gameModel){
        this.board = new Square[Board.getBoardYDimension()][Board.getBoardXDimension()];
        this.gameModel = gameModel;

        this.addMouseListener(this);
        initializeBoard();

        gameModel.addObserver(this);
    }

    public void initializeBoard(){
        setLayout(new GridLayout(8, 8, 0, 0));

        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {

                board[y][x] = new Square(x,y,gameModel.board.getSpot(x,y));
                this.add(board[y][x]);
            }
        }

        this.setPreferredSize(new Dimension(400, 400));
        this.setMaximumSize(new Dimension(400, 400));
        this.setMinimumSize(this.getPreferredSize());
        this.setSize(new Dimension(400, 400));

    }

    public void selectStartSquare(Square square){
        if(this.startSquare !=null){
            //unhighlight previous selected square
            this.startSquare.highlightSquare();
        }
        //highlight selected square
        this.startSquare = square;
        this.startSquare.highlightSquare();


    }
    public void selectEndSquare(Square square){
        this.endSquare = square;

    }

    public void submitMoveRequest(){
        gameModel.onMoveRequest(this.startSquare, this.endSquare);
    }

    public void executeMove(Move move){
        repaintMove(move);
        newMove();
    }

    private void newMove(){
        this.startSquare.highlightSquare();
        this.startSquare = null;
        this.endSquare = null;
    }

    private void repaintMove(Move move){
        List<Square> temp = getSquareFromMoveForRepaint(move);
        repaintSquares(temp);
    }

    private List<Square> getSquareFromMoveForRepaint(Move move){
        List<Square> repaintSquareList = new ArrayList<>();
        if(move.getOriginSpot() != null){
            Square temp = getSquare(move.getOriginSpot().getX(),move.getOriginSpot().getY());
            repaintSquareList.add(temp);
        }
        if(move.getEndSpot() != null){
            Square temp = getSquare(move.getEndSpot().getX(),move.getEndSpot().getY());
            repaintSquareList.add(temp);

            //special pawn kill
            if(move.getCapturedPiece() != null && move.getEndSpot().getX() == move.getCapturedPiece().getSpot().getX() && move.getEndSpot().getY() != move.getCapturedPiece().getSpot().getY()){
                temp = getSquare(move.getCapturedPiece().getSpot().getX(),move.getCapturedPiece().getSpot().getY());
                repaintSquareList.add(temp);
            }
        }


        return repaintSquareList;
    }

    private void repaintSquares(List<Square> squareList){
        for (Square sq: squareList) {
            sq.repaint();
        }
    }

    private Square getSquare(int x, int y){
        Square result = null;
        if(x < Board.getBoardXDimension() && y< Board.getBoardYDimension() && x >= 0 && y >= 0){
            result =  board[y][x];
        }
        return result;
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        Square square = (Square) getComponentAt(e.getX(), e.getY());

        //select start square
        if(startSquare == null){
            selectStartSquare(square);
        }
        else{
            //change selected start square
            if(square.getSpot().getPiece() != null && square.getSpot().getPiece().getColor() == gameModel.getPlays().getColor()){
                selectStartSquare(square);
            }
            if(square.getSpot().getPiece() == null || square.getSpot().getPiece().getColor() != gameModel.getPlays().getColor()){
                selectEndSquare(square);
                submitMoveRequest();
            }

        }







    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    @Override
    public void update(Observable o, Object arg) {

    }
}
