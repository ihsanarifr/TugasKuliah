
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String userType = s.nextLine();
        
        User user = null;
        try {
            user = UserFactory.getUser(userType);
            user.login();
        } catch (Exception ex) {
            //Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("================= SYSTEM ERROR =============");
            System.out.println(ex.getMessage());
        }finally{
            System.out.println("Selesai");
        }
        
        //user.login();
    }
}
