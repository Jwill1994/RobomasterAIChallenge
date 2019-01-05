import math

# Import our own constants:
import global_vals

import turtle

class thing:
  def __init__(self, x = 0, y = 0):

    self.ttl = turtle.Turtle() # create a new Python turtle object
    self.ttl.hideturtle()
    self.ttl.penup()
    self.ttl.speed('fastest')
    self.ttl.goto(x, y)
    self.ttl.showturtle()

  def getPosition(self):
    """Method to return the screen position of a 'thing' object.
       The return-value is a tuple (x, y).
    """
    return (self.ttl.xcor(), self.ttl.ycor()) # retrieve coordinates from
                                              # turtle ttl and return tuple


class dobbogi(thing):

  def __init__(self, x = 0, y = 0):
    """Special method to initialize a 'doboggi' object in memory."""
    thing.__init__(self, x, y)            # Call __init__() of the superclass
    self.ttl.shape('square') # Set image of the object's turtle
    self.ttl.color('yellow')

  def setIsEaten(self):
    """Stop displaying this doboggi object in the game."""
    self.ttl.hideturtle()



class Wall(thing):
    all = []

    def __init__(self, x, y, width, height):
        thing.__init__(self, x, y)
        self.ttl.shape('square')
        self.ttl.color('gray')
        self.ttl.shapesize(global_vals.SCALE * height/20, global_vals.SCALE * width/20)
        self.all.append(self)





class Bullet(thing):
    all = []

    def __init__(self, x=0, y=0, heading=0):
        thing.__init__(self, x, y) # Call __init__ of the superclass
        self.ttl.setheading(heading)
        self.all.append(self)


    def fly(self):
        self.ttl.forward(100)

    def move(self, pm):

        pmPos = pm.getPosition()
        ghPos = self.getPosition()

        dy = pmPos[1]-ghPos[1]
        dx = pmPos[0]-ghPos[0]

        if math.atan2(dy,dx)*180/math.pi<0 :
            degree=360+math.atan2(dy,dx)*180/math.pi
      # print(360+math.atan2(dy,dx)*180/math.pi)
        else:
            degree=math.atan2(dy,dx)*180/math.pi
            # print(math.atan2(dy,dx)*180/math.pi)
    
        self.ttl.setheading(degree)

        if self.ttl.xcor() > global_vals.X_MAX + 25:
          self.ttl.setx(-global_vals.X_MAX - 25)
        elif self.ttl.xcor() > global_vals.Y_MAX +25:
          self.ttl.sety(-global_vals.Y_MAX - 25)
        elif self.ttl.xcor() < -global_vals.X_MAX -25:
          self.ttl.setx(global_vals.X_MAX + 25)
        elif self.ttl.xcor() < -global_vals.Y_MAX -25:
          self.ttl.setx(-global_vals.Y_MAX -25)


class tanktop(thing):

    def __init__(self, x=0, y=0):
        thing.__init__(self, x, y)
        self.ttl.shape('arrow')
        self.ttl.color('green')
        self.ttl.shapesize(stretch_wid=0.5, stretch_len=2)
        self.rotateAngle = 10

    def setPosition(self, tankPosition):
        self.ttl.setposition(tankPosition[0], tankPosition[1])

    def rotateCW(self):
        self.ttl.right(self.rotateAngle)

    def rotateCCW(self):
        self.ttl.left(self.rotateAngle)

    def fire(self, position):
        heading = self.ttl.heading()
        Bullet(position[0], position[1], heading)





class Tank(thing):
  stepFW = 3
  stepBW = 3
  def __init__(self, x = 0, y = 0):
    thing.__init__(self, x, y) # call __init__() of the superclass
    self.steps = global_vals.STEPMAX       # remaining steps

    self.turnAngle = 10
    self.isYum = False         # no
    self.isYumOff = False      # bubble

    self.ttl.shape('square')
    self.ttl.shapesize(stretch_wid=1, stretch_len=2)
    self.gun = tanktop(x, y)

  def blocked(self):
    if self.ttl.xcor() > global_vals.X_MAX or self.ttl.xcor() < -global_vals.X_MAX or self.ttl.ycor() > global_vals.Y_MAX or self.ttl.ycor() < -global_vals.Y_MAX:
      return True
    else:
      return False





  def getRemainingSteps(self):
    """Return the steps left until the game terminates"""
    return self.steps

  def decrementSteps(self):
    """Decrement remaining steps by 1"""
    self.steps -= 1

  def turnCCW(self):
    self.ttl.left(self.turnAngle)
    self.gun.ttl.left(self.turnAngle)


  def turnCW(self):
    self.ttl.right(self.turnAngle)
    self.gun.ttl.right(self.turnAngle)


  def goForward(self, step=stepFW):
    if self.blocked():
      self.ttl.back(1)
      return
    self.ttl.forward(step)
    self.gun.setPosition(self.getPosition())
    print(int(self.getPosition()[0]), int(self.getPosition()[1]))

  def goBackward(self, step=stepBW):
    if self.blocked():
      self.ttl.forward(1)
      return
    self.ttl.back(step)
    self.gun.setPosition(self.getPosition())
    print(int(self.getPosition()[0]), int(self.getPosition()[1]))


  def setIsYum(self):
    """Remember to display the "Yum" bubble and call 
    """
    self.isYum = True
