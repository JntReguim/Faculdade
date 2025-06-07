package P1.aula3_Factory.controller1;
import P1.aula3_Factory.model.Factory;

public class ClientCode1{
    public void usaServicos(){
        Interface1 clienteF = Factory.createCliFisico();
        Interface1 clienteJ = Factory.createCliJuridico();

        clienteF.m1();
        clienteF.m2();
        clienteF.m3();
    }
}