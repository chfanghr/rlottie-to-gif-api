#include "controller/RenderController.h"
#include "AppComponent.h"

#include <oatpp/network/Server.hpp>

void run() {
  AppComponent components;

  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  auto renderController = std::make_shared<RenderController>();
  renderController->addEndpointsToRouter(router);

  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

  oatpp::network::Server server(connectionProvider, connectionHandler);

  OATPP_LOGI("service", "running on port %s", connectionProvider->getProperty("port").getData());

  server.run();
}

int main() {
  oatpp::base::Environment::init();

  run();

  oatpp::base::Environment::destroy();

  return 0;
}
