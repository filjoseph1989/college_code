/**
 * @date Aug 13, 2008
 */
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;

public class NetSend extends JFrame implements ActionListener
{
	JComboBox list = new JComboBox();
	JTextField message = new JTextField(20);
	JButton send = new JButton("Send");
	JTextField result = new JTextField(25);

	private static Connection cn = null;
 	private static Statement st= null;
	private ResultSet r= null;

	public NetSend(String title){
		setTitle(title);
		initialise();
		Container c = getContentPane();
		c.setLayout(new FlowLayout(FlowLayout.CENTER));
		c.add(list);
		c.add(message);
		send.addActionListener(this);
		send.setMnemonic(KeyEvent.VK_S);
		c.add(send);
		result.setEditable(false);
		result.setBackground(Color.yellow);
		result.setForeground(Color.red);
		c.add(result);
	}
	public void actionPerformed(ActionEvent ae){
		if(ae.getSource()==send){
			String dest = String.valueOf(list.getSelectedItem());
			String msg = message.getText();
			try{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			cn = DriverManager.getConnection("jdbc:odbc:netsend","mcp","mcp");
			st=cn.createStatement();
			ResultSet
 r=st.executeQuery("xp_cmdshell 'net send "+dest+" "+msg+"'");
			result.setText("Message Sent");

			}catch(Exception e){result.setText("Error in Sending Message");}
		}
	}
	public void initialise(){
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");

			cn = DriverManager.getConnection("jdbc:odbc:netsend","mcp","mcp");

	st=cn.createStatement();
			r=st.executeQuery("xp_cmdshell 'net view'");

			String temp = new String();
			int i = 1;
			ArrayList machNames = new ArrayList();
			while(r.next())
			{
				machNames.add(r.getString("output"));
			}
			for(int x=3;x<machNames.size()-3;x++){
				temp = String.valueOf(machNames.get(x));
				list.addItem(temp.substring(2,temp.length()));
			}
			result.setText("Type your message and press ALT and S");
		}
		catch(Exception e){result.setText("Not able to retrieve the hosts");}
	}
	public static void main(String args[])
	{
		NetSend ns = new NetSend("Send your messages to PC's in LAN");

	ns.setVisible(true);
		ns.setSize(400,400);
	}
}
