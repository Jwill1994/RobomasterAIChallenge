import math

# Import our own constants:
from globals import FOODMAX,  STEPMAX, WIDTH, HEIGHT, X_MAX, Y_MAX, MS_TO_QUIT

import turtle

class thing:
  def __init__(self, x = 0, y = 0):

    self.ttl = turtle.Turtle() # create a new Python turtle object
    self.ttl.penup()
    self.ttl.speed('fastest')
    self.ttl.goto(x, y)
    self.phase = 0

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

  def __str__(self):

    return 'Doboggi' + str(self.getPosition())



class ghost(thing):
    all = []

    def fly(self):
        self.ttl.forward(100)




    def __init__(self, name, x=0, y=0, heading=0):
        thing.__init__(self, x, y) # Call __init__ of the superclass
        self.name = name           # Initialize the name data attribute
        self.ttl.setheading(heading)
        self.all.append(self)


    def updateShape(self):
        pass


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

        if self.ttl.xcor() > X_MAX + 25:
          self.ttl.setx(-X_MAX - 25)
        elif self.ttl.xcor() > Y_MAX +25:
          self.ttl.sety(-Y_MAX - 25)
        elif self.ttl.xcor() < -X_MAX -25:
          self.ttl.setx(X_MAX + 25)
        elif self.ttl.xcor() < -Y_MAX -25:
          self.ttl.setx(-Y_MAX -25)
        # else:
          # self.ttl.forward(6)


      
    def __str__(self):
        return 'Ghost ' + self.name + str(self.getPosition())


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
        ghost('d', position[0], position[1], heading)




class pacman(thing):

  def __init__(self, x = 0, y = 0):
    """Special method to initialize a pacman object"""
    thing.__init__(self, x, y) # call __init__() of the superclass
    self.dir = 'east'          # set initial direction
    self.steps = STEPMAX       # remaining steps
    self.stepFW = 3
    self.stepBW = 3
    self.turnAngle = 10
    self.isYum = False         # no
    self.isYumOff = False      # bubble

    self.ttl.shape('square')
    self.ttl.shapesize(stretch_wid=0.5, stretch_len=1)
    self.gun = tanktop(x, y)


  def updateShape(self):
    pass


  def blocked(self):
    if self.ttl.xcor() > X_MAX or self.ttl.xcor() < -X_MAX or self.ttl.ycor() > Y_MAX or self.ttl.ycor() < -Y_MAX:
      return True
    else:
      return False



  def move(self):
    """Method to move pacman across the screen."""
    # Don't move beyond screen border:
    pass

    # Move forward:
    # self.ttl.forward(10)

  def getRemainingSteps(self):
    """Return the steps left until the game terminates"""
    return self.steps

  def decrementSteps(self):
    """Decrement remaining steps by 1"""
    self.steps -= 1

  def turnCCW(self):
    self.ttl.left(self.turnAngle) # change pacman turtle's direction to east
    self.gun.ttl.left(self.turnAngle)

    self.updateShape()     # call to switch image according our new direction

  def turnCW(self):
    self.ttl.right(self.turnAngle)
    self.gun.ttl.right(self.turnAngle)

    self.updateShape()

  def goForward(self):
    if self.blocked():
      self.ttl.back(1)
      return
    self.ttl.forward(self.stepFW)
    self.gun.setPosition(self.getPosition())
    self.updateShape()

  def goBackward(self):
    if self.blocked():
      self.ttl.forward(1)
      return
    self.ttl.back(self.stepBW)
    self.gun.setPosition(self.getPosition())
    self.updateShape()

  def setIsYum(self):
    """Remember to display the "Yum" bubble and call 
       updateShape() to switch pacman's appearance.
    """
    self.isYum = True
    self.updateShape()
