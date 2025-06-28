package br.ufscar.dc.dsw.controller;

import java.util.List;

import jakarta.validation.Valid;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import br.ufscar.dc.dsw.domain.Time;
import br.ufscar.dc.dsw.domain.Jogador;
import br.ufscar.dc.dsw.service.spec.ITimeService;
import br.ufscar.dc.dsw.service.spec.IJogadorService;

@Controller
@RequestMapping("/jogador")
public class JogadorController {

    @Autowired
    private IJogadorService jogadorService;

    @Autowired
    private ITimeService timeService;

    @GetMapping("/cadastrar")
    public String cadastrar(Jogador jogador) {
        return "jogador/cadastro";
    }

    @GetMapping("/listar")
    public String listar(ModelMap model) {
        model.addAttribute("jogadores", jogadorService.buscarTodos());
        return "jogador/lista";
    }

    @PostMapping("/salvar")
    public String salvar(@Valid Jogador jogador, BindingResult result, RedirectAttributes attr) {

        if (result.hasErrors()) {
            return "jogador/cadastro";
        }

        jogadorService.salvar(jogador);
        attr.addFlashAttribute("sucess", "Jogador inserido com sucesso");
        return "redirect:/jogador/listar";
    }

    @GetMapping("/editar/{id}")
    public String preEditar(@PathVariable("id") Long id, ModelMap model) {
        model.addAttribute("jogador", jogadorService.buscarPorId(id));
        return "jogador/cadastro";
    }

    @PostMapping("/editar")
    public String editar(@Valid Jogador jogador, BindingResult result, RedirectAttributes attr) {

        if (result.hasErrors()) {
            return "jogador/cadastro";
        }

        jogadorService.salvar(jogador);
        attr.addFlashAttribute("sucess", "Jogador editado com sucesso.");
        return "redirect:/jogador/listar";
    }

    @GetMapping("/excluir/{id}")
    public String excluir(@PathVariable("id") Long id, RedirectAttributes attr) {
        jogadorService.excluir(id);
        attr.addFlashAttribute("sucess", "Jogador excluído com sucesso.");
        return "redirect:/jogador/listar";
    }

    @ModelAttribute("times")
    public List<Time> listaTimes() {
        return timeService.buscarTodos();
    }
}