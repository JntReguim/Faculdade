package P1.aula3_Factory.controller2;
import P1.aula3_Factory.model.Factory;

public class ClientCode2{
    public void usaServicos(){
        Interface2 clienteF = Factory.createCliFisico();
        Interface2 clienteJ = Factory.createCliJuridico();

        clienteF.m3();
        clienteF.m4();
    }
}