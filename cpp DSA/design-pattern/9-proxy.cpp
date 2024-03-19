#include <iostream>
#include <string>

// Subject interface
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() {}
};

// Real subject class representing an image
class RealImage : public Image {
private:
    std::string filename;

public:
    RealImage(const std::string& filename) : filename(filename) {
        loadFromDisk();
    }

    void display() override {
        std::cout << "Displaying image: " << filename << std::endl;
    }

private:
    void loadFromDisk() {
        std::cout << "Loading image from disk: " << filename << std::endl;
    }
};

// Proxy class representing a lazy-loaded image
class ImageProxy : public Image {
private:
    std::string filename;
    RealImage* realImage; // Pointer to real subject

public:
    ImageProxy(const std::string& filename) : filename(filename), realImage(nullptr) {}

    void display() override {
        if (!realImage) {
            realImage = new RealImage(filename); // Lazy loading
        }
        realImage->display();
    }

    ~ImageProxy() {
        delete realImage; // Clean up real subject when proxy is destroyed
    }
};

int main() {
    // Create and display an image using proxy
    Image* image = new ImageProxy("image.jpg");
    image->display();

    // Image will be loaded from disk only when display() is called
    delete image;

    return 0;
}
