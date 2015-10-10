package Zombies;
/**
 *
 * @author ihsanarifr
 */

import plants.*;

public class Zombie {
    protected String name;
    protected int life;
    protected int speed;
    protected int lane;
    protected int attactPoint;
    
    public void spawn(int lane){
        this.lane = lane;
    }
    
    public void attack(Plant target){
        // aksi menyerang zombi terhadap target plant sehingga mengurangi life point plant
        int plantLife = target.getLifepoint();
        plantLife -= this.attactPoint;
        target.setLifepoint(plantLife);
        
        if(target.getLifepoint() <=0)
            target.kill();
    }
    
    public void walk(){
        // berjalan
    }
    
    public void die(){
        // meninggalll
    }
    
    public void eatHouseOwnerBrain(){
        // game over
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getLife() {
        return life;
    }
    public void setLife(int life) {
        this.life = life;
    }
    public int getSpeed() {
        return speed;
    }
    public void setSpeed(int speed) {
        this.speed = speed;
    }
    public int getLane() {
        return lane;
    }
    public void setLane(int lane) {
        this.lane = lane;
    }
    public int getAttactPoint() {
        return attactPoint;
    }
    public void setAttactPoint(int attactPoint) {
        this.attactPoint = attactPoint;
    }
}
