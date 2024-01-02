# Dodgeball

Testing/Learning how to use UE5 with C++ classes
A player has to dodge around the enemies' projectiles attempting to finish the maze

## DodgeballCharacter
This class is a child of built in Character class player gets to control this class

**ADodgeballCharacter()**: A function that initializes movement, collision capsule, springarm, camera to make it top down view

**SetupPlayerInputComponent(PlayerInputComponent)**: A function that takes in inputs of player

**OnDeath_Implementation()**: Once a player dies, this function calls a restart UI

**OnTakeDamage_Implementation()**: Once a player takes damage, this function updates the HUD for player HP

**Move()**: A function that allows players to move with given input

##DodgeballFunctionLibrary
This serves as a function library so both Player and Enemy can use if they wish to
**bool CanSeeActor(UWorld World, FVector Location, AActor TargetActor, TArray<AActor>  IgnoreActors)**:
  World: current world that actor is in
  Location: Start of the projectile
  TargetActor: A target character/object
  IgnoreActors: Actors that should be ignored that comes between start to end point
  The function returns true if Owner of the function is able to see a target
  
##DodgeballGameMode
Child class of a build in GameMode class

##DodgeballProjectile
A projecile that can do damage

**ADodgeballProjectile()**: initializes the sphere collider, and speed of the projectile

**OnHit(UPrimitiveComopnent HitComponent, AActor OtherActor, UPrimitiveComponent OtherComp, FVector NormalImpulse, FHitResult Hit)**: This function allows onhit detection for projectile, and once it hits the player, player loses hp and plays sound with particles

**BeginPlay()**: sets the lifespan of the projectile to be 5s

##EnemyCharacter
This codes is a child class of built in Character class that controls the Enemy, and Enemy looks for the target, rotates the orientation, then shoots the projectile

**AEnemyCharacter()**: Initializes the eyes (where the projectile shoots from)

**BeginPlay()**: Initializes the target (player)

**ThrowDodgeball()**: Throws the dodgeball from eyes to last seen target's location

**Tick()**: Every frame, track the player to where it is, and update if enemy can see the target

##HealthComponent
This tracks the HP of the player and functions around it such as losing health

**LoseHealth(float Amount)**:
  Amount: amount that loses health
  the function makes whoever calls the function lose health

##HealthInterface
This is an Interface, meaning that other script is able to use this. 
It has all the Health point related Interface such as OnDeath(), OnTakeDamage() the implementation of these are in 'DodgeballCharacter'

##HUDWidget
This updates the HP bar of the character

**UpdateHealthPercent(float HealthPercent)**: updates the UI of health bar

##LookAtActorComponent
This class is a component which 'EnemyCharacter' has, it acts as an eye

**LookAtActor()**: this function calls the 'CanSeeActor' from the eye of the enemy

##MusicManager
Manages background music of the game

##RestartWidget
This class is an UI once player dies, it allows player to restart or exit out of the game

**NativeOnInitialized()**: it initializes clickable buttons 

**OnRestartClicked()**: once player clicks on restart, the game restarts

**OnExitClicked()**: once player clicks on quit, the game exits

##VictoryBox
This class acts as a goal that player must reach to

**AVictoryBox()**: initalizes goal point, and the collision box

**OnBeginOverlap(UPrimitiveComponent OverlappedComp, AActor OtherActor, UPrimitiveComponent OtherComp, int32 OhterBodyIndex, bool bFromSweep, const FHitResult& SweepResult)**:
  On overlap of a player, the game ends

##Wall
Class that is a child of an built in Actor class, all its purpose is just a wall
