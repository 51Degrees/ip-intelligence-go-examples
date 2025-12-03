$ErrorActionPreference = "Stop"

$assets = "20000 Evidence Records.yml" #, "51Degrees-LiteV41.ipi" # TODO: uncomment light IPI file when it exists

./steps/fetch-assets.ps1 -Assets $assets
foreach ($asset in $assets) {
    New-Item -ItemType SymbolicLink -Force -Target "$PWD/assets/$asset" -Path "$PSScriptRoot/../$asset"
}
