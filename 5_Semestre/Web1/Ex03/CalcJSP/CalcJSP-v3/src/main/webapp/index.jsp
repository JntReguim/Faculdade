<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ page isELIgnored="false"%>
<html>

<head>
    <title>Calculadora</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- Bootstrap core CSS -->
    <link href="bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="estilo.css">
    <script src="bootstrap.bundle.min.js" defer></script>
</head>

<body class="d-flex flex-column h-100">
    <header>
        <!-- Fixed navbar -->
        <nav class="navbar navbar-expand-md navbar-dark fixed-top bg-light">
            <div class="container-fluid">
                <h3>Desenvolvimento de Software para Web 1</h3>
                <div>
                    <a href="mudaLingua?lingua=pt"><img src="images/Brasil.gif" width="20"></a>
                    <a href="mudaLingua?lingua=en"><img src="images/EstadosUnidos.gif" width="20"></a>
                    <a href="mudaLingua?lingua=fr"><img src="images/Franca.gif" width="20"></a>
                    <a href="mudaLingua?lingua=ja"><img src="images/Japao.gif" width="20"></a>
                </div>
        </nav>
    </header>
    <main class="flex-shrink-0">
        <div class="container" style="padding: 90px 15px 0;">
            <jsp:useBean id="now" class="java.util.Date" />
            <h4>
                <fmt:formatDate value="${now}" dateStyle="full" /> &#149;
                <fmt:formatDate value="${now}" type="time" />
            </h4>


            <fmt:bundle basename="i18n.Messages">
                <form class="row g-0" action="valida" name="entrada" method="POST">
                    <div class="mb-3 row">
                        <label for="a" class="form-label">
                            <fmt:message key="op1" />
                        </label>
                        <input type="number" class="form-control" id="a" name="a" step="0.01" value="0" min="-1000"
                            max="1000">
                    </div>
                    <div class="mb-3 row">
                        <label for="b" class="form-label">
                            <fmt:message key="op2" />
                        </label>
                        <input type="number" class="form-control" id="b" name="b" step="0.01" value="0" min="-1000"
                            max="1000">
                    </div>
                    <div>
                        <button type="submit" class="btn btn-primary mb-3">
                            <fmt:message key="submit" />
                        </button>
                    </div>
                </form>
            </fmt:bundle>
        </div>
    </main>
    <footer class="footer mt-auto py-3 bg-light">
        <div class="container text-center">
            Departamento de Computação - Universidade Federal de São Carlos
        </div>
    </footer>
</body>

</html>