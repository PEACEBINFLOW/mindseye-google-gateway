#include "mindseye/google/gateway/auth_middleware.hpp"

namespace mindseye::google::gateway {

static bool starts_with(const std::string& s, const std::string& prefix) {
  return s.rfind(prefix, 0) == 0;
}

bool AuthMiddleware::extract(
  const std::string& auth_header,
  const std::string& principal_header,
  RequestContext& out
) {
  if (!starts_with(auth_header, "Bearer ")) return false;
  out.bearer_token = auth_header.substr(7);
  out.principal = principal_header.empty() ? "unknown" : principal_header;
  return !out.bearer_token.empty();
}

} // namespace mindseye::google::gateway
