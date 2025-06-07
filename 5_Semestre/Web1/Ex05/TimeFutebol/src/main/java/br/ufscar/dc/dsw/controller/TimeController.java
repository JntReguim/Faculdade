package br.ufscar.dc.dsw.controller;

import br.ufscar.dc.dsw.dao.TimeDAO;
import br.ufscar.dc.dsw.domain.Time;

import java.io.IOException;
import java.util.List;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = "/times/*")
public class TimeController extends HttpServlet {

    private static final long serialVersionUID = 1L;
    
    private TimeDAO dao;

    @Override
    public void init() {
        dao = new TimeDAO();
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
        List<Time> listaTimes = dao.getAll();
        request.setAttribute("listaTimes", listaTimes);
        request.setAttribute("contextPath", request.getContextPath().replace("/", ""));
        RequestDispatcher dispatcher = request.getRequestDispatcher("/time/lista.jsp");
        dispatcher.forward(request, response);
    }

    private void apresentaFormCadastro(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        RequestDispatcher dispatcher = request.getRequestDispatcher("/time/formulario.jsp");
        dispatcher.forward(request, response);
    }

    private void apresentaFormEdicao(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Long id = Long.parseLong(request.getParameter("id"));
        Time time = dao.get(id);
        RequestDispatcher dispatcher = request.getRequestDispatcher("/time/formulario.jsp");
        request.setAttribute("time", time);
        dispatcher.forward(request, response);
    }

    private void insere(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");

        String cnpj = request.getParameter("cnpj");
        String nome = request.getParameter("nome");
        int anoFundacao = Integer.parseInt(request.getParameter("anoFundacao"));
        int titulos = Integer.parseInt(request.getParameter("titulos"));

        Time time = new Time(cnpj, nome, anoFundacao, titulos);

        dao.insert(time);
        response.sendRedirect("lista");
    }

    private void atualize(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        request.setCharacterEncoding("UTF-8");
        Long id = Long.parseLong(request.getParameter("id"));
        String cnpj = request.getParameter("cnpj");
        String nome = request.getParameter("nome");
        int anoFundacao = Integer.parseInt(request.getParameter("anoFundacao"));
        int titulos = Integer.parseInt(request.getParameter("titulos"));
        
        Time time = new Time(id, cnpj, nome, anoFundacao, titulos);

        dao.update(time);
        response.sendRedirect("lista");
    }

    private void remove(HttpServletRequest request, HttpServletResponse response)
            throws IOException {
        Long id = Long.parseLong(request.getParameter("id"));

        Time time = new Time(id);
        dao.delete(time);
        response.sendRedirect("lista");
    }
}