#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unpackfiles.h"

void unpackfiles(char* archive_file)
{
    FILE* archive = fopen(archive_file, "rb");
    if(!archive){
        perror("Error opening archive file");
        exit(1);
    }

    for(;;){
        Header header;
        int read = fread(&header, sizeof(Header), 1, archive);
        if(read == 0){ // if end of file break
            break;
        }
        else if(read != 1){
            perror("Error reading header");
            exit(1);
        }

        FILE* output = fopen(header.name, "wb"); // create the output files
        if(!output){
            perror("Error creating output file");
            exit(1);
        }

        for(int i = 0; i < header.size; i++){
            fputc(fgetc(archive), output); // write the file's content
        }

        fseek(archive, 4-(header.size % 4), SEEK_CUR); // this will skip the padding that was applied

        fclose(output);
    }

    fclose(archive);
}

int main(int argc, char* argv[])
{
    if(argc > 2){
        fprintf(stderr, "Usage: %s archive_file\n", argv[0]);
        return 1;
    }else{
        unpackfiles(argv[1]);
        remove(argv[1]);
    }

    return 0;
}
