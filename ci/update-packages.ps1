param (
    [Parameter(Mandatory)][string]$RepoName
)
$ErrorActionPreference = "Stop"
$PSNativeCommandUseErrorActionPreference = $true

Push-Location $RepoName
try {
    $env:GOPROXY = "direct"
    go get -u ./...
    go mod tidy
} finally {
    Pop-Location
}
