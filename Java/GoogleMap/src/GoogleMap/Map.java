/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package GoogleMap;

/**
 *
 * @author XD
 */

// Reference and how to make it
//https://developers.google.com/maps/documentation/static-maps/intro#ImageFormats

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.IOException;
import java.net.URL;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;


public class Map implements ActionListener, MouseListener {
	JFrame frame;
	JPanel mapPanel;
	JLabel showMap;
	String imageUrl;
	
	public static void main (String args[]){
            Map map = new Map();
	}
	
	public Map(){
		JFrame frame = new JFrame("Google maps");
		
		mapPanel = new JPanel();
		JPanel header = new JPanel();
		JPanel selection = new JPanel();
		showMap = new JLabel();
		mapPanel.setSize(1220,830);
		
		JLabel maptitle = new JLabel("Google Static Map API!");
		mapPanel.addMouseListener(this);
		header.add(maptitle);
		mapPanel.add(showMap);
		
		String str1 = "https://maps.googleapis.com/maps/api/staticmap?";
		str1 = str1 + "center=0.720600,0.494633&zoom=1&size=500x500";
		str1 = str1 + "&markers=color:red|32.7311,-97.1155&markers=color:red|-22.9068,-43.1739&markers=color:red|50.0647,19.9450&markers=color:red|27.1767,78.0081&markers=color:blue|20.2675,30.9338&markers=color:yellow|31.23045,121.4737";
		str1 = str1 + "&key=AIzaSyCQEP6v_RPtflvg8IK0FsDJ4SRqEJrvBLU";
		this.imageUrl = str1;
		System.out.println(imageUrl);
		this.refresh();
		frame.setLayout(new BorderLayout(1,1));
                frame.add(header, BorderLayout.NORTH);
                frame.add(mapPanel, BorderLayout.CENTER);	    
	    
                frame.add(selection, BorderLayout.SOUTH);
                frame.setVisible(true);
                frame.pack();
		
	}
	
	public void  refresh(){
		String destinationFile = "image.jpg";
		try {
		    /* Second set to test if same map can display multiple markers */   
		   
		   URL url2 = new URL(imageUrl);
		   showMap.setIcon( new ImageIcon( new ImageIcon(url2).getImage().getScaledInstance( 1220,830, java.awt.Image.SCALE_SMOOTH ) ) );

		   
		    } catch (IOException e) {
		    System.exit(1);
		    }
	}

	@Override
	public void mouseClicked(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		System.out.println(e.getX() + "," + e.getY());
		if((e.getY()<69 && e.getY()>63) && (e.getX()<75 && e.getX()>72)){
			JOptionPane.showMessageDialog(null,"this is a  marker",null, JOptionPane.INFORMATION_MESSAGE);
		}
		
	}

	@Override
	public void mouseReleased(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

    @Override
    public void actionPerformed(ActionEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

  
	
	
	
}


