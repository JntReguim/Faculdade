package br.ufscar.dc.dsw.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import br.ufscar.dc.dsw.domain.Time;
import br.ufscar.dc.dsw.domain.Jogador;

public class JogadorDAO extends GenericDAO {

    public void insert(Jogador jogador) {
        String sql = "INSERT INTO Jogador (cpf, nome, posicao, numero, idade, salario, time_id) VALUES (?, ?, ?, ?, ?, ?, ?)";

        try {
            Connection conn = this.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);

            statement.setString(1, jogador.getCpf());
            statement.setString(2, jogador.getNome());
            statement.setString(3, jogador.getPosicao());
            statement.setInt(4, jogador.getNumero());
            statement.setInt(5, jogador.getIdade());
            statement.setFloat(6, jogador.getSalario());
            statement.setLong(7, jogador.getTime().getId());
            statement.executeUpdate();

            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public List<Jogador> getAll() {
        List<Jogador> listaJogadores = new ArrayList<>();

        String sql = "SELECT * from Jogador j, Time t where j.TIME_ID = t.ID order by j.id";

        try {
            Connection conn = this.getConnection();
            Statement statement = conn.createStatement();

            ResultSet resultSet = statement.executeQuery(sql);
            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String cpf = resultSet.getString("cpf");
                String nome = resultSet.getString("nome");
                String posicao = resultSet.getString("posicao");
                int numero = resultSet.getInt("numero");
                int idade = resultSet.getInt("idade");
                float salario = resultSet.getFloat("salario");
                
                Long time_id = resultSet.getLong("time_id");
                String cnpj = resultSet.getString("cnpj");
                String nomeTime = resultSet.getString("t.nome");
                int anoFundacao = resultSet.getInt("ano_fundacao");
                int titulos = resultSet.getInt("titulos");
                
                Time time = new Time(time_id, cnpj, nomeTime, anoFundacao, titulos);
                Jogador jogador = new Jogador(id, cpf, nome, posicao, numero, idade, salario, time);
                listaJogadores.add(jogador);
            }

            resultSet.close();
            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return listaJogadores;
    }

    public void delete(Jogador jogador) {
        String sql = "DELETE FROM Jogador where id = ?";

        try {
            Connection conn = this.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);

            statement.setLong(1, jogador.getId());
            statement.executeUpdate();

            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void update(Jogador jogador) {
        String sql = "UPDATE Jogador SET cpf = ?, nome = ?, posicao = ?, numero = ?, idade = ?, salario = ?";
        sql += ", time_id = ? WHERE id = ?";

        try {
            Connection conn = this.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);

            statement.setString(1, jogador.getCpf());
            statement.setString(2, jogador.getNome());
            statement.setString(3, jogador.getPosicao());
            statement.setInt(4, jogador.getNumero());
            statement.setInt(5, jogador.getIdade());
            statement.setFloat(6, jogador.getSalario());
            statement.setLong(7, jogador.getTime().getId());
            statement.setLong(8, jogador.getId());
            statement.executeUpdate();

            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public Jogador get(Long id) {
        Jogador jogador = null;

        String sql = "SELECT * from Jogador j, Time t where j.id = ? and j.TIME_ID = t.ID";

        try {
            Connection conn = this.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);

            statement.setLong(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                String cpf = resultSet.getString("cpf");
                String nome = resultSet.getString("nome");
                String posicao = resultSet.getString("posicao");
                int numero = resultSet.getInt("numero");
                int idade = resultSet.getInt("idade");
                float salario = resultSet.getFloat("salario");

                Long timeID = resultSet.getLong("time_id");
                Time time = new TimeDAO().get(timeID);

                jogador = new Jogador(id, cpf, nome, posicao, numero, idade, salario, time);
            }

            resultSet.close();
            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return jogador;
    }

    public int countByTime(Long id) {
        int contador = 0;
        
        String sql = "SELECT count(*) from Jogador j where j.TIME_ID = ?";

        try {
            Connection conn = this.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);

            statement.setLong(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                contador = resultSet.getInt(1);
            }

            resultSet.close();
            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return contador;
    }
}