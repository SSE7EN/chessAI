package ui;

import logic.classes.util.GameModel;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GameWindow extends JFrame  {

    private static GameModel gameModel;
    private static BoardPanel boardPanel;


    public GameWindow(String wn, String bn){
        super("Chess");


        this.setLayout(new BorderLayout(20,20));
        // Game Data window

        this.gameModel  = new GameModel(wn,bn);;
        this.boardPanel = gameModel.getBoardPanel();

        this.add(boardPanel, BorderLayout.CENTER);

        this.add(buttons(), BorderLayout.SOUTH);

        this.setMinimumSize(this.getPreferredSize());
        this.setSize(this.getPreferredSize());
        this.setResizable(true);

        this.pack();
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    }

    private JPanel buttons() {
        JPanel buttons = new JPanel();
        buttons.setLayout(new GridLayout(1, 3, 10, 0));

        final JButton quit = new JButton("Quit");

        quit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int n = JOptionPane.showConfirmDialog(GameWindow.this,
                        "Are you sure you want to quit?",
                        "Confirm quit", JOptionPane.YES_NO_OPTION);

            }
        });

        final JButton nGame = new JButton("New game");

        nGame.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int n = JOptionPane.showConfirmDialog(
                        GameWindow.this,
                        "Are you sure you want to begin a new game?",
                        "Confirm new game", JOptionPane.YES_NO_OPTION);

                if (n == JOptionPane.YES_OPTION) {
                    SwingUtilities.invokeLater(new StartMenu());
                    GameWindow.this.dispose();
                }
            }
        });

        final JButton instr = new JButton("How to play");

        instr.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(GameWindow.this,
                        "Move the chess pieces on the board by clicking\n"
                                + "and dragging. The game will watch out for illegal\n"
                                + "moves. You can win either by your opponent running\n"
                                + "out of time or by checkmating your opponent.\n"
                                + "\nGood luck, hope you enjoy the game!",
                        "How to play",
                        JOptionPane.PLAIN_MESSAGE);
            }
        });

        buttons.add(instr);
        buttons.add(nGame);
        buttons.add(quit);

        buttons.setPreferredSize(buttons.getMinimumSize());

        return buttons;
    }


}
