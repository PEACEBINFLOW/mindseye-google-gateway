#pragma once
#include <string>

namespace mindseye::google::gateway {

class RateLimit {
public:
  // Deterministic, explicit stub:
  // Returns true if allowed; false if blocked.
  static bool allow(const std::string& principal, const std::string& route);
};

} // namespace mindseye::google::gateway
