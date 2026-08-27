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

Printing hex values:
C Language
    // Basic lowercase and uppercase hex
    printf("Lowercase: %x\n", num); // ff
    printf("Uppercase: %X\n", num); // FF

    // With '0x' or '0X' prefix automatically added
    printf("With prefix: %#x\n", num); // 0xff

    // Padded with leading zeros (8 characters wide)
    printf("Padded: 0x%08X\n", num); // 0x000000FF

CPP Language
    // Basic hex output, must tell by std::hex to print hexadecimal
    std::cout << "Hex: " << std::hex << num << std::endl; // ff

    // Uppercase with 0x prefix and zero padding
    std::cout << "Formatted: 0x" 
              << std::uppercase 
              << std::setw(8) 
              << std::setfill('0') 
              << num << std::endl; // 0x000000FF

    // Resetting the stream state back to decimal
    std::cout << std::dec << std::nouppercase; 