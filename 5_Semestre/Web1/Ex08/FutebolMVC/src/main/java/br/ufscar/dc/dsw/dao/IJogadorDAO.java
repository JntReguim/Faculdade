package br.ufscar.dc.dsw.dao;

import java.util.List;

import org.springframework.data.repository.CrudRepository;

import br.ufscar.dc.dsw.domain.Jogador;

@SuppressWarnings("unchecked")
public interface IJogadorDAO extends CrudRepository<Jogador, Long>{

	Jogador findById(long id);

	List<Jogador> findAll();
	
	Jogador save(Jogador jogador);

	void deleteById(Long id);
}