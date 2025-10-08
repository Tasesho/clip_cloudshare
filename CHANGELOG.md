# Changelog

All notable versions of Clip Assistant are documented here.

## [0.0.3] - 2025-10-06

### Added
- Support for case-insensitive commands.
- Improved command reading in `main.cpp`.
- Updated command list to be consistent with lowercase keys.

### Fixed
- Issue with commands not being recognized due to case differences.

### Comments
- Users can now enter commands without worrying about uppercase or lowercase.
- This version enhances the terminal user experience.


## [0.0.2] - 2025-10-03
### Added
- Executable `clip-0.0.2.exe` included in release
- `Run` command allows opening specified address
- `ConvertFile` placeholder command (Coming soon)

### Changed
- Commands now handled with `map<string, function<void()>>` for greater modularity
- Commands are case-insensitive

### Fixed
- Screen cleanup and cross-platform exit

### Comments

- Small changes to the logic and major modification in the main code. 
- For future updates, I will translate everything to English.



:)
Tase
