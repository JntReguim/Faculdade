<%@ page contentType="text/html;charset=UTF-8" %>
<%@ page pageEncoding="UTF-8" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ page isELIgnored="false" %>

<html>
<head>
    <fmt:bundle basename="i18n.Messages">
        <title><fmt:message key="conversorTitle" /></title>
    </fmt:bundle>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="estilo.css">
    <script src="bootstrap.bundle.min.js" defer></script>
</head>

<body class="d-flex flex-column h-100">
    <header>
        <nav class="navbar navbar-expand-md navbar-dark fixed-top bg-light">
            <div class="container-fluid">
                <h3>Desenvolvimento de Software para Web 1</h3>
                <div>
                    <a href="mudaLingua?lingua=pt"><img src="images/Brasil.gif" width="20"></a>
                    <a href="mudaLingua?lingua=en"><img src="images/EstadosUnidos.gif" width="20"></a>
                </div>
            </div>
        </nav>
    </header>

    <main class="flex-shrink-0">
        <div class="container" style="padding: 90px 15px 0;">
            <fmt:bundle basename="i18n.Messages">
                <form class="row g-0" action="valida" method="POST">
                    <div class="mb-3 row">
                        <label for="opcao" class="form-label">
                            <fmt:message key="conversionType" />
                        </label>
                        <select class="form-select" name="opcao" id="opcao" required>
                            <option value="">-- <fmt:message key="selectConversion" /> --</option>
                            <option value="miToM"><fmt:message key="miToM" /></option>
                            <option value="mToMi"><fmt:message key="mToMi" /></option>
                            <option value="ftToM"><fmt:message key="ftToM" /></option>
                            <option value="mToFt"><fmt:message key="mToFt" /></option>
                        </select>
                    </div>
                    <div class="mb-3 row">
                        <label for="valor" class="form-label">
                            <fmt:message key="value" />
                        </label>
                        <input type="text" class="form-control" id="valor" name="valor" required>
                    </div>
                    <div>
                        <button type="submit" class="btn btn-primary mb-3">
                            <fmt:message key="convertButton" />
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