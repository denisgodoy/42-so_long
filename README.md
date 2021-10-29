![Graphics](https://img.shields.io/badge/Graphics-306998) ![ImperativeProgramming](https://img.shields.io/badge/ImperativeProgramming-306998)

# so_long :video_game:
A small 2D game using MiniLibX, including textures, sprites and some basic gameplay elements.

- [Evaluation](https://github.com/denisgodoy/42-so_long#evaluation)
- [Game rules](https://github.com/denisgodoy/42-so_long#game-rules)
- [Mandatory part](https://github.com/denisgodoy/42-so_long#mandatory-part)
- [Bonus part](https://github.com/denisgodoy/42-so_long#bonus-part)

Clone this repository to play the game. Control keys are WASD.
```shell
git clone --recurse-submodules https://github.com/denisgodoy/42-so_long.git so_long
cd so_long
```

## Evaluation

[PROJECT IN PROGRESS]

## Game rules

The game must follow some strict rules:
- Treat wall collisions, the player must not be able to move over walls;
- Maps have to contain an specific configuration:
  - Surrounded by walls `1`;
  - Be rectangular;
  - Contain 1 player `P`, 1 exit `E`, at least 1 free space `0` and 1 collectible `C`;
  - .ber file extension.
- The player can leave the map when all collectibles have been collected or;
- Press the escape `ESC` key or;
- Close the window;

## Mandatory part

There are no animations or enemies, the player must collect all keys to open the treasure chest to finish the map.
```shell
make all
./so_long maps/<map-name>.ber
```

## Bonus part

The game gets quite complex, with an enemy patrol that causes the player to lose, and some sprite animation. At least 1 `T` character must be added to the map, representing the enemy.
```shell
make bonus
./so_long maps/<map-name>_bonus.ber
```
