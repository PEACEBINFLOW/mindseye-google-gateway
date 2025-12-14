#include "mindseye/google/gateway/handlers/ledger_view.hpp"

namespace mindseye::google::gateway::handlers {

void handle_ledger_view(const httplib::Request&, httplib::Response& res) {
  // Stub: ledger-core lives in another repo.
  // This endpoint exists so clients have a stable route.
  res.set_content("{\"ledger\":\"not_implemented_in_gateway\"}", "application/json");
}

}
