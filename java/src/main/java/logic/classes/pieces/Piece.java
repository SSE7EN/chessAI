package logic.classes.pieces;

import logic.classes.board.Spot;
import logic.classes.util.Move;
import logic.enums.Color;
import logic.enums.PieceCode;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.List;

public abstract class Piece {

    final PieceCode pieceCode;
    protected BufferedImage img;
    private Color color;
    private boolean killed;
    protected Spot spot;
    protected String imageName;

    Piece(Color color,PieceCode pieceCode,String imageName,Spot spot){
        this.pieceCode = pieceCode;
        this.killed = false;
        this.color = color;
        this.spot = spot;
        this.imageName = imageName;

    }
    Piece(Color color,PieceCode pieceCode,Spot spot){
        this.pieceCode = pieceCode;
        this.killed = false;
        this.color = color;
        this.spot = spot;

    }


    public PieceCode getPieceCode() {
        return pieceCode;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public boolean isKilled() {
        return killed;
    }

    public void setKilled(boolean killed) {
        this.killed = killed;
    }

    public abstract List<Spot> getAttackedSpots();

    public abstract boolean canMove(Move move);

    protected void initializeImage(){
        try {
            if (this.img == null) {
                this.img = ImageIO.read(getClass().getResource(imageName));
            }
        } catch (IOException e) {
            System.out.println("File not found: " + e.getMessage());
        }catch (Exception e){
            System.out.println("Exception " + e.getMessage());
        }
    }

    public BufferedImage getImg() {
        return img;
    }

    public void setImg(BufferedImage img) {
        this.img = img;
    }

    public Spot getSpot() {
        return spot;
    }

    public void setSpot(Spot spot) {
        this.spot = spot;
    }
}
