@echo off
join.exe input1.txt input_extraspace.txt temp.txt
echo:>>result.txt
echo ------->>result.txt
type temp.txt>>result.txt
echo:>>result.txt

join.exe input_HelloWorld.txt input_extraspace.txt input_HelloWorld.txt temp.txt
echo  ------->>result.txt
echo:>>result.txt
type temp.txt>>result.txt
echo:>>result.txt

join.exe input_HelloWorld.txt input_enter.txt input1.txt temp.txt
echo ------->>result.txt
echo:>>result.txt
type temp.txt>>result.txt
echo:>>result.txt

fc result.txt test_itog.txt > nul
if ERRORLEVEL 1 goto Different
echo Ok
pause
exit
:Different
echo Not ok
pause