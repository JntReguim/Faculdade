package br.ufscar.dc.dsw.dao;

import java.util.List;

import org.springframework.data.repository.CrudRepository;

import br.ufscar.dc.dsw.domain.Editora;
import br.ufscar.dc.dsw.domain.Livro;

public interface ILivroDAO extends CrudRepository<Livro, Long> {
    List<Livro> findByEditora(Editora editora);
    
    List<Livro> findAllByOrderByPrecoAsc();
}