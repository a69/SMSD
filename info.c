//
// Created by h37 on 11/10/16.
//

#include <stddef.h>
#include "info.h"

const char *get_networkinfo_state_string(GSM_NetworkInfo_State info_state) {
    switch (info_state){
        case GSM_HomeNetwork:
            return "GSM_HomeNetwork";
        case GSM_NoNetwork:
            return "GSM_NoNetwork";
        case GSM_RoamingNetwork:
            return "GSM_RoamingNetwork";
        case GSM_RegistrationDenied:
            return "GSM_RegistrationDenied";
        case GSM_NetworkStatusUnknown:
            return "GSM_NetworkStatusUnknown";
        case GSM_RequestingNetwork:
            return "GSM_RequestingNetwork";
        default:
            return "UNKNOWN";
    }
}

const char *get_networkinfo_gprs_string(GSM_GPRS_State gprs_state) {
    switch (gprs_state){
        case GSM_GPRS_Detached:
            return "GSM_GPRS_Detached";
        case GSM_GPRS_Attached:
            return "GSM_GPRS_Attached";
        default:
            return "UNKNOWN";
    }
}

const char *get_smsd_error_string(SMSD_Error error) {
    switch (error){
        case SMSD_ERR_NONE:
            return "SMSD_ERR_NONE";
        case SMSD_ERR_NOTWRIATE:
            return "SMSD_ERR_NOTWRIATE";
        case SMSD_ERR_UNKNOWN:
            return "SMSD_ERR_UNKNOWN";
        default:
            return "UNKNOWN";
    }
}

const char *get_gsm_error_string(GSM_Error error) {
    return GSM_ErrorString(error);
}

