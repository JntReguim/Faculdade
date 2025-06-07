<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"
isELIgnored="false" %> <%@ taglib prefix="c"
uri="http://java.sun.com/jsp/jstl/core" %> <%@ taglib prefix="fmt"
uri="http://java.sun.com/jsp/jstl/fmt" %>

<html>
    <fmt:bundle basename="message">
        <head>
            <meta charset="UTF-8" />
            <title><fmt:message key="page.title" /></title>
        </head>
        <body>
            <div align="center">
                <h1><fmt:message key="teams.welcome" /></h1>
                <h2>
                    <a href="${pageContext.request.contextPath}">
                        <fmt:message key="main.link" />
                    </a>
                    &nbsp;&nbsp;&nbsp;
                    <a href="${pageContext.request.contextPath}/times/cadastro">
                        <fmt:message key="teams.create" />
                    </a>
                </h2>
            </div>

            <div align="center">
                <fmt:message key="confirm.link" var="confirmMsg" />

                <table border="1">
                    <caption>
                        <fmt:message key="teams.list" />
                    </caption>
                    <tr>
                        <th><fmt:message key="team.ID" /></th>
                        <th><fmt:message key="team.cnpj" /></th>
                        <th><fmt:message key="team.name" /></th>
                        <th><fmt:message key="team.foundation_year" /></th>
                        <th><fmt:message key="team.titles" /></th>
                        <th><fmt:message key="actions.link" /></th>
                    </tr>
                    <c:forEach var="time" items="${listaTimes}">
                        <tr>
                            <td><c:out value="${time.id}" /></td>
                            <td><c:out value="${time.cnpj}" /></td>
                            <td><c:out value="${time.nome}" /></td>
                            <td><c:out value="${time.anoFundacao}" /></td>
                            <td><c:out value="${time.titulos}" /></td>
                            <td>
                                <a
                                    href="${pageContext.request.contextPath}/times/edicao?id=${time.id}"
                                >
                                    <fmt:message key="teams.update" />
                                </a>
                                <c:if test="${time.qtdeJogadores == 0}">
                                    &nbsp;&nbsp;&nbsp;
                                    <a
                                        href="${pageContext.request.contextPath}/times/remocao?id=${time.id}"
                                        onclick="return confirm('${confirmMsg}');"
                                    >
                                        <fmt:message key="teams.delete" />
                                    </a>
                                </c:if>
                            </td>
                        </tr>
                    </c:forEach>
                </table>
            </div>
        </body>
    </fmt:bundle>
</html>
