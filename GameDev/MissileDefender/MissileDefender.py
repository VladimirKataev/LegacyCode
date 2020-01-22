#################----INIT----##############
import pygame,sys,math,random
global screen
clock = pygame.time.Clock()
#dsad = input("Press any key to begin")
pygame.init()
pygame.display.init()
screen = pygame.display.set_mode((900, 550))
pygame.display.set_caption("Missile Defender")
from pygame.locals import *
from pygame import font
pygame.font.init
pygame.font.get_fonts
Alive= bool(True)
pygame.font.SysFont("Arial",24)
frame = int(0)
wave = int(1)
LastFired = int(0)
charged = bool(False)
FriendlyMissiles = []
EnemyMissiles = []
starsX = []
starsY = []
Wave = int(1)
ToLaunch = wave
KilledThisWave = int(0)
Airborne = wave
clicks = int(0)
begun = bool(False)
lost = bool(False)
Ranout = bool(False)
#################----FUNC----##############
def GenStars():
    for rec in range(random.randint(25,120)):
        starsX.append(random.randint(0,900))
        starsY.append(random.randint(0,350))
def DrawStars():
    for star in range(int(len(starsX))):
        pygame.draw.circle(screen,(250,250,250),[starsX[star],starsY[star]],2)
def DrawAtmo():
    pygame.draw.ellipse(screen,(50,50,250),[-150,400,1200,650])
def DrawEarth():
    pygame.draw.ellipse(screen,(50,250,50),[-200,500,1325,650])
def DrawCitys():
    pygame.draw.rect(screen,(150,150,150),[150,500,15,40])   
    pygame.draw.rect(screen,(150,150,150),[750,500,15,40])

def GameOver():
    pygame.draw.polygon(screen,(250,0,0),[[755,500],[730,485],[755,440],[780,485]],0)
    pygame.draw.polygon(screen,(200,200,200),[[735,490],[750,490],[758,450],[755,430],[747,410],[743,410],[715,430],[723,450]],0)
    Alive = False
    lost = True
#################----CLAS----##############
                

class EnemyMissile:
    def __init__(self,Apogee,LaunchFrame,velX):
        self.Apogee = float(Apogee)
        self.X = int(175)
        self.Y = int(500)
        self.A = float((self.Y-self.Apogee)/((self.X - 530)**2))
        self.LaunchFrame = int(LaunchFrame)
        self.velX = float(velX * 2.5)
    def update(self,frame):
        self.X += self.velX
        self.Y = float((self.A*(self.X-410)*(self.X-410))+self.Apogee)
        pygame.draw.circle(screen,(210,170,170),[int(self.X),int(self.Y)],10)
    def CheckHit(self,frame):
        if(self.X > 750):
            print("Lost")
            return True

class FriendMissile:
    def __init__(self,X,Y):
        #print("New rocket has ",X,Y)
        self.length = math.sqrt(((X-750)*(X-750))*((Y-500)*(Y-500)))
        self.state = bool(True)
        #self.angle = float(((500-Y)/(750-X)))
        #print(self.angle)
        self.velX = float((X-750)/(self.length*-0.001))
        self.velY = float((Y-500)/(self.length*-0.001))
        self.posX = float(750)
        self.posY = float(500)
        self.collideX = int(0)
        self.collideY = int(0)
        self.collideT = int(0)
    def update(self):
        self.posX -= self.velX
        self.posY -= self.velY
        if self.state:
            pygame.draw.circle(screen,(210,210,100),[int(self.posX),int(self.posY)],7)
        else:
            pygame.draw.line(screen,(250,20,20),[int(self.posX),int(self.posY)],[int(self.collideX),int(self.collideY)],3)
            pygame.draw.circle(screen,(250,10,10),[int(self.posX),int(self.posY)],(frame - self.collideT))
    def CheckHit(self,OX,OY):
        dist = math.sqrt(((self.posX-OX)**2) + (self.posY-OY)**2)
        if dist < 20:
            self.state = False
            self.collideX = self.posX
            self.collideY = self.posY
            self.collideT = frame
            return True
        return False
    def CheckBorders(self):
        if(self.posY < 0 or self.posX < 0):
            return True
#################----MAIN----##############

