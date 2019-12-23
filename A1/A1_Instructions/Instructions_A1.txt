Instructions for submitting programming assignment A1

All the programming assignments will be based on C.
This is an assignment from IITM HPC Course, I have modified the instructions to match our environment, no credit for me!!
Get yourself an account on the HPC Cluster from Noor sir( dont go to the next instruction without completing this!)
Send me your gitlab account user names(again no going forward without this)
Once you get an invitation from me for gitlab(check your mail), go throug a basic git tutorial to do repo management.
You are to clone the repo i have given you access to, commit and push your submissions ONLY via that repo! ( you have to do this in the cluster only!)
Download the assignment. Copy it to your login on 172.16.1.98 (use scp or winscp). Use unzip command to extract the assignment in your /home/<user-name>/work/<repo-directory>/.
cd /home/<user-name>/work/<repo-directory>/; unzip A1.zip
For the first programming assignment A1, you are supposed to optimize the codes using loop transformations(NO PARALLELISM YET! CRAZY!).There are three parts to the assignment. For each part, you will be given two files, one containing the main function (named p#_main.c e.g., p1_main.c) and one containing the function you are required to modify (named p#.c e.g., p1.c). There would be three such files, with # ranging from 1 to 3.
You will be able to compile the  program using the command
    gcc -O3 p#_main.c p#.c
        e.g., gcc -O3 p2_main.c p2.c
The flag -O3 applies inbuilt optimizations to your program.
Specific to p3: The programming assignment 3 uses math library. So you are required to use -lm flag while compiling.
gcc -O3 p3_main.c p3.c -lm  
You are supposed to maintain all files in home folder in the hierarchy provided in the template (e.g., after you have installed the template, if you execute ls command after you login, you should see A1 directory in your home folder; similarly A2, A3, A4 for the future assignments). ls ~/A1 must list your submission files.
You are expected to create a short report on your trials and findings to optimize the code.
Your p#.c and report.txt alone will be extracted from A1 folder after the deadline for evaluation (that is, p1.c, p2.c, p3.c and report.txt only).
Any changes made to p#_main.c will have no positive effect on the execution and so you are advised not to trifle with the main file on the function names.
You can use one of emacs, vim or nano as your preferred editor while using IIITDM machine(Don't worry  I have installed VSCode for you in that machine type code in the command line to use it! In Place of gedit!)
THIS IS A WEEK LONG ASSIGNMENT so take it slow do proper analysis and report.(BTW you are to write the report in LATEX only, you have to push this into the repo too!)


Incase you are ‘un familiar’ with linux!!
         
Linux Shell Commands:
mkdir dirname Make a directory dirname

rmdir dirname Remove the directory dirname

cd dirname Change the current working directory to dirname

cd ..      Change the current working directory to the parent directory

cd ~     Change the current working directory to your home directory

pwd Show your current working directory

mv srcfile destfile Rename the srcfile as destfile

cp srcfile destfile Copy one file, srcfile to destfile

cp srcfile(s) destDir Copy many file, srcfile(s) to destDir

rm -i file(s)     Delete file(s)

ls -l List files in the directory with their details (size, time of creation)

gcc –o prog prog.c Compile the C program in the file prog.c and create the executable
file prog (which could be other than the default a.out)

gcc –g –o prog prog.c Compile the C program in the file prog.c and create the
executable file prog that can be used for debugging with gdb

./prog Run the program prog in the current directory.

Special characters in file and directory names:
* - wildcard matches any string; 
? - matches any single character; 
~ - your home directory

