#pragma once
#include <string>

namespace mindseye::google::gateway {

struct RequestContext {
  std::string bearer_token;
  std::string principal;   // e.g. orch:alice or agent:routing:alpha
  std::string request_id;
};

} // namespace mindseye::google::gateway
