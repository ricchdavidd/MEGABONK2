$ErrorActionPreference='Stop'
$editorPath='C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$projectPath=Join-Path $PSScriptRoot 'Riftbound.uproject'
$logRoot=Join-Path $PSScriptRoot 'Saved\Logs'
New-Item -ItemType Directory -Path $logRoot -Force | Out-Null
$testProcesses=@()
try {
    $hostLog=Join-Path $logRoot 'NetworkHost.log'
    $hostArgs=@(('"'+$projectPath+'"'),'/Engine/Maps/Entry?listen','-game','-nullrhi','-nosound','-unattended','-RiftNetSmoke','-port=17877',('-abslog="'+$hostLog+'"'))
    $testHost=Start-Process -FilePath $editorPath -ArgumentList $hostArgs -WindowStyle Hidden -PassThru
    $testProcesses+=$testHost
    $deadline=(Get-Date).AddSeconds(120)
    do {
        Start-Sleep -Seconds 1
        $ready=(Test-Path -LiteralPath $hostLog) -and (Select-String -LiteralPath $hostLog -Pattern 'listening on port 17877' -Quiet)
    } while(-not $ready -and (Get-Date) -lt $deadline -and -not $testHost.HasExited)
    if(-not $ready){throw 'El anfitrion no inicio el puerto de prueba.'}
    for($index=1;$index -le 5;$index++){
        $clientLog=Join-Path $logRoot ('NetworkClient'+$index+'.log')
        $clientArgs=@(('"'+$projectPath+'"'),'127.0.0.1:17877','-game','-nullrhi','-nosound','-unattended','-RiftNetClient',('-abslog="'+$clientLog+'"'))
        $testProcesses+=Start-Process -FilePath $editorPath -ArgumentList $clientArgs -WindowStyle Hidden -PassThru
        Start-Sleep -Seconds 1
    }
    $deadline=(Get-Date).AddSeconds(150)
    while(-not $testHost.HasExited -and (Get-Date) -lt $deadline){Start-Sleep -Seconds 1}
    $passed=Select-String -LiteralPath $hostLog -Pattern 'RIFT_SMOKE PASS: heroes=6' -Quiet
    for($index=1;$index -le 5;$index++){
        $clientLog=Join-Path $logRoot ('NetworkClient'+$index+'.log')
        $clientPassed=Select-String -LiteralPath $clientLog -Pattern 'RIFT_CLIENT PASS' -Quiet
        Write-Output ('Cliente '+$index+': '+$clientPassed)
        $passed=$passed -and $clientPassed
    }
    if(-not $passed){throw 'Fallo en la prueba de red. Revisar Saved/Logs/Network*.log.'}
    Write-Output 'PASS: anfitrion y cinco clientes, seis jugadores totales.'
} finally {
    foreach($testProcess in $testProcesses){if(-not $testProcess.HasExited){Stop-Process -Id $testProcess.Id -ErrorAction SilentlyContinue}}
}
