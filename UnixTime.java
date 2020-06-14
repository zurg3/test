import java.util.Date;
import java.util.TimeZone;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class UnixTime {
  public static void main(String[] args) {
    if (args.length == 0) {
      System.out.println("|--------------------------------------------------------|");
      System.out.println("| UTC Time            | Local Time          | UNIX Time  |");
      System.out.println("|--------------------------------------------------------|");

      while (true) {
        Date current_date = new Date();

        DateFormat date_format = new SimpleDateFormat("HH:mm:ss dd.MM.yyyy");
        String local_time = date_format.format(current_date);

        date_format.setTimeZone(TimeZone.getTimeZone("UTC"));
        String utc_time = date_format.format(current_date);

        long unix_time = System.currentTimeMillis() / 1000L;

        System.out.println("| " + utc_time + " | " + local_time + " | " + unix_time + " |");

        try {
          Thread.sleep(1000);
        }
        catch (InterruptedException ex) {
          Thread.currentThread().interrupt();
        }
      }
    }
    else if (args.length == 1) {
      System.out.println("|--------------------------------------------------------|");
      System.out.println("| UTC Time            | Local Time          | UNIX Time  |");
      System.out.println("|--------------------------------------------------------|");

      for (int i = 0; i < Integer.parseInt(args[0]); i++) {
        Date current_date = new Date();

        DateFormat date_format = new SimpleDateFormat("HH:mm:ss dd.MM.yyyy");
        String local_time = date_format.format(current_date);

        date_format.setTimeZone(TimeZone.getTimeZone("UTC"));
        String utc_time = date_format.format(current_date);

        long unix_time = System.currentTimeMillis() / 1000L;

        System.out.println("| " + utc_time + " | " + local_time + " | " + unix_time + " |");

        try {
          Thread.sleep(1000);
        }
        catch (InterruptedException ex) {
          Thread.currentThread().interrupt();
        }
      }

      System.out.println("|--------------------------------------------------------|");
    }
    else {
      System.out.println("Something is wrong!");
    }
  }
}
