package br.ufscar.dc.dsw.controller;

import br.ufscar.dc.dsw.dao.TimeDAO;
import br.ufscar.dc.dsw.dao.JogadorDAO;
import br.ufscar.dc.dsw.domain.Time;
import br.ufscar.dc.dsw.domain.Jogador;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = "/jogadores/*")
public class JogadorController extends HttpServlet {

    private static final long serialVersionUID = 1L;
    
    private JogadorDAO dao;

    @Override
    public void init() {
        dao = new JogadorDAO();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException {
        doGet(request, response);
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException {
                
        String action = request.getPathInfo();
        if (action == null) {
            action = "";
        }

        try {
            switch (action) {
                case "/cadastro":
                    apresentaFormCadastro(request, response);
                    break;
                case "/insercao":
                    insere(request, response);
                    break;
                case "/remocao":
                    remove(request, response);
                    break;
                case "/edicao":
                    apresentaFormEdicao(request, response);
                    break;
                case "/atualizacao":
                    atualize(request, response);
                    break;
                default:
                    lista(request, response);
                    break;
            }
        } catch (RuntimeException | IOException | ServletException e) {
            throw new ServletException(e);
        }
    }

    private void lista(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        List<Jogador> listaJogadores = dao.getAll();
        request.setAttribute("listaJogadores", listaJogadores);
        request.setAttribute("contextPath", request.getContextPath().replace("/", ""));
        RequestDispatcher dispatcher = request.getRequestDispatcher("/jogador/lista.jsp");
        dispatcher.forward(request, response);
    }

    private Map<Long, String> getTimes() {
        Map<Long, String> times = new HashMap<>();
        for (Time time: new TimeDAO().getAll()) {
            times.put(time.getId(), time.getNome());
        }
        return times;
    }
    
    private void apresentaFormCadastro(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        request.setAttribute("times", getTimes());
        RequestDispatcher dispatcher = request.getRequestDispatcher("/jogador/formulario.jsp");
        dispatcher.forward(request, response);
    }

    private void apresentaFormEdicao(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Long id = Long.parseLong(request.getParameter("id"));
        Jogador jogador = dao.get(id);
        request.setAttribute("jogador", jogador);
        request.setAttribute("times", getTimes());
        RequestDispatcher dispatcher = request.getRequestDispatcher("/jogador/formulario.jsp");
        dispatcher.forward(request, response);
    }

    private void insere(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        
        String cpf = request.getParameter("cpf");
        String nome = request.getParameter("nome");
        String posicao = request.getParameter("posicao");
        int numero = Integer.parseInt(request.getParameter("numero"));
        int idade = Integer.parseInt(request.getParameter("idade"));
        float salario = Float.parseFloat(request.getParameter("salario"));
        
        Long timeID = Long.parseLong(request.getParameter("time"));
        Time time = new TimeDAO().get(timeID);
        
        Jogador jogador = new Jogador(cpf, nome, posicao, numero, idade, salario, time);
        dao.insert(jogador);
        response.sendRedirect("lista");
    }

    private void atualize(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        request.setCharacterEncoding("UTF-8");
        Long id = Long.parseLong(request.getParameter("id"));
        String cpf = request.getParameter("cpf");
        String nome = request.getParameter("nome");
        String posicao = request.getParameter("posicao");
        int numero = Integer.parseInt(request.getParameter("numero"));
        int idade = Integer.parseInt(request.getParameter("idade"));
        float salario = Float.parseFloat(request.getParameter("salario"));
        
        Long timeID = Long.parseLong(request.getParameter("time"));
        Time time = new TimeDAO().get(timeID);
        
        Jogador jogador = new Jogador(id, cpf, nome, posicao, numero, idade, salario, time);
        dao.update(jogador);
        response.sendRedirect("lista");
    }

    private void remove(HttpServletRequest request, HttpServletResponse response)
            throws IOException {
        Long id = Long.parseLong(request.getParameter("id"));

        Jogador jogador = new Jogador(id);
        dao.delete(jogador);
        response.sendRedirect("lista");
    }
}