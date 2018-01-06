import pygame
import threading
import random
pygame.init()

display_width=800
display_height=600

gameDisplay=pygame.display.set_mode((display_width,display_height))
pygame.display.set_caption('A bit Racey')

black=(0,0,0)
white=(255,255,255)

clock=pygame.time.Clock()
crashed=False
carImage=pygame.image.load('racecar.png')

def car(x,y):
    gameDisplay.blit(carImage,(x,y))
def mcar(x,y,Image):
  gameDisplay.blit(Image,(x,y))

crashed2=False
def randommovecar():
  xr=range(display_width)
  yr=range(display_height)
  dl=["Up","Down","Left","Right"]
  x=random.sample(xr,1)[0]
  y=random.sample(yr,1)[0]
  d=random.sample(dl,1)[0]
  s=random.sample(range(100,200),1)[0]
  cImage=pygame.image.load('racecar.png')
  cl=pygame.time.Clock()

  if d=="Left":
       cImage=rotate(cImage,90)
  if  d=="Right":
       cImage=rotate(cImage,-90)
  if d=="Down":
       cImage=rotate(cImage,180)

  while not crashed2:
    if d=="Up":y-=1
    if d=="Down":y+=1
    if d=="Right":x+=1
    if d=="Left":x-=1
    if x<0:x=display_width
    if y<0:y=display_height
    if x>display_width: x=0
    if y>display_height: y=0
    mcar(x,y,cImage)
    pygame.display.update()
    cl.tick(s) 

#dontCreateCar=False
def carCreater():
  print("come here")
  clk=pygame.time.Clock()
  for i in range(5):
       t=threading.Thread(target=randommovecar)
       t.daemon=True
       t.start()
       clk.tick(1)

tm=threading.Thread(target=carCreater)
tm.daemon=True
tm.start()


def soundplay():
  pygame.mixer.music.load('carsound.mp3')
  pygame.mixer.music.play(20)
   

def rotate(image, angle):
        """rotate an image while keeping its center"""
        rect=image.get_rect()
        rot_image = pygame.transform.rotate(image, angle)
        rot_rect = rot_image.get_rect(center=rect.center)
        return rot_image  

x=(display_width*0.45)
y=(display_height*0.8)
direction="Up"
t=threading.Thread(target=soundplay)
t.daemon = True  # thread dies when main thread (only non-daemon thread) exits.
t.start()
while not crashed:
  for event in pygame.event.get():
     if event.type==pygame.QUIT:
             crashed=True
     if event.type == pygame.KEYDOWN:        
        if event.key==pygame.K_UP:
          if direction=="Left":
           	      carImage=rotate(carImage,-90)
          if  direction=="Right":
                  carImage=rotate(carImage,90)
          if direction=="Down":
                  carImage=rotate(carImage,180)
          direction="Up"
        if event.key==pygame.K_LEFT:
          if direction=="Up":
           	      carImage=rotate(carImage,90)
          if  direction=="Right":
                  carImage=rotate(carImage,180)
          if direction=="Down":
                  carImage=rotate(carImage,-90)
          direction="Left"
        if event.key==pygame.K_DOWN:
          if direction=="Left":
           	      carImage=rotate(carImage,90)
          if  direction=="Right":
                  carImage=rotate(carImage,-90)
          if direction=="Up":
                  carImage=rotate(carImage,180)
          direction="Down"
        if event.key==pygame.K_RIGHT:
          if direction=="Left":
           	      carImage=rotate(carImage,180)
          if  direction=="Up":
                  carImage=rotate(carImage,-90)
          if direction=="Down":
                  carImage=rotate(carImage,90)
          direction="Right"    	
     	 
  
  if direction=="Up":y-=1
  if direction=="Down":y+=1
  if direction=="Right":x+=1
  if direction=="Left":x-=1
  if x<0:x=display_width
  if y<0:y=display_height
  if x>display_width: x=0
  if y>display_height: y=0 
  gameDisplay.fill(white)
  car(x,y)
  pygame.display.update()
  clock.tick(120)



pygame.quit()
quit()
