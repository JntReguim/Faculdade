<%@ taglib uri = "http://java.sun.com/jsp/jstl/core" prefix = "c" %>
<%@ page isELIgnored="false"%>

<c:catch var="exception">
  <c:set var="a" value="${0 + param.a}" />
  <c:set var="b" value="${0 + param.b}" />
</c:catch>

<c:choose>
  <c:when test="${not empty exception}">
    <c:redirect url="erro.html" />
  </c:when>
  <c:when test="${param.b == 0}">
    <c:redirect url="erro.html" />
  </c:when>
  <c:otherwise>
    <jsp:forward page="calculadora.jsp"/>
  </c:otherwise>
</c:choose>