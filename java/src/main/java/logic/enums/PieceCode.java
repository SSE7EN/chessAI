package logic.enums;

public enum PieceCode {
    KING("K"),QUEEN("Q"),BISHOP("B"),KNIGHT("N"),ROOK("R"),PAWN("");

    private String code;

    PieceCode(String code){
        this.code = code;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }
}
