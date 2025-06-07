package br.ufscar.dc.dsw.servlet;

import java.io.IOException;
import java.util.Set;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet(name = "ValidaServlet", urlPatterns = {"/valida"})
public class ValidaServlet extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        try {
            String valorStr = request.getParameter("valor");
            String opcao = request.getParameter("opcao");

            // Validação do valor
            if (valorStr == null || valorStr.isEmpty()) {
                throw new ServletException("Valor não fornecido");
            }
            
            // Verifica o formato do número
            if (!valorStr.matches("^\\d+(\\.\\d{1,2})?$")) {
                throw new ServletException("Formato numérico inválido. Use números com até 2 casas decimais.");
            }
            
            double valor = Double.parseDouble(valorStr);
            if (valor <= 0) {
                throw new ServletException("O valor deve ser maior que zero");
            }

            Set<String> opcoesValidas = Set.of("miToM", "mToMi", "ftToM", "mToFt");
            if (opcao == null || !opcoesValidas.contains(opcao)) {
                throw new ServletException("Opção inválida");
            }

            request.setAttribute("valor", valor);
            request.setAttribute("opcao", opcao);
            request.getRequestDispatcher("/calculadora.jsp").forward(request, response);

        } catch (Exception e) {
            request.setAttribute("errorMessage", e.getMessage());
            request.getRequestDispatcher("/erro.jsp").forward(request, response);
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }
}