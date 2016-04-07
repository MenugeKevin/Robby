@echo off

set BRANCH = "origin"
set MSG=
set MSG=Message du commmit: %=%

git add -A
git commit -am "Auto commited = %MSG%"
git push %BRANCH%
