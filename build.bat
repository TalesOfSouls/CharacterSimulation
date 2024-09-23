cls

IF NOT EXIST ..\build mkdir ..\build
IF NOT EXIST ..\build\simulation mkdir ..\build\simulation

if not defined DevEnvDir (call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat")

if "%Platform%" neq "x64" (
    echo ERROR: Platform is not "x64" - previous bat call failed.
    exit /b 1
)

cd ..\build\simulation
del *.pdb > NUL 2> NUL
del *.idb > NUL 2> NUL
cd ..\..\CharacterSimulation

REM Copy data
copy /y /d "settings.cfg" "..\build\simulation\settings.cfg"
copy /y /d "..\EngineDependencies\sqlite\lib\x64\sqlite3.dll" "..\build\simulation\sqlite3.dll"

REM Use /showIncludes for include debugging

REM Create main program
cl ^
    /MT /nologo /Gm- /GR- /EHsc /Od /Oi /WX /W4 /FC /Z7 /wd4201 ^
    /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /std:c++20 ^
    /D WIN32 /D _WINDOWS /D _UNICODE /D UNICODE /D _CRT_SECURE_NO_WARNINGS ^
    /Fo"../build/simulation/" /Fe"../build/simulation/sim_cross.exe" /Fd"../build/simulation/sim_cross.pdb" /Fm"../build/simulation/sim_cross.map" ^
    "sim_cross.cpp"^
    /link /INCREMENTAL:no ^
    /SUBSYSTEM:CONSOLE /MACHINE:X64 ^
    /LIBPATH:"../EngineDependencies/sqlite/lib/x64" ^
    kernel32.lib user32.lib gdi32.lib winmm.lib ^
    sqlite3.lib