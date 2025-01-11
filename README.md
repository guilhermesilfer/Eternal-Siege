# Eternal-Siege
Eternal Siege é um jogo de defesa de base feito para a matéria de Linguagem de Programação I

**VÍDEO TESTANDO: https://drive.google.com/file/d/1z3YL1lEqxCNNbNjLUJCVVr4L2vdfzbo5/view?usp=sharing**

- **SFML 2.6**

- **Compilador C++** (g++)

- **make** (opcional)


## Compilação

### Utilizando make
```
make
```

### Ou manualmente
```
g++ -c main.cpp game.cpp player.cpp enemy.cpp
g++ main.o game.o player.o enemy.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
```
