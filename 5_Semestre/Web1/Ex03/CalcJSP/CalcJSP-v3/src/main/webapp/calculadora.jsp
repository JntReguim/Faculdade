<%@ page contentType="text/html" pageEncoding="UTF-8" %>
<%@ page isELIgnored="false" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<!DOCTYPE html>
<html lang="pt-BR" class="h-100">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Calculadora</title>
    <link href="bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="estilo.css">
    <script src="bootstrap.bundle.min.js" defer></script>
</head>

<jsp:useBean id="calc" class="br.ufscar.dc.dsw.bean.Calculadora" />
<jsp:setProperty name="calc" property="op1" value="${param.a}" />
<jsp:setProperty name="calc" property="op2" value="${param.b}" />

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
            <div class="container" style="padding: 90px 15px 0;">
                <div class="mb-3 row">
                    <table class="table">
                        <thead>
                            <tr>
                                <th><fmt:message key="op1" /></th>
                                <th><fmt:message key="op" /></th>
                                <th><fmt:message key="op2" /></th>
                                <th><fmt:message key="result" /></th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:forTokens items="+,-,*,/" delims="," var="op">
                                <jsp:setProperty name="calc" property="operator" value="${op}" />
                                <tr>
                                    <td>${param.a}</td>
                                    <td>${op}</td>
                                    <td>${param.b}</td>
                                    <td>
                                        <jsp:getProperty name="calc" property="result" />
                                    </td>
                                </tr>
                            </c:forTokens>
                        </tbody>
                    </table>
                </div>
                <div class="mb-3 row">
                    <a href="/CalculadoraJSP"><fmt:message key="back" /></a>
                </div>
            </div>
        </main>
    </fmt:bundle>
    <footer class="footer mt-auto py-3 bg-light align-items-center">
        <div class="container text-center">
            Departamento de Computação - Universidade Federal de São Carlos
        </div>
    </footer>
</body>

</html>