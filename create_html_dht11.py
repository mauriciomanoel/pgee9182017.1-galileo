#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Importanco componente para receber os dados via parametro
import sys
# sys.argv[1] # status
# sys.argv[2] # temperatura
# sys.argv[3] # umidade

def gravar_arquivo(texto):
        arq = open('/www/pages/index.html', 'w');
        arq.write(texto);
        arq.close();

if len(sys.argv) >= 3:

	# Validando os parâmetros
	if (sys.argv[1] == "ok"):
		dados = "Temperatura: " + sys.argv[2] + "°C <br> Umidade: " + sys.argv[3] + "%";
	else:
		dados = "Sistema indispon&iacute;vel. Por favor tente mais tarde.";

	# Gerando o HTML
	html = '<!DOCTYPE html><html lang="en"><head><meta charset="utf-8"><meta http-equiv="refresh" content="3;url=index.html"><title>Galileo + Sensor DHT11</title></head><body><div class="container"><div class="starter-template" style="text-align: center;"><h2>Atualizado a cada 3 segundos</h2><p class="lead">';
	html += dados;
	html += '</p></div></div><link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous"></body></html>';

	# Gravando o html no arquivo
	gravar_arquivo(html);

	print('Dados gerados com sucesso.');
else:
	print("Você deve passar 3 parâmetros.");

