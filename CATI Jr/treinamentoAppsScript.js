/*
    TREINAMENTO DE JAVASCRIPT -> APPS SCRIPT

    PASTA DE OPERAÇÕES

    DATA: 11/06/2024
*/

// Comentário de linha (o computador não executa essa linha)

/*
    Comentário de bloco
    (o computador não executa esse bloco)
*/

/*
    VARIÁVEIS

    - As variáveis são informações armazenadas dentro da memória do computador
    - Elas permitem que manipulemos dados dentro do nosso código
    - Podem ser:
        * inteiros: 1, 2, 49, 1024...
        * floats: 1.2, 54.3696, 23.5439...
        * strings: "Olá mundo", "Pasta de Operações"
        * Booleanas: True, False, 0, 1
 
    - Em JavaScript não é necessário definir seu tipo (tipagem fraca)
    - Podem ser declaradas como:
        * var       -> Escopo de função, com Hoisting
        * let       -> Escopo de bloco, sem Hoinsting
        * const     -> Escopo de bloco, sem Hoinsting
        Mas é mais recomendado sempre usar let e const (mais utilizado)!
        
        -> Hoisting - É renderizado em cima, ou seja, mesmo que declare
        em baixo, pode ser utilizado em cima
         
    - Sua atribuição se dá com o comando =

*/

// Exemplo 1: 

//console.log("Olá mundo")

//let texto = "Olá mundo desse jeito"
//console.log(texto)

//let nota = 6.0
//console.log("A nota dele foi:", nota)

//nota = 10.0
//console.log("A nota dele foi:", nota)

// const a = 10
// const b = 5

// console.log(a + b)
// b = 20   // Vai dar um comando de erro


/*
    OPERAÇÕES LÓGICAS E MATEMÁTICAS

    - As operações lógicas e matemáticas são a base para se construir um algoritmo de computador
    - Operadores matemáticos: 
        * Soma, subtração, multiplicação e divizão: +, -, /, %
        * Comparativos: <, >, <=, >=, ==, !
    - Operadores lógicos: && (AND), || (OR)

*/

// Exemplo 2:

//let a = 5
// let b = 10

// let soma = a + b
// let subtracao = a - b
// let multiplicacao = a * b
// let divisao = a / b
// let exponencial = b**a

// console.log('Soma:', soma, '\nSubtração:', subtracao, '\nMultiplicação:', multiplicacao, '\nDivisão:', divisao)
// console.log('Exponencial', exponencial)

// console.log("a é maior que b?", a > b)
// console.log(`b é maior que a?`, a < b)

// let c = true

// console.log(c)


/*

    ESTUTURAS DE CONTROLE

    - São a partir desses comandos que as comparações lógicas podem ser feitas
        * if
        * else if
        * else

*/

// Exemplo 3

// let idade = 14

// if (idade < 18){
//     console.log("Você é menor de idade!")
// } else {
//     console.log("Você é um adulto!")
// }

// let tirou_Carta = true

// if (idade >= 18 && tirou_Carta == true) {
//     console.log("Você pode dirigir!")
// } else if (idade < 18 || tirou_Carta == false){
//     console.log("Você ainda não pode dirigir, pois:")

//     if (tirou_Carta == false) {
//         console.log("Você ainda não tirou sua carteira de motorista!")
//     } else {
//         console.log("Você aidna é uma criança!")
//     }
// }

/*
    LAÇOS DE REPETIÇÃO

    - Serve para realizar uma operação diversas vezes
        * For
        * While
        * Do While (não muito usado)

*/

// Exemplo 4

// for (let i = 0; i <= 10; i = i + 1){     // i++
//     console.log(i)
// }

// let i = 10
// while (i > 0){
//     console.log(--i)                        // ++i e i++
// }


/*
    FUNÇÕES

    - É uma parte de código que pode ser chamada a qualquer momento
    - É como uma caixinha preta que, dada uma entrada, retorna uma saída expecífica
    - Pode ter ou nao argumentos
    - Pode retornar um valor na variável ou não

*/

// Exemplo 5

// function tabuada(numero){
//     console.log("A tabuada do número " + numero + " é:")
//     for (let i = 1; i < 11; i++){
//         console.log("Vezes " + i + ": " + numero*i)
//     }
// }

// tabuada(3)
// tabuada(7)

