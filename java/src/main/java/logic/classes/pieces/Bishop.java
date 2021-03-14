package logic.classes.pieces;

import logic.classes.board.PossibleMoves;
import logic.classes.board.Spot;
import logic.classes.util.Move;
import logic.enums.Color;
import logic.enums.PieceCode;

import java.util.List;

public class Bishop extends Piece{

    public Bishop(Color color, Spot spot){
        super(color, PieceCode.PAWN, spot);



        ///Pawn can only move forward & Pawn image color
        if(this.getColor() == Color.WHITE){
            this.imageName = "/White_Bishop.png";
        }
        else{
            this.imageName = "/Black_Bishop.png";
        }

        initializeImage();

    }

    @Override
    public List<Spot> getAttackedSpots() {
        return PossibleMoves.diagonalMoves(this);
    }

    @Override
    public boolean canMove(Move move) {
        boolean result = false;
        List<Spot> possibleMoves = PossibleMoves.diagonalMoves(move.getOriginPiece());
        if(possibleMoves.indexOf(move.getEndSpot()) != -1) result = true;

        return result;
    }


}
