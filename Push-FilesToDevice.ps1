
param (
    [string]$DeviceAddr
)

$erroractionpreference = 'stop'
Set-StrictMode -version latest

@"
help
bell
quit
"@ | ftp.exe
