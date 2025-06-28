package br.ufscar.dc.dsw;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import br.ufscar.dc.dsw.dao.ITimeDAO;
import br.ufscar.dc.dsw.dao.IJogadorDAO;
import br.ufscar.dc.dsw.domain.Time;
import br.ufscar.dc.dsw.domain.Jogador;

@SpringBootApplication
public class FutebolMvcApplication {

    public static void main(String[] args) {
        SpringApplication.run(FutebolMvcApplication.class, args);
    }

    @Bean
    public CommandLineRunner demo(ITimeDAO timeDAO, IJogadorDAO jogadorDAO) {
        return (args) -> {
            
            // Inserindo os times
            Time t1 = new Time();
            t1.setCNPJ("12.345.678/0001-91");
            t1.setNome("Corinthians");
            t1.setAnoFundacao(1910);
            t1.setTitulos(30);
            timeDAO.save(t1);
            
            Time t2 = new Time();
            t2.setCNPJ("23.456.789/0001-92");
            t2.setNome("Palmeiras");
            t2.setAnoFundacao(1914);
            t2.setTitulos(25);
            timeDAO.save(t2);
            
            Time t3 = new Time();
            t3.setCNPJ("34.567.890/0001-93");
            t3.setNome("Santos");
            t3.setAnoFundacao(1912);
            t3.setTitulos(22);
            timeDAO.save(t3);
            
            // Inserindo os jogadores
            Jogador j1 = new Jogador();
            j1.setCpf("111.222.333-44");
            j1.setNome("Romero");
            j1.setPosicao("Atacante");
            j1.setNumero(9);
            j1.setIdade(28);
            j1.setSalario(500000.00f);
            j1.setTime(t1);
            jogadorDAO.save(j1);
            
            Jogador j2 = new Jogador();
            j2.setCpf("222.333.444-55");
            j2.setNome("Endrick");
            j2.setPosicao("Atacante");
            j2.setNumero(10);
            j2.setIdade(17);
            j2.setSalario(300000.00f);
            j2.setTime(t2);
            jogadorDAO.save(j2);
            
            Jogador j3 = new Jogador();
            j3.setCpf("333.444.555-66");
            j3.setNome("Neymar");
            j3.setPosicao("Atacante");
            j3.setNumero(10);
            j3.setIdade(31);
            j3.setSalario(1200000.00f);
            j3.setTime(t3);
            jogadorDAO.save(j3);
        };
    }
}