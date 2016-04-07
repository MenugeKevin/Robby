@echo off

set BRANCH="master"
set MSG=
set /P MSG=Message du commmit: %=%

git checkout -b %BRANCH%
git add -A
git commit -am "Auto commited = %MSG%"
git push %BRANCH% 

pause