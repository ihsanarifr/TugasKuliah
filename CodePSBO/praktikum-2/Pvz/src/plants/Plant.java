package plants;

/**
 *
 * @author ihsanarifr
 */
public abstract class Plant {
    protected String name;
    protected int lifepoint;
    protected int cost;
    protected int x,y;
    
    public void paint(int x,int y){
        // menanam plant pada posisi x,y
    }
    
    public void kill(){
        // plant terbunuh oleh zombie
    }
    
    public void remote(){
        // plant dicongkel pake sekop
    }
    
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getLifepoint() {
        return lifepoint;
    }
    public void setLifepoint(int lifepoint) {
        this.lifepoint = lifepoint;
    }
    public int getCost() {
        return cost;
    }
    public void setCost(int cost) {
        this.cost = cost;
    }
    public int getX() {
        return x;
    }
    public void setX(int x) {
        this.x = x;
    }
    public int getY() {
        return y;
    }
    public void setY(int y) {
        this.y = y;
    }
}
