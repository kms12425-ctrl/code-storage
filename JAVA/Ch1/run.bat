@echo off
chcp 65001 >nul
echo (1)把class文件设置到 classpath 环境变量里
set classpath=.\chapter1\class
echo (2)运行Welcome类的命令
java homework.ch1.Welcome

echo (3)把 jar 文件设置到 classpath 环境变量里
set classpath=.\chapter1\jar\run.jar
echo (4)运行 jar 文件夹下 run.jar 里的 Welcome 类
java homework.ch1.Welcome