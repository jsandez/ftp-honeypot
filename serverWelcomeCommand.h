#ifndef _WELCOME_H_
#define _WELCOME_H_
#include "serverCommand.h"

/*
 * Comando de bienvenida
 */
class serverWelcomeCommand : public serverCommand {
 public:
  serverWelcomeCommand(serverUserAuthentication &user_authentication, const serverCfgMap &cfg_map);
  std::string execute() override;
};

#endif
