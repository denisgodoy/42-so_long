![Graphics](https://img.shields.io/badge/Graphics-306998) ![ImperativeProgramming](https://img.shields.io/badge/ImperativeProgramming-306998)

# so_long :video_game:
A small 2D game using MiniLibX, including textures, sprites and some basic gameplay elements.

- [Evaluation](https://github.com/denisgodoy/42-so_long#evaluation)
- [Game rules](https://github.com/denisgodoy/42-so_long#game-rules)
- [Mandatory part](https://github.com/denisgodoy/42-so_long#mandatory-part)
- [Bonus part](https://github.com/denisgodoy/42-so_long#bonus-part)

![so_long](https://user-images.githubusercontent.com/56933400/139519574-ba2fe313-af45-41f8-a6cf-06755e118ff7.png)

Clone this repository to play the game. Control keys are WASD.
```shell
git clone --recurse-submodules -b mac_os https://github.com/denisgodoy/42-so_long.git so_long
cd so_long
```

## Evaluation

![grade](https://user-images.githubusercontent.com/56933400/139965040-7faa31f1-abc0-4a4d-9905-4cf0806cddda.png)
![badge](https://game.42sp.org.br/static/assets/achievements/so_longm.png)

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
- A movements counter must be displayed on terminal.

## Mandatory part

There are no animations or enemies, the player must collect all keys to open the treasure chest to finish the map.
```shell
make all
./so_long maps/<map-name>.ber
```

![mandatory_so_long](https://user-images.githubusercontent.com/56933400/139359201-53e072fa-266f-49e6-945a-8dd58cbc3b78.gif)

## Bonus part

The game objective remains the same, but it gets quite complex with an enemy patrol that causes the player to lose, and some sprite animation added.
- At least 1 `T` character must be added to the map, representing the enemy;
- The movements counter must be displayed directly on the window.
```shell
make bonus
./so_long maps/<map-name>_bonus.ber
```

![bonus_so_long](https://user-images.githubusercontent.com/56933400/139512160-ee03ca32-098b-4001-b553-64171fd2d058.gif)
