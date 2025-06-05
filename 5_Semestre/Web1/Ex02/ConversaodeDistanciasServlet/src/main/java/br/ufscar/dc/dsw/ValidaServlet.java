package br.ufscar.dc.dsw;

import java.io.IOException;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet(name = "ValidaServlet", urlPatterns = {"/calculadora"})
public class ValidaServlet extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String valorParam = request.getParameter("valor");
        String opcao     = request.getParameter("opcao");

        try {

            if (valorParam == null || valorParam.isBlank()) {
                throw new IllegalArgumentException("Valor não informado");
            }

            Integer.parseInt(valorParam);

            if (!("mi-m".equals(opcao)
               || "m-mi".equals(opcao)
               || "ft-m".equals(opcao)
               || "m-ft".equals(opcao))) {
                throw new IllegalArgumentException("Opção inválida");
            }

            request.getRequestDispatcher("/apresenta").forward(request, response);

        } catch (Exception e) {
            response.sendRedirect("erro.html");
        }
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        processRequest(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        processRequest(req, resp);
    }
}

