typedef struct{
    int size;
    char name[20];
}Header;
void packfiles(FILE* archive, char* file);
