<%@ page contentType="text/html" pageEncoding="UTF-8" %> <%@ page
isELIgnored="false" %> <%@ taglib uri="http://java.sun.com/jsp/jstl/core"
prefix="c" %> <%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<!DOCTYPE html>
<html lang="pt-BR" class="h-100">
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <title><fmt:message key="conversorTitle" /></title>
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js"
            defer
        ></script>
    </head>

    <jsp:useBean id="conversor" class="br.ufscar.dc.dsw.bean.Conversor" />
    <jsp:setProperty name="conversor" property="valor" value="${valor}" />
    <jsp:setProperty
        name="conversor"
        property="tipoConversao"
        value="${opcao}"
    />

    <body class="d-flex flex-column h-100">
        <fmt:bundle basename="i18n.Messages">
            <header>
                <nav
                    class="navbar navbar-expand-md navbar-dark bg-primary fixed-top"
                >
                    <div class="container-fluid">
                        <h3 class="text-white">
                            <fmt:message key="conversorTitle" />
                        </h3>
                    </div>
                </nav>
            </header>

            <main class="flex-shrink-0">
                <div class="container" style="padding: 90px 15px 0">
                    <div class="mb-3 row">
                        <h3><fmt:message key="resultTitle" /></h3>
                    </div>
                    <div class="mb-3 row">
                        <c:choose>
                            <c:when test="${opcao == 'miToM'}">
                                <p>
                                    <fmt:message key="miToMResult">
                                        <fmt:param value="${valor}" />
                                        <fmt:param
                                            value="${conversor.resultado}"
                                        />
                                    </fmt:message>
                                </p>
                            </c:when>
                            <c:when test="${opcao == 'mToMi'}">
                                <p>
                                    <fmt:message key="mToMiResult">
                                        <fmt:param value="${valor}" />
                                        <fmt:param
                                            value="${conversor.resultado}"
                                        />
                                    </fmt:message>
                                </p>
                            </c:when>
                            <c:when test="${opcao == 'ftToM'}">
                                <p>
                                    <fmt:message key="ftToMResult">
                                        <fmt:param value="${valor}" />
                                        <fmt:param
                                            value="${conversor.resultado}"
                                        />
                                    </fmt:message>
                                </p>
                            </c:when>
                            <c:when test="${opcao == 'mToFt'}">
                                <p>
                                    <fmt:message key="mToFtResult">
                                        <fmt:param value="${valor}" />
                                        <fmt:param
                                            value="${conversor.resultado}"
                                        />
                                    </fmt:message>
                                </p>
                            </c:when>
                            <c:otherwise>
                                <p><fmt:message key="invalidConversion" /></p>
                            </c:otherwise>
                        </c:choose>
                    </div>
                    <div class="mb-3 row">
                        <a href="index.jsp" class="btn btn-primary"
                            ><fmt:message key="back"
                        /></a>
                    </div>
                </div>
            </main>
        </fmt:bundle>
    </body>
</html>
