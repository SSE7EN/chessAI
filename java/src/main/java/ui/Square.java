package ui;

import logic.classes.board.Spot;

import javax.swing.*;
import java.awt.*;

public class Square extends JComponent{

    private Spot spot;
    private int posX;
    private int posY;
    private boolean isSelected = false;


    public Square(int posX, int posY, Spot spot){
        this.posX = posX;
        this.posY = posY;
        this.spot = spot;

        this.setBorder(BorderFactory.createEmptyBorder());
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        if ((this.posX + this.posY) %2 == 0) {
            g.setColor(new Color(221,192,127));
        } else {
            g.setColor(new Color(101,67,33));
        }
        g.fillRect(0, 0, this.getWidth(), this.getHeight());


        if(spot.getPiece() != null){
            drawPiece(g);
        }
    }

    public void drawPiece(Graphics g){
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        int x = (this.getWidth() - spot.getPiece().getImg().getWidth(null)) / 2;
        int y = (this.getHeight() - spot.getPiece().getImg().getHeight(null)) / 2;
        g.drawImage(spot.getPiece().getImg(),x,y,null);
    }

    public void highlightSquare(){
        if(!isSelected){
            isSelected = true;
            setBorder(BorderFactory.createLineBorder(Color.RED,5));
        }else{
            setBorder(null);
            isSelected = false;
        }
    }


    public Spot getSpot() {
        return spot;
    }

    public void setSpot(Spot spot) {
        this.spot = spot;
    }

    public int getPosX() {
        return posX;
    }

    public void setPosX(int posX) {
        this.posX = posX;
    }

    public int getPosY() {
        return posY;
    }

    public void setPosY(int posY) {
        this.posY = posY;
    }

    public boolean isSelected() {
        return isSelected;
    }

    public void setSelected(boolean selected) {
        isSelected = selected;
    }

}
