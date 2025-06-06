String pagina = R"===(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <!-- Defina a metatag viewport para impedir o zoom -->
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
    <style>
        body {
            text-align: center;
        }

        .prevent-select {
            -webkit-user-select: none; /* Safari */
            -ms-user-select: none; /* IE 10 and IE 11 */
            user-select: none; /* Standard syntax */
        }        

        .joystick-table {
            width: 100%;
            height: 100%;
            border-collapse: collapse;
            table-layout: fixed;
            margin: 0 auto;
        }

        .joystick-cell {
            width: 33.33%;
            text-align: center;
            vertical-align: middle;
        }

        .joystick-button {
            width: 100px; /* Largura dos botÃµes */
            height: 100px; /* Altura dos botÃµes */
            border: 6px solid;
            border-radius: 50%;
            font-size: 18px;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.3s, box-shadow 0.3s;
            display: inline-block;
        }

        #botao1 {
            background-color: #3498db; /* Cor 1 */
            color: #ffffff;
        }

        #botao1:active {
            background-color: #2980b9;
            transform: translateY(2px);
            box-shadow: none;
        }

        #botao2 {
            background-color: #ff8c66;
            color: #ffffff;
        }

        #botao2:active {
            background-color: #ff5733;
            transform: translateY(2px);
            box-shadow: none;
        }

        #botao3 {
            background-color: #1d8348;
            color: #ffffff;
        }

        #botao3:active {
            background-color: #27ae60;
            transform: translateY(2px);
            box-shadow: none;
        }

        #botao4 {
            background-color: #d35400;
            color: #ffffff;
        }

        #botao4:active {
            background-color: #f39c12;
            transform: translateY(2px);
            box-shadow: none;
        }

        #botao5 {
            background-color: #9b59b6; /* Cor lilÃ¡s */
            color: #ffffff;
        }

        #botao5:active {
            background-color: #8e44ad;
            transform: translateY(2px);
            box-shadow: none;
        }

        #emoji-robÃ´ {
            font-size: 100px; /* Tamanho do emoji do robÃ´ */
        }
    </style>
</head>
<body unselectable="on" class="prevent-select">
    <h2 class="prevent-select">&#129302; ROBOZÃO DO LULU &#129302;</h2>
    <h2 class="prevent-select">&#x1F3AE; AO INFINITO E ALÃM &#128246;</h2>

    <table class="joystick-table">
        <tr>
            <td class="joystick-cell"></td>
            <td class="joystick-cell"><button class="prevent-select joystick-button" id="botao1"></button></td>
            <td class="joystick-cell"></td>
        </tr>
        <tr>
            <td class="joystick-cell"><button class="prevent-select joystick-button" id="botao2"></button></td>
            <td class="joystick-cell"><div id="emoji-robÃ´" class="prevent-select">â</div></td>
            <td class="joystick-cell"><button class="prevent-select joystick-button" id="botao3"></button></td>
        </tr>
        <tr>
            <td class="joystick-cell"></td>
            <td class="joystick-cell"><button class="prevent-select joystick-button" id="botao4"></button></td>
            <td class="joystick-cell"></td>
        </tr>
        <tr>
            <td class="joystick-cell"></td>
            <td class="joystick-cell"><button class="prevent-select joystick-button" id="botao5"></button></td>
            <td class="joystick-cell"></td>
        </tr>
    </table>

<script>
    const botao1 = document.getElementById('botao1');
    const botao2 = document.getElementById('botao2');
    const botao3 = document.getElementById('botao3');
    const botao4 = document.getElementById('botao4');
    const botao5 = document.getElementById('botao5');

    let intervalID = null;
    let botaoAtivo = null; // VariÃ¡vel para controlar o botÃ£o pressionado

    function iniciarAcao(botao, comando, corPressionado, corSolto) {
        if (botaoAtivo === null) {
            botaoAtivo = botao; // Define o botÃ£o ativo
            botao.style.backgroundColor = corPressionado;
            botao.style.transform = 'translateY(2px)';
            botao.style.boxShadow = 'none';
            intervalID = setInterval(() => {
                fetch('/pressionado', { method: 'POST', body: comando });
            }, 100);
        }
    }

    function pararAcao(botao, corSolto) {
        if (botaoAtivo === botao) { // SÃ³ libera se for o botÃ£o ativo
            botao.style.backgroundColor = corSolto;
            botao.style.transform = 'translateY(0)';
            botao.style.boxShadow = 'none';
            clearInterval(intervalID);
            fetch('/pressionado', { method: 'POST', body: '0' }); // Envia o comando de parada
            botaoAtivo = null; // Libera para que outro botÃ£o possa ser pressionado
        }
    }

    // FunÃ§Ãµes de eventos para cada botÃ£o
    botao1.addEventListener('touchstart', () => iniciarAcao(botao1, '1', '#2980b9', '#3498db'));
    botao1.addEventListener('touchend', () => pararAcao(botao1, '#3498db'));

    botao2.addEventListener('touchstart', () => iniciarAcao(botao2, '2', '#ff8c66', '#ff5733'));
    botao2.addEventListener('touchend', () => pararAcao(botao2, '#ff5733'));

    botao3.addEventListener('touchstart', () => iniciarAcao(botao3, '3', '#1d8348', '#27ae60'));
    botao3.addEventListener('touchend', () => pararAcao(botao3, '#27ae60'));

    botao4.addEventListener('touchstart', () => iniciarAcao(botao4, '4', '#d35400', '#f39c12'));
    botao4.addEventListener('touchend', () => pararAcao(botao4, '#f39c12'));

    botao5.addEventListener('touchstart', () => iniciarAcao(botao5, '5', '#9b59b6', '#8e44ad'));
    botao5.addEventListener('touchend', () => pararAcao(botao5, '#9b59b6'));
</script>

</body>
</html>
)===";
