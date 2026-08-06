The Goal
    Write a command-line program that reads any binary file and prints
    its contents to the terminal in a classic hexdump format. This is
    the xxd or hexdump -C command you see in Linux, but built from
    scratch.

File handling in C
1. Open the file
    FILE *file = fopen(argv[1], "rb");
    Modes:
        "r" - Read
        "w" - Write
        "a" - Append
        "rb" - Read Binary
        "wb" - Write Binary
        "ab" - Append Binary
        "r+" - Read and Write
        "rb+" - Read and Write Binary
2. Read the file
    fread(buffer, size, count, file);
    fgetc(file);
3. Write to the file
    fwrite(buffer, size, count, file);
    fputc(char, file);
4. Close the file
    fclose(file);

File handling in C++
1. Open the file
    std::ifstream inFile("filename.bin", std::ios::binary);
    std::ofstream outFile("filename.bin", std::ios::binary);
    std::fstream file("filename.bin", std::ios::binary);
    Modes:
        std::ios::in - Input
        std::ios::out - Output
        std::ios::app - Append
        std::ios::binary - Binary mode
        std::ios::trunc - Truncate
2. Read the file
    file.read(buffer, size);
    file.get(char);
3. Write to the file
    file.write(buffer, size);
    file.put(char);
4. Close the file
    file.close()
