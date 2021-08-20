public class TixOrder
{
   private String name;
   private int numTickets;
   
   public TixOrder(String n, String t)
   {
      name = n;
      numTickets = Integer.parseInt(t);
      
   }
   
   public String getName()
   {
      return name;
   }
   
   public int getTickets()
   {
      return numTickets;
   }
}