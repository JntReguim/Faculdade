<%@ page contentType="text/html" pageEncoding="UTF-8" %>
<%@ page isELIgnored="false" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<!DOCTYPE html>
<html lang="pt-BR" class="h-100">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Calculadora</title>
    <!-- Bootstrap core CSS -->
    <link href="bootstrap.min.css" rel="stylesheet">
    <link rel = "stylesheet" type ="text/css" href = "estilo.css">
    <script src="bootstrap.bundle.min.js" defer></script>
</head>

<body class="d-flex flex-column h-100">
    <header>
        <!-- Fixed navbar -->
        <nav class="navbar navbar-expand-md navbar-dark fixed-top bg-light">
            <div class="container-fluid">
                <h3>Desenvolvimento de Software para Web 1</h3>
            </div>
        </nav>
    </header>

    <!-- Begin page content -->
    <fmt:bundle basename="i18n.Messages">
    <main class="flex-shrink-0">
        <div class="container" style="padding: 90px 15px 0;">
            <div class="mb-3 row">
                <h3><fmt:message key="error" /></h3>
            </div>
            <div class="mb-3 row">
                <a href="/CalculadoraJSP"><fmt:message key="back" /></a>
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