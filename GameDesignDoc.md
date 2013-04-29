# Game Design Document : Sheep With A Turret

S.W.A.T (Sheep With a Turret) is a side scrolling shooter game. The government has been secretly experimenting with sheep turrets.
Mr. Fluffles has escaped from a secret military facility out in the Hidden Omarian Valley. Your goal is to help Mr. Fluffles escape to
freedom!

#Controls:
+ W - Jump
+ A - Move Left
+ D - Move Right
+ Mouse Cursor - Rotate Turret.
+ Mouse Click - Shoot Missiles.

#Gameplay:
+ +25 pts. Shoot down airplanes (3 shots to kill).
+ +10 pts. Shoot a hamster (1 shot to kill).
+ -5 pts. per shot.

+ +1 Health if shoot or touch a health box.

#Scoring:
+ Players gain a fixed score when killing an enemy. Fixed score based on what type of enemy.
+ Score cannot decrease.

## Objects:
### Player
1. Mr. Fluffles
--  Controlled by player.

  +  W - Jump
  +  A - Left

  +  D - Right

  +  Mouse - Click to fire.

2. Reticle
  + Follows Mouse.
  + Location of where the bullets from the sheep are to be shot.

3. Health Bar
  + Shows the health of Mr. Fluffles.
  + Increases or decreases based on Mr. Fluffle's health.
  + If health = 0 then Mr. Fluffles "dies"

4. Lives
  + When Mr. Fluffle's health depletes, his lives decrease by one.

5. Weapons GUI
  + Little icon that shows what turret Mr. Fluffles has equiped.
  + Switch weapons using 1,2,3,4 commands.

6. Mr. Fluffle's turret
  + Stationary turret on the back of Mr. Fluffles.
  + Weapons will shoot out of the turret's nozzle.

7. Mr. Fluffle's missiles/lasers
  + A missile that fires from Mr. Fluffle's turret nozzle to the mouse point (and reticle).
  + When a missile collides with an enemy, the missile will damage the enemy's health.


### Enemies/Others
1. Humans
  + Sheep food.

  + Sheep health bar regenerates based on eating humans.


2. Missiles
  + Enemy aircrafts shoot missiles that move towards Mr. Fluffle's position.

  + Missiles will damage Mr. Fluffles and make him lose life using an damage equation.


3. Enemy aircraft
  + Has health.

  + Shoots enemy missiles at Mr. Fluffles.

  + Damaged by Mr. Fluffle's missiles.

  + Destroyed if health reaches 0

  + Air unit.

  + Cannot be eaten by sheep.


4. Enemy tank
  + Has health.

  + Ground unit

  + Also can shoot missiles.

  + Sheep can eat enemy tanks.


#Screenshot
![alt text](/pic.jpg "Screenshot")
























