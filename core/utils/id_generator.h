#ifndef MODOO_CORE_UTILS_ID_GENERATOR
#define MODOO_CORE_UTILS_ID_GENERATOR

#include <mutex>
#include <unordered_set>

// TODO: thread safty
namespace modoo::core::utils {
    class IdGenerator {
    public:
        IdGenerator(const IdGenerator&) = delete;
        IdGenerator(IdGenerator&&) = delete;
        IdGenerator& operator=(const IdGenerator&) = delete;

        static IdGenerator& getInstance() {
            std::call_once(initInstanceFlag, initInstance);
            return *instance;
        }

        int createId() {
            int newId = 0;

            do {
                // TODO: make id    
            } while(cache.find(newId) != cache.end());
            cache.insert(newId);

            return newId;
        }

        void resetCachedIds() {
            cache.clear();
        }

    private:
        IdGenerator() = default;
        ~IdGenerator() = default;
        static void initInstance() {
            instance = new IdGenerator();
        }

        static std::once_flag initInstanceFlag;
        static IdGenerator* instance;
        std::unordered_set<int> cache;
    };
}

#endif // MODOO_CORE_UTILS_ID_GENERATOR