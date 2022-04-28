Ultimate Spider-Man Debug menu for PC Recreation of the PS2 version's debug menu for the PC version

Download Get the menu from here

Installation Rename binkw32.dll in the game's folder to binkw32_.dll Copy the binkw32.dll in the zip file to the game's folder Usage Keyboard X - opens and closes the menu UP/DOWN Arrows - moves the current select option up and down ENTER - executes the selected option LEFT/RIGHT Arrows - changes the value of the current boolean option ESCAPE - go to previous menu Current implemented options Warp Allows to teleport to any in-game region

NOTE: Points of Interest(POI) are only used in missions and the option only works when the direction arrow is visible

District variants Allows to switch between variants of given regions

Level Select contains Hero Select and two options that not works

Hero Select Allows to switch with true of false between all available characters

NOTE: peter_parker and peter_hooded are versions of peter without powers, used in the first missions of the game

Game An folder that contains 4 sub folders DevOpt Flags, DevOpt Int, Game Flags and Saved Game Settings

Game Flags Allows to modify others in-game flags that controls certain behaviours contains 3 types of God Mode. God Mode if set 1 = invicible One Hit Kill if set 1 = kill all enemies Bomb Mode if set 1 = mega damage and destroy all cars

Character Viewer you can launch and view only a lot of characters bossess on city. 

DevOpt Ints unfortunately there are 76 options that not works.

Missions contains 7 sub folders called JF JG KF KG KH LH LG.

DevOpt Flags Allows to modify in-game flags that controls certain behaviours Live in Glass House: disables the Area unavailable messages

Script Access to in-game scripts that allow the player to tap into debug features.

Progression Set your progress to any point in the game.

Extending functionality If you desire to add any new option(s) to the menu, it's very simple. create_menu is used to create a new menu. add_debug_menu_entry is used to add entries to a menu.

License This project is MIT licensed
