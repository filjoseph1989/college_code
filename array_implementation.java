/**
 * @author Fil Joseph Elman
 * @date January 09, 2009
 */
public class list
{
    public static int x[] = new int[1000];
    public static int pos = -1;

    public static int add(int ele)
    {
        x[++pos] = ele;
        return ele;
    }

    public static int display(int n)
    {
      for(int i=0;i<=pos;i++)
      {
        System.out.println("["+i+"]   "+x[i]);
      }
      return n;
    }

    public static int insert(int insPos, int num)
    {
        int j;

        pos = pos + 1;
        for( j=pos; j>insPos-1; j--)
        {
            x[j] = x[j-1];
        }
        x[insPos-1] = num;
        return 0;
    }

    public static int delete(int delpos)
    {
        int temp;
        temp = x[delpos];
        for(int i=delpos-1; i<pos; i++)
        {
            x[i] = x[i+1];

        }
        pos--;
        return temp;
    }

    public static int size()
    {
        return pos + 1;
    }

    public static int makeNULL()
    {
        return pos = -1;
    }

    public static int getElement(int getPos)
    {
      return x[getPos-1];
    }

    public static boolean isEmpty()
    {
      if(pos== -1)
        return false;
      else
        return true
    }
}
