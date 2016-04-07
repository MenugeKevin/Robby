@echo off
set BRANCH="dev"
set DEVEL="master"

git checkout %BRANCH% --progress
git fetch --progress -v %DEVEL%
git rebase %DEVEL% 

pause