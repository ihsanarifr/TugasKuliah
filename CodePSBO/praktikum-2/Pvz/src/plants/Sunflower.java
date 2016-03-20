package plants;
/**
 *
 * @author ihsanarifr
 */
public class Sunflower extends ProducerPlant{
    
    public Sunflower(){
        this.name = "Sunflower";
        this.cost= 50;
        this.lifepoint = 6;
        this.x = 0;
        this.y = 0;
        this.sunRate = 3; // 3 sun per menit
        this.sunAmount = 25; // 25 sun setiap kali produksi
    }

    @Override
    public void produceSun() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}
