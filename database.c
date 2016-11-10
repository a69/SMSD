//
// Created by h37 on 11/8/16.
//

#include "database.h"

SMSD_Error reply_handler(redisReply *reply) {
    return SMSD_ERR_NONE;
}
SMSD_Error set_section_part_variable_int(const char *section,const char *part,const char *variable,int val){
    printf("%s:%s:%s::%d\n",section,part,variable,val);
    return SMSD_ERR_NONE;
}

SMSD_Error set_section_part_variable_string(const char *section, const char *part, const char *variable, char *val) {
    printf("%s:%s:%s::%s\n",section,part,variable,val);
    return SMSD_ERR_NONE;
}
