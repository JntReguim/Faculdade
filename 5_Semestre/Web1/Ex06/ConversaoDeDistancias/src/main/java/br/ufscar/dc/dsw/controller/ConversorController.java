package br.ufscar.dc.dsw.controller;

import java.util.Set;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import br.ufscar.dc.dsw.model.Conversor;

@Controller
public class ConversorController {

    private static final Set<String> OPCOES_VALIDAS = Set.of("miToM", "mToMi", "ftToM", "mToFt");

    @RequestMapping(value = "/conversor", method = { RequestMethod.GET, RequestMethod.POST })
    public String converter(
            @RequestParam(name = "valorStr", required = false) String valorStr,
            @RequestParam(name = "opcao", required = false) String opcao,
            Model model) {

        if (valorStr == null && opcao == null) {
            return "index";
        }

        try {
            if (valorStr == null || !valorStr.matches("^\\d+$")) {
                throw new IllegalArgumentException("invalidInput");
            }

            int valor = Integer.parseInt(valorStr);
            if (valor <= 0) {
                throw new IllegalArgumentException("invalidInput");
            }

            if (opcao == null || !OPCOES_VALIDAS.contains(opcao)) {
                throw new IllegalArgumentException("invalidInput");
            }

            Conversor conversor = new Conversor(valor, opcao);
            double resultado = conversor.getResultado();

            model.addAttribute("valor", valor);
            model.addAttribute("opcao", opcao);
            model.addAttribute("resultado", resultado);
            return "conversor";

        } catch (IllegalArgumentException e) {
            model.addAttribute("errorMessage", e.getMessage());
            return "erro";
        }
    }

    @RequestMapping(value = "/", method = RequestMethod.GET)
    public String redirectRoot() {
        return "redirect:/conversor";
    }
}
