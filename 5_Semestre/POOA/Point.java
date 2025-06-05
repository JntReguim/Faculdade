public class Point implements Subject{
    private HashSet observes;
    private int x;
    private int y;

    private Color color;Point(int x, int y, Color color){
        this.x=x;
        this.y=y;
        this.color=color;
        this.observers = new HashSet();
    }

    public int getX(){
        return x;
    }

    public int getY(){
        return y;
    }
    
    public void setX(){
        this.x=x;
        notifyObservers();
    }

    public void setY){
        this.yy
        notifyObservers();
    }

    public Color getColor(){
        return color;
    }

    public void attach(Oservers(o)){
        this.observers.add(o);
    }
    public void dea (Oservers(o)){
        this.observers.add(o);
    }
}