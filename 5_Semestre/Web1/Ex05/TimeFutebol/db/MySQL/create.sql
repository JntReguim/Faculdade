drop database if exists TimeFutebol;

create database TimeFutebol;

use TimeFutebol;

-- Tabela Time
CREATE TABLE Time (
    id BIGINT AUTO_INCREMENT,
    cnpj VARCHAR(18) NOT NULL,
    nome VARCHAR(100) NOT NULL,
    ano_fundacao INT NOT NULL,
    titulos INT NOT NULL,
    PRIMARY KEY (id)
);

-- Tabela Jogador
CREATE TABLE Jogador (
    id BIGINT AUTO_INCREMENT,
    cpf VARCHAR(14) NOT NULL,
    nome VARCHAR(100) NOT NULL,
    posicao VARCHAR(30) NOT NULL,
    numero INT NOT NULL,
    idade INT NOT NULL,
    salario FLOAT NOT NULL,
    time_id BIGINT,
    PRIMARY KEY (id),
    FOREIGN KEY (time_id) REFERENCES Time(id)
);

-- Inserindo os times
insert into Time(cnpj, nome, ano_fundacao, titulos) values ('12.345.678/0001-91', 'Corinthians', 1910, 30);
insert into Time(cnpj, nome, ano_fundacao, titulos) values ('23.456.789/0001-92', 'Palmeiras', 1914, 25);
insert into Time(cnpj, nome, ano_fundacao, titulos) values ('34.567.890/0001-93', 'Santos', 1912, 22);

-- Inserindo os jogadores
insert into Jogador(cpf, nome, posicao, numero, idade, salario, time_id) values ('111.222.333-44', 'Romero', 'Atacante', 9, 28, 500000.00, 1);
insert into Jogador(cpf, nome, posicao, numero, idade, salario, time_id) values ('222.333.444-55', 'Endrick', 'Atacante', 10, 17, 300000.00, 2);
insert into Jogador(cpf, nome, posicao, numero, idade, salario, time_id) values ('333.444.555-66', 'Neymar', 'Atacante', 10, 31, 1200000.00, 3);