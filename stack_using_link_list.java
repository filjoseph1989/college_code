/**
 * Stack implementation algorithm using
 * linked list in java
 *
 * @author Fil Joseph Elman
 * @date Feb 13, 2009
 */
class myStack
{
    private node top;                 //declare node type, the top
    private int size;                   //declare  int type, the size
    public String input;             //type string input


    public myStack()
    {
        top=null;                        // initialize null to top
        size=0;                           //  initialize 0 to top
    }

    public boolean isEmpty()
    {
      return (size==0);
    }

    public int size()
    {
        return size;
    }

    public node top()
    {
      return top;
    }

    public void push(int element)
    {
      node newNode = new node(element,top);
      top = newNode;
      size++;
    }

    public node pop()
    {
      node pop = top;
      top = top.getNext();
      size--;

      return pop;
    }

    /*-----------------------filter   methods------------------------*/

    public void filter(int element)
    {
      if(isEmpty()==false)
      {
        int s= pop().getElement();
        filter(element);
        if(s!=element)
        push(s);
      }
    }

    /*----------------------------display  method---------------------*/
    public void display()
    {
      if(isEmpty()==false)
      {
        int s= pop().getElement();
        display();
        input=input+"\n"+s;
        push(s);
      }
    }
}
