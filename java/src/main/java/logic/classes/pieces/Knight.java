package logic.classes.pieces;

import logic.classes.board.PossibleMoves;
import logic.classes.board.Spot;
import logic.classes.util.Move;
import logic.enums.Color;
import logic.enums.PieceCode;

import java.util.List;

public class Knight extends Piece{

    public Knight(Color color, Spot spot){
        super(color, PieceCode.KNIGHT, spot);



        ///Pawn can only move forward & Pawn image color
        if(this.getColor() == Color.WHITE){
            this.imageName = "/White_Knight.png";
        }
        else{
            this.imageName = "/Black_Knight.png";
        }

        initializeImage();
    }

    @Override
    public List<Spot> getAttackedSpots() {
        return PossibleMoves.knightMoves(this);
    }

    @Override
    public boolean canMove(Move move) {
        boolean result = false;
        List<Spot> possibleMoves = PossibleMoves.knightMoves(move.getOriginPiece());
        if(possibleMoves.indexOf(move.getEndSpot()) != -1) result = true;

        return result;
    }

}
