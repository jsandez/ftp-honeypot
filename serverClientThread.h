#ifndef _CLIENTTHREAD_H_
#define _CLIENTTHREAD_H_
#include "serverSocket.h"
#include <atomic>
#include "serverThread.h"
#include "serverFTPServer.h"

/*
 * Clase que representa al ciclo de vida de
 * un cliente en el socket correspondiente.
 * Enviara y recibira mensajes hasta que
 * el cliente se desconecte o el servidor se apague.
 * Utiliza variables atomicas para determinar
 * cuando el socket esta "muerto"
 */
class serverClientThread : public serverThread {
 private:
  std::atomic<bool> keep_talking;
  std::atomic<bool> is_running;
  serverSocket socket_server;
  serverFTPServer ftp_server;

 public:
  serverClientThread(serverSocket &socket_server,
                     serverCfgMap &cfg_map,
                     serverMonitorDirectory &directory);
  virtual void run() override;
  virtual void stop() override;
  virtual bool isAlive() override ;
};

#endif
