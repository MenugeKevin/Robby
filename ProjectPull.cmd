
set BRANCH="dev"
set DEVEL="master"

git checkout %BRANCH% --progress
git fetch --progress -v origin %DEVEL%
git rebase %DEVEL% 

pause