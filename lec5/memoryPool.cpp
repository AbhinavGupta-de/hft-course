//
// Created by atlas on 9/2/25.
//
#include <cstdint>
#include <iostream>

using namespace std;


const uint64_t SIZE = 1024 * 1024;

struct MemoryPool
{
    char buffer[SIZE];
    uint64_t offset{0};

    void* getMemory(uint64_t bytesNeeded)
    {
        if (offset * bytesNeeded > SIZE)
            return nullptr;

        void* ptrToOffset = reinterpret_cast<void*>(&(buffer[offset]));
        offset += bytesNeeded;
        return ptrToOffset;
    }
};

struct Box
{
    uint64_t size;
    uint64_t length;
};

int main()
{
    MemoryPool mPool;
    for (int i = 0; i < 100; i++)
    {
        Box* box1 = reinterpret_cast<Box*>(mPool.getMemory(sizeof(Box)));
        box1->size = 10;
        cout << box1->size << endl;
    }
}
