package logic.classes.board;

import logic.classes.pieces.*;
import logic.classes.util.Move;
import logic.classes.util.Player;
import logic.enums.Color;
import logic.enums.PieceCode;

import java.util.ArrayList;
import java.util.List;

public class Board {

    private static int boardXDimension = 8;
    private static int boardYDimension = 8;

    private static Spot[][] boxes;
    private static Board boardInstance = new Board();


    public static Board getInstance() {
        return boardInstance;
    }

    private Board(){
        initializeBoard();
        initializePieces();
    }

    public void initializeBoard(){
        boxes = new Spot[boardYDimension][boardXDimension];
        for(int y =0; y < boardXDimension; y++){
            for(int x =0; x < boardXDimension; x++){
                boxes[y][x] = new Spot(null,x,y);
            }
        }
    }

    public static Spot getSpot(int x, int y){
        Spot result = null;
        if( x >= 0 && x < boardXDimension && y >=0 && y < boardYDimension){
            result =  boxes[y][x];
        }
        return result;
    }

    private void initializePieces(){

        ////////////// set first player pieces
        for(int x =0; x < boardXDimension; x++){
            boxes[1][x].setPiece(new Pawn(Color.WHITE,boxes[1][x]));
        }
        //set bishops
        boxes[0][2].setPiece(new Bishop(Color.WHITE, boxes[0][2]));
        boxes[0][5].setPiece(new Bishop(Color.WHITE, boxes[0][5]));

        //set rooks
        boxes[0][0].setPiece(new Rook(Color.WHITE, boxes[0][0]));
        boxes[0][7].setPiece(new Rook(Color.WHITE, boxes[0][7]));

        //set king
        boxes[0][3].setPiece(new King(Color.WHITE, boxes[0][3]));

        //set queen
        boxes[0][4].setPiece(new Queen(Color.WHITE, boxes[0][4]));

        //set Knights
        boxes[0][1].setPiece(new Knight(Color.WHITE, boxes[0][2]));
        boxes[0][6].setPiece(new Knight(Color.WHITE, boxes[0][6]));

        ////////////// set second player pieces
        for(int x =0; x < boardXDimension; x++){
            boxes[6][x].setPiece(new Pawn(Color.BLACK, boxes[6][x]));
        }
        //set bishops
        boxes[7][1].setPiece(new Bishop(Color.BLACK, boxes[7][2]));
        boxes[7][5].setPiece(new Bishop(Color.BLACK, boxes[7][5]));

        //set rooks
        boxes[7][0].setPiece(new Rook(Color.BLACK, boxes[7][0]));
        boxes[7][7].setPiece(new Rook(Color.BLACK, boxes[7][7]));

        //set king
        boxes[7][3].setPiece(new King(Color.BLACK, boxes[7][3]));

        //set queen
        boxes[7][4].setPiece(new Queen(Color.BLACK, boxes[7][4]));

        //set Knights
        boxes[7][2].setPiece(new Knight(Color.BLACK, boxes[7][2]));
        boxes[7][6].setPiece(new Knight(Color.BLACK, boxes[7][6]));

    }

    public static List<Piece> getPlayerPieces(Player player){
        List<Piece> pieces = new ArrayList<>();
        for(int y =0; y < boardXDimension; y++){
            for(int x =0; x < boardXDimension; x++){
                if(boxes[y][x].getPiece() != null && boxes[y][x].getPiece().getColor() == player.getColor()){
                    pieces.add(boxes[y][x].getPiece());
                    if(boxes[y][x].getPiece().getPieceCode() == PieceCode.KING) player.setKing((King) boxes[y][x].getPiece());
                }
            }
        }

        return pieces;
    }

    public static void executeMove(Move move){
        if(move.getCapturedPiece() != null){
            move.getPlayer().getCapturedPieces().add(move.getCapturedPiece());
            move.getCapturedPiece().setKilled(true);

            //for Pawn special kill where endSpot != captured piece spot
            move.getCapturedPiece().getSpot().setPiece(null);
        }
        move.getEndSpot().setPiece(move.getOriginPiece());
        move.getOriginSpot().setPiece(null);
    }

    public static void undoMove(Move move){
        if(move.getCapturedPiece() != null){
            move.getPlayer().getCapturedPieces().remove(move.getCapturedPiece());

            //for Pawn special kill where endSpot != captured piece spot
            move.getOriginSpot().setPiece(move.getOriginPiece());
        }
        move.getEndSpot().setPiece(move.getCapturedPiece());
        move.getOriginSpot().setPiece(move.getOriginPiece());
    }

    public static int getBoardXDimension() {
        return boardXDimension;
    }

    public static int getBoardYDimension() {
        return boardYDimension;
    }




}
