# Utility to Convert Elevation Data to QGIS Readable Format

## Requirements
* Needs to format the elevation data into a QGIS readable format .csv file. 
* This formatting includes an x,y coordinate position and an elevation value (meters from sea level).
  
## Specifications
* Utility is a command-line utility/console program.
* Will be named qgisElevationConverter.exe
* Reads in a .csv file from the command line.
  * This will be prompted once the program is started, no command line arguments.
  * This allows the program to be started from the desktop, in an environment where no command line args can be passed.
* Then attempts to open the file.
  * If it fails, it says so and asks for another file.
* Then reads in the data from the .csv file, and creates another file with the data formatted such that the following is true
  * Each line of the spreadshett is formatted as X Y Elevation
  * Elevation is as described above, meters from sealevel.
* The name of the file is the inputname + "Formatted".
* It saves the new .csv file in the programs working directory.
 ## Release is up to date.
