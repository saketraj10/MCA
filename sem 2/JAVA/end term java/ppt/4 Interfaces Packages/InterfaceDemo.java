

interface Area
{
    double pi = 3.14;
    double computeArea();
}
class Rectangle implements Area{
    private double length, width;

    public Rectangle(double len, double wid)
    {
        length = len;
        width = wid;
    }

    public double computeArea()
    {
        return length*width;
    }
}
class Circle implements Area{
    private double radius;
    public Circle(double rad){
        radius = rad;
    }

    public double computeArea(){
        return pi*radius*radius;
    }
    
}

public class InterfaceDemo {
    public static void main(String[] args) {
        Rectangle rec = new Rectangle(12,7);
        Circle cir = new Circle(10);

        Area ar;
        ar = rec;
        System.out.println("Area of rectangle: " + ar.computeArea());
        ar = cir;
        System.out.println("Area of circle: " + ar.computeArea());
    }
}
