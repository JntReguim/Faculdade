<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"
isELIgnored="false" %> <%@ taglib prefix="c"
uri="http://java.sun.com/jsp/jstl/core" %> <%@ taglib prefix="fmt"
uri="http://java.sun.com/jsp/jstl/fmt" %>

<table border="1">
    <caption>
        <c:choose>
            <c:when test="${time != null}">
                <fmt:message key="teams.update" />
            </c:when>
            <c:otherwise>
                <fmt:message key="teams.create" />
            </c:otherwise>
        </c:choose>
    </caption>

    <c:if test="${time != null}">
        <input type="hidden" name="id" value="${time.id}" />
    </c:if>

    <tr>
        <td>
            <label for="cnpj"><fmt:message key="team.cnpj" /></label>
        </td>
        <td>
            <input
                type="text"
                id="cnpj"
                name="cnpj"
                size="18"
                required
                value="${time != null ? time.cnpj : ''}"
            />
        </td>
    </tr>
    <tr>
        <td>
            <label for="nome"><fmt:message key="team.name" /></label>
        </td>
        <td>
            <input
                type="text"
                id="nome"
                name="nome"
                size="45"
                required
                value="${time != null ? time.nome : ''}"
            />
        </td>
    </tr>
    <tr>
        <td>
            <label for="anoFundacao"
                ><fmt:message key="team.foundation_year"
            /></label>
        </td>
        <td>
            <input
                type="number"
                id="anoFundacao"
                name="anoFundacao"
                required
                value="${time != null ? time.anoFundacao : ''}"
            />
        </td>
    </tr>
    <tr>
        <td>
            <label for="titulos"><fmt:message key="team.titles" /></label>
        </td>
        <td>
            <input
                type="number"
                id="titulos"
                name="titulos"
                required
                value="${time != null ? time.titulos : ''}"
            />
        </td>
    </tr>
    <tr>
        <td colspan="2" align="center">
            <input type="submit" value="<fmt:message key='save.link'/>" />
        </td>
    </tr>
</table>
