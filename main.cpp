#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdint>

int main(int argc, char* argv[]){
    // Check if a filename is provided
    if(argc == 1) {
        std::cerr << "Please provide a filename\n";
        return 0;
    }
    
    // Open the file in binary mode
    std::ifstream file(argv[1], std::ios::binary);
    // std::cout << file.gcount() << "\n";
    if(file.is_open()){
        std::cout << "File opened successfully\n";
        // char byte;  
        // file.get(byte);
        unsigned char buffer[16]; // printed signed value without unsigned
        uint8_t bufferSize = sizeof(buffer);
        // reinterpret_cast<char*>(buffer) is used to convert the buffer to a char pointer
        file.read(reinterpret_cast<char*>(buffer), bufferSize);
        int bytesRead = file.gcount();

        // std::cout << std::setfill ('%08x') << std::setw(sizeof(char)*2) << std::hex << 5;
        int offset = 0;
        // std::cout << (int)offset << ": ";
        // offset++;

        while(bytesRead > 0){
            // std::cout << offset << std::endl;
            // if(offset % 16 == 1)
                    
            // if(offset % 16 == 0){
            //     std::cout << std::endl;
                
            //     // std::cout << " | ";
            // }

            // if(offset % 16 == 1){

            // }            

            std::cout << std::hex << std::setfill('0') << std::setw(8) << offset << std::setfill('0') << std::dec << "  ";
            for(int i=0; i<16; i++){
                if(i==8){
                    std::cout << " ";
                }
                if(i>=bytesRead)
                    std::cout << "   ";
                else
                    std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)buffer[i] << " ";
                
            }
            std::cout << " |";
            for(int i=0; i<16; i++){
                // ASCII codes 32 to 126 are printable characters
                if(buffer[i] >= 32 && buffer[i] <= 126 && i<bytesRead){
                    std::cout << buffer[i];
                }else{
                    std::cout << ".";
                }
                
            }
            std::cout << "|" << std::endl;
            
            // std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)byte;
            // if(byte == '\n') std::cout << std::endl;
            // file.get(byte);

            file.read(reinterpret_cast<char*>(buffer), bufferSize);
            bytesRead = file.gcount();
            offset+=16;
            // std::cout << buffer;
        }
        std::cout << "\n";
        file.close();
    }else {
        std::cerr << "File not found!\n";
    }
    return 0;
}