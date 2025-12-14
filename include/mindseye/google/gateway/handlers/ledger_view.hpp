#pragma once
#include "httplib.h"

namespace mindseye::google::gateway::handlers {

void handle_ledger_view(const httplib::Request& req, httplib::Response& res);

}
