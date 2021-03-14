package logic.classes.pieces;

import logic.classes.board.PossibleMoves;
import logic.classes.board.Spot;
import logic.classes.pieces.Piece;
import logic.classes.util.Move;
import logic.enums.Color;
import logic.enums.PieceCode;

import java.util.List;

public class Rook extends Piece {

    public Rook(Color color, Spot spot){
        super(color, PieceCode.ROOK, spot);



        ///Pawn can only move forward & Pawn image color
        if(this.getColor() == Color.WHITE){
            this.imageName = "/White_Rook.png";
        }
        else{
            this.imageName = "/Black_Rook.png";
        }

        initializeImage();

    }
    @Override
    public List<Spot> getAttackedSpots() {
        return PossibleMoves.axisMoves(this);
    }

    @Override
    public boolean canMove(Move move) {
        boolean result = false;
        List<Spot> possibleMoves = PossibleMoves.axisMoves(move.getOriginPiece());
        if(possibleMoves.indexOf(move.getEndSpot()) != -1) result = true;

        return result;
    }
}
