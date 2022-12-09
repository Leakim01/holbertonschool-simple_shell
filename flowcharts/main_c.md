```mermaid
flowchart TD

 style main.c fill:#F9F9F9, stroke: #E8E8E8,stroke-width:2px 
  style main fill:#F9F9F9, stroke: #8080FF,stroke-width:2px 
   style handle_signal fill:#F9F9F9, stroke: #008080,stroke-width:2px 


 style Libraries fill: #B8DAC6,stroke:#3A7050,stroke-width:2px


 style id fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
 style start fill: #FD8882,stroke: #FF6600,stroke-width:2px
 style input fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style args fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style exit fill: #FD8882,stroke: #FF6600,stroke-width:2px



 style id2 fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3
 style start2 fill: #FD8882,stroke: #FF6600,stroke-width:2px
 style input2 fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style args2 fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style signal fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style input3 fill: #CFE2E7,stroke:#A3C9D1,stroke-width:2px
 style args3 fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style get_cmd fill: #FFDE6C,stroke:#FFCB17,stroke-width:2px
 style 1-return fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style 1exit fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style 3exit fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style Break fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style 0return fill:#FFB15B, stroke-width:2px, stroke:#E67800
 style dgetcmd fill:#bbf,stroke:#B366FF,stroke-width:2px,color:#fff,stroke-dasharray: 3 3

  style Free1 fill:#F3D6E2, stroke-width:2px, stroke:#DA81A7
  style Free2 fill:#F3D6E2, stroke-width:2px, stroke:#DA81A7
  style Free3 fill:#F3D6E2, stroke-width:2px, stroke:#DA81A7
  style exit2 fill: #FD8882,stroke: #FF6600,stroke-width:2px







 subgraph main.c
        Libraries["#include main.h"]     

     subgraph handle_signal
       
       id(["void handle_signal(int signal)"])-.-start(Start)
       start--> input[/"(void) signal"/]
       input-->args["fflush(stdout)"]
       args-->exit("Exit")
       
       end
      
     subgraph main
       id2(["int main(int ac, char *av[], char *ev[])"])-.-start2("Start")
       start2--> input2[/"char *buffer;\nsize_t len = 1024, inputchar;\nint error = 0;\n(void) ac;\n(void) av;\n(void) ev;\n(void) error;"/]
        
       input2--> args2["buffer = malloc(len * sizeof(char))"]
       args2-->!buffer{!buffer}
       !buffer-->1-return(Return -1)
       !buffer-->signal["signal(SIGINT, handle_signal)"]
       signal-->while{1}
       dwhile(while)-.->while
       while-->input3[/"inputchar = getline(&buffer, &len, stdin)"/]
       input3-->args3["fflush(stdin)"]
       args3-->EOF{{"if (inputchar == (size_t) EOF)"}}
       EOF-->|false|get_cmd["error = get_cmd(buffer, len, ev)"]-->Error1{{"error == -1"}}
       dgetcmd[["check get_cmd.c flowchart"]]-.-get_cmd(Start)
     
               click dgetcmd href "https://www.github.com" "This is a tooltip for a link"

       
       EOF-->|true|Break("Break")
       Error1-->|false|Error3{{"error == -3"}}
       Error1-->|true|Free1([Free])-->1exit("Exit2")
       Error3-->|true|Free2([Free])-->3exit("Exit0")
       Error3-->while-->Free3([Free])-->0return("Return0")-->exit2("Exit")

       
        
      end
 end
