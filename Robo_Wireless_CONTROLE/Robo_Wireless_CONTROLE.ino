#include "arduino_secrets.h"

/*CARREGAR ESSE CÃDIGO NO MODULO ESP01*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "paginaHTML.h"

const char *nome_da_rede = "ROBO_REBORN";
const char *senha = "12345678";

ESP8266WebServer servidor(80);

void setup() {
    WiFi.softAP(nome_da_rede, senha);
    servidor.on("/", []() {
        servidor.send(200, "text/html", pagina);
    });

    servidor.on("/pressionado", HTTP_POST, []() {
        String estado = servidor.arg("plain");
        Serial.println(estado);
        servidor.send(200, "text/plain", "OK");
    });

    servidor.begin();
    Serial.begin(9600);
}

void loop() {
    servidor.handleClient();
}
