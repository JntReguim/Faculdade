package P1.aula3_Factory.controller3;
import P1.aula3_Factory.model.Factory;

public class ClientCode3{
    public void usaServicos(){
        Interface3 clienteF = Factory.createCliFisico();
        Interface3 clienteJ = Factory.createCliJuridico();

        clienteF.m5();
        clienteF.m6();
    }
}