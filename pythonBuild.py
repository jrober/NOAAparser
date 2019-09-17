import subprocess

executable = r"C:\\Users\\A10\\source\\noaaParser\\noaaParser\\Debug\\noaaParser.exe"
writeDebugFile = "1" # 1 - yes, 0 - no
inputFile = "C:/Users/A10/Documents/Justins/ACM00078861-data_header.txt"

# run executable with command line arguments
subprocess.check_call([executable, writeDebugFile, inputFile]) 
