package br.ufscar.dc.dsw.validation;

import jakarta.validation.ConstraintValidator;
import jakarta.validation.ConstraintValidatorContext;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import br.ufscar.dc.dsw.dao.ITimeDAO;
import br.ufscar.dc.dsw.domain.Time;

@Component
public class UniqueCNPJValidator implements ConstraintValidator<UniqueCNPJ, String> {

    @Autowired
    private ITimeDAO dao;

    @Override
    public boolean isValid(String CNPJ, ConstraintValidatorContext context) {
        if (dao != null) {
            Time time = dao.findByCNPJ(CNPJ);
            return time == null;
        } else {
            // Durante a execução da classe FutebolMvcApplication
            // não há injeção de dependência
            return true;
        }

    }
}