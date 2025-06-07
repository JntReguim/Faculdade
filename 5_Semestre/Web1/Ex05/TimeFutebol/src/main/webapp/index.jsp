<%@ page contentType="text/html" pageEncoding="UTF-8"%>
<%@ page isELIgnored="false"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>
<!DOCTYPE html>
<html>
    <fmt:bundle basename="message">

        <head>
            <title>
                <fmt:message key="page.title" />
            </title>
        </head>

        <body>
            <a href="jogadores">CRUD
                <fmt:message key="players.entity" /></a>
            <br>
            <a href="times">CRUD
                <fmt:message key="teams.entity" /></a>
        </body>
    </fmt:bundle>
</html>