package br.ufscar.dc.dsw.domain;

import java.util.List;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.OneToMany;
import jakarta.persistence.Table;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;

import br.ufscar.dc.dsw.validation.UniqueCNPJ;

@SuppressWarnings("serial")
@Entity
@Table(name = "Time")
public class Time extends AbstractEntity<Long> {

    @UniqueCNPJ(message = "{Unique.time.CNPJ}")
    @NotBlank
    @Size(min = 18, max = 18, message = "{Size.time.CNPJ}")
    @Column(nullable = false, unique = true, length = 18)
    private String CNPJ;
    
    @NotBlank
    @Size(min = 3, max = 100)
    @Column(nullable = false, length = 100)
    private String nome;

    @NotNull
    @Column(nullable = false)
    private Integer anoFundacao;

    @NotNull
    @Column(nullable = false)
    private Integer titulos;

    @OneToMany(mappedBy = "time")
    private List<Jogador> jogadores;
    
    public String getCNPJ() {
        return CNPJ;
    }

    public void setCNPJ(String CNPJ) {
        this.CNPJ = CNPJ;
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Integer getAnoFundacao() {
        return anoFundacao;
    }

    public void setAnoFundacao(Integer anoFundacao) {
        this.anoFundacao = anoFundacao;
    }

    public Integer getTitulos() {
        return titulos;
    }

    public void setTitulos(Integer titulos) {
        this.titulos = titulos;
    }

    public List<Jogador> getJogadores() {
        return jogadores;
    }

    public void setJogadores(List<Jogador> jogadores) {
        this.jogadores = jogadores;
    }
}