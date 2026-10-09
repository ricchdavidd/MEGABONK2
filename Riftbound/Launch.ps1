param(
    [ValidateSet('Solo','Host','Join')][string]$Mode='Solo',
    [string]$Address='127.0.0.1'
)
$editorPath='C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$projectPath=Join-Path $PSScriptRoot 'Riftbound.uproject'
if(-not (Test-Path -LiteralPath $editorPath)){throw 'No se encuentra Unreal Engine 5.8.'}
$map='/Engine/Maps/Entry'
if($Mode -eq 'Host'){$map='/Engine/Maps/Entry?listen'}
if($Mode -eq 'Join'){
    $parsedAddress=$null
    if(-not [System.Net.IPAddress]::TryParse($Address,[ref]$parsedAddress)){throw 'Indica una direccion IP valida.'}
    $map=$Address
}
& $editorPath $projectPath $map -game -windowed -ResX=1280 -ResY=720 -log
