import ch04.queues.LinkedQueue;
import java.util.UUID;
import java.text.SimpleDateFormat;
import java.util.Date;

public class TixQueue extends LinkedQueue implements Runnable
{
   private LinkedQueue<TixOrder> tq; 
   private int tickets;
   private int time;
   private boolean exit;
   private int totalMoney;
   
   public TixQueue(int tickets, int time)
   {
      tq = new LinkedQueue();
      this.tickets = tickets;
      this.time = time;
      exit = false;
      totalMoney = 0;
   }
   
   public void stop()//ends thred
   {
      exit = true;
   }
   
   public int getMoney()
   {
      return totalMoney;
   }
   
   public void run()
   {
      System.out.println("Initializing Ticket Queue...");
      System.out.println(tickets + " tickets available! Cost: $5");
   
      while(exit != true)
      {
         try 
         {
           Thread.sleep(time);
         }
         catch (InterruptedException e) 
         {
           e.printStackTrace();
         }

         if(tickets == 0)
         {
             System.out.println();
             System.out.println("SOLD OUT! NO MORE TICKETS!!");
             System.out.println(size() + " orders will not be processed.");
             stop();
             System.out.println("Money made: $" + getMoney());
         }
         else if(isEmpty())
         {
             System.out.println("No orders to process...");
             System.out.println(tickets + " tickets remaining");
         }
         else
         {
            SimpleDateFormat formatter = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
            Date date = new Date(System.currentTimeMillis());
            TixOrder temp = (TixOrder) dequeue();
     
            if(temp.getTickets() <= tickets)//validates sufficient tickets 
            {
               UUID id = UUID.randomUUID();
               System.out.println();
               System.out.println("ORDER PROCESSED");
               System.out.println("Order ID: " + id);
               System.out.println("Name: " + temp.getName());
               System.out.println("Quantity: " + temp.getTickets());
               System.out.println("Status: true");
               System.out.println("Processed: " + formatter.format(date));
               tickets = tickets - temp.getTickets();
               totalMoney = totalMoney + (temp.getTickets() * 5);
            }
            else
            {
               UUID id = UUID.randomUUID();
               System.out.println();
               System.out.println("Only " + tickets + " tickets remaining, order fewer tickets and try again");
               System.out.println("******ORDER NOT PROCESSED******");
               System.out.println("Order ID: " + id);
               System.out.println("Name: " + temp.getName());
               System.out.println("Quantity: " + temp.getTickets());
               System.out.println("Status: false");
               System.out.println("Processed: " + formatter.format(date));
            }
            System.out.println();
            System.out.println(tickets + " tickets available");
           }  
      }
   }
}