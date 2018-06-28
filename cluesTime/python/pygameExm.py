import sys, pygame
 
BLACK = 0, 0, 0
WHITE = 255, 255, 255
 
pygame.init()
screen = pygame.display.set_mode((640,480))
pygame.display.set_caption("Moving Box")
 
clock = pygame.time.Clock()
 
box_x = 300
box_dir = 3
 
while 1:
  clock.tick(50)
 
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      sys.exit()
 
  screen.fill(BLACK)
 
  box_x += box_dir
  if box_x >= 620:
    box_x = 620
    box_dir = -3
  elif box_x <= 0:
    box_x = 0
    box_dir = 3
 
  pygame.draw.rect(screen, WHITE, (box_x, 200, 20, 20))
  pygame.display.flip()
