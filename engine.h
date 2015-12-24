#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
public:
    Engine();
    ~Engine();

    void initialize();
    void update();
    void render();
    void finalize();

private:
};

#endif // ENGINE_H
