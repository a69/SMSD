//
// Created by h37 on 11/5/16.
//

#ifndef SMSD_RECEIVE_H
#define SMSD_RECEIVE_H

#include <hiredis.h>
#include <gammu-statemachine.h>
#include "struct.h"

SMSD_Error receive_sms(GSM_StateMachine *stateMachine, redisContext *context);

#endif //SMSD_RECEIVE_H
