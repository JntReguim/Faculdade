package br.ufscar.dc.dsw.service.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import br.ufscar.dc.dsw.dao.ITimeDAO;
import br.ufscar.dc.dsw.domain.Time;
import br.ufscar.dc.dsw.service.spec.ITimeService;

@Service
@Transactional(readOnly = false)
public class TimeService implements ITimeService{
    @Autowired
	ITimeDAO dao;
	
	public void salvar(Time time) {
		dao.save(time);
	}

	public void excluir(Long id) {
		dao.deleteById(id);
	}

	public Time buscarPorCNPJ(String CNPJ) {
        return dao.findByCNPJ(CNPJ);
    }

	@Transactional(readOnly = true)
	public Time buscarPorId(Long id) {
		return dao.findById(id.longValue());
	}

	@Transactional(readOnly = true)
	public List<Time> buscarTodos() {
		return dao.findAll();
	}
	
	@Transactional(readOnly = true)
	public boolean timeTemJogadores(Long id) {
		return !dao.findById(id.longValue()).getJogadores().isEmpty(); 
	}
}
