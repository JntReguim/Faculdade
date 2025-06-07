package br.ufscar.dc.dsw.model;

public class Conversor {
    private double valor;
    private String tipoConversao;

    public Conversor() {
    }

    public Conversor(double valor, String tipoConversao) {
        this.valor = valor;
        this.tipoConversao = tipoConversao;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public String getTipoConversao() {
        return tipoConversao;
    }

    public void setTipoConversao(String tipoConversao) {
        this.tipoConversao = tipoConversao;
    }

    public double getResultado() {
        if (valor <= 0) {
            throw new IllegalArgumentException("Valor deve ser positivo.");
        }
        switch (tipoConversao) {
            case "miToM":
                return valor * 1609.34;
            case "mToMi":
                return valor / 1609.34;
            case "ftToM":
                return valor * 0.3048;
            case "mToFt":
                return valor / 0.3048;
            default:
                throw new IllegalArgumentException("Tipo de conversão inválido.");
        }
    }
}
