@echo off

set BRANCH = "origin"

git fetch --progress -v %BRANCH%
git rebase %BRANCH%
