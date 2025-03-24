@echo off

pushd %~dp0

echo Startup AXIO CMD...

cd ../
set BUILD_APPLICATION_DIR=%cd%
set SOLUTION_FILE=solution.json

:axio_home_dir_get
    cd ../
    if not exist %SOLUTION_FILE% (
        goto axio_home_dir_get 
    )

set AXIO_HOME_DIR=%cd%

cd packages
for /F %%i in ('dir venv_git_bash.bat /s /b') do (set BAT_FILE=%%i)
set SOFT_ROOT_DIR=%BAT_FILE:~0,-18%

cd %SOFT_ROOT_DIR%
set PYTHON_SCRIPT_DIR=%SOFT_ROOT_DIR%\Scripts
set path=%SystemRoot%\system32;%SystemRoot%;%SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;
set path=%SystemRoot%\system32;%SystemRoot%;%SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;
set path=%PYTHON_ROOT_DIR%;%PYTHON_SCRIPT_DIR%;%path%;
set VIRTUAL_ENV=%SOFT_ROOT_DIR%
Scripts\python.exe resite.py

cd %BUILD_APPLICATION_DIR%

cd %BUILD_APPLICATION_DIR%
axio --version
echo build env init finish.
echo.&echo.

axio build -tclean
echo.&echo.

pause

if exist user_config(
    rd  user_config
)

