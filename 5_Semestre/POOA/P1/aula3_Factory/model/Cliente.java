package P1.aula3_Factory.model;

import P1.aula3_Factory.controller1.Interface1;
import P1.aula3_Factory.controller2.Interface2;
import P1.aula3_Factory.controller3.Interface3;

abstract class Cliente implements Interface1, Interface2, Interface3{
    private Integer nome;

    public abstract int calcular();

    public abstract void m1();
    public abstract void m2();
    public abstract void m3();
    public abstract void m4();
    public abstract void m5();
    public abstract void m6();
}