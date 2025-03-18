# Cloud-Native-Hw1
## Environments
### c++14 with gcc version 13.2.0 (Rev3, Built by MSYS2 project), run on Windows
### SQLite 安裝
到
https://www.sqlite.org/download.html
下載對應版本
本人使用windows
## Structure and how to use
### ./build.sh ./run.sh (User interface)(cmd)
build.sh 用於編譯，編譯完會自動刪除.o檔
run.sh 執行程式
***若要清空database，要刪除database.db，否則會保存此次運行紀錄
***增加# EXIT 指令可以離開程式
另附.exe檔
### 以下為r13922141_cli_app 中的內容
#### User Interface: command line
#### Presentation layer:
main.cpp: initialize database and use to cin the command and cout the output
#### Application layer: (Command class)
command.h: use to analyze the command and distribute the task
#### Domain layer: (MainService class)
cpp in operation file: all of the task we need include register, create list, get list, delete list, get category, get top category
#### Persistence layer: (dataoperation class)
cpp in operation/dataoperation file: the task which need command to SQLite database
#### Data layer:
SQLite database (database.db)

