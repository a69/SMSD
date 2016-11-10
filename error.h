//
// Created by h37 on 11/3/16.
//

#ifndef SMSD_ERROR_H
#define SMSD_ERROR_H

#include "struct.h"
#include "info.h"
#include <stdio.h>
#include <stdlib.h>
#include <gammu.h>
#include <hiredis/hiredis.h>

void smsd_error_handler(GSM_StateMachine *stateMachine, SMSD_Error error, redisContext *context);

void gsm_error_handler(GSM_StateMachine *stateMachine, GSM_Error error, redisContext *context);

#endif //SMSD_ERROR_H
