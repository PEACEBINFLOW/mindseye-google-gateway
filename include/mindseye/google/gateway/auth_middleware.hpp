#pragma once
#include "mindseye/google/gateway/types.hpp"
#include <string>

namespace mindseye::google::gateway {

// Extracts auth headers into RequestContext.
// This gateway does presence checks only.
// Full validation belongs to mindseye-google-auth (separate repo).
class AuthMiddleware {
public:
  static bool extract(
    const std::string& auth_header,
    const std::string& principal_header,
    RequestContext& out
  );
};

} // namespace mindseye::google::gateway
