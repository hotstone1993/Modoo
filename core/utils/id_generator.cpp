#include "id_generator.h"
#include <random>

namespace modoo::core::utils {

    IdGenerator* IdGenerator::instance= nullptr;
    std::once_flag IdGenerator::initInstanceFlag;
    std::random_device IdGenerator::rd;
    std::mt19937 IdGenerator::gen(rd());

    IdGenerator& IdGenerator::getInstance() {
        std::call_once(initInstanceFlag, initInstance);
        return *instance;
    }

    int IdGenerator::createId() {
        int newId = 0;
        std::unique_lock<std::mutex>(m);

        do {
            newId = dist(gen);  
        } while(cache.find(newId) != cache.end());
        cache.insert(newId);

        return newId;
    }

    void IdGenerator::resetCachedIds() {
        std::unique_lock<std::mutex>(m);
        cache.clear();
    }
}