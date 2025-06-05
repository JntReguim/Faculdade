package br.ufscar.dc.dsw.domain;

public class Jogador {

    private Long id;
    private String cpf;
    private String nome;
    private String posicao;
    private Integer numero;
    private Integer idade;
    private Float salario;
    private Time time;

    public Jogador(Long id) {
        this.id = id;
    }

    public Jogador(String cpf, String nome, String posicao, Integer numero, 
            Integer idade, Float salario, Time time) {
        this.cpf = cpf;
        this.nome = nome;
        this.posicao = posicao;
        this.numero = numero;
        this.idade = idade;
        this.salario = salario;
        this.time = time;
    }

    public Jogador(Long id, String cpf, String nome, String posicao, Integer numero,
            Integer idade, Float salario, Time time) {
        this(cpf, nome, posicao, numero, idade, salario, time);
        this.id = id;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getPosicao() {
        return posicao;
    }

    public void setPosicao(String posicao) {
        this.posicao = posicao;
    }

    public Integer getNumero() {
        return numero;
    }

    public void setNumero(Integer numero) {
        this.numero = numero;
    }

    public Integer getIdade() {
        return idade;
    }

    public void setIdade(Integer idade) {
        this.idade = idade;
    }

    public Float getSalario() {
        return salario;
    }

    public void setSalario(Float salario) {
        this.salario = salario;
    }

    public Time getTime() {
        return time;
    }

    public void setTime(Time time) {
        this.time = time;
    }
}