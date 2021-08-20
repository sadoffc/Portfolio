import ch04.queues.*;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class QueueProcessing
{
   public static void main(String[] args)
   {
      TixQueue tq = new TixQueue(10,10000);
      Thread t = new Thread(tq);
      t.start();
    
      //infinite loop to take ticket orders, broken by entering STOP
      int i = 1;
      while(i != 0)
      { 
         String order = JOptionPane.showInputDialog("Enter a name and quantity for order seperated by a colon.\n EXAMPLE: Connor:2\n Enter STOP to exit program.");
         
         if(order.equals("STOP"))
         {
            t.stop();
            System.out.println();
            System.out.println("INTERUPPTED");
            System.out.println(tq.size() + " unprocessed jobs. Exiting...");

            break;
         } 
         else
         {
            if(order.indexOf(':') == -1 || order.indexOf(' ') != -1) //makes sure order can be processed by split() method
            {
               System.out.println("Please check formatting and try again.");
            }
            else
            {
               
               String[] orderArray = order.split(":");
               TixOrder to = new TixOrder(orderArray[0], orderArray[1]);
            
               tq.enqueue(to);
            }
         }
      }
      System.out.println("Money made: $" + tq.getMoney());      
   }
}