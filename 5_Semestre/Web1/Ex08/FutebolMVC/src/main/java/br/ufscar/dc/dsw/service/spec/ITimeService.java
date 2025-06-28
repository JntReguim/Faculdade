package br.ufscar.dc.dsw.service.spec;

import java.util.List;

import br.ufscar.dc.dsw.domain.Time;

public interface ITimeService {
    Time buscarPorId(Long id);

	Time buscarPorCNPJ(String CNPJ);

	List<Time> buscarTodos();

	void salvar(Time time);

	void excluir(Long id);
	
	boolean timeTemJogadores(Long id);
}
