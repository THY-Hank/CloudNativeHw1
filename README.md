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
另附.exe檔
### 以下為r13922141_cli_app 中的內容
### main.cpp (Presentation layer)
主程式，作用為讀取指令
### /operation 
#### command.h (Application layer)
作用為解析指令、並分發任務
#### operation.h (Domain layer)
執行各種指令任務
### /operation/dataoperation (Persistence layer)
執行所有接觸database的工作
### /operation/dataoperation/sqlite and database.db (Data layer)
database library 與 database 檔案
