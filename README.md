# Dodgeball

Testing/Learning how to use UE5 with C++ classes
A player has to dodge around the enemies' projectiles attempting to finish the maze

## Image of Gameplay
### A map in the editor
![image](https://github.com/hyeonukim/Dodgeball/assets/48634064/0178ddfd-cfe1-4c4a-bf53-62277a893f1d)

### In game screen
![image](https://github.com/hyeonukim/Dodgeball/assets/48634064/6f6de80d-b204-48df-a79c-c55ead0da988)

### UI when player dies
![image](https://github.com/hyeonukim/Dodgeball/assets/48634064/48a74b77-6069-465c-94d2-3aae8da051af)



## Table of Contents

- [ADodgeballCharacter](#ADodgeballCharacter)
- [UDodgeballFunctionLibrary](#UDodgeballFunctionLibrary)
- [ADodgeballGameMode](#ADodgeballGameMode)
- [ADodgeballPlayerController](#ADodgeballPlayerController)
- [ADodgeballProjectile](#ADodgeballProjectile)
- [AEnemyCharacter](#AEnemyCharacter)
- [UHUDWidget](#UHUDWidget)
- [UHealthComponent](#UHealthComponent)
- [UHealthInterface](#UHealthInterface)
- [ULookAtActorComponent](#ULookAtActorComponent)
- [AMusicManager](#AMusicManager)
- [AVictoryBox](#AVictoryBox)
- [AWall](#AWall)

## ADodgeballCharacter
- **Description**: Represents the main character in the Dodgeball game, incorporating camera components, input handling, and health management.
- **Usage**: Controls the player's character movement, camera positioning, and interacts with the game environment.
- **Implementation**: Inherits from ACharacter and IHealthInterface, utilizes camera components, and includes methods for handling input, health events, and setup.

## UDodgeballFunctionLibrary
- **Description**: Provides a utility library function for checking if an actor is visible from a specific location in the game world.
- **Usage**: Used for determining line of sight between actors in the game, such as checking if an enemy character can see the player character.
- **Implementation**: Static function within the UDodgeballFunctionLibrary class, taking the world, location, target actor, and optional array of ignore actors as parameters.

## ADodgeballGameMode
- **Description**: Manages the game environment setup and various aspects of the game mode.
- **Usage**: Configures initial game state, sets up necessary components, and handles game-specific logic.
- **Implementation**: Inherits from AGameModeBase and includes methods for initialization and game mode-specific functionality.

## ADodgeballPlayerController
- **Description**: Handles player input, manages HUD widgets, and controls the overall game flow.
- **Usage**: Listens for player input, updates the HUD, and communicates with other game components.
- **Implementation**: Inherits from APlayerController and includes methods for showing/hiding widgets, updating health, and responding to player input.

## ADodgeballProjectile
- **Description**: Defines the Dodgeball projectile, including movement, collision, and impact effects.
- **Usage**: Represents the throwable object in the game, handling collisions and interactions with other actors.
- **Implementation**: Inherits from AActor and includes components for sphere collision, projectile movement, and methods for handling hits and impact effects.

## AEnemyCharacter
- **Description**: Enemy character capable of throwing Dodgeball projectiles at the player.
- **Usage**: Represents an AI-controlled enemy with the ability to attack the player.
- **Implementation**: Inherits from ACharacter, includes a LookAtActorComponent for targeting, and handles throwing Dodgeball projectiles at intervals.

## UHUDWidget
- **Description**: User interface widget displaying the player's health using a progress bar.
- **Usage**: Provides a visual representation of the player's health on the screen.
- **Implementation**: Inherits from UUserWidget and includes a progress bar for health display and a method for updating the health percentage.

## UHealthComponent
- **Description**: Manages the health of an actor, allowing it to take damage and trigger events on death.
- **Usage**: Attached to actors that need health management, such as the main character or enemies.
- **Implementation**: Inherits from UActorComponent and includes methods for losing health, getting health percentage, and handling events on death.

## UHealthInterface
- **Description**: Interface defining methods for handling health-related events.
- **Usage**: Implemented by classes that can take damage and die, ensuring a consistent way to handle health events.
- **Implementation**: Consists of two BlueprintNativeEvent methods - OnDeath and OnTakeDamage - to be implemented by classes that implement the interface.

## ULookAtActorComponent
- **Description**: Scene component allowing an actor to focus on another actor and determine if it can see the target.
- **Usage**: Attached to actors that need to focus on specific targets or check line of sight.
- **Implementation**: Inherits from USceneComponent and includes methods for setting the target actor and determining if the target is visible.

## AMusicManager
- **Description**: Manages background music in the game.
- **Usage**: Provides a centralized system for controlling and playing background music tracks.
- **Implementation**: Inherits from AActor and includes an AudioComponent for playing music.

## URestartWidget
- **Description**: User interface widget providing options to restart the game or exit.
- **Usage**: Displayed on-screen to allow the player to restart the game or exit to the main menu.
- **Implementation**: Inherits from UUserWidget, includes buttons for restarting and exiting, and methods for handling button clicks.

## AVictoryBox
- **Description**: Actor representing a victory box that triggers an event when overlapped by another actor.
- **Usage**: Placed in the game environment to define victory conditions or events.
- **Implementation**: Inherits from AActor, includes components for collision detection, and handles overlap events.

## AWall
- **Description**: Actor representing a wall in the game environment.
- **Usage**: Used to create barriers or boundaries within the game space.
- **Implementation**: Inherits from AActor and includes a scene component for positioning and scaling.
