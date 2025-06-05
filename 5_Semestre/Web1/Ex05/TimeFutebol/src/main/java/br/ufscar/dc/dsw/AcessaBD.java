package br.ufscar.dc.dsw;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class AcessaBD {

	public static void main(String[] args) {
		try {

			/* Setup para uso do banco de dados MySQL */

			Class.forName("com.mysql.cj.jdbc.Driver");
			String url = "jdbc:mysql://localhost:3306/TimeFutebol";
			Connection con = (Connection) DriverManager.getConnection(url, "root", "root");

			/* Setup para uso do banco de dados PostgreSQL */
			
			/*
			 * Class.forName("org.postgresql.Driver");
			 * String url = "jdbc:postgresql://localhost:5432/Livraria";
			 * Connection con = (Connection) DriverManager.getConnection(url, "root", "root");
			 */
			
			/* Setup para uso do banco de dados Derby */

			/*
			 * Class.forName("org.apache.derby.jdbc.ClientDriver");
			 * String url = "jdbc:derby://localhost:1527/Livraria";
			 * Connection con = (Connection) DriverManager.getConnection(url, "root", "root");
			 */

			/* Setup para uso do banco de dados SQLite */
			
			/*
			 * Class.forName("org.sqlite.JDBC");
			 * String url = "jdbc:sqlite:./db/SQLite/Livraria.db";
			 * Connection con = (Connection) DriverManager.getConnection(url);
			 */

			Statement stmt = con.createStatement();
			String query = "SELECT j.cpf, j.nome AS jogador, j.posicao, j.numero, j.idade, j.salario, t.nome AS time FROM Jogador j, Time t WHERE j.time_id = t.id;";
			ResultSet rs = stmt.executeQuery(query);
			while (rs.next()) {
				System.out.print(rs.getString("cpf"));
				System.out.print(", " + rs.getString("jogador"));
				System.out.print(", " + rs.getString("posicao"));
				System.out.print(", " + rs.getInt("numero"));
				System.out.print(", " + rs.getInt("idade"));
				System.out.print(", " + rs.getString("time"));
				System.out.println(" (R$ " + rs.getFloat("salario") + ")");
			}
			stmt.close();
			con.close();
		} catch (ClassNotFoundException e) {
			System.out.println("A classe do driver de conexão não foi encontrada!");
		} catch (SQLException e) {
			e.printStackTrace();
			System.out.println("O comando SQL não pode ser executado!");
		}
	}
}