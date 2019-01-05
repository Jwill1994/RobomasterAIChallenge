
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

def checkCollision(t1, t2):
  """Input: 2 coordinate tuples.
     Return: True if the coordinates are sufficiently close
             False otherwise
  """
  if (abs(t1[0] - t2[0]) < 25) and (abs(t1[1] - t2[1]) < 25):
    return True
  return False

def periodicTimer():
  """Timer function which is called periodically by Python.
     This function implements the game logic:
     - creating all objects
     - arranging objects on the screen
     - calling object's move() methods
     - checking for collisions
     - checking for invalid moves
     - detection program termination conditions (all food eaten, ...)
     - initiate termination
  """
  global phase
  global isQuit
  global food
  global score
  turtle.tracer(0, 0) # disable screen updates

  for g in Bullet.all:
    g.fly()

  # for g in ghosts:
  #   g.updateShape()   # make ghost change its shape


  # turtle.update()      # force turtle module's screen update
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
    window.ontimer(periodicTimer, 100)


def Foward():
    global food
    tank_pos = tank.getPosition()
    for dish in food:
        if checkCollision(tank_pos, dish.getPosition()):
            tank.goBackward()
            tank.goBackward()
            return
    tank.goForward()
    for dish in food:
        if checkCollision(tank_pos, dish.getPosition()):
            tank.goBackward()
            tank.goBackward()
            return

def Backward():
    global food
    tank_pos = tank.getPosition()
    for dish in food:
        if checkCollision(tank_pos, dish.getPosition()):
            tank.goForward()
            tank.goForward()
            return
    tank.goBackward()
    for dish in food:
        if checkCollision(tank_pos, dish.getPosition()):
            tank.goForward()
            tank.goForward()
            return


def TurnLeft():
    global food
    tank_pos = tank.getPosition()
    for dish in food:
        if checkCollision(tank_pos, dish.getPosition()):
            return
    tank.turnCCW()


def TurnRight():
    global food
    tank_pos = tank.getPosition()
    for dish in food:
        if checkCollision(tank_pos, dish.getPosition()):
            return
    tank.turnCW()


def GunLeft():
    tank.gun.rotateCCW()

def GunRight():
    tank.gun.rotateCW()


def quitKeyHandler():
  global isQuit
  isQuit = True

def placeFood():
  global food

  food = []
  Upper = True
  for i in range(0, global_vals.FOODMAX):
    ok = False
    while not ok: # loop until proper position was computed:
      r_x = random.randrange(-global_vals.X_MAX + 20, global_vals.X_MAX - 20)
      if Upper:
        # Position above the ghosts:
        r_y = random.randrange(160, global_vals.Y_MAX)
      else:
        # Position below the ghosts:
        r_y = random.randrange(-global_vals.Y_MAX, -40)
      new_pos = (r_x, r_y)
      HaveCollision = False
      for i in food:
        HaveCollision = HaveCollision or checkCollision(new_pos, i.getPosition())
      if not HaveCollision:
        food.append(dobbogi(r_x, r_y))
        ok = True
    Upper = not Upper # toggle between ``above'' and ``below" ghost's
                      # screen part.
  return food

#
# Main program
#
isQuit = False
score = 0
turtle.setup(global_vals.WIDTH, global_vals.HEIGHT)
window = turtle.Screen()
window.title('Dobbogi-Man')
window.bgcolor('white')

turtle.register_shape('yum.gif')
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

food = []
food += placeFood()
# Prepare the "game over" turtle already:
game_over = turtle.Turtle()
game_over.hideturtle()
game_over.speed('fastest')
phase = 0
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
