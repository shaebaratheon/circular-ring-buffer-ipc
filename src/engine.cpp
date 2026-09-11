#include "circular_ring_buffer_ipc/ring_buffer.hpp"

namespace circular_ring_buffer_ipc {
bool RingBufferEngine::register_item(const std::string& k, const std::string& v) {
    std::lock_guard<std::mutex> lock(mu_);
    return map_.emplace(k, v).second;
}
std::string RingBufferEngine::process(const std::string& id, const std::unordered_map<std::string, std::string>&) {
    count_++;
    return "hash-" + id;
}
uint64_t RingBufferEngine::count() const {
    return count_.load();
}
}
