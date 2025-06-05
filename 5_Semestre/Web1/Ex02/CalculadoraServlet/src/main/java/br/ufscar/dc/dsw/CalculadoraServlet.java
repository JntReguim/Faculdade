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

    private float resultado(float A, char op, float B) {
        switch (op) {
            case '+': {
                return A + B;
            }
            case '-': {
                return A - B;
            }
            case '*': {
                return A * B;
            }
            default:
                return A / B;
        }
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            
            String paramA = request.getParameter("a");
            float A = Float.parseFloat(paramA);
            String paramB = request.getParameter("b");
            float B = Float.parseFloat(paramB);
            
            out.println("<!DOCTYPE html>");
            out.println("<html lang=\"pt-BR\" class=\"h-100\">");
            out.println("   <head>");
            out.println("       <meta charset=\"utf-8\">");
            out.println("       <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            out.println("       <title>Calculadora</title>");
            out.println("       <link href=\"bootstrap.min.css\" rel=\"stylesheet\">");
            out.println("       <link rel = \"stylesheet\" type =\"text/css\" href = \"estilo.css\">");
            out.println("       <script src=\"bootstrap.bundle.min.js\" defer></script>");
            out.println("   </head>");
            out.println("   <body class=\"d-flex flex-column h-100\">");
            out.println("       <header>");
            out.println("           <nav class=\"navbar navbar-expand-md navbar-dark fixed-top bg-light\">");
            out.println("               <div class=\"container-fluid\">");
            out.println("                   <h3>Desenvolvimento de Software para Web 1</h3>");
            out.println("               </div>");
            out.println("           </nav>");
            out.println("       </header>");
            out.println("       <main class=\"flex-shrink-0\">");
            out.println("           <div class=\"container\" style=\"padding: 90px 15px 0;\">");
            out.println("               <div class=\"mb-3 row\">");
            out.println("                   <table class=\"table\">");
            out.println("                       <thead>");
            out.println("                           <tr>");
            out.println("                               <th >A</th>");
            out.println("                               <th>Op</th>");
            out.println("                               <th>B</th>");
            out.println("                               <th>Resultado</th>");
            out.println("                           </tr>");
            out.println("                       </thead>");
            out.println("                       <tbody>");
            char operações [] = {'+', '-', '*', '/'};
            for (char op : operações) {
                out.println("                       <tr>");
                out.println("                           <td>" + paramA +"</td>");
                out.println("                           <td>" + op + "</td>");
                out.println("                           <td>" + paramB + "</td>");
                out.println("                           <td>" + resultado(A, op, B) + "</td>");
                out.println("                       </tr>");
            } 
            out.println("                       </tbody>");
            out.println("                   </table>");
            out.println("               </div>");
            out.println("               <div class=\"mb-3 row\">");
            out.println("                   <a href=\"/CalculadoraServlet\">Retorne à página principal</a>");
            out.println("               </div>");
            out.println("           </div>");
            out.println("       </main>");
            out.println("       <footer class=\"footer mt-auto py-3 bg-light align-items-center\">");
            out.println("           <div class=\"container text-center\">");
            out.println("               Departamento de Computação - Universidade Federal de São Carlos");
            out.println("           </div>");
            out.println("       </footer>");
            out.println("   </body>");
            out.println("</html>");
            
            
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