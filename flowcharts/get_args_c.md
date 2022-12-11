```mermaid
flowchart TD

 style Libraries fill: #B8DAC6,stroke:#3A7050,stroke-width:2px
 style id fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
 style !otherchart fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 5 5
 style !token fill: #CDDCB6,stroke:#93B362,stroke-width:2px
 style while_com fill:#CDDCB6,stroke:#93B362,stroke-width:2px,stroke-dasharray: 3 3
 style input fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style false fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style strcmp1 fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style input fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style inner fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style exec fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style args fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style stroke fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style Exit fill: #FD8882,stroke: #FF6600,stroke-width:2px
 style start fill: #FD8882,stroke: #FF6600,stroke-width:2px
 style exit fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style return fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style return2 fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style continue fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style inner_cmd fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
 style get_args.c fill:#F9F9F9, stroke: #E8E8E8,stroke-width:2px 
 style free fill:#F3D6E2, stroke-width:2px, stroke:#DA81A7
 style 2exit fill:#F3D6E2, stroke-width:2px, stroke:#DA81A7

      subgraph get_args.c
      Libraries["#include main.h"]
      id(["int get_cmd(char *str, size_t size, char *ev[]"])-.-start(Start)
      
      start --> input[/"char **args;\nchar *token;\nint i = 0,error;\n"/]
      input --> args["args = malloc(size * sizeof(char *));"]
      args -->!args{!args}
      !args-->|true|exit("return -2")
      !args-->|false|stroke["token = strtok(str \t\r)"]
      stroke -->!token{token != NULL}

      while_com(["WHILE"]) -.->!token
      2exit["strcmp(args 0, exit)"]-->!token
      !token-->|true|strlen{{"strlen(token) == 0"}}-->|true|continue("continue")--> strcmp1[/"args[i] = NULL"/]-->inner(["error = inner_cmd(args[0], ev)"])-->| true|strcmp2{{"error != 0"}}-->| true|strcmp3{{"error > -3"}}
inner-.->inner_cmd[["check inner_cmd.c flowchart"]]
      strlen-->|false|false[/"args[i++] = token;\ntoken = strtok(NULL,  \n\t\r)"/]-->strcmp1
      strcmp3-->|true| free(free)
      
      strcmp2-->|false|exec(["error = exec_cmd(args, ev)"])-->2exit[/"free(args);\nfree(token);"/]
      exec<-.-!otherchart[["check  exec_cmd.c flowcharts"]]
      strcmp3-->|false|return2("return error")-->2exit
      end
