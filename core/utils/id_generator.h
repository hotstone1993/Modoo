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
            std::unique_lock<std::mutex>(m);

            do {
                // TODO: make id    
            } while(cache.find(newId) != cache.end());
            cache.insert(newId);

            return newId;
        }

        void resetCachedIds() {
            std::unique_lock<std::mutex>(m);
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
        std::mutex m;
    };
}

#endif // MODOO_CORE_UTILS_ID_GENERATOR