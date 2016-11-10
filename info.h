//
// Created by h37 on 11/10/16.
//

#include <gammu-info.h>
#include "struct.h"

#ifndef SMSD_INFO_H
#define SMSD_INFO_H

const char *get_networkinfo_state_string(GSM_NetworkInfo_State info_state);

const char *get_networkinfo_gprs_string(GSM_GPRS_State gprs_state);

const char *get_gsm_error_string(GSM_Error error);

const char *get_smsd_error_string(SMSD_Error error);


#endif //SMSD_INFO_H
