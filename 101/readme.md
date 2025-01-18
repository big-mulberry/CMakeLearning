
`cmake -B build`
在CMakeList.txt 同级目录 创建build 并在其中cmake ..

进入build后
`cmake --build .` 相当于 make，这个`.` 为build的路径

`cmake -S . -B build`
-S : CMakeList.txt 的路径
-B ：生成的 makefile 的路径

`cmake --build . --target help` 
查看可以生成哪些对应的目标