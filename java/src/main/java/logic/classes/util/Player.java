package logic.classes.util;

import logic.classes.pieces.King;
import logic.classes.pieces.Piece;
import logic.classes.board.Spot;
import logic.enums.Color;

import java.util.*;

public class Player {

    private String name;
    private Color color;
    private List<Piece> pieces;
    private List<Piece> capturedPieces;
    private Map<Piece, List<Spot>> attackedFields;
    private King king;

    public Player(String name, Color color){
        this.pieces = new ArrayList<>();
        this.capturedPieces = new ArrayList<>();
        this.attackedFields = new HashMap<>();
        this.name = name;
        this.color = color;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public List<Piece> getPieces() {
        return pieces;
    }

    public void setPieces(List<Piece> pieces) {
        this.pieces = pieces;
        calculateAttackedFields();
    }
    
    public void addToPiecesList(Piece piece){
        this.attackedFields.put(piece, piece.getAttackedSpots());
        this.pieces.add(piece);

    }
    
    public void recalculateAttackedSpots(){
        Iterator<Map.Entry<Piece, List<Spot>>> iterator = attackedFields.entrySet().iterator();
        while (iterator.hasNext()) {
            Map.Entry<Piece, List<Spot>> entry = iterator.next();
            if(!entry.getKey().isKilled()){
                entry.setValue(entry.getKey().getAttackedSpots());
            }

        }
    }

    private void calculateAttackedFields(){
        for (Piece piece: pieces) {
            attackedFields.put(piece, piece.getAttackedSpots());
        }
    }

    public List<Piece> getCapturedPieces() {
        return capturedPieces;
    }

    public Piece getPiece(Piece piece){
        int idx = pieces.indexOf(piece);
        return pieces.get(idx);
    }

    public Map<Piece, List<Spot>> getAttackedFields() {
        recalculateAttackedSpots();
        return attackedFields;
    }

    public void setAttackedFields(Map<Piece, List<Spot>> attackedFields) {
        this.attackedFields = attackedFields;
    }

    public King getKing() {
        return king;
    }

    public void setKing(King king) {
        this.king = king;
    }

    public void setCapturedPieces(List<Piece> capturedPieces) {
        this.capturedPieces = capturedPieces;
    }


}
