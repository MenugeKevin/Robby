
set BRANCH="dev"
set MSG=
set /P MSG=Message du commmit: %=%

git checkout %BRANCH%
git add -A
git commit -am "Auto commited = %MSG%"
git push origin %BRANCH% 


pause