param (
    [Parameter(Mandatory)][string]$RepoName
)
$ErrorActionPreference = "Stop"
$PSNativeCommandUseErrorActionPreference = $true

Push-Location $RepoName
try {
	go clean -modcache

    if (Test-Path "go.sum") {
        Remove-Item "go.sum" -Force
    }

    $env:GOPROXY = "direct"
	go mod download

    go get -u ./...
    go mod tidy

	go mod verify
} finally {
    Pop-Location
}
