package br.ufscar.dc.dsw.conversor;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.convert.converter.Converter;
import org.springframework.stereotype.Component;

import br.ufscar.dc.dsw.domain.Time;
import br.ufscar.dc.dsw.service.spec.ITimeService;

@Component
public class TimeConversor implements Converter<String, Time>{

	@Autowired
	private ITimeService service;
	
	@Override
	public Time convert(String text) {
		
		if (text.isEmpty()) {
		 return null;	
		}
		
		Long id = Long.valueOf(text);	
		return service.buscarPorId(id);
	}
}