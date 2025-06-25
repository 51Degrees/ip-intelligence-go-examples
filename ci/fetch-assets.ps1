param (
    [Parameter(Mandatory=$true)]
    [string]$RepoName
)

$assets = New-Item -ItemType Directory -Path assets -Force
$assetsDestination = "$RepoName"
$file = "51Degrees-LiteV41.ipi"

$downloads = @{
#    "51Degrees-LiteV41.ipi" = {Invoke-WebRequest -Uri "https://github.com/51Degrees/ip-intelligence-data/raw/main/51Degrees-LiteV41.ipi" -OutFile $assets/$file} // TODO: set the right path to the file when the file will be available
    "20000 Evidence Records.yml" = {Invoke-WebRequest -Uri "https://github.com/51Degrees/ip-intelligence-data/blob/main/evidence.yml" -OutFile $assets/$file}
}

foreach ($file in $downloads.Keys) {
    if (!(Test-Path $assets/$file)) {
        Write-Output "Downloading $file"
        Invoke-Command -ScriptBlock $downloads[$file]
    } else {
        Write-Output "'$file' exists, skipping download"
    }
}

New-Item -ItemType SymbolicLink -Force -Target "$assets/20000 Evidence Records.yml" -Path "$assetsDestination/20000 Evidence Records.yml"
