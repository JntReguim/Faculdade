package br.ufscar.dc.dsw.service.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import br.ufscar.dc.dsw.dao.IJogadorDAO;
import br.ufscar.dc.dsw.domain.Jogador;
import br.ufscar.dc.dsw.service.spec.IJogadorService;

@Service
@Transactional(readOnly = false)
public class JogadorService implements IJogadorService{
    @Autowired
	IJogadorDAO dao;
	
	public void salvar(Jogador jogador) {
		dao.save(jogador);
	}

	public void excluir(Long id) {
		dao.deleteById(id);
	}

	@Transactional(readOnly = true)
	public Jogador buscarPorId(Long id) {
		return dao.findById(id.longValue());
	}

	@Transactional(readOnly = true)
	public List<Jogador> buscarTodos() {
		return dao.findAll();
	}
}
