//
// Created by h37 on 11/3/16.
//

#include "error.h"

void smsd_error_handler(GSM_StateMachine *stateMachine, SMSD_Error error, redisContext *context) {
    if (error != SMSD_ERR_NONE) {
        printf("ERROR: %s\n", get_smsd_error_string(error));
    }
}
void gsm_error_handler(GSM_StateMachine *stateMachine, GSM_Error error, redisContext *context) {
    if (error != ERR_NONE) {
        printf("ERROR: %s\n", get_gsm_error_string(error));
    }
}