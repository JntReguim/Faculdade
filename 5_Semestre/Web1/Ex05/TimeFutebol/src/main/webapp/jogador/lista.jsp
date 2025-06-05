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
                <h1><fmt:message key="players.welcome" /></h1>
                <h2>
                    <a href="${pageContext.request.contextPath}">
                        <fmt:message key="main.link" />
                    </a>
                    &nbsp;&nbsp;&nbsp;
                    <a
                        href="${pageContext.request.contextPath}/jogadores/cadastro"
                    >
                        <fmt:message key="players.create" />
                    </a>
                </h2>
            </div>

            <div align="center">
                <fmt:message key="confirm.link" var="confirmMsg" />

                <table border="1">
                    <caption>
                        <fmt:message key="players.list" />
                    </caption>
                    <tr>
                        <th><fmt:message key="player.ID" /></th>
                        <th><fmt:message key="player.cpf" /></th>
                        <th><fmt:message key="player.name" /></th>
                        <th><fmt:message key="player.position" /></th>
                        <th><fmt:message key="player.number" /></th>
                        <th><fmt:message key="player.age" /></th>
                        <th><fmt:message key="player.salary" /></th>
                        <th><fmt:message key="player.team" /></th>
                        <th><fmt:message key="actions.link" /></th>
                    </tr>
                    <c:forEach
                        var="jogador"
                        items="${requestScope.listaJogadores}"
                    >
                        <tr>
                            <td><c:out value="${jogador.id}" /></td>
                            <td><c:out value="${jogador.cpf}" /></td>
                            <td><c:out value="${jogador.nome}" /></td>
                            <td><c:out value="${jogador.posicao}" /></td>
                            <td><c:out value="${jogador.numero}" /></td>
                            <td><c:out value="${jogador.idade}" /></td>
                            <td><c:out value="${jogador.salario}" /></td>
                            <td><c:out value="${jogador.time.nome}" /></td>
                            <td>
                                <a
                                    href="${pageContext.request.contextPath}/jogadores/edicao?id=${jogador.id}"
                                >
                                    <fmt:message key="players.update" />
                                </a>
                                &nbsp;&nbsp;&nbsp;
                                <a
                                    href="${pageContext.request.contextPath}/jogadores/remocao?id=${jogador.id}"
                                    onclick="return confirm('${confirmMsg}');"
                                >
                                    <fmt:message key="players.delete" />
                                </a>
                            </td>
                        </tr>
                    </c:forEach>
                </table>
            </div>
        </body>
    </fmt:bundle>
</html>
