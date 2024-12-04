import matplotlib.pyplot as plt

tempo = list()
intervalo_tempo = list()


#main
titulo = str(input('Insira o titulo do grafico: '))

#definição dos intervalos de tempo(s)\
passo = float(input('Insira o passo: '))
maximo = float(input('Insira o maximo: '))
inicio = 0

while inicio <= maximo:
    intervalo_tempo.append(inicio)
    inicio += passo

#definição dos valores de tempo(s)
for c in range(1, 21):
    valor = float(input(f'Insira o valor do tempo(ms) para o tamanho {c * 20000}: '))
    tempo.append(valor / 1000);


#criação do grafico
plt.figure(figsize=(10, 6))
plt.plot(range(20, 420, 20), tempo, marker='o', linestyle='-', color='b')
plt.title(titulo)
plt.xlabel('Size (mil)')
plt.ylabel('Tempo (s)')
plt.grid(True)
plt.xticks(range(0, 420, 20))
plt.yticks(intervalo_tempo)  # Definindo os ticks do eixo y
plt.xlim(10, 410)  # Ajustando limites do eixo x
plt.ylim(0, max(tempo) + passo)  # Ajustando limites do eixo y
plt.show()
