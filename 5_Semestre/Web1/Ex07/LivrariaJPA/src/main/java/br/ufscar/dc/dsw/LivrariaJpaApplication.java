package br.ufscar.dc.dsw;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import br.ufscar.dc.dsw.dao.IEditoraDAO;
import br.ufscar.dc.dsw.dao.ILivroDAO;
import br.ufscar.dc.dsw.domain.Editora;
import br.ufscar.dc.dsw.domain.Livro;

import java.math.BigDecimal;
import java.util.Arrays;

@SpringBootApplication
public class LivrariaJpaApplication {

    private static final Logger log = LoggerFactory.getLogger(LivrariaJpaApplication.class);

    public static void main(String[] args) {
        SpringApplication.run(LivrariaJpaApplication.class, args);
    }

    @Bean
    public CommandLineRunner demo(ILivroDAO livroDAO, IEditoraDAO editoraDAO) {
        return (args) -> {
            livroDAO.deleteAll();
            editoraDAO.deleteAll();

            Editora companhia = new Editora("55.789.390/0008-99", "Companhia das Letras");
            Editora record = new Editora("71.150.470/0001-40", "Record");
            Editora objetiva = new Editora("32.106.536/0001-82", "Objetiva");
            Editora seguinte = new Editora("87.557.922/0001-82", "Seguinte");
            
            editoraDAO.saveAll(Arrays.asList(companhia, record, objetiva, seguinte));
            log.info("Editoras adicionadas");

            Livro ensaio = new Livro();
            ensaio.setTitulo("Ensaio sobre a Cegueira");
            ensaio.setAutor("José Saramago");
            ensaio.setAno(1995);
            ensaio.setPreco(BigDecimal.valueOf(54.9));
            ensaio.setEditora(companhia);

            Livro cemAnos = new Livro();
            cemAnos.setTitulo("Cem anos de Solidão");
            cemAnos.setAutor("Gabriel Garcia Márquez");
            cemAnos.setAno(1977);
            cemAnos.setPreco(BigDecimal.valueOf(59.9));
            cemAnos.setEditora(record);

            Livro dialogos = new Livro();
            dialogos.setTitulo("Diálogos Impossíveis");
            dialogos.setAutor("Luis Fernando Verissimo");
            dialogos.setAno(2012);
            dialogos.setPreco(BigDecimal.valueOf(22.9));
            dialogos.setEditora(objetiva);

            Livro curinga = new Livro();
            curinga.setTitulo("O Dia do Curinga");
            curinga.setAutor("Jostein Gaarder");
            curinga.setAno(1996);
            curinga.setPreco(BigDecimal.valueOf(29.99));
            curinga.setEditora(seguinte);

            Livro revolucao = new Livro();
            revolucao.setTitulo("A Revolução dos Bichos");
            revolucao.setAutor("George Orwell");
            revolucao.setAno(2007);
            revolucao.setPreco(BigDecimal.valueOf(23.90));
            revolucao.setEditora(companhia);

            livroDAO.saveAll(Arrays.asList(ensaio, cemAnos, dialogos, curinga, revolucao));
            log.info("Livros adicionados");

            log.info("Livros ordenados por preço:");
            log.info("--------------------------------");
            livroDAO.findAllByOrderByPrecoAsc().forEach(livro -> log.info(livro.toString()));
            log.info("");
        };
    }
}