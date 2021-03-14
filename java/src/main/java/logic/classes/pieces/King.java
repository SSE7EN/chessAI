package logic.classes.pieces;

import logic.classes.board.PossibleMoves;
import logic.classes.board.Spot;
import logic.classes.util.Move;
import logic.enums.Color;
import logic.enums.PieceCode;

import java.util.List;

public class King extends Piece {


    public King(Color color, Spot spot){
        super(color, PieceCode.KING, spot);



        ///Pawn can only move forward & Pawn image color
        if(this.getColor() == Color.WHITE){
            this.imageName = "/White_King.png";
        }
        else{
            this.imageName = "/Black_King.png";
        }

        initializeImage();
    }

    @Override
    public List<Spot> getAttackedSpots() {
        return PossibleMoves.kingMoves(this);
    }

    @Override
    public boolean canMove(Move move) {

        boolean result = false;
        List<Spot> possibleMoves = PossibleMoves.kingMoves(move.getOriginPiece());
        if(possibleMoves.indexOf(move.getEndSpot()) != -1) result = true;

        return result;
    }
}
