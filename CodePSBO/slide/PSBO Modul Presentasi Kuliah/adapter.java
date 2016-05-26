//Before
//Because the interface between Line and Rectangle objects is 
//incompatible, the user has to recover the type of each shape and manually supply the correct arguments. 
 
class LegacyLine
{
    public void draw(int x1, int y1, int x2, int y2)
    {
        System.out.println("line from (" + x1 + ',' + y1 + ") to (" + x2 + ',' 
          + y2 + ')');
    }
}
 
class LegacyRectangle
{
    public void draw(int x, int y, int w, int h)
    {
        System.out.println("rectangle at (" + x + ',' + y + ") with width " + w
          + " and height " + h);
    }
}
 
public class AdapterDemo
{
    public static void main(String[] args)
    {
        Object[] shapes = 
        {
            new LegacyLine(), new LegacyRectangle()
        };
        // A begin and end point from a graphical editor
        int x1 = 10, y1 = 20;
        int x2 = 30, y2 = 60;
        for (int i = 0; i < shapes.length; ++i)
          if (shapes[i].getClass().getName().equals("LegacyLine"))
            ((LegacyLine)shapes[i]).draw(x1, y1, x2, y2);
          else if (shapes[i].getClass().getName().equals("LegacyRectangle"))
            ((LegacyRectangle)shapes[i]).draw(Math.min(x1, x2), Math.min(y1, y2)
              , Math.abs(x2 - x1), Math.abs(y2 - y1));
    }
}
//line from (10,20) to (30,60)
//rectangle at (10,20) with width 20 and height 40
 
 
 
//After
//The Adapter’s “extra level of indirection” takes care of mapping
//a user-friendly common interface to legacy-speciﬁc peculiar interfaces. 
 
class LegacyLine
{
    public void draw(int x1, int y1, int x2, int y2)
    {
        System.out.println("line from (" + x1 + ',' + y1 + ") to (" + x2 + ',' 
          + y2 + ')');
    }
}
 
class LegacyRectangle
{
    public void draw(int x, int y, int w, int h)
    {
        System.out.println("rectangle at (" + x + ',' + y + ") with width " + w
          + " and height " + h);
    }
}
 
interface Shape
{
  void draw(int x1, int y1, int x2, int y2);
}
 
class Line implements Shape
{
    private LegacyLine adaptee = new LegacyLine();
    public void draw(int x1, int y1, int x2, int y2)
    {
        adaptee.draw(x1, y1, x2, y2);
    }
}
 
class Rectangle implements Shape
{
    private LegacyRectangle adaptee = new LegacyRectangle();
    public void draw(int x1, int y1, int x2, int y2)
    {
        adaptee.draw(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x2 - x1),
          Math.abs(y2 - y1));
    }
}
 
public class AdapterDemo
{
    public static void main(String[] args)
    {
        Shape[] shapes = 
        {
            new Line(), new Rectangle()
        };
        // A begin and end point from a graphical editor
        int x1 = 10, y1 = 20;
        int x2 = 30, y2 = 60;
        for (int i = 0; i < shapes.length; ++i)
          shapes[i].draw(x1, y1, x2, y2);
    }
}
//line from (10,20) to (30,60)
//rectangle at (10,20) with width 20 and height 40
