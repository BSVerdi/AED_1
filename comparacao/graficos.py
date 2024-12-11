import matplotlib.pyplot as plt

tempo = list()
intervalo_tempo = list()
inicio = 0  

#main

plt.figure(figsize=(10, 6))
plt.xlabel('Size (mil)')
plt.ylabel('Tempo (s)')
plt.grid(True)
plt.xticks(range(0, 420, 20))
plt.xlim(10, 410)

titulo = str(input('Insira o titulo do grafico: '))
plt.title(titulo)

#definição dos intervalos de tempo(s)\
passo = float(input('Insira o passo: '))
maximo = float(input('Insira o maximo: '))

while(inicio <= maximo):
    intervalo_tempo.append(inicio)
    inicio += passo

plt.yticks(intervalo_tempo)
plt.ylim(0, maximo)

dados = int(input('Insira quantos dados deseja no grafico: '))


for c in range(1, dados + 1):
    nome_dado = str(input(f'Insira o nome do {c}º dado: '))

    #definição dos valores de tempo(s)  
    for c in range(1, 21):
        valor = float(input(f'Insira o valor do tempo(ms) para o tamanho {c * 20000}: '))
        tempo.append(valor/1000)

    plt.plot(range(20, 420, 20), tempo, label = nome_dado)

    tempo.clear()
    
plt.legend()
plt.show()
