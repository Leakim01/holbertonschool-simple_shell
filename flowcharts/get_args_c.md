```mermaid
flowchart TD

 style id fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
 style !otherchart fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 5 5
 style !token fill: #CDDCB6,stroke:#93B362,stroke-width:2px
 style while_com fill:#CDDCB6,stroke:#93B362,stroke-width:2px,stroke-dasharray: 3 3
 style input fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style 2exit fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style args fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style stroke fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style Exit fill: #FD8882,stroke: #FF6600,stroke-width:2px
 style start fill: #FD8882,stroke: #FF6600,stroke-width:2px
 
  style 3exit fill:#FFB15B, stroke-width:2px, stroke:#E67800
  style exit fill:#FFB15B, stroke-width:2px, stroke:#E67800
  style return fill:#FFB15B, stroke-width:2px, stroke:#E67800


 
 






 


    
      subgraph get_args.c
      id(["int get_cmd(char *str, size_t size, char *ev[]"])-.-start(Start)
      
      start --> input[/"char **args;\nchar *token;\nint i = 0, j = 0, error;\n(void) ev;"/]
      input --> args["args = malloc(size * sizeof(char *));"]
      args -->!args{!args}
      !args-->|False|exit("return -2")
      !args-->|True|stroke["token = strtok(str \n\t\r)"]
      stroke -->!token{token != NULL}

      
      while_com(["WHILE"]) -.->!token
      
      2exit["strcmp(args 0, exit)"]-->!token
      
      strcmp1-->|false| 3exit(return -1)
      !token-->|true| strcmp1{{"strcmp(args 0, exit) == 0"}}-->| true|strcmp2{{"strcmp(args[0], help) == 0"}}-->| true|strcmp3{{"strcmp(args[0], env) == 0"}}
      !token-->|false|return("return 0")-->Exit("Exit")
      strcmp2-->|false| 2exit[/"error = exec_cmd(args, ev);\nfree(args);\nfree(token);"/]
      2exit<-.-!otherchart(["check  exec_cmd.c flowcharts"])
      strcmp3-->|true| 2exit
            

      
      
 






    



      
      

      




      
   
    
      end
