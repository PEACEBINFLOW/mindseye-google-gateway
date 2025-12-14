#include "mindseye/google/gateway/sse_bus.hpp"

namespace mindseye::google::gateway {

void SSEBus::publish(const std::string& event, const std::string& data) {
  std::lock_guard<std::mutex> lock(mu_);
  buffer_.push_back("event: " + event + "\n" + "data: " + data + "\n\n");
  // Keep buffer bounded
  if (buffer_.size() > 2000) buffer_.erase(buffer_.begin(), buffer_.begin() + 500);
}

std::vector<std::string> SSEBus::snapshot() const {
  std::lock_guard<std::mutex> lock(mu_);
  return buffer_;
}

} // namespace mindseye::google::gateway
