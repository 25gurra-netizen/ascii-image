/*
1. Get the filename from the command line.
2. Check that the file exists/can be opened.
3. Load the image.
4. Retrieve its width and height.
5. Print them to the terminal.
6. Handle the case where the image can't be loaded.
*/
#include <iostream>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

int main(int argc, char* argv[]) {
    // Step 1: Get the filename from the command line
    if (argc != 2) {
            std::cerr << "Usage: " << argv[0] << " <filename>\n";
            return 1;
    }
    //2. Check that the file exists/can be opened.
    if (!std::filesystem::exists(argv[1])){
        std::cerr << "File does not exist: " << argv[1] << "\n";
        return 1;
    }
    std::cout << "File exist: " << argv[1] << "\n";
    
    int height, width, channel;
    unsigned char *image = stbi_load(argv[1], &width, &height, &channel, 0);
    if (image == nullptr){
        std::cerr << "Invalid image\n";
        return 1;
    }
    std::cout << "File loaded successfully\n";
    std::cout << "Height: " << height << "\n";
    std::cout << "Width: " << width << "\n";
    stbi_image_free(image);
    return 0;
}