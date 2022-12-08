<br>
<p align="center">
  <img src="https://zupimages.net/up/22/49/4ouj.png" />
</p>
<br>

# C - SIMPLE SHELL PROJECT

## :pencil: SIMPLE SHELL DESCRIPTION :
The Simple Shell mirroring the real Shell in a simple version of himself.
The Shell is a program that takes commands from the keyboard and gives them to the operating system to perform.

## :pencil: PROTOTYPE :
`int main(int ac, char *av[], char *ev[]);`
`int exec_cmd (char *av[], char *ev[]);`

## :pencil: COMPILATION :
You need to type `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o NameOfTheScriptFile` to compile your code to an executable file.

## :pencil: EXECUTION :
You need to type `./NameOfTheScriptFIle` to execute your file.

## :pencil: MAN PAGE:
You need to type `man ./man_1_simple_shell` command to know how to use our Simple Shell

## :pencil: COMMAND LINE - CL :

| CL           | Descriptions                                                                |
| ------------------------- | ------------------------------------------------------------------ |
| `CTRL+D`  | Keyboard shortcut to exit the Simple Shell.
| `exit` | Type `exit` command to exit the Simple Shell
| `man` | Type `man` command in this Simple Shell to have the entire description of how to use it.
| `help` | Type `help` to know how to know 0:) Or type your request on Google.
| `ls` | This command display the names of the files in the current path. You can use the OPTION `-l` to display the list of all the informations about this files.
| `env` | Displays the current environment before leaving

## :pencil: FILES & DIRECTORIES DESCRIPTIONS :

| Files Names             | Descriptions                                                                |
| ----------------- | ------------------------------------------------------------------ |
| AUTHORS | Contains the list of the Simple Shell's creators and their e-mail |
| README.md | Contains all the informations of the Simple Shell project |
| main.h | Contains the libraries and the prototypes of our functions to work the Simple Shell |
| main.c | Main Function |
| exec_cmd.c | Contains the function that execute the cmd |
| get_cmd.c | Contains the function entry point |
| hsh | Contains the script of the Simple Shell |
| check_simple_shell.bash | Contains scripts of some crashtests for the checker |

| Directories Names             | Descriptions
| ----------------- | ------------------------------------------------------------------ |
| Flowcharts | Contains the diagram explaining the order of operation of our Simple Shell  |
| ToStartCodingOwnShell | Contains all the exercices files to understand how to create the Simple Shell

## :keyboard: EXAMPLE OF USING A COMMAND :

If you use the `ls` command with `-l` option :
```
$ ls -l
total 40
-rw-r--r-- 1 root root  136 Dec  7 05:27 AUTHORS
-rwxr-xr-x 1 root root 1489 Dec  7 05:27 check_simple_shell.bash
-rw-r--r-- 1 root root  672 Dec  8 00:57 exec_cmd.c
drwxr-xr-x 2 root root 4096 Dec  7 05:27 flowcharts
-rw-r--r-- 1 root root  566 Dec  8 00:57 get_cmd.c
-rw-r--r-- 1 root root 1445 Dec  8 00:57 main.c
-rw-r--r-- 1 root root  387 Dec  8 00:57 main.h
-rwxr-xr-x 1 root root 2410 Dec  8 00:57 man_1_simple_shell
-rw-r--r-- 1 root root 3440 Dec  8 00:59 README.md
drwxr-xr-x 2 root root 4096 Dec  7 05:27 tostartcodingownshell
```

## :spiral_calendar: ORGANISATION TOOLS :

| Tools             | Tools Links                                                                |
| ----------------- | ------------------------------------------------------------------ |
| Trello | <a href="https://trello.com/b/9Knotcwi/shell"><img src="https://www.zupimages.net/up/22/49/0l1k.jpg"></a> |
| Flowchart | <a href="https://trello.com/b/9Knotcwi/shell"><img src=https://www.zupimages.net/up/22/49/59rh.jpg></a> |

### :writing_hand: AUTHORS :

| Authors Names             | Linkedin Links                                                                |
| ----------------- | ------------------------------------------------------------------ |
| 🤷‍♀️ Vanessa TESSIER | [![linkedin](https://img.shields.io/badge/linkedin-white?style=for-the-badge&logo=linkedin&logoColor=black)](https://www.linkedin.com/in/vanessa-tessier-601794252/) |
| 👦 Redginald GODEAU | [![linkedin](https://img.shields.io/badge/linkedin-white?style=for-the-badge&logo=linkedin&logoColor=black)](https://www.linkedin.com/in/redginald-godeau-04ab8a254/) |
| 👨 Mickaël MANGIN | [![linkedin](https://img.shields.io/badge/linkedin-white?style=for-the-badge&logo=linkedin&logoColor=black)](https://www.linkedin.com/in/micka%C3%ABl-mangin-331aa2170/) |

### :mortar_board: SCHOOL :

Holberton School - TOULOUSE
C19 Cohort
Dec. 2022
