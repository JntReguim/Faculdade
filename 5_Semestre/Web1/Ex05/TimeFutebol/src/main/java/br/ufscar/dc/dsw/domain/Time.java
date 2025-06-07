package br.ufscar.dc.dsw.domain;

public class Time {

    private Long id;
    private String cnpj;
    private String nome;
    private int anoFundacao;
    private int titulos;
    private int qtdeJogadores;

    public Time(Long id) {
        this.id = id;
    }

    public Time(String cnpj, String nome, int anoFundacao, int titulos) {
        this.cnpj = cnpj;
        this.nome = nome;
        this.anoFundacao = anoFundacao;
        this.titulos = titulos;
    }

    public Time(Long id, String cnpj, String nome, int anoFundacao, int titulos) {
        this(cnpj, nome, anoFundacao, titulos);
        this.id = id;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getCnpj() {
        return cnpj;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAnoFundacao() {
        return anoFundacao;
    }

    public void setAnoFundacao(int anoFundacao) {
        this.anoFundacao = anoFundacao;
    }

    public int getTitulos() {
        return titulos;
    }

    public void setTitulos(int titulos) {
        this.titulos = titulos;
    }

    public int getQtdeJogadores() {
        return qtdeJogadores;
    }

    public void setQtdeJogadores(int qtdeJogadores) {
        this.qtdeJogadores = qtdeJogadores;
    }
}