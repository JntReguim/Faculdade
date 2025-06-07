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
                    <a href="lista"><fmt:message key="players.list" /></a>
                    &nbsp;&nbsp;&nbsp;
                    <a href="${pageContext.request.contextPath}">
                        <fmt:message key="main.link" />
                    </a>
                </h2>
            </div>

            <div align="center">
                <c:choose>
                    <c:when test="${jogador != null}">
                        <form action="atualizacao" method="post">
                            <%@ include file="campos.jsp" %>
                        </form>
                    </c:when>
                    <c:otherwise>
                        <form action="insercao" method="post">
                            <%@ include file="campos.jsp" %>
                        </form>
                    </c:otherwise>
                </c:choose>
            </div>

            <c:if test="${not empty requestScope.mensagens}">
                <ul class="erro">
                    <c:forEach items="${requestScope.mensagens}" var="mensagem">
                        <li><c:out value="${mensagem}" /></li>
                    </c:forEach>
                </ul>
            </c:if>
        </body>
    </fmt:bundle>
</html>
