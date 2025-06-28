package br.ufscar.dc.dsw.controller;

import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import br.ufscar.dc.dsw.domain.Time;
import br.ufscar.dc.dsw.service.spec.ITimeService;

@Controller
@RequestMapping("/time")
public class TimeController {
    
    @Autowired
    private ITimeService service;
    
    @GetMapping("/cadastrar")
    public String cadastrar(Time time) {
        return "time/cadastro";
    }
    
    @GetMapping("/listar")
    public String listar(ModelMap model) {
        model.addAttribute("times", service.buscarTodos());
        return "time/lista";
    }
    
    @PostMapping("/salvar")
    public String salvar(@Valid Time time, BindingResult result, RedirectAttributes attr) {
        
        if (result.hasErrors()) {
            return "time/cadastro";
        }
        
        service.salvar(time);
        attr.addFlashAttribute("sucess", "Time inserido com sucesso.");
        return "redirect:/time/listar";
    }
    
    @GetMapping("/editar/{id}")
    public String preEditar(@PathVariable("id") Long id, ModelMap model) {
        model.addAttribute("time", service.buscarPorId(id));
        return "time/cadastro";
    }
    
    @PostMapping("/editar")
    public String editar(@Valid Time time, BindingResult result, RedirectAttributes attr) {
        
        // Apenas rejeita se o problema não for com o CNPJ (CNPJ campo read-only)
        if (result.getFieldErrorCount() > 1 || result.getFieldError("cnpj") == null) {
            return "time/cadastro";
        }

        service.salvar(time);
        attr.addFlashAttribute("sucess", "Time editado com sucesso.");
        return "redirect:/time/listar";
    }
    
    @GetMapping("/excluir/{id}")
    public String excluir(@PathVariable("id") Long id, ModelMap model) {
        if (service.timeTemJogadores(id)) {
            model.addAttribute("fail", "Time não excluído. Possui jogador(es) vinculado(s).");
        } else {
            service.excluir(id);
            model.addAttribute("sucess", "Time excluído com sucesso.");
        }
        return listar(model);
    }
}