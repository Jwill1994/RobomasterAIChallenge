
import global_vals
# Import our own constants
from game import dobbogi, Tank, tanktop, Bullet, Wall
# Import our game character classes

import turtle
import random

def shutDownHander():
  """Outputs score and terminates the program"""
  global score
  print('Your score:', score)
  window.bye()

def hit(bullet, wall):
    # left_low, right_low, left_high, right_high
    prev_bullet_position = bullet.prevPosition
    curr_bullet_position = bullet.getPosition()



    left_low, right_low, left_high, right_high = wall.range()


def periodicTimer():

  global phase
  global isQuit
  global food
  global score
  turtle.tracer(0, 0) # disable screen updates

  for bullet in Bullet.all:
    bullet.fly()
    for wall in Wall.all:
        if hit(bullet, wall):
            pass


  turtle.tracer(1, 10) # re-enable periodic screen updates



  tank_pos = tank.getPosition()



  if isQuit:
    # Game will terminate, put the "Game Over" image:
    game_over.setposition(0, -global_vals.HEIGHT//2 + 22)
    game_over.shape('game_over.gif')
    game_over.showturtle()
    # Trigger the shutdown handler function to be called in MS_TO_QUIT ms
    # from now:
    window.ontimer(shutDownHander, global_vals.MS_TO_QUIT)
  else:
    # Trigger the next firing of our timer function, in 90ms from now:
    window.ontimer(periodicTimer, 5)


def Foward():
    tank_pos = tank.getPosition()
    tank.goForward()

def Backward():
    tank_pos = tank.getPosition()
    tank.goBackward()



def TurnLeft():
    tank_pos = tank.getPosition()
    tank.turnCCW()


def TurnRight():
    tank_pos = tank.getPosition()
    tank.turnCW()


def GunLeft():
    tank.gun.rotateCCW()

def GunRight():
    tank.gun.rotateCW()


def quitKeyHandler():
  global isQuit
  isQuit = True


isQuit = False
score = 0
turtle.setup(global_vals.WIDTH, global_vals.HEIGHT)
window = turtle.Screen()
window.title('Robomaster')
window.bgcolor('white')

turtle.register_shape('game_over.gif')

def Fire():
    tank.gun.fire(tank.getPosition())



# Wall(x, y, width, height)
width = global_vals.WIDTH
height = global_vals.HEIGHT

Wall(0, height/2 + 5, width+20, 10)
Wall(0, -height/2 - 5, width+20, 10)  # top and bottom

Wall(width/2 + 5, 0, 10, height)
Wall(-width/2 - 5, 0, 10, height)  # sides

Wall(0, height/2-25, 100, 50)
Wall(0, -height/2+25, 100, 50)  # D

Wall(0, 0, 100, 25)  #center


Wall(width/2 - 140 - 12.5, 50, 25, 100)
Wall(-width/2 + 140 + 12.5, -50, 25, 100)


tank = Tank(100, 100)

# Prepare the "game over" turtle already:
game_over = turtle.Turtle()
game_over.hideturtle()
game_over.speed('fastest')
# Install the keyboard handlers:
window.onkey(TurnRight, 'd')
window.onkey(TurnLeft,  'a')
window.onkey(Foward,    'w')
window.onkey(Backward,  's')

window.onkey(GunLeft,  'Left')
window.onkey(GunRight,  'Right')

window.onkey(Fire,  'space')

window.onkey(quitKeyHandler,  'q')
periodicTimer()

window.listen()
window.mainloop()
