```mermaid
flowchart TD
      subgraph main.h
       style main.h fill:#F9F9F9, stroke: #E8E8E8,stroke-width:2px 
       style Start fill: #FD8882,stroke: #FF6600,stroke-width:2px
       style endbox fill: #FD8882,stroke: #FF6600,stroke-width:2px

      
       style DLibraries fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
       style Dmainc fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
       style Dexec_cmd fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
       style Dget_cmd fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
       style Libraries fill: #B8DAC6,stroke:#3A7050,stroke-width:2px
       style main.c fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
       style exec_cmd fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
       style get_cmd fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
       style Define fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
       style Definend fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px



        Start("START")
        Start --> Define[/"#ifndef MAIN_H\n#define MAIN_H"/]
        DLibraries(["Libraries"]) -.->Libraries
        Define --> Libraries("#include ctype.h\n#include fcntl.h\n#include stdio.h\n#include stdlib.h\n#include string.h\n#include sys/file.h\n#include sys/types.h\n#include sys/wait.h\n#include sys/stat.h\n#include unistd.h")
        
        Dmainc(["Prototypes main.c"]) -.->main.c
        Libraries --> main.c["char *ev[]);\nvoid handle_signal(int signal);\nint main(int ac, char *av[]"]
        
        Dexec_cmd(["Prototypes exec_cmd.c"]) -.->exec_cmd
        main.c --> exec_cmd["int exec_cmd(char *av[], char *ev[]);\n"]
        
        
        Dget_cmd(["Prototypes get_args.c"]) -.->get_cmd
        exec_cmd --> get_cmd["int get_cmd(char *str, size_t size, char *ev[]);"]
        get_cmd --> Definend[/"#endif"/]
        Definend--> endbox("END")

      end
