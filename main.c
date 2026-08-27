#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[]){
    if(argc == 1){
        perror("Please provide a filename.\n");
        return 0;
    }

    FILE *file = fopen(argv[1], "rb");
    if(file){
        printf("File opened successfully!\n");
        // uint8_t byte = fgetc(file);
        uint8_t buffer[16];
        uint8_t bytesRead = fread(buffer, 1 ,16, file);
        int offset = 0;
        // while(byte != EOF)
        while(bytesRead > 0){ 

            printf("%08x  ", offset);

            for(int i=0; i<16; i++){
                if(i == 8)
                    printf(" ");
                if(i < bytesRead)
                    printf("%02x ", buffer[i]);
                else
                    printf("   ");
            }
            printf("  |");

            for(int i=0; i<16; i++){
                if(buffer[i] >= 32 && buffer[i] <= 126 && i<bytesRead){
                    printf("%c", buffer[i]);
                }
                else
                    printf(".");
            }
            printf("|\n");

            // printf("%c", (char)byte);
            // byte = fgetc(file);
            // printf("%s", buffer);
            bytesRead = fread(buffer, 1, 16, file);
            offset += 16;
        }
        printf("\n");
        fclose(file);
    }else {
        perror("File not found!\n");
    }
    return 0;
}