#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <atomic>
#include <mutex>

namespace circular_ring_buffer_ipc {

class FutexNotifierEngine {
public:
    FutexNotifierEngine() = default;
    bool register_item(const std::string& k, const std::string& v);
    std::string process(const std::string& id, const std::unordered_map<std::string, std::string>& data);
    uint64_t count() const;

private:
    mutable std::mutex mu_;
    std::unordered_map<std::string, std::string> map_;
    std::atomic<uint64_t> count_{0};
};

}