GenStars()
DrawAtmo()
DrawEarth()
DrawCitys()
DrawStars()
while Alive:
    if not begun:
        font = pygame.font.SysFont("Arial", 20)
        text = font.render("Push the red button to declare war",1,(240,0,0))
        screen.blit(text,(275,50))
        font = pygame.font.SysFont("Arial", 18)
        text = font.render("Be prepared for the enemy to defend himself",1,(240,0,0))
        screen.blit(text,(275,150))
        pygame.draw.circle(screen,(240,0,0),[450,275],50)
        font = pygame.font.SysFont("Arial", 20)
        text = font.render("LAUNCH!",1,(240,240,0))
        screen.blit(text,(405,265))
        pygame.display.flip()
        for event in pygame.event.get():
            if event.type == MOUSEBUTTONDOWN:
                begun = bool(True)
    elif (not lost) and (not Ranout):
        screen.fill((0,0,0))
        DrawAtmo()
        DrawEarth()
        DrawCitys()
        DrawStars()
        clock.tick(60)                          #60FPS
        frame += 1
        for event in pygame.event.get():        # Event handling      
            if event.type == QUIT:              # If you press the close button
                Alive = False
            elif event.type == MOUSEBUTTONDOWN: # If you left click
                X,Y = pygame.mouse.get_pos()
                print(X,Y)
                if(X < 750 and Y < 500 and charged ):        # To avoid friendly-fire or divide/0
                    FriendlyMissiles.append(FriendMissile(X,Y))
                    #FriendlyMissiles.append(FriendMissile(X,Y))
                    pygame.draw.line(screen,(240,40,40),[750,500],[X,Y])
                    print(len(FriendlyMissiles))
                    LastFired = frame
                    charged = False
                    #if(len(FriendlyMissiles) > 0):
                     #   FriendlyMissiles.pop(len(FriendlyMissiles)-1)
                    print(len(FriendlyMissiles))

        if(wave == 1 and Alive):                
            font = pygame.font.SysFont("Arial", 20)
            text = font.render("OMG WE'RE GOING TO DIE LEFT CLICK TO FIRE COUNTER-MISSILE",1,(240,0,0))
            screen.blit(text,(50,50))


        if Airborne == 0:
            wave += 1
            ToLaunch = wave
            KilledThisWave = int(0)
            Airborne = wave

        if wave == 6:
            Ranout = True
        else:
            while(ToLaunch > 0):
                EnemyMissiles.append(EnemyMissile(random.randint(50,425),frame,random.random()))
                ToLaunch -= 1
        for missile in range(0,int(len(FriendlyMissiles))):
            FriendlyMissiles[missile-1].update()
            if FriendlyMissiles[missile-1].CheckBorders():
                FriendlyMissiles.pop(missile-1)
            
            
        for Emissile in range(0,int(len(EnemyMissiles))):
            try:
                lost = EnemyMissiles[Emissile].CheckHit(frame)
                EnemyMissiles[Emissile].update(frame)
                if EnemyMissiles[Emissile].CheckHit(frame):
                    GameOver()
                if not Alive or lost:
                    break
            #if len(FriendlyMissiles) > 0 and len(FriendlyMissiles) > 0:
                for missile in range(0,int(len(FriendlyMissiles))):
                     if FriendlyMissiles[missile].CheckHit(EnemyMissiles[Emissile].X,EnemyMissiles[Emissile].Y):
                         EnemyMissiles.pop(Emissile)
                         Airborne -= 1
                         #FriendlyMissiles.pop(missile)
            except LookupError:
                break

        if(frame-LastFired > (150 - (20 * wave))):
            charged = True

        pygame.draw.circle(screen,(150,150,150),[800,100],30)
        if charged:
            pygame.draw.circle(screen,(230,230,20),[800,100],28)
            pygame.draw.circle(screen,(20,20,20),[800,100],18)
            pygame.draw.circle(screen,(230,230,20),[800,100],16)
            pygame.draw.circle(screen,(20,20,20),[800,100],5)



        pygame.display.flip()

    elif Ranout:
        pygame.draw.rect(screen,(0,0,0),[0,0,900,550])
        font = pygame.font.SysFont("Arial", 20)
        text = font.render("The enemy ran out of Nukes to throw at you, so you go on the offensive and win",1,(240,0,0))
        screen.blit(text,(75,50))
        font = pygame.font.SysFont("Arial", 18)
        text = font.render("Game made for SHS space game jam, in Honour of Nuclear space treaty",1,(240,0,0))
        screen.blit(text,(150,200))


        pygame.display.flip()
        for event in pygame.event.get():        # Event handling      
            if event.type == QUIT:              # If you press the close button
                Alive = False
        
    
    else:
        pygame.draw.rect(screen,(0,0,0),[0,0,900,550])
        font = pygame.font.SysFont("Arial", 26)
        text = font.render("It's a shame war doesn't give second chances",1,(240,0,0))
        screen.blit(text,(175,50))
        font = pygame.font.SysFont("Arial", 18)
        text = font.render("Game made for SHS space game jam, in Honour of Nuclear space treaty",1,(240,0,0))
        screen.blit(text,(250,200))
        pygame.draw.rect(screen,(150,150,150),[750,500,15,40])
        pygame.draw.polygon(screen,(250,0,0),[[755,500],[730,485],[755,440],[780,485]],0)
        pygame.draw.polygon(screen,(200,200,200),[[735,490],[750,490],[758,450],[755,430],[747,410],[743,410],[715,430],[723,450]],0)
        pygame.display.flip()
        for event in pygame.event.get():        # Event handling      
            if event.type == QUIT:              # If you press the close button
                Alive = False

pygame.quit()

