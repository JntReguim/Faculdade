<%@ page contentType="text/html" pageEncoding="UTF-8" %> <%@ page
isELIgnored="false" %> <%@ taglib prefix="fmt"
uri="http://java.sun.com/jsp/jstl/fmt" %> <%@ taglib prefix="c"
uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html lang="pt-BR" class="h-100">
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <title>Calculadora - Erro</title>
        <link href="bootstrap.min.css" rel="stylesheet" />
        <link rel="stylesheet" type="text/css" href="estilo.css" />
        <script src="bootstrap.bundle.min.js" defer></script>
        <style>
            .back-link {
                color: #0d6efd;
                text-decoration: underline;
                cursor: pointer;
            }
            .back-link:hover {
                color: #0a58ca;
            }
        </style>
    </head>

    <body class="d-flex flex-column h-100">
        <header>
            <nav class="navbar navbar-expand-md navbar-dark fixed-top bg-light">
                <div class="container-fluid">
                    <h3>Desenvolvimento de Software para Web 1</h3>
                </div>
            </nav>
        </header>

        <fmt:bundle basename="i18n.Messages">
            <main class="flex-shrink-0">
                <div class="container" style="padding: 90px 15px 0">
                    <div class="mb-3 row">
                        <h3><fmt:message key="error" /></h3>
                    </div>
                    <div class="mb-3 row">
                        <p class="h5 text-dark">
                            <c:choose>
                                <c:when test="${param.errorType == 'value'}">
                                    <fmt:message key="invalidInput" />
                                </c:when>
                                <c:when test="${param.errorType == 'option'}">
                                    <fmt:message key="invalidInput2" />
                                </c:when>
                                <c:otherwise>
                                    <fmt:message key="invalidInput" /><br />
                                    <fmt:message key="invalidInput2" />
                                </c:otherwise>
                            </c:choose>
                        </p>
                    </div>
                    <div class="mb-3 row">
                        <span
                            class="back-link"
                            onclick="window.location.href='/CalculadoraJSP'"
                        >
                            <fmt:message key="back" />
                        </span>
                    </div>
                </div>
            </main>
        </fmt:bundle>

        <footer class="footer mt-auto py-3 bg-light">
            <div class="container text-center">
                Departamento de Computação - Universidade Federal de São Carlos
            </div>
        </footer>
    </body>
</html>
