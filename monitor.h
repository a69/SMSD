//
// Created by h37 on 11/10/16.
//

#ifndef SMSD_MONITOR_H
#define SMSD_MONITOR_H

#include <gammu-statemachine.h>
#include <hiredis/hiredis.h>
#include <gammu-info.h>
#include <wchar.h>
#include <gammu-types.h>
#include <gammu-config.h>
#include "struct.h"
#include "error.h"
#include "database.h"

SMSD_Error set_monitors(GSM_StateMachine *stateMachine,redisContext *context);

#endif //SMSD_MONITOR_H
