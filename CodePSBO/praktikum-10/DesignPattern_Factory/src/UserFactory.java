public class UserFactory {
    public static User getUser(String userType) throws Exception{
        if(userType.equals("Mahasiswa")){
            return new Mahasiswa();
        }else if(userType.equals("Dosen")){
            return new Dosen();
        }else{
             throw new Exception("user type tidak valid");
        }
    }
}
