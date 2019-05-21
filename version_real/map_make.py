import value_assign as va
import numpy as np
import matplotlib.pyplot as plt
import cv2

x = 500
y = 800
border = y / 16
border2 = x + border*2
pm = va.potentialField([x,y])
pm.rectangular_assign(0, 8.000, 0, 5.000, 255, mode='abs')

inner_wall_tuple = ((1.200,2.200, 3.750,4.000), (1.400,1.650,1.400,2.400), (3.250,3.500,0,1.000),(3.500,4.500,2.375,2.625),(5.800,6.800,1.000,1.250),(6.350,6.600,2.600,3.600),(4.500,4.750,4.000,5.000))

for item in inner_wall_tuple:
    x1, x2, y1, y2 = item
    pm.rectangular_assign(x1,x2,y1,y2, 0, mode='abs')


image = np.flip(pm.out(), axis=0)
black1 = np.zeros([border, y])
black2 = np.zeros([border2, border])

image = cv2.vconcat([image, black1])
image = cv2.vconcat([black1, image])
image = cv2.hconcat([image, black2])
image = cv2.hconcat([black2, image])

image = cv2.resize(image, (180,120))

cv2.imwrite('map.png', image)
cv2.imwrite('map.pgm', image)
