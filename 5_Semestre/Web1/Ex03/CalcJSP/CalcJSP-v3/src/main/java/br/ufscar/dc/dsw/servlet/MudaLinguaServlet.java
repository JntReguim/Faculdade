package br.ufscar.dc.dsw.servlet;

import java.io.IOException;
import java.util.Locale;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.jsp.jstl.core.Config;

@WebServlet(urlPatterns = { "/mudaLingua" })
public class MudaLinguaServlet extends HttpServlet {
   
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        String language = request.getParameter("lingua");
        Locale locale = new Locale(language);
        Config.set(request.getSession(), Config.FMT_LOCALE, locale);
        Config.set(request.getSession(), Config.FMT_FALLBACK_LOCALE, locale);
        response.sendRedirect("index.jsp");
    } 
}
