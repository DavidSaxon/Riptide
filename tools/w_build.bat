@echo off

set VCTargetsPath=c:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V120

msbuild ..\Riptide.sln /v:n /p:Configuration=core
msbuild ..\Riptide.sln /v:n /p:Configuration=sovereign
msbuild ..\Riptide.sln /v:n /p:Configuration=meta_qt
msbuild ..\Riptide.sln /v:n /p:Configuration=Scry


echo.
echo --------------------------------
echo.

