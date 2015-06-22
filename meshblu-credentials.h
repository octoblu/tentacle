#ifndef TENTACLE_MESSAGE_H
#define TENTACLE_MESSAGE_H

#include "pin-array.h"
#include "pins.hpp"

struct MeshbluCredentials {

public:
  MeshbluCredentials(const char* uuid=NULL, const char* token=NULL);
  const char* getUuid() const;
  const char* getToken() const;

private:
  const char* uuid;
  const char* token;
};
#endif
