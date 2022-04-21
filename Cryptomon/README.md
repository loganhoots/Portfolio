# Cryptomon Project
CST-461 project to create a substantial project with the skills and knowledge learned from the class. 

Cryptomon is a NFT battler videogame. In this game, the user is able to connect their blockchain connected NFT to use moves to attack other user's NFTs.

Cryptomon is a game developed for the Grand Canyon University course Current Trends in Computer Science Lecture and Lab in collaboration by four developers: Logan Hoots and Collin Stratton. Throughout this course we learned to utilize blockchain technologies in order to create a videogame that directly interfaces with an Ethereum based blockchain.

To access the scripts for Cryptomon, please visit the link:\
 https://github.com/loganhoots/Portfolio/tree/master/Cryptomon/contracts \
 https://github.com/loganhoots/Portfolio/tree/master/Cryptomon/test \
 https://github.com/loganhoots/Portfolio/tree/master/Cryptomon/Cryptomon/Assets/Scripts \
To access screenshots for Cryptomon, please visit the link:\
 https://github.com/loganhoots/Portfolio/tree/master/Cryptomon/Screenshots 

Because these files were made for Grand Canyon University, these files can only be used by possible future employers of Logan Hoots. These files are subject to copyright and the ownership belongs to Logan Hoots and Collin Stratton. We do not give permission for anyone to use these files for personal use or academic use.

If you would like to check out my projects, you can check out my website linked here:\
 www.loganhoots.com

Any you have any questions please feel free to reach out over LinkedIn:\
  https://www.linkedin.com/in/logan-hoots-3ab838223/

# How To Run
- Launch Ganache
- Update all Cryptomon Ownership in order to be deployed
- Deploy Cryptomon contract
- Launch Cryptomon Battle Hub
- Input addresses associated with NFTs you wish to battle

# How To Battle
- Turn order is determined by the speed of the two Cryptomon that are battling. The faster a Cryptomon the sooner it will get a turn
- On a Cryptomon’s turn, you are able to choose between the two available moves associated with said NFT. These are unique to each NFT. 
- Each move will have a damage number and a miss rate out of 100. When a move is selected, the move's miss rate is compared against a random number to - determine if the move hits the opponent. If the move hits the opponent, the opponent’s hp is lowered by an equal number to the move’s damage.
- When a Cryptomon’s HP is lowered to 0. The game ends and the Cryptomon existing with HP above 0 wins the battle.