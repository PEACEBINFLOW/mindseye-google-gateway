#pragma once

#include <mutex>
#include <string>
#include <vector>

namespace mindseye::google::gateway {

// Minimal in-memory SSE broadcast bus.
// Used for /v1/render/stream (and later ledger streams).
class SSEBus {
public:
  void publish(const std::string& event, const std::string& data);

  // Returns buffered messages since last call (per-connection poll model).
  // We keep it simple & explicit.
  std::vector<std::string> snapshot() const;

private:
  mutable std::mutex mu_;
  std::vector<std::string> buffer_;
};

} // namespace mindseye::google::gateway