// function resultado_disciplina(nota){
//     if (nota >= 6) return 'Aprovado'
//     else if (nota >= 5) return 'Recuperacao'
//     else return 'Reprovado'
// }

// let resultado = resultado_disciplina(5.45)
// console.log('Sua situação é: ' + resultado)


/*
    ARRAYS

    - Estrutura de Dados que nos permite guardar um conjunto de valores

*/

// Exemplo 6

// let valores = [6, 7, 7, 8, 5, 4, 6, 6, 9, 2]

// for (let i = 0; i < 10; i++){
//     console.log(valores[i])
// }

// let cartas_de_hora = ['Pedro', 'Augusto', 'Jose', 'Fatima']
// Seria como se fosse: cartas_de_hora = [0: 'Pedro', 1: 'Augusto', 2: 'Jose', 3: 'Fatima']
// console.log(cartas_de_hora[2])


// for (let i = 0; i < 4; i++){
    //     console.log(cartas_de_hora[i])
    // }
    
// let cartas_de_hora_dicionario = {'Pedro': 'Um cara muito bacana', 'Augusto': 'Um lider muito bom!', 'Jose': 6, 'Fatima': 9}
// let exemplo = {3: 30, 4:40, 1: 10, 2: 20}
// console.log(cartas_de_hora_dicionario['Pedro'])

// for (let i = 0; i < 4; i++){
    // console.log(cartas_de_hora_dicionario[cartas_de_hora[i]])
// }

// for (let i = 1; i <= 4; i++){
//     console.log(exemplo[i])
// }


/*
    OBJETOS

    - São um conjunto de informações que podem conter diversos tipos de dados em si
    *** Métodos de objetos: são funções que se encontram dentro de objetos

*/

// Exemplo 7

// const pessoa = {
//     nome: 'João Paulo',
//     idade: 21,
//     profissao: "Programador",
//     getNome(){
//         return this.nome;
//     },
//     resumo(valor){
//         console.log(valor)
//         return console.log('Nome: ' + this.nome + '\nIdade: ' + this.idade + '\nProfissao: ' + this.profissao)
//     }
// }

// pessoa.idade = 26; // Modifica a propriedade idade
// pessoa.nome = 'Carolina'
// pessoa.resumo(3)
// console.log(pessoa.getNome())


// console.log(pessoa.nome);
// console.log(pessoa.getNome()); 
// console.log(pessoa.idade)
// console.log(pessoa); // { nome: "João", idade: 26, profissao: "Programador" }
// pessoa.resumo()



/*
    MÉTODOS DE OBJETOS

    - São como funções aplicadas a um objeto

*/

// Exemplo 8

// cartas_de_hora.forEach(function(pessoa){
//     console.log(pessoa)
// })


// let array = [1, 2, 3, 4]

// // 1. Obtendo o tamanho do array
// const length = array.length;
// console.log(`Tamanho do array: ${length}`);
// // console.log('Tamanho do array: ' + length);


// // 2. Acessando elementos do array
// const firstElement = array[0];
// console.log(`Primeiro elemento do array: ${firstElement}`);


// // // 3. Adicionando elementos no final do array
// array.push(6);
// console.log('Array após adicionar elemento:', array);


// // // 4. Removendo o último elemento do array
// const lastElement = array.pop();
// console.log(`Último elemento removido: ${lastElement}`);
// console.log('Array após remover elemento:', array);


// // // 5. Adicionando elementos no início do array
// array.unshift(0);
// console.log('Array após adicionar elemento no início:', array);


// // // 6. Removendo o primeiro elemento do array
// const firstRemoved = array.shift();
// console.log(`Primeiro elemento removido: ${firstRemoved}`);
// console.log('Array após remover elemento do início:', array);


// // // 7. Obtendo o índice de um elemento no array
// const index = array.indexOf(3);
// console.log(`Índice do elemento 3: ${index}`);


// // // 8. Verificando se um elemento existe no array
// const exists = array.includes(2);
// console.log(`O elemento 2 existe no array? ${exists}`);


// // // 9. Copiando um array
// const copyArray = array.slice(0, 3);
// console.log('Cópia parcial do array:', copyArray);


// // // 10. Ordenando o array
// array.sort();
// console.log('Array ordenado:', array);


// // // 11. Invertendo o array
// const reversed = array.reverse();
// console.log('Array invertido: ', reversed);


// let lista = ['ola', 'tudo', 'bem']
// let i
// for (i in lista){
//     console.log(i)
// }