# Ultimate Spider-Man Debug menu for PC 

**Recreation** of the PS2 version's debug menu for the PC version

## Download

Get the Custom menu from [here](https://github.com/UNK9090/USMDebugMenuPC/releases)
Get the menu original from [here](https://github.com/krystalgamer/usm-debug-menu/releases)

## Requirements

* ultimate spider-man pc widescreen


## Installation


* First download ultimate spider-man pc widescreen [here](https://github.com/ThirteenAG/WidescreenFixesPack/releases/tag/usm)
* Then extract UltimateSpiderMan.WidescreenFix.zip on desktop
* Copy script folder and dsound.dll on game folder
* Rename `debug_menu.dll` in the game's folder to `debug_menu.asi`
* Copy the `debug_menu.asi` in the zip file to the game's folder

## Usage

Keyboard
* **X** - opens and closes the menu
* **UP/DOWN Arrows** - moves the current select option up and down
* **ENTER** - executes the selected option
* **LEFT/RIGHT Arrows** - changes the value of the current **boolean** option
* **ESCAPE** - go to previous menu

Dualshock 4
* **PS Button** - opens and closes the menu
* **UP/DOWN Pads** - moves the current select option up and down
* **Square Button** - changes the value of the current **boolean** option
* **LEFT/RIGHT Pads** - changes the value of the current **boolean** option
* **Cross Button** - executes the selected option
* **Circle Button** - go to previous menu

## Current implemented options

### Warp

Allows to teleport to any in-game region

**NOTE**: Points of Interest(POI) are only used in missions and the option only works when the direction arrow is visible 

### District variants

Allows to switch variants of given regions

### Character Viewer

Allows to switch and view all available characters on menu unlockables

### Hero

Allows to switch between all available heroes

**NOTE**: `peter_parker` and `peter_hooded` are versions of peter without powers, used in the first missions of the game

### Game

Allows to modify in-game flags that controls certain behaviours
* God Mode: enable hero invulnerable
* One Hit Kill: Kill all enemies
* Bomb Mode: Destroy all cars and kill all enemies
* Monkey Time: Enable Watermark timer only on game
* Show Fps: Show all game infos and fps
* Show Memory Info: Show Memory bar on game

### Savegame Opt
* Unlock All Unlockables: unlock all menu unlockables
* Unlock Characters: unlock Characters menu
* Unlock Landmarks:  unlock Landmarks menu
* Unlock Concept Art:  unlock Concept Art menu


### Dev Opt Flags

Allows to modify flags options that controls certain behaviours
* Live in Glass House: disables the `Area unavailable` messages
* Gravity: disable gravity on city
* Env Map Tool: is dev tool that change the game map

### Dev Opt Int

Allows to modify int options that controls certain behaviours

Note: this int options not working on game

### NGL Debug

This is NGL Debug menu contains:

Show Perf Info: if set to 1 show game info and if set to 0 back to normal
Screenshot: capture instanely a screenshot of the game or debug menu 

### Misc Menu

This is Cheat Misc menu contains:

Play City Ambient Music
Disable Pause Menu
Enable Red Watermark
TestFlag
Weird Flag
Disable Environment
Unload District
Invulnerable Hero
Invulnerable Enemies


### Script

Access to in-game scripts that allow the player to tap into debug features

### Progression

Set your progress to any point before to start the mission in the game

### Missions

This is a work in progress menu need add stuffs

## Extending functionality

If you desire to add any new option(s) to the menu, it's very simple.
`create_menu` is used to create a new menu.
`add_debug_menu_entry` is used to add entries to a menu.


## License

This project is MIT licensed
