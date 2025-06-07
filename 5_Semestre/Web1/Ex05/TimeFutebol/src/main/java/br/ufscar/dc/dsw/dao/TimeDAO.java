package br.ufscar.dc.dsw.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import br.ufscar.dc.dsw.domain.Time;

public class TimeDAO extends GenericDAO {

    public void insert(Time time) {
        String sql = "INSERT INTO Time (cnpj, nome, ano_fundacao, titulos) VALUES (?, ?, ?, ?)";

        try {
            Connection conn = this.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);

            statement.setString(1, time.getCnpj());
            statement.setString(2, time.getNome());
            statement.setInt(3, time.getAnoFundacao());
            statement.setInt(4, time.getTitulos());
            statement.executeUpdate();

            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public List<Time> getAll() {
        List<Time> listaTimes = new ArrayList<>();

        String sql = "SELECT * from Time";

        try {
            Connection conn = this.getConnection();
            Statement statement = conn.createStatement();

            ResultSet resultSet = statement.executeQuery(sql);
            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String cnpj = resultSet.getString("cnpj");
                String nome = resultSet.getString("nome");
                int anoFundacao = resultSet.getInt("ano_fundacao");
                int titulos = resultSet.getInt("titulos");
                
                Time time = new Time(id, cnpj, nome, anoFundacao, titulos);
                time.setQtdeJogadores(new JogadorDAO().countByTime(id));
                listaTimes.add(time);
            }

            resultSet.close();
            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return listaTimes;
    }

    public void delete(Time time) {
        String sql = "DELETE FROM Time where id = ?";

        try {
            Connection conn = this.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);

            statement.setLong(1, time.getId());
            statement.executeUpdate();

            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void update(Time time) {
        String sql = "UPDATE Time SET cnpj = ?, nome = ?, ano_fundacao = ?, titulos = ?";
        sql += " WHERE id = ?";

        try {
            Connection conn = this.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);

            statement.setString(1, time.getCnpj());
            statement.setString(2, time.getNome());
            statement.setInt(3, time.getAnoFundacao());
            statement.setInt(4, time.getTitulos());
            statement.setLong(5, time.getId());
            
            statement.executeUpdate();

            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public Time get(Long id) {
        Time time = null;
        
        String sql = "SELECT * from Time where id = ?";

        try {
            Connection conn = this.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);
            
            statement.setLong(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                String cnpj = resultSet.getString("cnpj");
                String nome = resultSet.getString("nome");
                int anoFundacao = resultSet.getInt("ano_fundacao");
                int titulos = resultSet.getInt("titulos");
                
                time = new Time(id, cnpj, nome, anoFundacao, titulos);
                time.setQtdeJogadores(new JogadorDAO().countByTime(id));
            }

            resultSet.close();
            statement.close();
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return time;
    }
}