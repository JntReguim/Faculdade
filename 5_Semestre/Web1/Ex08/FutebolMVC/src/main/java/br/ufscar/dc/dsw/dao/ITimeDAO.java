package br.ufscar.dc.dsw.dao;

import java.util.List;

import org.springframework.data.repository.CrudRepository;

import br.ufscar.dc.dsw.domain.Time;

@SuppressWarnings("unchecked")
public interface ITimeDAO extends CrudRepository<Time, Long>{

	Time findById(long id);
	
	Time findByCNPJ (String CNPJ);

	List<Time> findAll();
	
	Time save(Time time);

	void deleteById(Long id);
}