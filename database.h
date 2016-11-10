//
// Created by h37 on 11/8/16.
//

#ifndef SMSD_DATABASE_H
#define SMSD_DATABASE_H

#include "error.h"
#include "struct.h"
#include <hiredis/hiredis.h>

SMSD_Error reply_handler(redisReply *reply);

SMSD_Error set_section_part_variable_int(const char *section, const char *part, const char *variable, int val);

SMSD_Error set_section_part_variable_string(const char *section, const char *part, const char *variable, char *val);

#endif //SMSD_DATABASE_H
