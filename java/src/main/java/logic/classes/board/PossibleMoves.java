package logic.classes.board;

import logic.classes.pieces.Piece;
import logic.enums.Color;

import java.util.ArrayList;
import java.util.List;

public class PossibleMoves {

    public static List<Spot> diagonalMoves(Piece piece){
        List<Spot> possibleSpots = new ArrayList<>();
        //search left up
        searchInDirection(possibleSpots, piece.getSpot(), -1,-1, piece.getColor());
        //search left down
        searchInDirection(possibleSpots, piece.getSpot(), 1,1, piece.getColor());
        //search right up
        searchInDirection(possibleSpots, piece.getSpot(), 1,-1, piece.getColor());
        //search left down
        searchInDirection(possibleSpots, piece.getSpot(), -1,1, piece.getColor());

        return possibleSpots;
    }

    public static List<Spot> axisMoves(Piece piece){
        List<Spot> possibleSpots = new ArrayList<>();
        //search left
        searchInDirection(possibleSpots, piece.getSpot(), -1,0, piece.getColor());
        //search right down
        searchInDirection(possibleSpots, piece.getSpot(), 1,0, piece.getColor());
        //search  up
        searchInDirection(possibleSpots, piece.getSpot(), 0,1, piece.getColor());
        //search  down
        searchInDirection(possibleSpots, piece.getSpot(), 0,-1, piece.getColor());

        return possibleSpots;
    }

    public static List<Spot> knightMoves(Piece piece){
        List<Spot> possibleSpots = new ArrayList<>();

        pieceMove(possibleSpots, piece.getSpot(), 1,2, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), -1,2, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), -1,-2, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), 1,-2, piece.getColor());

        pieceMove(possibleSpots, piece.getSpot(), 2,1, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), -2,1, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), -2,-1, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), 2,-1, piece.getColor());




        return possibleSpots;
    }

    public static List<Spot> kingMoves(Piece piece){
        List<Spot> possibleSpots = new ArrayList<>();

        pieceMove(possibleSpots, piece.getSpot(), 1,0, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), -1,0, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), 0,1, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), 0,-1, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), 1,1, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), -1,-1, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), -1,1, piece.getColor());
        pieceMove(possibleSpots, piece.getSpot(), 1,-1, piece.getColor());

        return possibleSpots;

    }




    /*
        @param color-> color which we cannot kill
     */
    private static void searchInDirection(List<Spot> possibleSpots, Spot startSpot,int xDirection, int yDirection, Color color){
        int tempX = startSpot.getX();
        int tempY = startSpot.getY();
        tempX += xDirection;
        tempY += yDirection;
        while(tempX >= 0 && tempX <= 7 && tempY >= 0 && tempY <= 7){
            Spot tempSpot = Board.getSpot(tempX, tempY);
            if(tempSpot != null && tempSpot.getPiece() == null){
                possibleSpots.add(tempSpot);
            }
            else if(tempSpot != null && tempSpot.getPiece().getColor() != color){
                possibleSpots.add(tempSpot);
                break;
            }
            else break;

            tempX += xDirection;
            tempY += yDirection;
        }
    }

    private static void pieceMove(List<Spot> possibleSpots, Spot startSpot, int xDirection, int yDirection, Color color){
        int tempX = startSpot.getX();
        int tempY = startSpot.getY();
        tempX += xDirection;
        tempY += yDirection;

        Spot tempSpot = Board.getSpot(tempX, tempY);

        if(tempSpot != null && (tempSpot.getPiece() == null || tempSpot.getPiece().getColor() != color)){
            possibleSpots.add(tempSpot);
        }

        return;
    }


}
