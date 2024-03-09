class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // Private constructor to prevent instantiation
public:
    static Singleton* getInstance() {
        if (!instance)
            instance = new Singleton();
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
