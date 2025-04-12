document.addEventListener("click", function (event) {
    if (event.target.id === "p1") {
        var flag = confirm("Você tem certeza?");

        if (flag) {
            const texto = document.getElementById("p1");

            if (texto.classList.contains("verde")) {
                texto.classList.remove("verde");
                texto.classList.add("azul");
            } else if (texto.classList.contains("azul")) {
                texto.classList.remove("azul");
            } else {
                texto.classList.add("verde");
            }
        }
    }
});
