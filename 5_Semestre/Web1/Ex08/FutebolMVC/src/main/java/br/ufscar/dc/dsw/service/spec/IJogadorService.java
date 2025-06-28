package br.ufscar.dc.dsw.service.spec;

import java.util.List;

import br.ufscar.dc.dsw.domain.Jogador;

public interface IJogadorService {
    Jogador buscarPorId(Long id);
	
	List<Jogador> buscarTodos();
	
	void salvar(Jogador jogador);
	
	void excluir(Long id);
}
