/**
 * @author Fil Joseph Elman
 * @date Dec 09, 2009
 */
 public class cellphone
 {
     public float load;
     public int cost;

     public void myLoad(int num)
     {
       load = num;
     }

     public void reLoad(int num)
     {
       load= load + num;
     }

     public void pasaLoad(int num)
     {
       if(num==5 ||num==10 || num==15)
       {
         load= load - (num+1);
       } else {
         System.out.println("cannot pasaload");
       }
     }

     public float ballanceInquire()
     {
       return load;
     }

     public void call(int cost,int min)
     {
       cost= cost * min;
       load=load - cost;
     }

     public void sendmessages(int num)
     {
       load=load-num;
     }

     public void call15(int num)
     {
       if(load>=num && num==15) {
         load=load-num;
       } else {
         System.out.println("you  have a small amount of load");
       }
     }

     public void Unli(int num)
     {
       if(load>=num || num==15|| num==20 || num==30) {
         load=load-m;
       else {
         System.out.println("cannot have unlimited");
       }
     }
}
