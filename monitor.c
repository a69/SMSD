//
// Created by h37 on 11/10/16.
//

#include <gammu-info.h>
#include <gammu-settings.h>
#include "monitor.h"
#include "info.h"


SMSD_Error set_monitors(GSM_StateMachine *stateMachine, redisContext *context) {

    GSM_NetworkInfo networkInfo;
    GSM_SignalQuality signalQuality;
    GSM_GPRSAccessPoint accessPoint;
    char IMEI[50];
    char IMSI[50];

    GSM_Error gsm_error;
    SMSD_Error smsd_error;
    gsm_error = GSM_GetSignalQuality(stateMachine, &signalQuality);
    gsm_error_handler(stateMachine, gsm_error, context);

    smsd_error = set_section_part_variable_int("Monitor","Signal","SignalPercent", signalQuality.SignalPercent);
    smsd_error_handler(stateMachine, smsd_error, context);

    smsd_error = set_section_part_variable_int("Monitor","Signal","SignalStrength", signalQuality.SignalStrength);
    smsd_error_handler(stateMachine, smsd_error, context);

    smsd_error = set_section_part_variable_int("Monitor","Signal","BitErrorRate", signalQuality.BitErrorRate);
    smsd_error_handler(stateMachine, smsd_error, context);

    gsm_error = GSM_GetNetworkInfo(stateMachine, &networkInfo);
    gsm_error_handler(stateMachine, gsm_error, context);


    smsd_error = set_section_part_variable_string("Monitor", "NetworkInfo", "GPRS", (char *) get_networkinfo_gprs_string(networkInfo.GPRS));
    smsd_error_handler(stateMachine, smsd_error, context);

    smsd_error = set_section_part_variable_string("Monitor","NetworkInfo","CID", networkInfo.CID);
    smsd_error_handler(stateMachine, smsd_error, context);

    smsd_error = set_section_part_variable_string("Monitor","NetworkInfo","LAC", networkInfo.LAC);
    smsd_error_handler(stateMachine, smsd_error, context);

    smsd_error = set_section_part_variable_string("Monitor","NetworkInfo","NetworkCode", networkInfo.NetworkCode);
    smsd_error_handler(stateMachine, smsd_error, context);

    smsd_error = set_section_part_variable_string("Monitor", "NetworkInfo", "NetworkName", (char *) networkInfo.NetworkName);
    smsd_error_handler(stateMachine, smsd_error, context);

    smsd_error = set_section_part_variable_string("Monitor","NetworkInfo","PacketCID", networkInfo.PacketCID);
    smsd_error_handler(stateMachine, smsd_error, context);

    smsd_error = set_section_part_variable_string("Monitor", "NetworkInfo", "PacketLAC", (char *) get_networkinfo_state_string(networkInfo.PacketState));
    smsd_error_handler(stateMachine, smsd_error, context);

    smsd_error = set_section_part_variable_string("Monitor", "NetworkInfo", "PacketLAC", (char *) get_networkinfo_state_string(networkInfo.State));
    smsd_error_handler(stateMachine, smsd_error, context);


    gsm_error = GSM_GetIMEI(stateMachine ,IMEI);
    gsm_error_handler(stateMachine, gsm_error, context);

    smsd_error = set_section_part_variable_string("Monitor", "Modem", "IMEI", IMEI);
    smsd_error_handler(stateMachine, smsd_error, context);

    gsm_error = GSM_GetSIMIMSI(stateMachine,IMSI);
    gsm_error_handler(stateMachine, gsm_error, context);

    smsd_error = set_section_part_variable_string("Monitor", "SIM", "IMSI", IMEI);
    smsd_error_handler(stateMachine, smsd_error, context);

}

