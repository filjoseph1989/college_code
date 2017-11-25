import java.io.*;
import java.lang.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

class number_convert extends JFrame{
	private static final Font BIGGER_FONT = new Font("monspaced", Font.PLAIN, 10);
	private JTextField display;
	private boolean   _start = true; 
	private boolean   start = false; 
	private String prev="",input="",last="";
	private int check =0;
	
	public static void main(String args[]){
		number_convert window = new number_convert();
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setVisible(true);
	}
	
	public number_convert(){
		String button = "1234567890abcdef";
		String button2= "BODHCn";
		ActionListener numListener = new NumListener();
		ActionListener chListener = new ChListener();
		JPanel buttonPanel = new JPanel();
		JPanel buttonPanel2 = new JPanel();
		JPanel content = new JPanel();
		
		
		display = new JTextField("0", 16);
        display.setHorizontalAlignment(JTextField.RIGHT);
        display.setFont(BIGGER_FONT);
        
        buttonPanel.setLayout(new GridLayout(5, 3, 2, 2));
        
        for(int i = 0; i < button.length(); i++) {
            String key = button.substring(i, i+1);
            JButton b = new JButton(key);            	
                b.addActionListener(numListener);
                b.setFont(BIGGER_FONT);
            buttonPanel.add(b);
        }
        
        buttonPanel2.setLayout(new FlowLayout());
        for(int j=0;j<button2.length();j++){
        	String k= button2.substring(j,j+1);
        	JButton a= new JButton(k);
        		a.addActionListener(chListener);
        		a.setFont(BIGGER_FONT);
        	buttonPanel2.add(a);
        		
        }
        
        content.setLayout(new BorderLayout(8, 8));
        content.add(display, BorderLayout.NORTH );
        content.add(buttonPanel   , BorderLayout.CENTER);
        content.add(buttonPanel2   , BorderLayout.SOUTH);
        
        content.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        
        //makita najud ang result
        this.setContentPane(content);//
        this.pack();
        this.setTitle("number CONVERTER");
        this.setResizable(false);
	}
	
	class NumListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String digit = e.getActionCommand();
            if (_start == false) {
                display.setText(" ");
                start = true;
                input += digit;
                display.setText(input); 
                             
            } 
            
        }
    }
    
    class ChListener implements ActionListener{
    	public void actionPerformed(ActionEvent c){
    		prev= c.getActionCommand();
    		
    		int i=0;
    		if(prev.equals("n")){
    			_start= true;
    			display.setText("new convertion");
    		}
    		if(_start==true){
    			if(prev.equals("B"))display.setText("BINARY INPUT");
    			if(prev.equals("O"))display.setText("OCTAL INPUT");
    			if(prev.equals("D"))display.setText("DECIMAL INPUT");
    			if(prev.equals("H"))display.setText("HEXADECIMAL INPUT");
				last= prev;    		
				_start = false;
    		}
    		if(start==true){
    			
    			if (prev.equals("C")){
    				display.setText("CONVERT TO");//mag display og convert
    				if(last.equals("B")){
    					do{
							check = checker_bin((int)input.charAt(i)-48);
							if(check == 0)i = input.length()-1;
							i++;
						}while(i!=input.length());
						
						
					}//end
					if(last.equals("O")){
						do{
							check = checker_oct((int)input.charAt(i)-48);
							if(check == 0)i = input.length()-1;
							i++;
						}while(i!=input.length());
						
					}
					if(last.equals("D")){
						do{
							check = checker_dec((int)input.charAt(i)-48);
							if(check == 0)i = input.length()-1;
							i++;
						}while(i!=input.length());
						
					}
					if(last.equals("H")){
						do{
							check = checker_hex((int)input.charAt(i)-48);
							if(check == 0)i = input.length()-1;
							i++;
						}while(i!=input.length());
						
					}
					
    			}//end if 2nd
    			start=false;
    			
    		}//end if 1st

    		if(start==false){
    			if (prev.equals("B")){
    				
    				if(check == 1){//kung binary
    					display.setText("BIN "+input);
    					input="";
    				}
    				if(check == 2){//kung octal
  						int num= Integer.parseInt(input,8);
  						String by = Integer.toBinaryString(num);
  						display.setText("BIN "+by);
  						input="";
  					}
  					if(check == 3){//kung dcimal
  						int num= Integer.parseInt(input);
  						String by = Integer.toBinaryString(num);
  						display.setText("BIN "+by);
  						input="";
  					}
  					if(check == 4){//kung hexa decimal
  						int num= Integer.parseInt(input,16);
  						String by = Integer.toBinaryString(num);
  						display.setText("BIN "+by);
  						input="";
  					}

    			}//B
    			if (prev.equals("O")){
    				if(check == 1){//kung binary
    					int num= Integer.parseInt(input,2);
    					String str = Integer.toString(num,8);
    					display.setText("OCT "+str);
    					input="";
    				}
    				if(check == 2){//kung octal
  						display.setText("OCT "+input);
  						input="";
  					}
  					if(check == 3){//kung decimal
  						int num= Integer.parseInt(input);
  						String by = Integer.toString(num,8);
  						display.setText("OCT "+by);
  						input="";
  					}
  					if(check == 4){//kung hexa decimal
  						int num= Integer.parseInt(input,16);
  						String by = Integer.toString(num,8);
  						display.setText("OCT "+by);
  						input="";
  					}

    			}
    			if (prev.equals("D")){
    				if(check == 1){//kung binary
    					int num= Integer.parseInt(input,2);
    					String str = new Integer(num).toString();
    					display.setText("DEC "+str);
    					input="";
    				}
    				if(check == 2){//kung octal
  						int num= Integer.parseInt(input,8);
    					String str = new Integer(num).toString();
    					display.setText("DEC "+str);
    					input="";
  					}
  					if(check == 3){//kung decimal
  						int num= Integer.parseInt(input);
  						String by = new Integer(num).toString();
  						display.setText("DEC "+by);
  						input="";
  					}
  					if(check == 4){//kung hexa decimal
  						int num= Integer.parseInt(input,16);
  						String by = new Integer(num).toString();
  						display.setText("DEC "+by);
  						input="";
  					}

    			}
    			if (prev.equals("H")){
    				if(check == 1){//kung binary
    					int num= Integer.parseInt(input,2);
    					String str = Integer.toHexString(num);
    					display.setText("HEX "+str);
    					input="";
    				}
    				if(check == 2){//kung octal
  						int num= Integer.parseInt(input,8);
    					String str = Integer.toHexString(num);
    					display.setText("HEX "+str);
    					input="";
  					}
  					if(check == 3){//kung decimal
  						int num= Integer.parseInt(input);
  						String by = Integer.toHexString(num);
  						display.setText("HEX "+by);
  						input="";
  					}
  					if(check == 4){//kung hexa decimal
  						int num= Integer.parseInt(input,16);
  						String by = Integer.toHexString(num);
  						display.setText("HEX "+by);
  						input="";
  					}

    			}//end
    			
    			
    		}//end if
    	}
    	
    	public int checker_bin(int n){
			if(n > -1 && n < 2){
				return n=1;
			}
			else{
				return n=0;
			}	
		}
		
		public int checker_oct(int n){
			if(n > -1 && n < 8){
				return n=2;
			}	
			else{
				return n=0;
			}
	
		}
	
		public int checker_dec(int n){
			if(n > -1 && n < 10){
				return n=3;
			}
			else{
				return n=0;
			}
			
		}
		public int checker_hex(int n){
			if((n > -1 && n < 10)||(n > 48 && n < 55)){
				return n=4;
			}
			else{
				return n=0;
			}
	
		}

    }//end
}