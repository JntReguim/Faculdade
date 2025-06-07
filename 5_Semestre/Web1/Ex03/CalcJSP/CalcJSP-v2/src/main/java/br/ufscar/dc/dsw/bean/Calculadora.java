package br.ufscar.dc.dsw.bean;

public class Calculadora {

    private double op1;
    private double op2;
    private char operator;

    public Calculadora() {
    }

    public double getOp1() {
        return this.op1;
    }

    public void setOp1(double op1) {
        this.op1 = op1;
    }

    public double getOp2() {
        return this.op2;
    }

    public void setOp2(double op2) {
        this.op2 = op2;
    }

    public char getOperator() {
        return this.operator;
    }

    public void setOperator(char operator) {
        this.operator = operator;
    }

    public double getResult() {
        switch(operator) {
            case '+': {
                return op1 + op2;
            }
            case '-': {
                return op1 - op2;
            }
            case '*': {
                return op1 * op2;
            }
            default: {
                return op1 / op2;
            }
        }
    }
}
