package br.ufscar.dc.dsw.domain;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.Table;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;

@SuppressWarnings("serial")
@Entity
@Table(name = "Jogador")
public class Jogador extends AbstractEntity<Long> {

    @NotBlank(message = "{NotBlank.jogador.cpf}")
    @Size(max = 14)
    @Column(nullable = false, length = 14)
    private String cpf;

    @NotBlank(message = "{NotBlank.jogador.nome}")
    @Size(max = 100)
    @Column(nullable = false, length = 100)
    private String nome;
    
    @NotBlank(message = "{NotBlank.jogador.posicao}")
    @Size(max = 30)
    @Column(nullable = false, length = 30)
    private String posicao;
    
    @NotNull(message = "{NotNull.jogador.numero}")
    @Column(nullable = false)
    private Integer numero;
    
    @NotNull(message = "{NotNull.jogador.idade}")
    @Column(nullable = false)
    private Integer idade;
    
    @NotNull(message = "{NotNull.jogador.salario}")
    @Column(nullable = false, columnDefinition = "FLOAT DEFAULT 0.0")
    private Float salario;
    
    @NotNull(message = "{NotNull.jogador.time}")
    @ManyToOne
    @JoinColumn(name = "time_id")
    private Time time;

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