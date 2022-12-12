```mermaid
flowchart TD

 style inner_cmd.c fill:#F9F9F9, stroke: #E8E8E8,stroke-width:2px 
 style Libraries fill: #B8DAC6,stroke:#3A7050,stroke-width:2px
 style id fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
 style start fill: #FD8882,stroke: #FF6600,stroke-width:2px
 style exit fill: #FD8882,stroke: #FF6600,stroke-width:2px
 style input fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style for fill: #CDDCB6,stroke:#93B362,stroke-width:2px
 style loop fill:#CDDCB6,stroke:#93B362,stroke-width:2px,stroke-dasharray: 3 3
 style printf fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style printf2 fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style return0 fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style return1 fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style return2 fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style return3 fill:#FFB15B, stroke-width:2px, stroke:#E67800
 
  subgraph inner_cmd.c
          Libraries["#include main.h"]    
          id(["int inner_cmd(const char *cmd, char *ev[])"])-.-start(Start)
          start-->input[/"int j = 0;"/]-->cmd{{"cmd == NULL"}}-->|true|return3("return -3")
          cmd-->|false|strcmp{{"strcmp(cmd, exit) == 0"}}-->|true|return1("return (-1)")
          strcmp-->|false|strcmp2{{"strcmp(cmd, help) == 0"}}-->|true|printf
          strcmp2-->|false|strcmp3{{"strcmp(cmd, env) == 0"}}-->|true|for{"for (j = 0; ev[j] != NULL; j++)"}-->printf2["printf(%s, ev[j]);"]-->return2("return -2")
          loop(["Loop"])-.->for
          strcmp3-->|false| return0("return 0")-->exit("Exit")
  
  end
