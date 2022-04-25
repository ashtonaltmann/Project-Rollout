# Project Rollout


Team Rollout
Ian Binstock, Jacob Halek, Ashton Altmann
Project Rollout


# - How to run Image conversion into txt.file
Files: rollout.cpp, Hard_Rock_Mine.txt, rgbIndex.txt, show_mem.h

... 1. cd into the directory
.....: cd ~/SD/proj
... 2. run the program rollout.cpp
.....: g++ -g -Wall rollout.cpp ../react.o -lcurl
.....: ./a.out
... 3. output will be printed into Hard_Rock_Mine.txt
.....: > File > Open File...
.....: > /home/users/binsto1/SD/proj/Hard_Rock_Mine.txt

note*: The ppm file being read is located on line 27. It is called "test2.ppm". If you want to try transforming other images, use "convert <png> test2.ppm" in the terminal before compiling and running.
note**: We didn't have great communication so some code was lost which had been used for looking into the png with a 24px*24px view crop

Ian Binstock - responsible for the code
Ashton Altmann - debugging assistance and responsible for documentation


# - How to run React page of our Project
Files: titleScreen.cpp, titleScreen.yaml, GGselection.yaml, mainScreen.yaml, characterSelection.yaml, placeholder.yaml, mainEndScreen.yaml, memory.txt, react.h
Images: 1*.png, BBbutton.png, Bbutton.png, Blank.png, Gamemodes.png, Gbutton.png, GGbanner.png, GGbutton.png, Hbutton.png, HZbanner.png, HZbutton.png, KObanner.png, KObutton.png, project-rollout.png, Sbutton.png, SPbutton.png

... 1. cd into the directory
.....: cd ~/SD/proj
... 2. open a second terminal and run the following code
.....: cd ~/SD/proj; ../bridge.py
... 3. open a web browser and enter the following into the search bar
.....: http://anansi.stolaf.edu/sd/local/?TO=rns202-16.cs.stolaf.edu:25143
... 4. go back to the first terminal and compile the program
.....: g++ -g -Wall titleScreen.cpp ../react.o -lcurl
... 5. go to the web browser and the program should now be running there. Take the following path to demo the program
.....: 1) Click gem grab button (first one on the left)
.....: 2) Click Hard Rock Mine (first one on the left)
.....: 3) Click on 8-bit (1st column, 4th row on the right side)

Ian Binstock - responsible for the code
Ashton Altmann - debugging assistance and responsible for documentation


# - Layout for our Brawler intro
Files: Brawler.cpp, Brawler.h, BrawlerClass.cpp, testBrawler.cpp

Jacob Halek / Ashton Altmann - responsible for the code


# Unnecessary files and images
note*: These either were used for the sake of testing or weren't developed enough to be incorporating into the working parts of our project.

Files: envTest1.ppm, GMselection.h, GMselection.cpp, testGMselection.cpp, Makefile, memory.txt, mapLibrary.txt, Hard_Rock_Mine.ppm, introFade.yaml, mapTest.cpp, small.ppm, test1.ppm, tile.ppm, veggie.cpp
Images: back.png, envTest1.png, Hard_Rock_Mine.png, test2.png, tile.png

