
set BRANCH="dev"
set MSG=
set /P MSG=Message du commmit: %=%

git checkout %BRANCH%
git add -A
git commit -amv "Auto commited = %MSG%"
git push origin %BRANCH% 

#Master
pause