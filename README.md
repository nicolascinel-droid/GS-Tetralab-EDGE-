# GS-Tetralab-EDGE-
Projeto sobre a Tetrataenita

# MAGNOSPACE – Sistema Inteligente de Monitoramento de Temperatura e Campo Magnético

## Integrantes

* Nicolas Cinel – RM 572940
* Isac Nilton – RM 573282
* Luis Fernando – RM 570958
* Leonardo Formigari – RM 573291
* João Benedito – RM 570206
---

# Descrição do Projeto

O MAGNOSPACE é uma solução de Edge Computing desenvolvida para monitorar as condições operacionais de materiais magnéticos avançados, como a Tetrataenita, analisando simultaneamente temperatura e intensidade do campo magnético.

O sistema utiliza um Arduino Uno para processar os dados localmente, permitindo identificar situações de operação normal, alerta e estado crítico em tempo real.

As informações são exibidas em um display LCD, sinalizadas por LEDs coloridos e registradas em um Data Logger com data e hora para acompanhamento dos eventos.

---

# Objetivo

Desenvolver um sistema embarcado capaz de monitorar variáveis críticas relacionadas ao desempenho de materiais magnéticos, alertando operadores sobre possíveis falhas antes que elas comprometam o funcionamento do sistema.

A proposta demonstra conceitos de:

* Edge Computing
* Monitoramento em Tempo Real
* Sistemas Embarcados
* Aquisição de Dados
* Registro Histórico de Eventos

---

# Componentes Utilizados

| Componente                         | Quantidade |
| ---------------------------------- | ---------- |
| Arduino Uno                        | 1          |
| Display LCD 16x2                   | 1          |
| RTC DS1307 (Relógio de Tempo Real) | 1          |
| LED Verde                          | 1          |
| LED Amarelo                        | 1          |
| LED Vermelho                       | 1          |
| Resistores 220 Ω                   | 3          |
| Buzzer                             | 1          |
| Potenciômetro (Temperatura)        | 1          |
| Potenciômetro (Campo Magnético)    | 1          |
| Protoboard                         | 1          |
| Jumpers                            | Diversos   |

---

# Funcionamento do Sistema

O sistema realiza a leitura contínua de dois sensores simulados por potenciômetros:

### Temperatura

Representada pelo potenciômetro conectado à porta A0.

### Campo Magnético

Representado pelo potenciômetro conectado à porta A1.

Os valores são convertidos para porcentagem (0% a 100%) e utilizados para determinar o estado operacional do sistema.

---

# Estados de Operação

## 🟢 Estado NORMAL

Condições:

* Temperatura abaixo de 34%
* Campo magnético acima de 49%

Ações:

* LED verde aceso
* Buzzer desligado
* LCD exibe estado NORMAL

Significado:

O material mantém suas propriedades magnéticas de forma estável, operando em condições ideais.

---

## 🟡 Estado ALERTA

Condições:

* Temperatura entre 34% e 68%
* Campo magnético acima de 49%

Ações:

* LED amarelo aceso
* Buzzer desligado
* LCD exibe estado ALERTA

Significado:

A temperatura está aumentando e existe risco de perda gradual das propriedades magnéticas caso a condição continue evoluindo.

---

## 🔴 Estado CRÍTICO

Condições:

* Temperatura acima de 68%
* Ou campo magnético abaixo de 49%

Ações:

* LED vermelho aceso
* Buzzer acionado em 1000 Hz
* LCD exibe estado CRÍTICO

Significado:

O material perdeu ou está prestes a perder suas propriedades magnéticas ideais, exigindo intervenção imediata.

---

# Interface do Usuário

O display LCD apresenta:

* Estado atual do sistema
* Temperatura em porcentagem
* Intensidade do campo magnético em porcentagem
* Ícones personalizados para facilitar a visualização

Além disso, LEDs coloridos indicam rapidamente a condição operacional do sistema.

---

# Data Logger

O projeto registra automaticamente informações no Serial Monitor a cada 2 segundos.

Cada registro contém:

* Número da medição
* Data
* Hora
* Temperatura (%)
* Campo magnético (%)
* Estado atual do sistema

Exemplo:

registro,data_hora,T%=45%,M=70%,ALERTA

Esse recurso permite criar um histórico de funcionamento e acompanhar a evolução das condições monitoradas.

---

# Mapeamento de Portas

## Entradas

| Porta | Componente                |
| ----- | ------------------------- |
| A0    | Sensor de Temperatura     |
| A1    | Sensor de Campo Magnético |
| A4    | SDA do RTC DS1307         |
| A5    | SCL do RTC DS1307         |

---

## Saídas

| Porta | Componente   |
| ----- | ------------ |
| D2    | LED Verde    |
| D3    | LED Amarelo  |
| D4    | LED Vermelho |
| D5    | Buzzer       |

---

## Display LCD

| LCD | Arduino |
| --- | ------- |
| RS  | D12     |
| E   | D11     |
| D4  | D10     |
| D5  | D9      |
| D6  | D8      |
| D7  | D7      |

---

# Tecnologias Utilizadas

* Arduino C/C++
* Arduino Uno
* Wokwi Simulator
* Biblioteca LiquidCrystal
* Biblioteca RTClib
* Edge Computing
* Data Logging

---

# Estrutura do Repositório

```text
/
├── README.md
├── sketch.ino
└── diagram.json
```

# Link do Projeto



[https://wokwi.com/](https://wokwi.com/projects/465209479035038721)

---

# Conclusão

O MAGNOSPACE demonstra como técnicas de Edge Computing podem ser utilizadas para monitoramento local de variáveis críticas, permitindo respostas rápidas, geração de alertas e registro histórico de dados. A solução oferece uma forma simples e eficiente de acompanhar o comportamento de sistemas magnéticos, contribuindo para a prevenção de falhas e aumento da confiabilidade operacional.
