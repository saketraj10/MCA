import java.util.*;
class Box
{
    protected double length, width, height;
    Box(double l, double w, double h){
        length = l;
        width = w;
        height = h;
    }
    void calculate_volume(){
        System.out.println("Length = " + length);
        System.out.println("Breadth = " + width);
        System.out.println("Height = " + height);
        System.out.println("Volume = " + (length*width*height));
    }
}
class Boxmodel extends Box
{
    protected double weigth;
    protected String color;
    Boxmodel(double len, double wei, double hei, double w, String c)
    {
        super(len,wei,hei);
        weigth = w;
        color = c;
    }
    void calculate_volume()
    {
        super.calculate_volume();
        System.out.println("Weight = " + weigth);
        System.out.println("Color = " + color);
    }
    
}
class q1
{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Length, Width, Height, Weight and Color ?");
        double len = s.nextDouble();
        double wid = s.nextDouble();
        double hei = s.nextDouble();
        double w = s.nextDouble();
        String c = s.next();
        Boxmodel b1 = new Boxmodel(len, wid, hei, w, c);
        b1.calculate_volume();

        s.close();
    }
}