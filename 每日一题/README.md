- vscode 开发环境搭建：<br>
vscode打开命令：<br>
```shell
mkdir hello
cd hello
code .
```
具体可参照官网文档，下面只简述快捷的步骤<br>
[visual studio code官网文档](https://code.visualstudio.com/docs)

----------------------------------------
- java:<br>
1、安装vscode的java扩展；<br>
2、打开vscode, ctrl+shift+P，输入create，选择第一个，创建java工程，再选择第一个No build toos, 然后选择一个开发目录, 再输入项目名称，Enter确定；<br>
3、会生成一个bin,lib,src/App.java的目录，运行App.java,会自动生成一个.vscode/settings.json的文件；<br>
4、vscode新建不了.vscode目录，就进入目录,输入cmd打开命令窗口，mkdir .vscode；<br>
5、settings.json设置字体及字体大小：<br>
```java
{
    "editor.fontSize": 18, //字体大小
    "terminal.integrated.fontFamily": "Lucida Console", // 字型
    
    "java.project.sourcePaths": ["src"],
    "java.project.outputPath": "bin",
    "java.project.referencedLibraries": [
        "lib/**/*.jar"
    ]
}
```

----------------------------------------
- python:<br>
1、安装vscode扩展：[Python extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-python.python)<br>
2、anaconda3 环境变量配置（否则会报运行会报conda相关的错）：<br>
D:\Anaconda<br>
D:\Anaconda\Scripts<br>
D:\Anaconda\Library\bin<br>
重启vscode!!<br>
3、vscode激活conda（不激活运行也会报错）:<br>
激活命令<br>
Windows：conda init <SHELL_NAME><br>
比如 Windows 一般是 conda init cmd.exe<br>
Linux：一般是 source activate<br>
最后记得重启vscode，否则不生效，还报错!!!<br>
4、运行一个.py文件：run和debug运行，会生成一个launch.json文件;<br>
5、自己新建.vscode\settings.json文件设置字体及字体大小：<br>
```python
{
    "editor.fontSize": 18, //字体大小
    "terminal.integrated.fontFamily": "Lucida Console" // 字型
}
```

----------------------------------------
- C++: <br>
- vscode官网文档貌似没有C语言的说明，不过估计和C++类似<br>
1、C++各种环境安装：<br>
[GCC on Windows](https://code.visualstudio.com/docs/cpp/config-mingw)<br>
[Microsoft C++ on Windows](https://code.visualstudio.com/docs/cpp/config-msvc)<br>
[GCC on Linux](https://code.visualstudio.com/docs/cpp/config-linux)<br>
[GCC on Windows Subsystem For Linux](https://code.visualstudio.com/docs/cpp/config-wsl)<br>
[Clang/LLVM on macOS](https://code.visualstudio.com/docs/cpp/config-clang-mac)<br>
2、MingW环境（GCC on Windows）说明：<br>
```c++
mkdir projects
cd projects
mkdir helloworld
cd helloworld
code .
```
打开vscode就会自动生成3个文件：<br>
```C++
tasks.json (build instructions)
launch.json (debugger settings)
c_cpp_properties.json (compiler path and IntelliSense settings)
```
3、新建一个.cpp文件，设置vscode为自动保存；<br>
4、run和degug运行： Run C/C++ File and Debug C/C++ File.<br>
总之，.vscode里四个文件都可以自动生成的，不需要自建：<br>
```C++
tasks.json (build instructions)
launch.json (debugger settings)
c_cpp_properties.json (compiler path and IntelliSense settings)
```
5、记录之前配置的.vscode的四个文件（其实完全可以不用自己新建配置，且网上找的配置后有些时标灰色，表示用不了的）：<br>
```C++
// launch.json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch", // 配置名称，将会在启动配置的下拉菜单中显示
            "type": "cppdbg", // 配置类型，这里只能为cppdbg
            "request": "launch", // 请求配置类型，可以为launch（启动）或attach（附加）
            "program": "${workspaceFolder}/bin/${fileBasenameNoExtension}.exe", // 要进行调试程序的路径
            "args": [], // 调试程序时传递给程序时的命令行参数，一般为空
            "stopAtEntry": false, // 设为true时程序暂停在程序入口处，相当于在main上打断点
            "cwd": "${workspaceFolder}", // 调试程序时的工作目录，此为工作区文件夹，改成{$fileDirname}可变为文件所在目录
            "environment": [], // 环境变量
            "externalConsole": true, // 使用单独的cmd窗口，与其它IDE一致，为false时使用内置终端
            "internalConsoleOptions": "neverOpen", // 如果不设为neverOpen，调试时会跳到“调试控制台”选项卡，你应该不需要对gdb手动输命令吧？
            "MIMode": "gdb", // 指定连接的调试器，可以为gdb或lldb。但目前lldb在windows下没有预编译好的版本。
            "miDebuggerPath": "C:/NewInstalledApp/MinGW/bin/gdb.exe", // 调试器路径，windows下后缀不能省略，linux下则不要
            "preLaunchTask": "build", // 调试会话开始前执行的任务，一般为编译程序。与tasks.json的label相对应
            "setupCommands": [
                {   // 模板自带，好像可以更好地显示SLT容器的内容，具体作用自行google
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": false
                }
            ]
        }
    ]
 }
```

```C++
// settings.json
{
    "editor.fontSize": 18,
    // "terminal.integrated.shellArgs.windows": ["/K chcp 65001 >nul"],
    "terminal.integrated.fontFamily": "Lucida Console",

    "files.defaultLanguage": "cpp", // ctrl+N新建文件后默认的语言
    "editor.formatOnType": true, // 输入时就进行格式化，默认触发字符较少，分号(c/c++的语句结束标志)可以触发
    "editor.suggest.snippetsPreventQuickSuggestions": false, // clangd的snippets有很多的跳转点，不用这个就必须手动触发Intellisence了
    "editor.acceptSuggestionOnEnter":"off",//我个人的习惯，按回车时一定是真正的执行，只有tab时才会接受Intellisense
    "editor.snippetSuggestions": "top", // snippets代码优先显示补全 // （可选）snippets显示在补全列表顶端，默认是inline

    // 不能识别的！估计时clang的，不是gcc的？？
    // "code-runner.runInTerminal": true, // 设置成false会在“输出”中输出，无法输入
    // "code-runner.executorMap": {
    //     "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt.exe -Wall -O2 -m64 -lm -static-libgcc -fexec-charset=GBK -D__USE_MINGW_ANSI_STDIO -fcolor-diagnostics --target=x86_64-w64-mingw -std=c11 && $dir$fileNameWithoutExt",
    //     "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt.exe -Wall -O2 -m64 -lm -static-libgcc -fexec-charset=GBK -fcolor-diagnostics --target=x86_64-w64-mingw -std=c++17 && $dir$fileNameWithoutExt"
    // }, // 设置code runner的命令行
    // "code-runner.saveFileBeforeRun": true, // run code前保存
    // "code-runner.preserveFocus": true, // 若为false，run code后光标会聚焦到终端上。如果需要频繁输入数据可设为false
    // "code-runner.clearPreviousOutput": false, // 每次run code前清空属于code runner的终端消息,默认为false
    // "code-runner.ignoreSelection": true, // 默认为false，效果时鼠标选中一段代码后可以单独执行，但c时编译型语言，不适合这样用
    // "code-runner.fileDictoryAsCwd": true,// 将code runner的终端的工作目录切换到文件目录再运行，对依赖cwd的程序产生影响，如果为false，code-runner.executorMap里要加cd $dir

    "C_Cpp.clang_format_sortIncludes": true, // 格式化时调整include的顺序（按字母排序）
    "C_Cpp.intelliSenseEngine": "Default", // 可以为Default或Tag Parser，后者较老，功能较简单。具体差别参考cpptools扩展文档
    // "C_Cpp.errorSquiggles": "Disabled", // 因为有clang的lint，所以关掉
    // "C_Cpp.autocomplete": "Disabled", // 因为有clang的补全，所以关掉

    // "clang.cflags": [ // 控制c语言静态检测的参数
    //     "--target=x86_64-w64-mingw",
    //     "-std=c11",
    //     "-Wall"
    // ],
    // "clang.cxxflags": [ // 控制c++静态检测时的参数
    //     "--target=x86_64-w64-mingw",
    //     "-std=c++17",
    //     "-Wall"
    // ],
    // "clang.completion.enable":true // 效果效果比cpptools要好
}
```

```C++
// tasks.json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "command": "gcc",
            "args": [
                "${file}",
                "-o",
                "${fileDirname}/bin/${fileBasenameNoExtension}.exe",
                "-g",
                "-m64",
                "-Wall",
                "-static-libgcc",
                "-fexec-charset=GBK",
                "-std=c++11",
                "-fcolor-diagnostics",
                "--target=x86_64-w64-mingw",
                "-std=c++17"
            ],
            "problemMatcher": {
                "owner": "$gcc",
                "fileLocation": [
                    "relative",
                    "${workspaceFolder}"
                ],
                "pattern": {
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            },
            "type": "shell",
            "group": "build",
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": false,
                "panel": "shared"
            }
        },
        {
            "label": "run",
            "type": "shell",
            "dependsOn": "build",
            "command": "${fileDirname}/bin/${fileBasenameNoExtension}.exe",
            "group": {
                "kind": "test",
                "isDefault": true
            },
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": true,
                "panel": "shared"
            }
        },
        {
            "type": "cppbuild",
            "label": "C/C++: gcc.exe 生成活动文件",
            "command": "C:\\NewInstalledApp\\MinGW\\bin\\gcc.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "C:\\NewInstalledApp\\MinGW\\bin"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ]
}
```

```C++
// c_cpp_properties.json
{
    "configurations": [
        {
            "name": "MinGW",
            "includePath": [
                "${workspaceFolder}"
                // "C:\\NewInstalledApp\\MinGW\\lib\\gcc\\mingw32\\6.3.0\\include\\c++" // 可以去掉
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "intelliSenseMode": "windows-gcc-x86", // clang-x64
            "browse": {
                "path": [
                    "${workspaceFolder}"
                    // "C:\\NewInstalledApp\\MinGW\\lib\\gcc\\mingw32\\6.3.0\\include\\c++" // 可以去掉
                ],
                "limitSymbolsToIncludedHeaders": true,
                "databaseFilename": ""
            },
            "compilerPath": "C:\\NewInstalledApp\\MinGW\\bin\\gcc.exe", // LLVM\\bin\\gcc.exe" -- clang
            "cStandard": "c11",
            "cppStandard": "c++14"
        }
    ],
    "version": 4
}
```

----------------------------------------
其它语言的后续再补充记录




