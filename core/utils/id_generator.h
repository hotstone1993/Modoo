#ifndef MODOO_CORE_UTILS_ID_GENERATOR
#define MODOO_CORE_UTILS_ID_GENERATOR

#include <mutex>
#include <unordered_set>
#include <random>

// TODO: thread safty
namespace modoo::core::utils {
    class IdGenerator {
    public:
        IdGenerator(const IdGenerator&) = delete;
        IdGenerator(IdGenerator&&) = delete;
        IdGenerator& operator=(const IdGenerator&) = delete;

        static IdGenerator& getInstance();

        int createId();
        void resetCachedIds();

    private:
        IdGenerator() = default;
        ~IdGenerator() = default;
        static void initInstance() {
            instance = new IdGenerator();
        }

        static std::once_flag initInstanceFlag;
        static IdGenerator* instance;
        static std::mt19937 gen;
        static std::random_device rd;

        std::uniform_int_distribution<int> dist;
        std::unordered_set<int> cache;
        std::mutex m;
    };
}

#endif // MODOO_CORE_UTILS_ID_GENERATOR