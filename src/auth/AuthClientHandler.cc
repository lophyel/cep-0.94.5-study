// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*- 
// vim: ts=8 sw=2 smarttab
/*
 * Ceph - scalable distributed file system
 *
 * Copyright (C) 2004-2009 Sage Weil <sage@newdream.net>
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software 
 * Foundation.  See file COPYING.
 * 
 */


#include <errno.h>

#include "AuthClientHandler.h"
#include "KeyRing.h"

#include "messages/MAuth.h"
#include "messages/MAuthReply.h"

#include "cephx/CephxClientHandler.h"
#include "none/AuthNoneClientHandler.h"

AuthClientHandler *get_auth_client_handler(CephContext *cct, int proto,
					   RotatingKeyRing *rkeys)
{
  switch (proto) {
  case CEPH_AUTH_CEPHX:
    return new CephxClientHandler(cct, rkeys);
  case CEPH_AUTH_NONE:
    return new AuthNoneClientHandler(cct, rkeys);
  default:
    return NULL;
  }
}

