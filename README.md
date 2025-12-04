# 🤖 Projeto Integrador: Robô Sumô Autônomo - SENAI 2025

Este repositório contém a documentação, código-fonte e esquemáticos do Robô Sumô desenvolvido para o Projeto Integrador das unidades curriculares de **Lógica de Programação** e **Fundamentos de Eletroeletrônica**.

## 📋 Sobre o Projeto
O objetivo é desenvolver um robô autônomo de até 1kg capaz de localizar e empurrar um oponente para fora de uma arena circular (Dohyo), mantendo-se dentro dos limites da mesma.

* **Instituição:** SENAI
* **Data da Competição:** 28/11/2025

## 👥 Equipe Desenvolvedora

* EUZEBIO SOUZA
* JUAN DA SILVA
* LUCAS AUGUSTO
* MARCOS VINICIUS
* RODRIGO MIRANDA

## 🛠️ Hardware Utilizado
* **Microcontrolador:** Arduino Mega 2560
* **Drivers:** Ponte H L298N
* **Sensores:** 3x Ultrassônicos HC-SR04 + 3x Sensores de Linha Infravermelho
* **Atuadores:** 2x Motores DC 5V com caixa de redução
* **Alimentação:** 2x Bateria 9V

## ⚙️ Estrutura do Repositório

* `/src`: Contém o código-fonte em C++ (`.ino`).
* `/docs`: Relatório técnico completo e esquemático elétrico.
* `/media`: Fotos e vídeos dos testes e funcionamento.

## 🚀 Como Executar
1. Clone este repositório.
2. Abra o arquivo `/src/codigo_sumo.ino` na Arduino IDE.
3. Instale as bibliotecas necessárias (se houver).
4. Conecte o Arduino Mega e faça o upload.
