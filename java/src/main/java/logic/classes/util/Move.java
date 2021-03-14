package logic.classes.util;

import logic.classes.pieces.Piece;
import logic.classes.board.Spot;

public class Move {
    Player player;
    Piece originPiece;
    Spot originSpot;
    Piece capturedPiece;
    Spot endSpot;

    public Move(Player player, Spot originSpot, Spot endSpot) {
        this.player = player;

        this.originPiece = originSpot.getPiece();
        this.originSpot = originSpot;
        this.capturedPiece = endSpot.getPiece();
        this.endSpot = endSpot;
    }

    public Piece getOriginPiece() {
        return originPiece;
    }

    public void setOriginPiece(Piece originPiece) {
        this.originPiece = originPiece;
    }

    public Spot getOriginSpot() {
        return originSpot;
    }

    public void setOriginSpot(Spot originSpot) {
        this.originSpot = originSpot;
    }

    public Piece getCapturedPiece() {
        return capturedPiece;
    }

    public void setCapturedPiece(Piece capturedPiece) {
        capturedPiece.setKilled(true);
        this.capturedPiece = capturedPiece;
    }

    public Spot getEndSpot() {
        return endSpot;
    }

    public void setEndSpot(Spot endSpot) {
        this.endSpot = endSpot;
    }

    public Player getPlayer() {
        return player;
    }

    public void setPlayer(Player player) {
        this.player = player;
    }
}
