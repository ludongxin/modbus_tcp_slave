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

SET AXIO_BOARD_SET_FILE=axio_board_set.bat
SET AXIO_BUILDSET_SET_FILE=axio_buildset_set.bat

if not exist %AXIO_BOARD_SET_FILE% (
    goto board_choice
) else (
    goto board_end
)

:board_choice
echo Please choise which board you want build.

echo 1. EPC6450-AWI

echo 2. EPC6450-ZC1

echo 3. EPC6750-AWI-muti

echo 4. EPC6750-AWI

echo 5. HPM6280-EVK

echo 6. HPM6360-EVK

echo 7. HPM6750EVK

echo 8. MPC6340-AWI


echo.&echo.

set /p board_input=input choice:


if "%board_input%" == "1" (
    echo SET AXIO_BOARD_NAME=EPC6450-AWI > %AXIO_BOARD_SET_FILE%
)

if "%board_input%" == "2" (
    echo SET AXIO_BOARD_NAME=EPC6450-ZC1 > %AXIO_BOARD_SET_FILE%
)

if "%board_input%" == "3" (
    echo SET AXIO_BOARD_NAME=EPC6750-AWI-muti > %AXIO_BOARD_SET_FILE%
)

if "%board_input%" == "4" (
    echo SET AXIO_BOARD_NAME=EPC6750-AWI > %AXIO_BOARD_SET_FILE%
)

if "%board_input%" == "5" (
    echo SET AXIO_BOARD_NAME=HPM6280-EVK > %AXIO_BOARD_SET_FILE%
)

if "%board_input%" == "6" (
    echo SET AXIO_BOARD_NAME=HPM6360-EVK > %AXIO_BOARD_SET_FILE%
)

if "%board_input%" == "7" (
    echo SET AXIO_BOARD_NAME=HPM6750EVK > %AXIO_BOARD_SET_FILE%
)

if "%board_input%" == "8" (
    echo SET AXIO_BOARD_NAME=MPC6340-AWI > %AXIO_BOARD_SET_FILE%
)


:board_end

call %AXIO_BOARD_SET_FILE%
echo Board: %AXIO_BOARD_NAME%
echo.&echo.

if exist %AXIO_BUILDSET_SET_FILE% (
    goto has_buildset

) else (
    goto no_buildset
)

:has_buildset
call %AXIO_BUILDSET_SET_FILE%
echo buildset: %AXIO_BUILDSET_NAME%
echo.&echo.

echo axio build  -Xplatform=platform-hpm-aworks-lp -Xboard=%AXIO_BOARD_NAME%  -Xbuildsets=%AXIO_BUILDSET_NAME% -tguiconfig
echo.&echo.
axio build  -Xplatform=platform-hpm-aworks-lp -Xboard=%AXIO_BOARD_NAME%  -Xbuildsets=%AXIO_BUILDSET_NAME% -tguiconfig
goto end

:no_buildset
echo axio build  -Xplatform=platform-hpm-aworks-lp -Xboard=%AXIO_BOARD_NAME%  -tguiconfig
echo.&echo.
axio build  -Xplatform=platform-hpm-aworks-lp -Xboard=%AXIO_BOARD_NAME%  -tguiconfig
goto end

:end
pause