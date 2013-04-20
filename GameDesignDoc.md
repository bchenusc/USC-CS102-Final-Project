# Game Design Document : Sheep With A Turret

S.W.A.T (Sheep With a Turret) is a side scrolling shooter game. The government has been secretly experimenting with sheep turrets.
Mr. Fluffles has escaped from a secret military facility out in the Nevada desert. Your goal is to help Mr. Fluffles escape to
freedom!

#Controls:
1. W - Jump
2. A - Move Left
3. D - Move Right
4. 1 - Change to weapon 1.
5. 2 - Change to weapon 2 (if unlocked).
6. Mouse Cursor - Determines where you shoot missiles.
7. Mouse Click - Shoot Missiles.

#Gameplay:
1. Shoot enemy aircrafts to gain score.
2. At certain score milestones, newer turrets are unlocked.
3. Newer turrets can be accessed by pressing the 1,2,3,4 hotkeys.
4. A player can still use their old turrets.
5. Eating people/tanks will also gain score and health.

#Scoring:
1. Players gain a fixed score when killing an enemy. Fixed score based on what type of enemy.
2. Score cannot decrease.

## Objects:
### Player
1. Mr. Fluffles
--  Controlled by player.
--  W - Jump
--  A - Left
--  D - Right
--  Mouse - Click to fire.

2. Reticle
-- Follows Mouse.
-- Location of where the bullets from the sheep are to be shot.

3. Health Bar
-- Shows the health of Mr. Fluffles.
-- Increases or decreases based on Mr. Fluffle's health.
-- If health = 0 then Mr. Fluffles "dies"

4. Lives
-- When Mr. Fluffle's health depletes, his lives decrease by one.

5. Weapons GUI
-- Little icon that shows what turret Mr. Fluffles has equiped.
-- Switch weapons using 1,2,3,4 commands.

6. Mr. Fluffle's turret
-- Stationary turret on the back of Mr. Fluffles.
-- Weapons will shoot out of the turret's nozzle.

7. Mr. Fluffle's missiles/lasers
-- A missile that fires from Mr. Fluffle's turret nozzle to the mouse point (and reticle).
-- When a missile collides with an enemy, the missile will damage the enemy's health.


### Enemies/Others
1. Humans
-- Sheep food.
-- Sheep health bar regenerates based on eating humans.

2. Missiles
-- Enemy aircrafts shoot missiles that move towards Mr. Fluffle's position.
-- Missiles will damage Mr. Fluffles and make him lose life using an damage equation.

3. Enemy aircraft
-- Has health.
-- Shoots enemy missiles at Mr. Fluffles.
-- Damaged by Mr. Fluffle's missiles.
-- Destroyed if health reaches 0
-- Air unit.
-- Cannot be eaten by sheep.

4. Enemy tank
-- Has health.
-- Ground unit
-- Also can shoot missiles.
-- Sheep can eat enemy tanks.

#Screenshot
[alt text](https://github.com/usc-csci102-spring2013/game_brianych/blob/master/pic.jpg "Screenshot")
























