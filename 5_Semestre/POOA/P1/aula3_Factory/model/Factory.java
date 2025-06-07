package P1.aula3_Factory.model;

public class Factory{
    private Factory(){}

    public static Cliente createCliFisico(){
        return new ClienteFisico();
    }

    public static Cliente createCliJuridico(){
        return new ClienteJuridico();
    }
}