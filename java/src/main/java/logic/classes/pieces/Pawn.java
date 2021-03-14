package logic.classes.pieces;

import logic.classes.board.Board;
import logic.classes.board.Spot;
import logic.classes.util.Move;
import logic.classes.util.MoveHistory;
import logic.enums.Color;
import logic.enums.PieceCode;

import javax.imageio.ImageIO;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Pawn extends Piece{

    private int direction;

    public Pawn(Color color, Spot spot){
        super(color, PieceCode.PAWN, spot);



        ///Pawn can only move forward & Pawn image color
        if(this.getColor() == Color.WHITE){
            this.direction = 1;
            this.imageName = "/White_Pawn.png";
        }
        else{
            this.imageName = "/Black_Pawn.png";
            this.direction = -1;
        }

        initializeImage();

    }

    public int getDirection() {
        return direction;
    }

    public void setDirection(int direction) {
        this.direction = direction;
    }

    @Override
    public List<Spot> getAttackedSpots() {
        List<Spot> attackedSpots = new ArrayList<>();
        if(this.spot.getX() > 0 && this.spot.getY() < 7){
            if(this.spot.getY() > 0){
                attackedSpots.add(Board.getSpot(this.getSpot().getX() - 1, this.getSpot().getY()+this.direction));
            }
            if(this.spot.getX() < 7){
                attackedSpots.add(Board.getSpot(this.getSpot().getX() + 1, this.getSpot().getY()+this.direction));
            }
        }

        return attackedSpots;
    }

    @Override
    public boolean canMove(Move move) {
        boolean result = false;
        Move lastMove = null;
        //check if it is the first move
        if(MoveHistory.moveHistory.size() > 0) lastMove = MoveHistory.moveHistory.get(MoveHistory.moveHistory.size()- 1);

        if(move.getCapturedPiece() == null || this.getColor() != move.getOriginPiece().getColor()){
            //Normal pawn move
            if(move.getEndSpot().getY()- move.getOriginSpot().getY() == this.direction && move.getOriginSpot().getX() == move.getEndSpot().getX()  && move.getCapturedPiece() == null) {
                result = true;
            }

            // 2 spot pawn move
            else if((move.getOriginSpot().getY() == 6 || move.getOriginSpot().getY() == 1) && (move.getEndSpot().getY() - move.getOriginSpot().getY()) == (2*this.direction) && move.getEndSpot().getX() == move.getOriginSpot().getX() && move.getCapturedPiece() == null){
                result = true;
            }

            //special kill
            else if(move.getCapturedPiece() == null && move.getEndSpot().getY()-move.getOriginSpot().getY() == this.direction && Math.abs(move.getOriginSpot().getX()-move.getEndSpot().getX()) == 1 && lastMove != null &&
                    lastMove.getOriginPiece().getPieceCode() == PieceCode.PAWN && Math.abs(lastMove.getEndSpot().getY() -lastMove.getOriginSpot().getY()) == 2 && lastMove.getEndSpot().getX() == move.getEndSpot().getX() &&
                    (lastMove.getEndSpot().getY() - (this.direction *(-1))) == move.getEndSpot().getY()){
                move.setCapturedPiece(lastMove.getOriginPiece());
                result = true;
            }

        }
        else{
            //normal kill
            if(move.getCapturedPiece() != null && move.getEndSpot().getY() - move.getOriginSpot().getY() == this.direction &&  Math.abs(move.getEndSpot().getX() - move.getOriginSpot().getX()) == 1){
                result = true;
            }
        }
        return result;
    }


}
