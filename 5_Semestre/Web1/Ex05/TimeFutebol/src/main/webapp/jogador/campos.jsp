<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" isELIgnored="false" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>

<table border="1">
  <caption>
    <c:choose>
      <c:when test="${jogador != null}">
        <fmt:message key="players.update" />
      </c:when>
      <c:otherwise>
        <fmt:message key="players.create" />
      </c:otherwise>
    </c:choose>
  </caption>

  <c:if test="${jogador != null}">
    <input type="hidden" name="id" value="${jogador.id}" />
  </c:if>

  <tr>
    <td><label for="cpf"><fmt:message key="player.cpf" /></label></td>
    <td><input type="text" id="cpf" name="cpf" value="${jogador.cpf}" required /></td>
  </tr>
  
  <tr>
    <td><label for="nome"><fmt:message key="player.name" /></label></td>
    <td><input type="text" id="nome" name="nome" value="${jogador.nome}" required /></td>
  </tr>
  
  <tr>
    <td><label for="posicao"><fmt:message key="player.position" /></label></td>
    <td><input type="text" id="posicao" name="posicao" value="${jogador.posicao}" required /></td>
  </tr>
  
  <tr>
    <td><label for="numero"><fmt:message key="player.number" /></label></td>
    <td><input type="number" id="numero" name="numero" value="${jogador.numero}" required /></td>
  </tr>
  
  <tr>
    <td><label for="idade"><fmt:message key="player.age" /></label></td>
    <td><input type="number" id="idade" name="idade" value="${jogador.idade}" required /></td>
  </tr>
  
  <tr>
    <td><label for="salario"><fmt:message key="player.salary" /></label></td>
    <td><input type="number" step="0.01" id="salario" name="salario" value="${jogador.salario}" required /></td>
  </tr>

  <tr>
    <td><label for="time"><fmt:message key="player.team" /></label></td>
    <td>
      <select id="time" name="time" required>
        <c:forEach var="entry" items="${times.entrySet()}">
          <c:set var="timeId" value="${entry.key}" />
          <c:set var="timeNome" value="${entry.value}" />
          <option value="${timeId}"
            <c:if test="${jogador != null and jogador.time.id == timeId}">
              selected
            </c:if>
          >
            ${timeNome}
          </option>
        </c:forEach>
      </select>
    </td>
  </tr>

  <tr>
    <td colspan="2" align="center">
      <input type="submit" value="<fmt:message key='save.link'/>" />
    </td>
  </tr>
</table>