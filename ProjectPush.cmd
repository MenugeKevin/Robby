@echo off

set BRANCH = "dev"
set MSG=
set /P MSG=Message du commmit: %=%

git add -A
git commit -am "Auto commited = %MSG%"
git push %BRANCH% 

pause