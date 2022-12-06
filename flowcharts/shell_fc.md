```mermaid
flowchart TD

      subgraph SHELL
        start("START")
        start --> input[/"Input:\nchar buffer[1024]\nsize_t size"/]
        while_com["WHILE"] -.-> while{"1"}
        input --> while
        while --> print["printf($)"]
        print --> getline["getline(&buffer, &size, stdin)"]
        getline-->getcmd["getcmd"]
        getcmd-->execmd["execmd()"] --> endbox("END")
      end
