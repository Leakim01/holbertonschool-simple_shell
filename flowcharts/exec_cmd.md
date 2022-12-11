```mermaid
flowchart TD

 style exec_cmd.c fill:#F9F9F9, stroke: #E8E8E8,stroke-width:2px 
 style Libraries fill: #B8DAC6,stroke:#3A7050,stroke-width:2px
 style id fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
 style start fill: #FD8882,stroke: #FF6600,stroke-width:2px
 style exit2 fill:#FFB15B, stroke-width:2px, stroke:#E67800

 style input fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style input2 fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style pid fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style pid2 fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style execve fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style else fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style free fill:#F3D6E2, stroke-width:2px, stroke:#DA81A7
 style free2 fill:#F3D6E2, stroke-width:2px, stroke:#DA81A7
 style free3 fill:#F3D6E2, stroke-width:2px, stroke:#DA81A7
 style free4 fill:#F3D6E2, stroke-width:2px, stroke:#DA81A7
 style dswitch fill:#CDDCB6,stroke:#93B362,stroke-width:2px,stroke-dasharray: 3 3
 style switch fill: #CDDCB6,stroke:#93B362,stroke-width:2px
 style case1 fill: #CDDCB6,stroke:#93B362,stroke-width:2px
 style case+1 fill: #CDDCB6,stroke:#93B362,stroke-width:2px
 style case0 fill: #CDDCB6,stroke:#93B362,stroke-width:2px
 style Break fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style Break2 fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style Break3 fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style return4 fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style return fill:#FFB15B, stroke-width:2px, stroke:#E67800

 subgraph exec_cmd.c
       Libraries["#include main.h"]   
       id(["int exec_cmd(char *av[], char *ev[])"])-.-start(Start)
       start--> input[/"char *path = /bin/;\nchar tmp[1024];\npid_t pid;\nint error = 0;\nint have_path = !strstr(av[0], ./)\n&& !strstr(av[0], /bin/);"/]
       input-->!av{{"!av[0]"}}-->|false|return("return -3")
       !av-->|true|have_path{{"have_path"}}-->|true|input2[/"strcpy(tmp, path);\nstrcat(tmp, av[0]);\nav[0] = strdup(tmp);"/]
       !av-->|true|pid[/"pid = fork();"/]-->switch{"pid"}-->case1{{"case -1"}}-->pid2[/"pid = wait(NULL);"/]-->have_path1{{"have_path"}}-->|true|free(["free(av[0])"])
       have_path1-->Break("BREAK")
       switch-->case0{{"case 0"}}-->execve[/"execve(av[0], av, ev);"/]-->have_path2{{"have_path"}}-->|true|free2(["free(av[0])"])
       have_path2-->exit2["exit(2)"]-->Break2("BREAK")
       switch-->case+1{{"case 1"}}-->have_path3{{"have_path"}}-->|true|free3(["free(av[0])"])
       have_path3-->Break3("BREAK")
       switch-->else[/"pid = wait(&error);"/]-->have_path4{{"have_path"}}-->|true|free4(["free(av[0])"])
       have_path4-->return4("return error")
       dswitch("switch")-.->switch
        
 end
        
