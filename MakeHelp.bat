@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by CACHE2003.HPJ. >"hlp\Cache2003.hm"
echo. >>"hlp\Cache2003.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Cache2003.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Cache2003.hm"
echo. >>"hlp\Cache2003.hm"
echo // Prompts (IDP_*) >>"hlp\Cache2003.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Cache2003.hm"
echo. >>"hlp\Cache2003.hm"
echo // Resources (IDR_*) >>"hlp\Cache2003.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Cache2003.hm"
echo. >>"hlp\Cache2003.hm"
echo // Dialogs (IDD_*) >>"hlp\Cache2003.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Cache2003.hm"
echo. >>"hlp\Cache2003.hm"
echo // Frame Controls (IDW_*) >>"hlp\Cache2003.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Cache2003.hm"
REM -- Make help for Project CACHE2003


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Cache2003.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Cache2003.hlp" goto :Error
if not exist "hlp\Cache2003.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Cache2003.hlp" Debug
if exist Debug\nul copy "hlp\Cache2003.cnt" Debug
if exist Release\nul copy "hlp\Cache2003.hlp" Release
if exist Release\nul copy "hlp\Cache2003.cnt" Release
echo.
goto :done

:Error
echo hlp\Cache2003.hpj(1) : error: Problem encountered creating help file

:done
echo.
