#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packfiles.h"

void packfiles(FILE* archive, char* file)
{
    
        FILE* input = fopen(file, "rb");
        if(!input){
            perror("Error opening input file");
            exit(1);
        }

        
        fseek(input, 0, SEEK_END); // retrieve file size
        int fileSize = ftell(input);
        rewind(input);

        Header header; // initialize the header
        header.size = fileSize;
        strncpy(header.name, file, 20); // copy name from the filestore which contains the names

        fwrite(&header, sizeof(Header), 1, archive); //append the header into the archive file
        for(int j = 0; j < fileSize; j++){
            fputc(fgetc(input), archive); //appends the files into the archive
        }

        if(fileSize % 4 != 0){ // this applies padding if necessary
            for(int j = 0; j < 4-(fileSize % 4); j++){
                fputc(0, archive); //this puts 0 where padding is needed
            }
        }

        fclose(input);
    

}

int main(int argc, char* argv[])
{
    if(argc < 3){
        fprintf(stderr, "Usage: %s archive_file file1 file2 ...\n", argv[0]);
        return 1;
    }else{
        
        FILE* archive = fopen(argv[1], "wb");
        if(!archive){
            perror("Error opening archive file");
            exit(1);
        }
        
        for(int i = 2; i < argc; i++){
            packfiles(archive, argv[i]);
        }
        
        fclose(archive);

        for(int i = 2; i < argc; i++){
            remove(argv[i]);
        }
    }
    return 0;
}
