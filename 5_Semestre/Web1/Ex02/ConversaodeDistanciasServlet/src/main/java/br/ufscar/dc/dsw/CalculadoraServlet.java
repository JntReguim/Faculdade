package br.ufscar.dc.dsw;

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet(name = "CalculadoraServlet", urlPatterns = {"/apresenta"})
public class CalculadoraServlet extends HttpServlet {

    private float converter(float valor, String opcao) {
        switch (opcao) {
            case "mi-m": return valor * 1609.34f;
            case "m-mi": return valor / 1609.34f;
            case "ft-m": return valor * 0.3048f;
            case "m-ft": return valor / 0.3048f;
            default:
                throw new IllegalArgumentException("Opção de conversão inválida");
        }
    }

    private String labelOrigem(String opcao) {
        switch (opcao) {
            case "mi-m": return "milha(s)";
            case "m-mi": return "metro(s)";
            case "m-ft": return "metro(s)";
            case "ft-m": return "pé(s)";
            default:      return "";
        }
    }

    private String labelDestino(String opcao) {
        switch (opcao) {
            case "mi-m": return "metro(s)";
            case "m-mi": return "milha(s)";
            case "ft-m": return "metro(s)";
            case "m-ft": return "pé(s)";
            default:      return "";
        }
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String valorParam = request.getParameter("valor");
        String opcao      = request.getParameter("opcao");

        // parseInt garante que é inteiro
        int valorInt     = Integer.parseInt(valorParam);
        float resultado  = converter(valorInt, opcao);

        String uniOrig = labelOrigem(opcao);
        String uniDest = labelDestino(opcao);

        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            out.println("<!DOCTYPE html>");
            out.println("<html lang=\"pt-BR\" class=\"h-100\">");
            out.println("<head>");
            out.println("  <meta charset=\"utf-8\">");
            out.println("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            out.println("  <title>Resultado da Conversão</title>");
            out.println("  <link href=\"bootstrap.min.css\" rel=\"stylesheet\">");
            out.println("  <script src=\"bootstrap.bundle.min.js\" defer></script>");
            out.println("</head>");
            out.println("<body class=\"d-flex flex-column h-100\">");
            out.println("  <header>");
            out.println("    <nav class=\"navbar navbar-expand-md navbar-dark bg-light fixed-top\">");
            out.println("      <div class=\"container-fluid\">");
            out.println("        <h3>Conversor de Distâncias</h3>");
            out.println("      </div>");
            out.println("    </nav>");
            out.println("  </header>");
            out.println("  <main class=\"flex-shrink-0\">");
            out.println("    <div class=\"container\" style=\"padding: 90px 15px 0;\">");
            out.println("      <table class=\"table table-bordered\">");
            out.println("        <thead><tr><th>Valor</th><th>Conversão</th><th>Resultado</th></tr></thead>");
            out.println("        <tbody><tr>");
            out.println("          <td>" + valorInt + " " + uniOrig + "</td>");
            out.println("          <td>" + uniOrig + " → " + uniDest + "</td>");
            out.printf  ("          <td>%.2f %s</td>%n", resultado, uniDest);
            out.println("        </tr></tbody>");
            out.println("      </table>");
            out.println("      <a href=\"index.html\" class=\"btn btn-secondary\">← Nova Conversão</a>");
            out.println("    </div>");
            out.println("  </main>");
            out.println("  <footer class=\"footer mt-auto py-3 bg-light text-center\">");
            out.println("    Departamento de Computação - UFSCar");
            out.println("  </footer>");
            out.println("</body>");
            out.println("</html>");
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

