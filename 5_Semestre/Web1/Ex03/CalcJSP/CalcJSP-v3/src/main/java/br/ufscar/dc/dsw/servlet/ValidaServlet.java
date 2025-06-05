package br.ufscar.dc.dsw.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet(name = "ValidaServlet", urlPatterns = {"/valida"})
public class ValidaServlet extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            
            try {
                Float.parseFloat(request.getParameter("a"));
                float b = Float.parseFloat(request.getParameter("b"));
                if (b == 0) {
                    throw new ServletException("Divisão por zero");
                }
                request.getRequestDispatcher("/calculadora.jsp").forward(request, response);

            } catch(Exception e) {
                response.sendRedirect("erro.jsp");
            }
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