Requisitos e instruções para executar o projeto TimeFutebol

1. Pré-requisitos do sistema:
    - Java JDK 17 (versão especificada no pom.xml)
    - Servidor Apache Tomcat 7 ou superior
    - MySQL Server 8.0 ou versão compatível com o driver 8.0.21
    - Maven 3.6+

2. Dependências principais incluídas:
    - Jakarta Servlet API 6.0.0
    - Jakarta JSP/JSTL 3.0.0
    - MySQL Connector/J 8.0.21
    - Biblioteca Gson 2.8.0 para processamento JSON
    - JUnit 4.11 para testes unitários

3. Configuração necessária:
   3.1. Configuração do Tomcat:
    - Plugin tomcat7-maven-plugin versão 2.2
    - URL padrão: http://localhost:8080/manager/
    - Caminho da aplicação: /TimeFutebol

    3.2. Configuração do banco de dados:
    - Servidor MySQL na porta padrão 3306
    - Credenciais padrão: usuário 'root', senha 'root'

4. Procedimento de instalação e execução:
   4.1. Iniciar o tomcat (apache/bin):
   ./catalina.sh run

    4.2. Configurar o wrapper do Maven (No diretório do Projeto):
    mvn -N io.takari:maven:wrapper

    4.3. Preparar o banco de dados:
    mysql -uroot -p
    senha: root

    source db/MySQL/create.sql
    quit

    4.4. Executar a aplicação:
    mvn tomcat7:redeploy <- automaticamente faz o deploy também

5. Acesso à aplicação:
   Disponível em: http://localhost:8080/TimeFutebol

6. Solução de problemas:
   6.1. Erro 403: verificar permissões no Tomcat
   6.2. Timeout MySQL: verificar status do serviço
   6.3. Erros de JDK: confirmar uso do Java 17
   6.4. Problemas de compilação: executar 'mvn clean' antes de rebuild
