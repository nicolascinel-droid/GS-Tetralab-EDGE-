# 🚀 GS-Tetralab-EDGE

## 🧲 TETRALAB – Sistema Inteligente de Monitoramento de Temperatura e Campo Magnético

Projeto desenvolvido para monitorar as condições operacionais da **Tetrataenita**, utilizando conceitos de **Edge Computing**, sensores simulados e registro de dados em tempo real.

---

# 🧲 O que é a Tetrataenita?

A **Tetrataenita** é uma liga metálica composta principalmente por ferro e níquel, conhecida por suas propriedades magnéticas excepcionais.

Ela é considerada uma alternativa promissora para a fabricação de ímãs permanentes de alto desempenho, podendo reduzir a dependência de terras raras utilizadas atualmente na indústria.

Entretanto, suas propriedades magnéticas podem ser afetadas por alterações de temperatura e intensidade do campo magnético, tornando essencial o monitoramento dessas variáveis.

Foi com base nesse desafio que surgiu o **TETRALAB**.

---

# 👥 Integrantes

* Nicolas Cinel – RM 572940
* Isac Nilton – RM 573282
* Luis Fernando – RM 570958
* Leonardo Formigari – RM 573291
* João Benedito – RM 570206

---

# 📖 Descrição do Projeto

O **TETRALAB** é uma solução de Edge Computing desenvolvida para monitorar condições operacionais relacionadas à Tetrataenita.

Utilizando um **Arduino Uno**, o sistema realiza o processamento local dos dados, analisando simultaneamente:

* 🌡️ Temperatura
* 🧲 Campo Magnético

Com base nessas informações, o sistema identifica três estados operacionais:

* 🟢 Normal
* 🟡 Alerta
* 🔴 Crítico

Os resultados são exibidos em um display LCD, sinalizados por LEDs coloridos e registrados em um sistema de Data Logger com data e hora.

---

# 🎯 Objetivo

Desenvolver um sistema embarcado capaz de monitorar variáveis críticas relacionadas ao desempenho de materiais magnéticos, permitindo identificar possíveis falhas antes que elas comprometam o funcionamento do sistema.

### Conceitos Aplicados

* Edge Computing
* Sistemas Embarcados
* Monitoramento em Tempo Real
* Aquisição de Dados
* Data Logging
* Alertas Visuais e Sonoros

---

# 🔧 Componentes Utilizados

| Componente                      | Quantidade |
| ------------------------------- | ---------- |
| Arduino Uno                     | 1          |
| Display LCD 16x2                | 1          |
| RTC DS1307                      | 1          |
| LED Verde                       | 1          |
| LED Amarelo                     | 1          |
| LED Vermelho                    | 1          |
| Resistores 220 Ω                | 3          |
| Buzzer                          | 1          |
| Potenciômetro (Temperatura)     | 1          |
| Potenciômetro (Campo Magnético) | 1          |
| Protoboard                      | 1          |
| Jumpers                         | Diversos   |

---

# ⚙️ Funcionamento do Sistema

O sistema realiza leituras contínuas de dois sensores simulados por potenciômetros.

### 🌡️ Temperatura

Leitura realizada pela porta **A0**.

### 🧲 Campo Magnético

Leitura realizada pela porta **A1**.

Os valores são convertidos para porcentagem (**0% a 100%**) e utilizados para definir o estado operacional do sistema.

---

# 🚦 Estados de Operação

## 🟢 NORMAL

### Condições

* Temperatura abaixo de 34%
* Campo magnético acima de 49%

### Ações

* LED verde aceso
* Buzzer desligado
* LCD exibe "NORMAL"

### Significado

A Tetrataenita mantém suas propriedades magnéticas de forma estável.

---

## 🟡 ALERTA

### Condições

* Temperatura entre 34% e 68%
* Campo magnético acima de 49%

### Ações

* LED amarelo aceso
* Buzzer desligado
* LCD exibe "ALERTA"

### Significado

A temperatura está aumentando e existe risco de degradação gradual das propriedades magnéticas.

---

## 🔴 CRÍTICO

### Condições

* Temperatura acima de 68%
  **ou**
* Campo magnético abaixo de 49%

### Ações

* LED vermelho aceso
* Buzzer acionado em 1000 Hz
* LCD exibe "CRÍTICO"

### Significado

A Tetrataenita perdeu ou está prestes a perder suas propriedades magnéticas ideais.

---

# 🖥️ Interface do Usuário

O display LCD apresenta:

* Estado atual do sistema
* Temperatura (%)
* Campo magnético (%)
* Ícones personalizados

Além disso, LEDs coloridos e buzzer fornecem feedback imediato sobre a condição monitorada.

---

# 📊 Data Logger

O sistema registra automaticamente informações no Serial Monitor a cada 2 segundos.

### Informações registradas

* Número da medição
* Data
* Hora
* Temperatura (%)
* Campo Magnético (%)
* Estado Atual

### Exemplo

```csv
registro,data_hora,T%=45%,M=70%,ALERTA
```

Esses registros permitem acompanhar o histórico de funcionamento do sistema.

---

# 🔌 Mapeamento de Portas

## Entradas

| Porta | Componente                |
| ----- | ------------------------- |
| A0    | Sensor de Temperatura     |
| A1    | Sensor de Campo Magnético |
| A4    | SDA RTC DS1307            |
| A5    | SCL RTC DS1307            |

### Saídas

| Porta | Componente   |
| ----- | ------------ |
| D2    | LED Verde    |
| D3    | LED Amarelo  |
| D4    | LED Vermelho |
| D5    | Buzzer       |

---

# 📟 Conexão do LCD

| LCD | Arduino |
| --- | ------- |
| RS  | D12     |
| E   | D11     |
| D4  | D10     |
| D5  | D9      |
| D6  | D8      |
| D7  | D7      |

---

# 💻 Tecnologias Utilizadas

* Arduino C/C++
* Arduino Uno
* Wokwi Simulator
* LiquidCrystal
* RTClib
* Edge Computing
* Data Logging

---

# 📂 Estrutura do Repositório

```text
/
├── README.md
├── sketch.ino
└── diagram.json
```

---

# 🔗 Simulação no Wokwi

https://wokwi.com/projects/465209479035038721

---

# ✅ Conclusão

O **TETRALAB** demonstra a aplicação prática de Edge Computing para monitoramento local de variáveis críticas relacionadas à Tetrataenita.

A solução permite detectar alterações de temperatura e campo magnético em tempo real, gerar alertas visuais e sonoros, além de registrar informações históricas para análise posterior, contribuindo para a confiabilidade e segurança operacional do sistema.
