#include "mindseye/google/gateway/rate_limit.hpp"

namespace mindseye::google::gateway {

bool RateLimit::allow(const std::string&, const std::string&) {
  // Stub: allow all. Replace with fixed-window token bucket later.
  return true;
}

} // namespace mindseye::google::gateway
