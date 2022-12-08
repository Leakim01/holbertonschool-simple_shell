```mermaid
flowchart TD
      subgraph main.h
        Start("START")
        Start --> Define[/"#ifndef MAIN_H\n#define MAIN_H"/]
        DLibraries["Libraries"] -.->Libraries
        Define --> Libraries["#include ctype.h\n#include fcntl.h\n#include stdio.h\n#include stdlib.h\n#include string.h\n#include sys/file.h\n#include sys/types.h\n#include sys/wait.h\n#include sys/stat.h\n#include unistd.h"]
        
        Dmainc["Prototypes main.c"] -.->main.c
        Libraries --> main.c["char *ev[]);\nvoid handle_signal(int signal);\nint main(int ac, char *av[]"]
        
        Dexec_cmd["Prototypes exec_cmd.c"] -.->exec_cmd
        main.c --> exec_cmd["int exec_cmd(char *av[], char *ev[]);\n"]
        
        
        Dget_cmd["Prototypes get_cmd.c"] -.->get_cmd
        exec_cmd --> get_cmd["int get_cmd(char *str, size_t size, char *ev[]);"]
        
        
        get_cmd--> endbox("END")

      end
