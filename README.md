# Pack-Unpack-Files

The given program is responsible for packing and unpacking multiple files into an archive file. Here's a brief README description of the program:

1. Function `packfiles`:
   - This function is responsible for packing an individual file into the archive file.
   - It takes two parameters: a `FILE*` pointer to the archive file and a character array `file` representing the name of the file to be packed.
   - The function opens the input file in binary mode using `fopen` and performs error checking.
   - It determines the size of the input file using `fseek` and `ftell`.
   - An instance of the `Header` struct is created, which includes the size of the file and its name.
   - The header is written to the archive file using `fwrite`.
   - The contents of the input file are then read byte by byte using `fgetc` and written to the archive file using `fputc`.
   - If the file size is not a multiple of 4, padding with zeros is applied to ensure alignment.
   - Finally, the input file is closed using `fclose`.

2. `main` function:
   - The program's entry point, which is responsible for handling command-line arguments.
   - It expects at least three command-line arguments: the name of the archive file, followed by one or more file names to be packed.
   - If the number of arguments is less than 3, an error message is printed, and the program returns with a non-zero exit status.
   - The archive file is opened in binary write mode using `fopen` and error handling is performed.
   - A loop iterates over the remaining command-line arguments (file names) starting from index 2.
   - For each file name, the `packfiles` function is called to pack the file into the archive file.
   - Once all files are packed, the archive file is closed using `fclose`.
   - Another loop iterates over the file names again and removes each file using `remove` function.

The program allows users to pack multiple files into an archive file by providing the archive file name and the names of the files to be packed as command-line arguments. It utilizes the `packfiles` function to handle the packing process and ensures the proper handling of file I/O operations.
