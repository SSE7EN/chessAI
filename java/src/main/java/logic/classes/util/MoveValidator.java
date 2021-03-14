package logic.classes.util;

import logic.classes.board.Spot;
import logic.classes.pieces.King;

import java.util.ArrayList;
import java.util.List;

public class MoveValidator {

    public static boolean validateMoveBeforeMove(Move move){

        //check if origin is valid
        if(move.getOriginPiece() == null) return false;

        // check for valid destination
        if (move.getCapturedPiece() != null) {
            if (move.getOriginPiece().getColor().equals(move.getCapturedPiece().getColor())) {
                return false;
            }
        }
        //check piece move rules
        if(!move.getOriginPiece().canMove(move)) return false;

        return true;

    }

    public static boolean validateMoveAfterMove(Move move, Player player2){
        boolean result = false;

        King king = move.getPlayer().getKing();
        List<Spot> attackedSpots = new ArrayList<>();

        for (List<Spot> sL: player2.getAttackedFields().values()) {
            attackedSpots.addAll(sL);
        }
        if(!attackedSpots.contains(king.getSpot())) result = true;

        return result;


    }

}
