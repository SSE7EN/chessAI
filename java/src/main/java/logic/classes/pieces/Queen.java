package logic.classes.pieces;

import logic.classes.board.PossibleMoves;
import logic.classes.board.Spot;
import logic.classes.util.Move;
import logic.enums.Color;
import logic.enums.PieceCode;

import java.util.List;
import java.util.stream.Stream;

public class Queen extends Piece {

    public Queen(Color color, Spot spot){
        super(color, PieceCode.QUEEN, spot);



        ///Pawn can only move forward & Pawn image color
        if(this.getColor() == Color.WHITE){
            this.imageName = "/White_Queen.png";
        }
        else{
            this.imageName = "/Black_Queen.png";
        }

        initializeImage();

    }

    @Override
    public List<Spot> getAttackedSpots() {
        List<Spot> attackedSpots = PossibleMoves.axisMoves(this);
        attackedSpots.addAll(PossibleMoves.diagonalMoves(this));
        return attackedSpots;
    }

    @Override
    public boolean canMove(Move move) {
        boolean result = false;
        List<Spot> possibleMoves = getAttackedSpots();
        if(possibleMoves.indexOf(move.getEndSpot()) != -1) result = true;

        return result;
    }
}
