package br.ufscar.dc.dsw.bean;

public class Conversor {
    private double valor;
    private String tipoConversao;

    public Conversor() {
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
        switch (tipoConversao) {
            case "miToM": // Milhas para metros
                return valor * 1609.34;
            case "mToMi": // Metros para milhas
                return valor / 1609.34;
            case "ftToM": // Pés para metros
                return valor * 0.3048;
            case "mToFt": // Metros para pés
                return valor / 0.3048;
            default:
                return 0;
        }
    }

    public String getMensagemResultado() {
        return tipoConversao;
    }
}